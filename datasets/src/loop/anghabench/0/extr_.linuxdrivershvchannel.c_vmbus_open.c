#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u32 ;
struct TYPE_6__ {int /*<<< orphan*/  msgtype; } ;
struct vmbus_channel_open_channel {size_t downstream_ringbuffer_pageoffset; int /*<<< orphan*/  userdata; int /*<<< orphan*/  target_vp; int /*<<< orphan*/  ringbuffer_gpadlhandle; int /*<<< orphan*/  child_relid; int /*<<< orphan*/  openid; TYPE_1__ header; } ;
struct TYPE_8__ {scalar_t__ status; } ;
struct TYPE_9__ {TYPE_3__ open_result; } ;
struct vmbus_channel_msginfo {int /*<<< orphan*/  msglistentry; TYPE_4__ response; int /*<<< orphan*/  waitevent; int /*<<< orphan*/ * msg; struct vmbus_channel* waiting_channel; } ;
struct TYPE_7__ {int /*<<< orphan*/  child_relid; } ;
struct vmbus_channel {scalar_t__ state; void (* onchannel_callback ) (void*) ;size_t ringbuffer_pagecount; int /*<<< orphan*/  inbound; int /*<<< orphan*/  outbound; int /*<<< orphan*/  ringbuffer_gpadlhandle; scalar_t__ rescind; int /*<<< orphan*/  target_vp; TYPE_2__ offermsg; int /*<<< orphan*/  ringbuffer_pages; int /*<<< orphan*/  target_cpu; int /*<<< orphan*/ * channel_callback_context; int /*<<< orphan*/  lock; } ;
struct page {int dummy; } ;
struct TYPE_10__ {int /*<<< orphan*/  channelmsg_lock; int /*<<< orphan*/  chn_msg_list; } ;

