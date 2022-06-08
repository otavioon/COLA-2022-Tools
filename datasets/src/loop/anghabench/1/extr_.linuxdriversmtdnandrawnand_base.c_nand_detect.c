#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int uint64_t ;
typedef  scalar_t__ u8 ;
struct nand_manufacturer {int dummy; } ;
struct nand_flash_dev {scalar_t__ dev_id; int chipsize; int options; int /*<<< orphan*/  pagesize; int /*<<< orphan*/ * name; } ;
struct TYPE_6__ {scalar_t__ model; } ;
struct TYPE_5__ {struct nand_manufacturer const* desc; } ;
struct TYPE_4__ {scalar_t__* data; int /*<<< orphan*/  len; } ;
struct nand_chip {int options; int chipsize; int page_shift; int pagemask; int chip_shift; int badblockbits; scalar_t__ cmdfunc; TYPE_3__ parameters; int /*<<< orphan*/  erase; void* phys_erase_shift; void* bbt_erase_shift; TYPE_2__ manufacturer; TYPE_1__ id; int /*<<< orphan*/  (* select_chip ) (struct mtd_info*,int /*<<< orphan*/ ) ;} ;
struct mtd_info {unsigned int writesize; unsigned int erasesize; int /*<<< orphan*/  oobsize; scalar_t__ name; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (scalar_t__*) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int NAND_BUSWIDTH_16 ; 
 int NAND_BUSWIDTH_AUTO ; 
 int NAND_ROW_ADDR_3 ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 void* ffs (unsigned int) ; 
 scalar_t__ find_full_id_nand (struct nand_chip*,struct nand_flash_dev*) ; 
 scalar_t__ is_full_id_nand (struct nand_flash_dev*) ; 
 int /*<<< orphan*/  kfree (scalar_t__) ; 
 scalar_t__ kstrdup (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ nand_command ; 
 scalar_t__ nand_command_lp ; 
 int /*<<< orphan*/  nand_decode_bbm_options (struct nand_chip*) ; 
 int /*<<< orphan*/  nand_decode_id (struct nand_chip*,struct nand_flash_dev*) ; 
 int nand_flash_detect_jedec (struct nand_chip*) ; 
 int nand_flash_detect_onfi (struct nand_chip*) ; 
 struct nand_flash_dev* nand_flash_ids ; 
 struct nand_manufacturer* nand_get_manufacturer (scalar_t__) ; 
 int /*<<< orphan*/  nand_id_len (scalar_t__*,int /*<<< orphan*/ ) ; 
 scalar_t__ nand_is_slc (struct nand_chip*) ; 
 int /*<<< orphan*/  nand_manufacturer_detect (struct nand_chip*) ; 
 int /*<<< orphan*/  nand_manufacturer_name (struct nand_manufacturer const*) ; 
 int nand_readid_op (struct nand_chip*,int /*<<< orphan*/ ,scalar_t__*,int) ; 
 int nand_reset (struct nand_chip*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nand_set_defaults (struct nand_chip*) ; 
 struct mtd_info* nand_to_mtd (struct nand_chip*) ; 
 int /*<<< orphan*/  pr_info (char*,int,char*,...) ; 
 int /*<<< orphan*/  pr_warn (char*,int,int) ; 
 int /*<<< orphan*/  single_erase ; 
 int /*<<< orphan*/  stub1 (struct mtd_info*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int nand_detect(struct nand_chip *chip, struct nand_flash_dev *type)
{
	const struct nand_manufacturer *manufacturer;
	struct mtd_info *mtd = nand_to_mtd(chip);
	int busw, ret;
	u8 *id_data = chip->id.data;
	u8 maf_id, dev_id;

	/*
	 * Reset the chip, required by some chips (e.g. Micron MT29FxGxxxxx)
	 * after power-up.
	 */
	ret = nand_reset(chip, 0);
	if (ret)
		return ret;

	/* Select the device */
	chip->select_chip(mtd, 0);

	/* Send the command for reading device ID */
	ret = nand_readid_op(chip, 0, id_data, 2);
	if (ret)
		return ret;

	/* Read manufacturer and device IDs */
	maf_id = id_data[0];
	dev_id = id_data[1];

	/*
	 * Try again to make sure, as some systems the bus-hold or other
	 * interface concerns can cause random data which looks like a
	 * possibly credible NAND flash to appear. If the two results do
	 * not match, ignore the device completely.
	 */

	/* Read entire ID string */
	ret = nand_readid_op(chip, 0, id_data, sizeof(chip->id.data));
	if (ret)
		return ret;

	if (id_data[0] != maf_id || id_data[1] != dev_id) {
		pr_info("second ID read did not match %02x,%02x against %02x,%02x\n",
			maf_id, dev_id, id_data[0], id_data[1]);
		return -ENODEV;
	}

	chip->id.len = nand_id_len(id_data, ARRAY_SIZE(chip->id.data));

	/* Try to identify manufacturer */
	manufacturer = nand_get_manufacturer(maf_id);
	chip->manufacturer.desc = manufacturer;

	if (!type)
		type = nand_flash_ids;

	/*
	 * Save the NAND_BUSWIDTH_16 flag before letting auto-detection logic
	 * override it.
	 * This is required to make sure initial NAND bus width set by the
	 * NAND controller driver is coherent with the real NAND bus width
	 * (extracted by auto-detection code).
	 */
	busw = chip->options & NAND_BUSWIDTH_16;

	/*
	 * The flag is only set (never cleared), reset it to its default value
	 * before starting auto-detection.
	 */
	chip->options &= ~NAND_BUSWIDTH_16;

	for (; type->name != NULL; type++) {
		if (is_full_id_nand(type)) {
			if (find_full_id_nand(chip, type))
				goto ident_done;
		} else if (dev_id == type->dev_id) {
			break;
		}
	}

	if (!type->name || !type->pagesize) {
		/* Check if the chip is ONFI compliant */
		ret = nand_flash_detect_onfi(chip);
		if (ret < 0)
			return ret;
		else if (ret)
			goto ident_done;

		/* Check if the chip is JEDEC compliant */
		ret = nand_flash_detect_jedec(chip);
		if (ret < 0)
			return ret;
		else if (ret)
			goto ident_done;
	}

	if (!type->name)
		return -ENODEV;

	chip->parameters.model = kstrdup(type->name, GFP_KERNEL);
	if (!chip->parameters.model)
		return -ENOMEM;

	chip->chipsize = (uint64_t)type->chipsize << 20;

	if (!type->pagesize)
		nand_manufacturer_detect(chip);
	else
		nand_decode_id(chip, type);

	/* Get chip options */
	chip->options |= type->options;

ident_done:
	if (!mtd->name)
		mtd->name = chip->parameters.model;

	if (chip->options & NAND_BUSWIDTH_AUTO) {
		WARN_ON(busw & NAND_BUSWIDTH_16);
		nand_set_defaults(chip);
	} else if (busw != (chip->options & NAND_BUSWIDTH_16)) {
		/*
		 * Check, if buswidth is correct. Hardware drivers should set
		 * chip correct!
		 */
		pr_info("device found, Manufacturer ID: 0x%02x, Chip ID: 0x%02x\n",
			maf_id, dev_id);
		pr_info("%s %s\n", nand_manufacturer_name(manufacturer),
			mtd->name);
		pr_warn("bus width %d instead of %d bits\n", busw ? 16 : 8,
			(chip->options & NAND_BUSWIDTH_16) ? 16 : 8);
		ret = -EINVAL;

		goto free_detect_allocation;
	}

	nand_decode_bbm_options(chip);

	/* Calculate the address shift from the page size */
	chip->page_shift = ffs(mtd->writesize) - 1;
	/* Convert chipsize to number of pages per chip -1 */
	chip->pagemask = (chip->chipsize >> chip->page_shift) - 1;

	chip->bbt_erase_shift = chip->phys_erase_shift =
		ffs(mtd->erasesize) - 1;
	if (chip->chipsize & 0xffffffff)
		chip->chip_shift = ffs((unsigned)chip->chipsize) - 1;
	else {
		chip->chip_shift = ffs((unsigned)(chip->chipsize >> 32));
		chip->chip_shift += 32 - 1;
	}

	if (chip->chip_shift - chip->page_shift > 16)
		chip->options |= NAND_ROW_ADDR_3;

	chip->badblockbits = 8;
	chip->erase = single_erase;

	/* Do not replace user supplied command function! */
	if (mtd->writesize > 512 && chip->cmdfunc == nand_command)
		chip->cmdfunc = nand_command_lp;

	pr_info("device found, Manufacturer ID: 0x%02x, Chip ID: 0x%02x\n",
		maf_id, dev_id);
	pr_info("%s %s\n", nand_manufacturer_name(manufacturer),
		chip->parameters.model);
	pr_info("%d MiB, %s, erase size: %d KiB, page size: %d, OOB size: %d\n",
		(int)(chip->chipsize >> 20), nand_is_slc(chip) ? "SLC" : "MLC",
		mtd->erasesize >> 10, mtd->writesize, mtd->oobsize);
	return 0;

free_detect_allocation:
	kfree(chip->parameters.model);

	return ret;
}