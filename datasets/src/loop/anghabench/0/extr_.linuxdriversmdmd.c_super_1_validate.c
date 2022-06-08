#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct mdp_superblock_1 {int devflags; int /*<<< orphan*/  feature_map; int /*<<< orphan*/  recovery_offset; int /*<<< orphan*/  journal_tail; int /*<<< orphan*/ * dev_roles; int /*<<< orphan*/  max_dev; int /*<<< orphan*/  new_chunk; int /*<<< orphan*/  new_layout; int /*<<< orphan*/  new_level; int /*<<< orphan*/  delta_disks; int /*<<< orphan*/  reshape_position; int /*<<< orphan*/  bitmap_offset; int /*<<< orphan*/  set_uuid; int /*<<< orphan*/  resync_offset; int /*<<< orphan*/  size; int /*<<< orphan*/  raid_disks; int /*<<< orphan*/  layout; int /*<<< orphan*/  level; int /*<<< orphan*/  utime; int /*<<< orphan*/  ctime; int /*<<< orphan*/  chunksize; int /*<<< orphan*/  events; } ;
struct TYPE_4__ {int offset; int space; int default_offset; int default_space; int /*<<< orphan*/ * file; } ;
struct mddev {int raid_disks; int major_version; int chunk_sectors; int level; int layout; scalar_t__ events; int reshape_backwards; int max_disks; scalar_t__ minor_version; int delta_disks; int new_level; int new_layout; int new_chunk_sectors; TYPE_1__* bitmap; int /*<<< orphan*/ * pers; int /*<<< orphan*/  flags; void* reshape_position; TYPE_2__ bitmap_info; int /*<<< orphan*/  uuid; void* recovery_cp; void* dev_sectors; scalar_t__* clevel; void* utime; void* ctime; scalar_t__ external; scalar_t__ patch_version; } ;
struct md_rdev {int raid_disk; int desc_nr; int saved_raid_disk; int /*<<< orphan*/  flags; void* recovery_offset; void* journal_tail; int /*<<< orphan*/  sb_page; } ;
typedef  scalar_t__ __u64 ;
typedef  int __s32 ;
struct TYPE_3__ {scalar_t__ events_cleared; } ;

/* Variables and functions */
 int /*<<< orphan*/  Bitmap_sync ; 
 int EINVAL ; 
 int /*<<< orphan*/  FailFast ; 
 int FailFast1 ; 
 int /*<<< orphan*/  Faulty ; 
 int /*<<< orphan*/  In_sync ; 
 int /*<<< orphan*/  Journal ; 
 int LEVEL_MULTIPATH ; 
#define  MD_DISK_ROLE_FAULTY 130 
#define  MD_DISK_ROLE_JOURNAL 129 
 int MD_DISK_ROLE_MAX ; 