/* Variables and functions */
 int /*<<< orphan*/  CHANNELMSG_OPENCHANNEL ; 
 scalar_t__ CHANNEL_OPENED_STATE ; 
 scalar_t__ CHANNEL_OPENING_STATE ; 
 scalar_t__ CHANNEL_OPEN_STATE ; 
 int EAGAIN ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int GFP_KERNEL ; 
 size_t MAX_USER_DEFINED_BYTES ; 
 size_t PAGE_SHIFT ; 
 size_t PAGE_SIZE ; 
 int __GFP_ZERO ; 
 int /*<<< orphan*/  __free_pages (struct page*,int /*<<< orphan*/ ) ; 
 struct page* alloc_pages (int,int /*<<< orphan*/ ) ; 
 struct page* alloc_pages_node (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_to_node (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  get_order (size_t) ; 
 int /*<<< orphan*/  hv_ringbuffer_cleanup (int /*<<< orphan*/ *) ; 
 int hv_ringbuffer_init (int /*<<< orphan*/ *,struct page*,size_t) ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct vmbus_channel_msginfo*) ; 
 struct vmbus_channel_msginfo* kmalloc (int,int) ; 
 int /*<<< orphan*/  list_add_tail (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  list_del (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ *,size_t) ; 
 int /*<<< orphan*/  page_address (struct page*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  trace_vmbus_open (struct vmbus_channel_open_channel*,int) ; 
 TYPE_5__ vmbus_connection ; 
 int vmbus_establish_gpadl (struct vmbus_channel*,int /*<<< orphan*/ ,size_t,int /*<<< orphan*/ *) ; 
 int vmbus_post_msg (struct vmbus_channel_open_channel*,int,int) ; 
 int /*<<< orphan*/  vmbus_teardown_gpadl (struct vmbus_channel*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wait_for_completion (int /*<<< orphan*/ *) ; 

int vmbus_open(struct vmbus_channel *newchannel, u32 send_ringbuffer_size,
		     u32 recv_ringbuffer_size, void *userdata, u32 userdatalen,
		     void (*onchannelcallback)(void *context), void *context)
{
	struct vmbus_channel_open_channel *open_msg;
	struct vmbus_channel_msginfo *open_info = NULL;
	unsigned long flags;
	int ret, err = 0;
	struct page *page;

	if (send_ringbuffer_size % PAGE_SIZE ||
	    recv_ringbuffer_size % PAGE_SIZE)
		return -EINVAL;

	spin_lock_irqsave(&newchannel->lock, flags);
	if (newchannel->state == CHANNEL_OPEN_STATE) {
		newchannel->state = CHANNEL_OPENING_STATE;
	} else {
		spin_unlock_irqrestore(&newchannel->lock, flags);
		return -EINVAL;
	}
	spin_unlock_irqrestore(&newchannel->lock, flags);

	newchannel->onchannel_callback = onchannelcallback;
	newchannel->channel_callback_context = context;

	/* Allocate the ring buffer */
	page = alloc_pages_node(cpu_to_node(newchannel->target_cpu),
				GFP_KERNEL|__GFP_ZERO,
				get_order(send_ringbuffer_size +
				recv_ringbuffer_size));

	if (!page)
		page = alloc_pages(GFP_KERNEL|__GFP_ZERO,
				   get_order(send_ringbuffer_size +
					     recv_ringbuffer_size));

	if (!page) {
		err = -ENOMEM;
		goto error_set_chnstate;
	}

	newchannel->ringbuffer_pages = page_address(page);
	newchannel->ringbuffer_pagecount = (send_ringbuffer_size +
					   recv_ringbuffer_size) >> PAGE_SHIFT;

	ret = hv_ringbuffer_init(&newchannel->outbound, page,
				 send_ringbuffer_size >> PAGE_SHIFT);

	if (ret != 0) {
		err = ret;
		goto error_free_pages;
	}

	ret = hv_ringbuffer_init(&newchannel->inbound,
				 &page[send_ringbuffer_size >> PAGE_SHIFT],
				 recv_ringbuffer_size >> PAGE_SHIFT);
	if (ret != 0) {
		err = ret;
		goto error_free_pages;
	}


	/* Establish the gpadl for the ring buffer */
	newchannel->ringbuffer_gpadlhandle = 0;

	ret = vmbus_establish_gpadl(newchannel,
				    page_address(page),
				    send_ringbuffer_size +
				    recv_ringbuffer_size,
				    &newchannel->ringbuffer_gpadlhandle);

	if (ret != 0) {
		err = ret;
		goto error_free_pages;
	}

	/* Create and init the channel open message */
	open_info = kmalloc(sizeof(*open_info) +
			   sizeof(struct vmbus_channel_open_channel),
			   GFP_KERNEL);
	if (!open_info) {
		err = -ENOMEM;
		goto error_free_gpadl;
	}

	init_completion(&open_info->waitevent);
	open_info->waiting_channel = newchannel;

	open_msg = (struct vmbus_channel_open_channel *)open_info->msg;
	open_msg->header.msgtype = CHANNELMSG_OPENCHANNEL;
	open_msg->openid = newchannel->offermsg.child_relid;
	open_msg->child_relid = newchannel->offermsg.child_relid;
	open_msg->ringbuffer_gpadlhandle = newchannel->ringbuffer_gpadlhandle;
	open_msg->downstream_ringbuffer_pageoffset = send_ringbuffer_size >>
						  PAGE_SHIFT;
	open_msg->target_vp = newchannel->target_vp;

	if (userdatalen > MAX_USER_DEFINED_BYTES) {
		err = -EINVAL;
		goto error_free_gpadl;
	}

	if (userdatalen)
		memcpy(open_msg->userdata, userdata, userdatalen);

	spin_lock_irqsave(&vmbus_connection.channelmsg_lock, flags);
	list_add_tail(&open_info->msglistentry,
		      &vmbus_connection.chn_msg_list);
	spin_unlock_irqrestore(&vmbus_connection.channelmsg_lock, flags);

	if (newchannel->rescind) {
		err = -ENODEV;
		goto error_free_gpadl;
	}

	ret = vmbus_post_msg(open_msg,
			     sizeof(struct vmbus_channel_open_channel), true);

	trace_vmbus_open(open_msg, ret);

	if (ret != 0) {
		err = ret;
		goto error_clean_msglist;
	}

	wait_for_completion(&open_info->waitevent);

	spin_lock_irqsave(&vmbus_connection.channelmsg_lock, flags);
	list_del(&open_info->msglistentry);
	spin_unlock_irqrestore(&vmbus_connection.channelmsg_lock, flags);

	if (newchannel->rescind) {
		err = -ENODEV;
		goto error_free_gpadl;
	}

	if (open_info->response.open_result.status) {
		err = -EAGAIN;
		goto error_free_gpadl;
	}

	newchannel->state = CHANNEL_OPENED_STATE;
	kfree(open_info);
	return 0;

error_clean_msglist:
	spin_lock_irqsave(&vmbus_connection.channelmsg_lock, flags);
	list_del(&open_info->msglistentry);
	spin_unlock_irqrestore(&vmbus_connection.channelmsg_lock, flags);

error_free_gpadl:
	vmbus_teardown_gpadl(newchannel, newchannel->ringbuffer_gpadlhandle);
	kfree(open_info);
error_free_pages:
	hv_ringbuffer_cleanup(&newchannel->outbound);
	hv_ringbuffer_cleanup(&newchannel->inbound);
	__free_pages(page,
		     get_order(send_ringbuffer_size + recv_ringbuffer_size));
error_set_chnstate:
	newchannel->state = CHANNEL_OPEN_STATE;
	return err;
}