#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct us_data {unsigned int send_bulk_pipe; unsigned int recv_bulk_pipe; TYPE_1__* srb; int /*<<< orphan*/ * iobuf; } ;
struct scsi_cmnd {int* cmnd; } ;
struct freecom_status {int Type; int Status; int Reason; int /*<<< orphan*/  Count; int /*<<< orphan*/  Filler; int /*<<< orphan*/  Atapi; scalar_t__ Timeout; } ;
struct freecom_cb_wrap {int Type; int Status; int Reason; int /*<<< orphan*/  Count; int /*<<< orphan*/  Filler; int /*<<< orphan*/  Atapi; scalar_t__ Timeout; } ;
struct TYPE_2__ {int sc_data_direction; } ;

/* Variables and functions */
#define  DMA_FROM_DEVICE 134 
#define  DMA_NONE 133 
#define  DMA_TO_DEVICE 132 
 int DRQ_STAT ; 
 int ERR_STAT ; 
 int FCM_PACKET_ATAPI ; 
 int /*<<< orphan*/  FCM_PACKET_LENGTH ; 
 int FCM_PACKET_STATUS ; 
 int FCM_STATUS_BUSY ; 
 int /*<<< orphan*/  FCM_STATUS_PACKET_LENGTH ; 
#define  INQUIRY 131 
#define  MODE_SENSE 130 
#define  MODE_SENSE_10 129 
#define  REQUEST_SENSE 128 
 int USB_STOR_TRANSPORT_ERROR ; 
 int USB_STOR_TRANSPORT_FAILED ; 
 int USB_STOR_TRANSPORT_GOOD ; 
 int USB_STOR_XFER_GOOD ; 
 int USB_STOR_XFER_SHORT ; 
 int /*<<< orphan*/  US_DEBUG (int /*<<< orphan*/ ) ; 
 int freecom_readdata (struct scsi_cmnd*,struct us_data*,unsigned int,unsigned int,int) ; 
 int freecom_writedata (struct scsi_cmnd*,struct us_data*,unsigned int,unsigned int,int) ; 
 int le16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int*,int) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pdump (struct us_data*,int*,unsigned int) ; 
 int scsi_bufflen (struct scsi_cmnd*) ; 
 int usb_stor_bulk_transfer_buf (struct us_data*,unsigned int,struct freecom_status*,int /*<<< orphan*/ ,unsigned int*) ; 
 int /*<<< orphan*/  usb_stor_dbg (struct us_data*,char*,...) ; 

