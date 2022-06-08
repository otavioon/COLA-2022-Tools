#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_26__   TYPE_7__ ;
typedef  struct TYPE_25__   TYPE_6__ ;
typedef  struct TYPE_24__   TYPE_5__ ;
typedef  struct TYPE_23__   TYPE_4__ ;
typedef  struct TYPE_22__   TYPE_3__ ;
typedef  struct TYPE_21__   TYPE_2__ ;
typedef  struct TYPE_20__   TYPE_1__ ;
typedef  struct TYPE_19__   TYPE_13__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  void* u32 ;
struct mbox_out {int dummy; } ;
typedef  int /*<<< orphan*/  raw_mbox ;
typedef  int /*<<< orphan*/  mraid_inquiry ;
struct TYPE_22__ {int /*<<< orphan*/  raid_inq; } ;
typedef  TYPE_3__ mraid_ext_inquiry ;
typedef  int /*<<< orphan*/  mega_product_info ;
struct TYPE_23__ {int /*<<< orphan*/  num_ldrv; } ;
typedef  TYPE_4__ mega_inquiry3 ;
struct TYPE_19__ {int xferaddr; int /*<<< orphan*/  cmd; } ;
struct TYPE_24__ {TYPE_13__ m_out; } ;
typedef  TYPE_5__ mbox_t ;
typedef  int dma_addr_t ;
struct TYPE_21__ {scalar_t__ max_commands; scalar_t__ subsysvid; int* fw_version; int* bios_version; scalar_t__ nchannels; } ;
struct TYPE_25__ {int buf_dma_handle; scalar_t__ max_cmds; TYPE_7__* dev; scalar_t__ support_ext_cdb; int /*<<< orphan*/  numldrv; scalar_t__* bios_version; scalar_t__* fw_version; TYPE_2__ product_info; int /*<<< orphan*/  sglen; TYPE_1__* host; int /*<<< orphan*/  flag; int /*<<< orphan*/ * mega_buffer; } ;
typedef  TYPE_6__ adapter_t ;
struct TYPE_26__ {int /*<<< orphan*/  dev; } ;
struct TYPE_20__ {int max_id; int max_lun; scalar_t__ can_queue; int /*<<< orphan*/  sg_tablesize; int /*<<< orphan*/  cmd_per_lun; scalar_t__ max_channel; } ;