#define  MD_DISK_ROLE_SPARE 128 
 int MD_FEATURE_BITMAP_OFFSET ; 
 int MD_FEATURE_JOURNAL ; 
 int MD_FEATURE_MULTIPLE_PPLS ; 
 int MD_FEATURE_PPL ; 
 int MD_FEATURE_RECOVERY_BITMAP ; 
 int MD_FEATURE_RECOVERY_OFFSET ; 
 int MD_FEATURE_REPLACEMENT ; 
 int MD_FEATURE_RESHAPE_ACTIVE ; 
 int MD_FEATURE_RESHAPE_BACKWARDS ; 
 int /*<<< orphan*/  MD_HAS_JOURNAL ; 
 int /*<<< orphan*/  MD_HAS_PPL ; 
 void* MaxSector ; 
 int /*<<< orphan*/  Replacement ; 
 int /*<<< orphan*/  WriteMostly ; 
 int WriteMostly1 ; 
 int /*<<< orphan*/  clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int le16_to_cpu (int /*<<< orphan*/ ) ; 
 int le32_to_cpu (int /*<<< orphan*/ ) ; 
 void* le64_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 struct mdp_superblock_1* page_address (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_warn (char*) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int super_1_validate(struct mddev *mddev, struct md_rdev *rdev)
{
	struct mdp_superblock_1 *sb = page_address(rdev->sb_page);
	__u64 ev1 = le64_to_cpu(sb->events);

	rdev->raid_disk = -1;
	clear_bit(Faulty, &rdev->flags);
	clear_bit(In_sync, &rdev->flags);
	clear_bit(Bitmap_sync, &rdev->flags);
	clear_bit(WriteMostly, &rdev->flags);

	if (mddev->raid_disks == 0) {
		mddev->major_version = 1;
		mddev->patch_version = 0;
		mddev->external = 0;
		mddev->chunk_sectors = le32_to_cpu(sb->chunksize);
		mddev->ctime = le64_to_cpu(sb->ctime);
		mddev->utime = le64_to_cpu(sb->utime);
		mddev->level = le32_to_cpu(sb->level);
		mddev->clevel[0] = 0;
		mddev->layout = le32_to_cpu(sb->layout);
		mddev->raid_disks = le32_to_cpu(sb->raid_disks);
		mddev->dev_sectors = le64_to_cpu(sb->size);
		mddev->events = ev1;
		mddev->bitmap_info.offset = 0;
		mddev->bitmap_info.space = 0;
		/* Default location for bitmap is 1K after superblock
		 * using 3K - total of 4K
		 */
		mddev->bitmap_info.default_offset = 1024 >> 9;
		mddev->bitmap_info.default_space = (4096-1024) >> 9;
		mddev->reshape_backwards = 0;

		mddev->recovery_cp = le64_to_cpu(sb->resync_offset);
		memcpy(mddev->uuid, sb->set_uuid, 16);

		mddev->max_disks =  (4096-256)/2;

		if ((le32_to_cpu(sb->feature_map) & MD_FEATURE_BITMAP_OFFSET) &&
		    mddev->bitmap_info.file == NULL) {
			mddev->bitmap_info.offset =
				(__s32)le32_to_cpu(sb->bitmap_offset);
			/* Metadata doesn't record how much space is available.
			 * For 1.0, we assume we can use up to the superblock
			 * if before, else to 4K beyond superblock.
			 * For others, assume no change is possible.
			 */
			if (mddev->minor_version > 0)
				mddev->bitmap_info.space = 0;
			else if (mddev->bitmap_info.offset > 0)
				mddev->bitmap_info.space =
					8 - mddev->bitmap_info.offset;
			else
				mddev->bitmap_info.space =
					-mddev->bitmap_info.offset;
		}

		if ((le32_to_cpu(sb->feature_map) & MD_FEATURE_RESHAPE_ACTIVE)) {
			mddev->reshape_position = le64_to_cpu(sb->reshape_position);
			mddev->delta_disks = le32_to_cpu(sb->delta_disks);
			mddev->new_level = le32_to_cpu(sb->new_level);
			mddev->new_layout = le32_to_cpu(sb->new_layout);
			mddev->new_chunk_sectors = le32_to_cpu(sb->new_chunk);
			if (mddev->delta_disks < 0 ||
			    (mddev->delta_disks == 0 &&
			     (le32_to_cpu(sb->feature_map)
			      & MD_FEATURE_RESHAPE_BACKWARDS)))
				mddev->reshape_backwards = 1;
		} else {
			mddev->reshape_position = MaxSector;
			mddev->delta_disks = 0;
			mddev->new_level = mddev->level;
			mddev->new_layout = mddev->layout;
			mddev->new_chunk_sectors = mddev->chunk_sectors;
		}

		if (le32_to_cpu(sb->feature_map) & MD_FEATURE_JOURNAL)
			set_bit(MD_HAS_JOURNAL, &mddev->flags);

		if (le32_to_cpu(sb->feature_map) &
		    (MD_FEATURE_PPL | MD_FEATURE_MULTIPLE_PPLS)) {
			if (le32_to_cpu(sb->feature_map) &
			    (MD_FEATURE_BITMAP_OFFSET | MD_FEATURE_JOURNAL))
				return -EINVAL;
			if ((le32_to_cpu(sb->feature_map) & MD_FEATURE_PPL) &&
			    (le32_to_cpu(sb->feature_map) &
					    MD_FEATURE_MULTIPLE_PPLS))
				return -EINVAL;
			set_bit(MD_HAS_PPL, &mddev->flags);
		}
	} else if (mddev->pers == NULL) {
		/* Insist of good event counter while assembling, except for
		 * spares (which don't need an event count) */
		++ev1;
		if (rdev->desc_nr >= 0 &&
		    rdev->desc_nr < le32_to_cpu(sb->max_dev) &&
		    (le16_to_cpu(sb->dev_roles[rdev->desc_nr]) < MD_DISK_ROLE_MAX ||
		     le16_to_cpu(sb->dev_roles[rdev->desc_nr]) == MD_DISK_ROLE_JOURNAL))
			if (ev1 < mddev->events)
				return -EINVAL;
	} else if (mddev->bitmap) {
		/* If adding to array with a bitmap, then we can accept an
		 * older device, but not too old.
		 */
		if (ev1 < mddev->bitmap->events_cleared)
			return 0;
		if (ev1 < mddev->events)
			set_bit(Bitmap_sync, &rdev->flags);
	} else {
		if (ev1 < mddev->events)
			/* just a hot-add of a new device, leave raid_disk at -1 */
			return 0;
	}
	if (mddev->level != LEVEL_MULTIPATH) {
		int role;
		if (rdev->desc_nr < 0 ||
		    rdev->desc_nr >= le32_to_cpu(sb->max_dev)) {
			role = MD_DISK_ROLE_SPARE;
			rdev->desc_nr = -1;
		} else
			role = le16_to_cpu(sb->dev_roles[rdev->desc_nr]);
		switch(role) {
		case MD_DISK_ROLE_SPARE: /* spare */
			break;
		case MD_DISK_ROLE_FAULTY: /* faulty */
			set_bit(Faulty, &rdev->flags);
			break;
		case MD_DISK_ROLE_JOURNAL: /* journal device */
			if (!(le32_to_cpu(sb->feature_map) & MD_FEATURE_JOURNAL)) {
				/* journal device without journal feature */
				pr_warn("md: journal device provided without journal feature, ignoring the device\n");
				return -EINVAL;
			}
			set_bit(Journal, &rdev->flags);
			rdev->journal_tail = le64_to_cpu(sb->journal_tail);
			rdev->raid_disk = 0;
			break;
		default:
			rdev->saved_raid_disk = role;
			if ((le32_to_cpu(sb->feature_map) &
			     MD_FEATURE_RECOVERY_OFFSET)) {
				rdev->recovery_offset = le64_to_cpu(sb->recovery_offset);
				if (!(le32_to_cpu(sb->feature_map) &
				      MD_FEATURE_RECOVERY_BITMAP))
					rdev->saved_raid_disk = -1;
			} else
				set_bit(In_sync, &rdev->flags);
			rdev->raid_disk = role;
			break;
		}
		if (sb->devflags & WriteMostly1)
			set_bit(WriteMostly, &rdev->flags);
		if (sb->devflags & FailFast1)
			set_bit(FailFast, &rdev->flags);
		if (le32_to_cpu(sb->feature_map) & MD_FEATURE_REPLACEMENT)
			set_bit(Replacement, &rdev->flags);
	} else /* MULTIPATH are always insync */
		set_bit(In_sync, &rdev->flags);

	return 0;
}