__attribute__((used)) static int freecom_transport(struct scsi_cmnd *srb, struct us_data *us)
{
	struct freecom_cb_wrap *fcb;
	struct freecom_status  *fst;
	unsigned int ipipe, opipe;		/* We need both pipes. */
	int result;
	unsigned int partial;
	int length;

	fcb = (struct freecom_cb_wrap *) us->iobuf;
	fst = (struct freecom_status *) us->iobuf;

	usb_stor_dbg(us, "Freecom TRANSPORT STARTED\n");

	/* Get handles for both transports. */
	opipe = us->send_bulk_pipe;
	ipipe = us->recv_bulk_pipe;

	/* The ATAPI Command always goes out first. */
	fcb->Type = FCM_PACKET_ATAPI | 0x00;
	fcb->Timeout = 0;
	memcpy (fcb->Atapi, srb->cmnd, 12);
	memset (fcb->Filler, 0, sizeof (fcb->Filler));

	US_DEBUG(pdump(us, srb->cmnd, 12));

	/* Send it out. */
	result = usb_stor_bulk_transfer_buf (us, opipe, fcb,
			FCM_PACKET_LENGTH, NULL);

	/*
	 * The Freecom device will only fail if there is something wrong in
	 * USB land.  It returns the status in its own registers, which
	 * come back in the bulk pipe.
	 */
	if (result != USB_STOR_XFER_GOOD) {
		usb_stor_dbg(us, "freecom transport error\n");
		return USB_STOR_TRANSPORT_ERROR;
	}

	/*
	 * There are times we can optimize out this status read, but it
	 * doesn't hurt us to always do it now.
	 */
	result = usb_stor_bulk_transfer_buf (us, ipipe, fst,
			FCM_STATUS_PACKET_LENGTH, &partial);
	usb_stor_dbg(us, "foo Status result %d %u\n", result, partial);
	if (result != USB_STOR_XFER_GOOD)
		return USB_STOR_TRANSPORT_ERROR;

	US_DEBUG(pdump(us, (void *)fst, partial));

	/*
	 * The firmware will time-out commands after 20 seconds. Some commands
	 * can legitimately take longer than this, so we use a different
	 * command that only waits for the interrupt and then sends status,
	 * without having to send a new ATAPI command to the device.
	 *
	 * NOTE: There is some indication that a data transfer after a timeout
	 * may not work, but that is a condition that should never happen.
	 */
	while (fst->Status & FCM_STATUS_BUSY) {
		usb_stor_dbg(us, "20 second USB/ATAPI bridge TIMEOUT occurred!\n");
		usb_stor_dbg(us, "fst->Status is %x\n", fst->Status);

		/* Get the status again */
		fcb->Type = FCM_PACKET_STATUS;
		fcb->Timeout = 0;
		memset (fcb->Atapi, 0, sizeof(fcb->Atapi));
		memset (fcb->Filler, 0, sizeof (fcb->Filler));

		/* Send it out. */
		result = usb_stor_bulk_transfer_buf (us, opipe, fcb,
				FCM_PACKET_LENGTH, NULL);

		/*
		 * The Freecom device will only fail if there is something
		 * wrong in USB land.  It returns the status in its own
		 * registers, which come back in the bulk pipe.
		 */
		if (result != USB_STOR_XFER_GOOD) {
			usb_stor_dbg(us, "freecom transport error\n");
			return USB_STOR_TRANSPORT_ERROR;
		}

		/* get the data */
		result = usb_stor_bulk_transfer_buf (us, ipipe, fst,
				FCM_STATUS_PACKET_LENGTH, &partial);

		usb_stor_dbg(us, "bar Status result %d %u\n", result, partial);
		if (result != USB_STOR_XFER_GOOD)
			return USB_STOR_TRANSPORT_ERROR;

		US_DEBUG(pdump(us, (void *)fst, partial));
	}

	if (partial != 4)
		return USB_STOR_TRANSPORT_ERROR;
	if ((fst->Status & 1) != 0) {
		usb_stor_dbg(us, "operation failed\n");
		return USB_STOR_TRANSPORT_FAILED;
	}

	/*
	 * The device might not have as much data available as we
	 * requested.  If you ask for more than the device has, this reads
	 * and such will hang.
	 */
	usb_stor_dbg(us, "Device indicates that it has %d bytes available\n",
		     le16_to_cpu(fst->Count));
	usb_stor_dbg(us, "SCSI requested %d\n", scsi_bufflen(srb));

	/* Find the length we desire to read. */
	switch (srb->cmnd[0]) {
	case INQUIRY:
	case REQUEST_SENSE:	/* 16 or 18 bytes? spec says 18, lots of devices only have 16 */
	case MODE_SENSE:
	case MODE_SENSE_10:
		length = le16_to_cpu(fst->Count);
		break;
	default:
		length = scsi_bufflen(srb);
	}

	/* verify that this amount is legal */
	if (length > scsi_bufflen(srb)) {
		length = scsi_bufflen(srb);
		usb_stor_dbg(us, "Truncating request to match buffer length: %d\n",
			     length);
	}

	/*
	 * What we do now depends on what direction the data is supposed to
	 * move in.
	 */

	switch (us->srb->sc_data_direction) {
	case DMA_FROM_DEVICE:
		/* catch bogus "read 0 length" case */
		if (!length)
			break;
		/*
		 * Make sure that the status indicates that the device
		 * wants data as well.
		 */
		if ((fst->Status & DRQ_STAT) == 0 || (fst->Reason & 3) != 2) {
			usb_stor_dbg(us, "SCSI wants data, drive doesn't have any\n");
			return USB_STOR_TRANSPORT_FAILED;
		}
		result = freecom_readdata (srb, us, ipipe, opipe, length);
		if (result != USB_STOR_TRANSPORT_GOOD)
			return result;

		usb_stor_dbg(us, "Waiting for status\n");
		result = usb_stor_bulk_transfer_buf (us, ipipe, fst,
				FCM_PACKET_LENGTH, &partial);
		US_DEBUG(pdump(us, (void *)fst, partial));

		if (partial != 4 || result > USB_STOR_XFER_SHORT)
			return USB_STOR_TRANSPORT_ERROR;
		if ((fst->Status & ERR_STAT) != 0) {
			usb_stor_dbg(us, "operation failed\n");
			return USB_STOR_TRANSPORT_FAILED;
		}
		if ((fst->Reason & 3) != 3) {
			usb_stor_dbg(us, "Drive seems still hungry\n");
			return USB_STOR_TRANSPORT_FAILED;
		}
		usb_stor_dbg(us, "Transfer happy\n");
		break;

	case DMA_TO_DEVICE:
		/* catch bogus "write 0 length" case */
		if (!length)
			break;
		/*
		 * Make sure the status indicates that the device wants to
		 * send us data.
		 */
		/* !!IMPLEMENT!! */
		result = freecom_writedata (srb, us, ipipe, opipe, length);
		if (result != USB_STOR_TRANSPORT_GOOD)
			return result;

		usb_stor_dbg(us, "Waiting for status\n");
		result = usb_stor_bulk_transfer_buf (us, ipipe, fst,
				FCM_PACKET_LENGTH, &partial);

		if (partial != 4 || result > USB_STOR_XFER_SHORT)
			return USB_STOR_TRANSPORT_ERROR;
		if ((fst->Status & ERR_STAT) != 0) {
			usb_stor_dbg(us, "operation failed\n");
			return USB_STOR_TRANSPORT_FAILED;
		}
		if ((fst->Reason & 3) != 3) {
			usb_stor_dbg(us, "Drive seems still hungry\n");
			return USB_STOR_TRANSPORT_FAILED;
		}

		usb_stor_dbg(us, "Transfer happy\n");
		break;


	case DMA_NONE:
		/* Easy, do nothing. */
		break;

	default:
		/* should never hit here -- filtered in usb.c */
		usb_stor_dbg(us, "freecom unimplemented direction: %d\n",
			     us->srb->sc_data_direction);
		/* Return fail, SCSI seems to handle this better. */
		return USB_STOR_TRANSPORT_FAILED;
		break;
	}

	return USB_STOR_TRANSPORT_GOOD;
}