/* Variables and functions */
 int /*<<< orphan*/  BOARD_40LD ; 
 int /*<<< orphan*/  ENQ3_GET_SOLICITED_FULL ; 
 int /*<<< orphan*/  FC_NEW_CONFIG ; 
 scalar_t__ MAX_COMMANDS ; 
 int MEGA_BUFFER_SIZE ; 
 int /*<<< orphan*/  MEGA_MBOXCMD_ADPEXTINQ ; 
 int /*<<< orphan*/  NC_SUBOP_ENQUIRY3 ; 
 int /*<<< orphan*/  NC_SUBOP_PRODUCT_INFO ; 
 scalar_t__ NVIRT_CHAN ; 
 int /*<<< orphan*/  PCI_DMA_FROMDEVICE ; 
 scalar_t__ PCI_VENDOR_ID_HP ; 
 int /*<<< orphan*/  dev_notice (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*,int) ; 
 int issue_scb_block (TYPE_6__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  max_cmd_per_lun ; 
 int /*<<< orphan*/  mega_8_to_40ld (int /*<<< orphan*/ *,TYPE_4__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mega_get_max_sgl (TYPE_6__*) ; 
 scalar_t__ mega_support_ext_cdb (TYPE_6__*) ; 
 int /*<<< orphan*/  memcpy (scalar_t__*,char*,int) ; 
 int /*<<< orphan*/  memset (TYPE_13__*,int /*<<< orphan*/ ,int) ; 
 TYPE_3__* pci_alloc_consistent (TYPE_7__*,int,int*) ; 
 int /*<<< orphan*/  pci_free_consistent (TYPE_7__*,int,TYPE_3__*,int) ; 
 int pci_map_single (TYPE_7__*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_unmap_single (TYPE_7__*,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snprintf (scalar_t__*,int,char*,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int
mega_query_adapter(adapter_t *adapter)
{
	dma_addr_t	prod_info_dma_handle;
	mega_inquiry3	*inquiry3;
	u8	raw_mbox[sizeof(struct mbox_out)];
	mbox_t	*mbox;
	int	retval;

	/* Initialize adapter inquiry mailbox */

	mbox = (mbox_t *)raw_mbox;

	memset((void *)adapter->mega_buffer, 0, MEGA_BUFFER_SIZE);
	memset(&mbox->m_out, 0, sizeof(raw_mbox));

	/*
	 * Try to issue Inquiry3 command
	 * if not succeeded, then issue MEGA_MBOXCMD_ADAPTERINQ command and
	 * update enquiry3 structure
	 */
	mbox->m_out.xferaddr = (u32)adapter->buf_dma_handle;

	inquiry3 = (mega_inquiry3 *)adapter->mega_buffer;

	raw_mbox[0] = FC_NEW_CONFIG;		/* i.e. mbox->cmd=0xA1 */
	raw_mbox[2] = NC_SUBOP_ENQUIRY3;	/* i.e. 0x0F */
	raw_mbox[3] = ENQ3_GET_SOLICITED_FULL;	/* i.e. 0x02 */

	/* Issue a blocking command to the card */
	if ((retval = issue_scb_block(adapter, raw_mbox))) {
		/* the adapter does not support 40ld */

		mraid_ext_inquiry	*ext_inq;
		mraid_inquiry		*inq;
		dma_addr_t		dma_handle;

		ext_inq = pci_alloc_consistent(adapter->dev,
				sizeof(mraid_ext_inquiry), &dma_handle);

		if( ext_inq == NULL ) return -1;

		inq = &ext_inq->raid_inq;

		mbox->m_out.xferaddr = (u32)dma_handle;

		/*issue old 0x04 command to adapter */
		mbox->m_out.cmd = MEGA_MBOXCMD_ADPEXTINQ;

		issue_scb_block(adapter, raw_mbox);

		/*
		 * update Enquiry3 and ProductInfo structures with
		 * mraid_inquiry structure
		 */
		mega_8_to_40ld(inq, inquiry3,
				(mega_product_info *)&adapter->product_info);

		pci_free_consistent(adapter->dev, sizeof(mraid_ext_inquiry),
				ext_inq, dma_handle);

	} else {		/*adapter supports 40ld */
		adapter->flag |= BOARD_40LD;

		/*
		 * get product_info, which is static information and will be
		 * unchanged
		 */
		prod_info_dma_handle = pci_map_single(adapter->dev, (void *)
				&adapter->product_info,
				sizeof(mega_product_info), PCI_DMA_FROMDEVICE);

		mbox->m_out.xferaddr = prod_info_dma_handle;

		raw_mbox[0] = FC_NEW_CONFIG;	/* i.e. mbox->cmd=0xA1 */
		raw_mbox[2] = NC_SUBOP_PRODUCT_INFO;	/* i.e. 0x0E */

		if ((retval = issue_scb_block(adapter, raw_mbox)))
			dev_warn(&adapter->dev->dev,
				"Product_info cmd failed with error: %d\n",
				retval);

		pci_unmap_single(adapter->dev, prod_info_dma_handle,
				sizeof(mega_product_info), PCI_DMA_FROMDEVICE);
	}


	/*
	 * kernel scans the channels from 0 to <= max_channel
	 */
	adapter->host->max_channel =
		adapter->product_info.nchannels + NVIRT_CHAN -1;

	adapter->host->max_id = 16;	/* max targets per channel */

	adapter->host->max_lun = 7;	/* Up to 7 luns for non disk devices */

	adapter->host->cmd_per_lun = max_cmd_per_lun;

	adapter->numldrv = inquiry3->num_ldrv;

	adapter->max_cmds = adapter->product_info.max_commands;

	if(adapter->max_cmds > MAX_COMMANDS)
		adapter->max_cmds = MAX_COMMANDS;

	adapter->host->can_queue = adapter->max_cmds - 1;

	/*
	 * Get the maximum number of scatter-gather elements supported by this
	 * firmware
	 */
	mega_get_max_sgl(adapter);

	adapter->host->sg_tablesize = adapter->sglen;

	/* use HP firmware and bios version encoding
	   Note: fw_version[0|1] and bios_version[0|1] were originally shifted
	   right 8 bits making them zero. This 0 value was hardcoded to fix
	   sparse warnings. */
	if (adapter->product_info.subsysvid == PCI_VENDOR_ID_HP) {
		snprintf(adapter->fw_version, sizeof(adapter->fw_version),
			 "%c%d%d.%d%d",
			 adapter->product_info.fw_version[2],
			 0,
			 adapter->product_info.fw_version[1] & 0x0f,
			 0,
			 adapter->product_info.fw_version[0] & 0x0f);
		snprintf(adapter->bios_version, sizeof(adapter->fw_version),
			 "%c%d%d.%d%d",
			 adapter->product_info.bios_version[2],
			 0,
			 adapter->product_info.bios_version[1] & 0x0f,
			 0,
			 adapter->product_info.bios_version[0] & 0x0f);
	} else {
		memcpy(adapter->fw_version,
				(char *)adapter->product_info.fw_version, 4);
		adapter->fw_version[4] = 0;

		memcpy(adapter->bios_version,
				(char *)adapter->product_info.bios_version, 4);

		adapter->bios_version[4] = 0;
	}

	dev_notice(&adapter->dev->dev, "[%s:%s] detected %d logical drives\n",
		adapter->fw_version, adapter->bios_version, adapter->numldrv);

	/*
	 * Do we support extended (>10 bytes) cdbs
	 */
	adapter->support_ext_cdb = mega_support_ext_cdb(adapter);
	if (adapter->support_ext_cdb)
		dev_notice(&adapter->dev->dev, "supports extended CDBs\n");


	return 0;
}