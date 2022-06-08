#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_32__   TYPE_8__ ;
typedef  struct TYPE_31__   TYPE_7__ ;
typedef  struct TYPE_30__   TYPE_6__ ;
typedef  struct TYPE_29__   TYPE_5__ ;
typedef  struct TYPE_28__   TYPE_4__ ;
typedef  struct TYPE_27__   TYPE_3__ ;
typedef  struct TYPE_26__   TYPE_2__ ;
typedef  struct TYPE_25__   TYPE_1__ ;
typedef  struct TYPE_24__   TYPE_12__ ;

/* Type definitions */
struct TYPE_26__ {int level; } ;
struct TYPE_28__ {TYPE_2__ header; } ;
typedef  TYPE_4__ tree ;
struct TYPE_29__ {TYPE_3__* item; } ;
typedef  TYPE_5__ traverse_ptr ;
struct TYPE_25__ {int incompat_flags; } ;
struct TYPE_30__ {int /*<<< orphan*/  extent_root; TYPE_1__ superblock; } ;
typedef  TYPE_6__ device_extension ;
typedef  int /*<<< orphan*/  UINT8 ;
typedef  void* UINT64 ;
struct TYPE_32__ {int /*<<< orphan*/  level; } ;
struct TYPE_31__ {scalar_t__ obj_id; scalar_t__ obj_type; int offset; } ;
struct TYPE_24__ {scalar_t__ obj_id; scalar_t__ obj_type; int /*<<< orphan*/  offset; } ;
struct TYPE_27__ {int size; TYPE_12__ key; int /*<<< orphan*/  data; } ;
typedef  int /*<<< orphan*/  PIRP ;
typedef  void* NTSTATUS ;
typedef  TYPE_7__ KEY ;
typedef  TYPE_8__ EXTENT_ITEM_TREE ;
typedef  TYPE_8__ EXTENT_ITEM_SKINNY_METADATA ;

/* Variables and functions */
 int /*<<< orphan*/  ALLOC_TAG ; 
 int BTRFS_INCOMPAT_FLAGS_SKINNY_METADATA ; 
 int /*<<< orphan*/  ERR (char*,...) ; 
 TYPE_8__* ExAllocatePoolWithTag (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ExFreePool (TYPE_8__*) ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  NT_SUCCESS (void*) ; 
 int /*<<< orphan*/  PagedPool ; 
 int /*<<< orphan*/  RtlCopyMemory (TYPE_8__*,int /*<<< orphan*/ ,int) ; 
 void* STATUS_INSUFFICIENT_RESOURCES ; 
 void* STATUS_INTERNAL_ERROR ; 
 void* STATUS_SUCCESS ; 
 scalar_t__ TYPE_EXTENT_ITEM ; 
 scalar_t__ TYPE_METADATA_ITEM ; 
 void* delete_tree_item (TYPE_6__*,TYPE_5__*) ; 
 void* find_item (TYPE_6__*,int /*<<< orphan*/ ,TYPE_5__*,TYPE_7__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void* insert_tree_item (TYPE_6__*,int /*<<< orphan*/ ,void*,scalar_t__,int /*<<< orphan*/ ,TYPE_8__*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  keycmp (TYPE_12__,TYPE_7__) ; 

__attribute__((used)) static NTSTATUS update_extent_level(device_extension* Vcb, UINT64 address, tree* t, UINT8 level, PIRP Irp) {
    KEY searchkey;
    traverse_ptr tp;
    NTSTATUS Status;

    if (Vcb->superblock.incompat_flags & BTRFS_INCOMPAT_FLAGS_SKINNY_METADATA) {
        searchkey.obj_id = address;
        searchkey.obj_type = TYPE_METADATA_ITEM;
        searchkey.offset = t->header.level;

        Status = find_item(Vcb, Vcb->extent_root, &tp, &searchkey, FALSE, Irp);
        if (!NT_SUCCESS(Status)) {
            ERR("error - find_item returned %08x\n", Status);
            return Status;
        }

        if (!keycmp(tp.item->key, searchkey)) {
            EXTENT_ITEM_SKINNY_METADATA* eism;

            if (tp.item->size > 0) {
                eism = ExAllocatePoolWithTag(PagedPool, tp.item->size, ALLOC_TAG);

                if (!eism) {
                    ERR("out of memory\n");
                    return STATUS_INSUFFICIENT_RESOURCES;
                }

                RtlCopyMemory(eism, tp.item->data, tp.item->size);
            } else
                eism = NULL;

            Status = delete_tree_item(Vcb, &tp);
            if (!NT_SUCCESS(Status)) {
                ERR("delete_tree_item returned %08x\n", Status);
                if (eism) ExFreePool(eism);
                return Status;
            }

            Status = insert_tree_item(Vcb, Vcb->extent_root, address, TYPE_METADATA_ITEM, level, eism, tp.item->size, NULL, Irp);
            if (!NT_SUCCESS(Status)) {
                ERR("insert_tree_item returned %08x\n", Status);
                if (eism) ExFreePool(eism);
                return Status;
            }

            return STATUS_SUCCESS;
        }
    }

    searchkey.obj_id = address;
    searchkey.obj_type = TYPE_EXTENT_ITEM;
    searchkey.offset = 0xffffffffffffffff;

    Status = find_item(Vcb, Vcb->extent_root, &tp, &searchkey, FALSE, Irp);
    if (!NT_SUCCESS(Status)) {
        ERR("error - find_item returned %08x\n", Status);
        return Status;
    }

    if (tp.item->key.obj_id == searchkey.obj_id && tp.item->key.obj_type == searchkey.obj_type) {
        EXTENT_ITEM_TREE* eit;

        if (tp.item->size < sizeof(EXTENT_ITEM_TREE)) {
            ERR("(%llx,%x,%llx) was %u bytes, expected at least %u\n", tp.item->key.obj_id, tp.item->key.obj_type, tp.item->key.offset, tp.item->size, sizeof(EXTENT_ITEM_TREE));
            return STATUS_INTERNAL_ERROR;
        }

        eit = ExAllocatePoolWithTag(PagedPool, tp.item->size, ALLOC_TAG);

        if (!eit) {
            ERR("out of memory\n");
            return STATUS_INSUFFICIENT_RESOURCES;
        }

        RtlCopyMemory(eit, tp.item->data, tp.item->size);

        Status = delete_tree_item(Vcb, &tp);
        if (!NT_SUCCESS(Status)) {
            ERR("delete_tree_item returned %08x\n", Status);
            ExFreePool(eit);
            return Status;
        }

        eit->level = level;

        Status = insert_tree_item(Vcb, Vcb->extent_root, tp.item->key.obj_id, tp.item->key.obj_type, tp.item->key.offset, eit, tp.item->size, NULL, Irp);
        if (!NT_SUCCESS(Status)) {
            ERR("insert_tree_item returned %08x\n", Status);
            ExFreePool(eit);
            return Status;
        }

        return STATUS_SUCCESS;
    }

    ERR("could not find EXTENT_ITEM for address %llx\n", address);

    return STATUS_INTERNAL_ERROR;
}