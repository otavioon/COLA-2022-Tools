#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ const u32 ;
struct tee_shm {scalar_t__ flags; int id; unsigned long offset; size_t size; int num_pages; struct tee_shm* pages; int /*<<< orphan*/  link; int /*<<< orphan*/  dmabuf; struct tee_context* ctx; struct tee_device* teedev; } ;
struct tee_device {int /*<<< orphan*/  mutex; int /*<<< orphan*/  idr; TYPE_2__* desc; } ;
struct tee_context {int /*<<< orphan*/  list_shm; struct tee_device* teedev; } ;
struct TYPE_8__ {size_t size; struct tee_shm* priv; int /*<<< orphan*/  flags; int /*<<< orphan*/ * ops; } ;
struct TYPE_7__ {TYPE_1__* ops; } ;
struct TYPE_6__ {int (* shm_register ) (struct tee_context*,struct tee_shm*,struct tee_shm*,int,unsigned long) ;int /*<<< orphan*/  (* shm_unregister ) (struct tee_context*,struct tee_shm*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  DEFINE_DMA_BUF_EXPORT_INFO (TYPE_3__) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ENOTSUPP ; 
 struct tee_shm* ERR_CAST (int /*<<< orphan*/ ) ; 
 struct tee_shm* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  O_RDWR ; 
 unsigned long PAGE_SIZE ; 
 scalar_t__ const TEE_SHM_DMA_BUF ; 
 scalar_t__ const TEE_SHM_REGISTER ; 
 scalar_t__ const TEE_SHM_USER_MAPPED ; 
 int /*<<< orphan*/  dma_buf_export (TYPE_3__*) ; 
 TYPE_3__ exp_info ; 
 int get_user_pages_fast (unsigned long,int,int,struct tee_shm*) ; 
 int idr_alloc (int /*<<< orphan*/ *,struct tee_shm*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  idr_remove (int /*<<< orphan*/ *,int) ; 
 struct tee_shm* kcalloc (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct tee_shm*) ; 
 struct tee_shm* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  list_add_tail (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  put_page (struct tee_shm) ; 
 unsigned long rounddown (unsigned long,unsigned long) ; 
 unsigned long roundup (unsigned long,unsigned long) ; 
 int stub1 (struct tee_context*,struct tee_shm*,struct tee_shm*,int,unsigned long) ; 
 int /*<<< orphan*/  stub2 (struct tee_context*,struct tee_shm*) ; 
 int /*<<< orphan*/  tee_device_get (struct tee_device*) ; 
 int /*<<< orphan*/  tee_device_put (struct tee_device*) ; 
 int /*<<< orphan*/  tee_shm_dma_buf_ops ; 
 int /*<<< orphan*/  teedev_ctx_get (struct tee_context*) ; 
 int /*<<< orphan*/  teedev_ctx_put (struct tee_context*) ; 

struct tee_shm *tee_shm_register(struct tee_context *ctx, unsigned long addr,
				 size_t length, u32 flags)
{
	struct tee_device *teedev = ctx->teedev;
	const u32 req_flags = TEE_SHM_DMA_BUF | TEE_SHM_USER_MAPPED;
	struct tee_shm *shm;
	void *ret;
	int rc;
	int num_pages;
	unsigned long start;

	if (flags != req_flags)
		return ERR_PTR(-ENOTSUPP);

	if (!tee_device_get(teedev))
		return ERR_PTR(-EINVAL);

	if (!teedev->desc->ops->shm_register ||
	    !teedev->desc->ops->shm_unregister) {
		tee_device_put(teedev);
		return ERR_PTR(-ENOTSUPP);
	}

	teedev_ctx_get(ctx);

	shm = kzalloc(sizeof(*shm), GFP_KERNEL);
	if (!shm) {
		ret = ERR_PTR(-ENOMEM);
		goto err;
	}

	shm->flags = flags | TEE_SHM_REGISTER;
	shm->teedev = teedev;
	shm->ctx = ctx;
	shm->id = -1;
	start = rounddown(addr, PAGE_SIZE);
	shm->offset = addr - start;
	shm->size = length;
	num_pages = (roundup(addr + length, PAGE_SIZE) - start) / PAGE_SIZE;
	shm->pages = kcalloc(num_pages, sizeof(*shm->pages), GFP_KERNEL);
	if (!shm->pages) {
		ret = ERR_PTR(-ENOMEM);
		goto err;
	}

	rc = get_user_pages_fast(start, num_pages, 1, shm->pages);
	if (rc > 0)
		shm->num_pages = rc;
	if (rc != num_pages) {
		if (rc >= 0)
			rc = -ENOMEM;
		ret = ERR_PTR(rc);
		goto err;
	}

	mutex_lock(&teedev->mutex);
	shm->id = idr_alloc(&teedev->idr, shm, 1, 0, GFP_KERNEL);
	mutex_unlock(&teedev->mutex);

	if (shm->id < 0) {
		ret = ERR_PTR(shm->id);
		goto err;
	}

	rc = teedev->desc->ops->shm_register(ctx, shm, shm->pages,
					     shm->num_pages, start);
	if (rc) {
		ret = ERR_PTR(rc);
		goto err;
	}

	if (flags & TEE_SHM_DMA_BUF) {
		DEFINE_DMA_BUF_EXPORT_INFO(exp_info);

		exp_info.ops = &tee_shm_dma_buf_ops;
		exp_info.size = shm->size;
		exp_info.flags = O_RDWR;
		exp_info.priv = shm;

		shm->dmabuf = dma_buf_export(&exp_info);
		if (IS_ERR(shm->dmabuf)) {
			ret = ERR_CAST(shm->dmabuf);
			teedev->desc->ops->shm_unregister(ctx, shm);
			goto err;
		}
	}

	mutex_lock(&teedev->mutex);
	list_add_tail(&shm->link, &ctx->list_shm);
	mutex_unlock(&teedev->mutex);

	return shm;
err:
	if (shm) {
		size_t n;

		if (shm->id >= 0) {
			mutex_lock(&teedev->mutex);
			idr_remove(&teedev->idr, shm->id);
			mutex_unlock(&teedev->mutex);
		}
		if (shm->pages) {
			for (n = 0; n < shm->num_pages; n++)
				put_page(shm->pages[n]);
			kfree(shm->pages);
		}
	}
	kfree(shm);
	teedev_ctx_put(ctx);
	tee_device_put(teedev);
	return ret;
}