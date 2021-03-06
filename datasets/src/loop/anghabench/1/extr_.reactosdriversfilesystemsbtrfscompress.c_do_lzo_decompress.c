#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {int outlen; int outpos; void* error; } ;
typedef  TYPE_1__ lzo_stream ;
typedef  int UINT8 ;
typedef  int UINT32 ;
typedef  int /*<<< orphan*/  NTSTATUS ;
typedef  int BOOL ;

/* Variables and functions */
 void* FALSE ; 
 int /*<<< orphan*/  STATUS_INTERNAL_ERROR ; 
 int /*<<< orphan*/  STATUS_SUCCESS ; 
 int TRUE ; 
 int /*<<< orphan*/  lzo_copy (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lzo_copyback (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 int lzo_len (TYPE_1__*,int,int) ; 
 int lzo_nextbyte (TYPE_1__*) ; 
 int /*<<< orphan*/  min (int,int) ; 

__attribute__((used)) static NTSTATUS do_lzo_decompress(lzo_stream* stream) {
    UINT8 byte;
    UINT32 len, back;
    BOOL backcopy = FALSE;

    stream->error = FALSE;

    byte = lzo_nextbyte(stream);
    if (stream->error) return STATUS_INTERNAL_ERROR;

    if (byte > 17) {
        lzo_copy(stream, min((UINT8)(byte - 17), (UINT32)(stream->outlen - stream->outpos)));
        if (stream->error) return STATUS_INTERNAL_ERROR;

        if (stream->outlen == stream->outpos)
            return STATUS_SUCCESS;

        byte = lzo_nextbyte(stream);
        if (stream->error) return STATUS_INTERNAL_ERROR;

        if (byte < 16) return STATUS_INTERNAL_ERROR;
    }

    while (1) {
        if (byte >> 4) {
            backcopy = TRUE;
            if (byte >> 6) {
                len = (byte >> 5) - 1;
                back = (lzo_nextbyte(stream) << 3) + ((byte >> 2) & 7) + 1;
                if (stream->error) return STATUS_INTERNAL_ERROR;
            } else if (byte >> 5) {
                len = lzo_len(stream, byte, 31);
                if (stream->error) return STATUS_INTERNAL_ERROR;

                byte = lzo_nextbyte(stream);
                if (stream->error) return STATUS_INTERNAL_ERROR;

                back = (lzo_nextbyte(stream) << 6) + (byte >> 2) + 1;
                if (stream->error) return STATUS_INTERNAL_ERROR;
            } else {
                len = lzo_len(stream, byte, 7);
                if (stream->error) return STATUS_INTERNAL_ERROR;

                back = (1 << 14) + ((byte & 8) << 11);

                byte = lzo_nextbyte(stream);
                if (stream->error) return STATUS_INTERNAL_ERROR;

                back += (lzo_nextbyte(stream) << 6) + (byte >> 2);
                if (stream->error) return STATUS_INTERNAL_ERROR;

                if (back == (1 << 14)) {
                    if (len != 1)
                        return STATUS_INTERNAL_ERROR;
                    break;
                }
            }
        } else if (backcopy) {
            len = 0;
            back = (lzo_nextbyte(stream) << 2) + (byte >> 2) + 1;
            if (stream->error) return STATUS_INTERNAL_ERROR;
        } else {
            len = lzo_len(stream, byte, 15);
            if (stream->error) return STATUS_INTERNAL_ERROR;

            lzo_copy(stream, min(len + 3, stream->outlen - stream->outpos));
            if (stream->error) return STATUS_INTERNAL_ERROR;

            if (stream->outlen == stream->outpos)
                return STATUS_SUCCESS;

            byte = lzo_nextbyte(stream);
            if (stream->error) return STATUS_INTERNAL_ERROR;

            if (byte >> 4)
                continue;

            len = 1;
            back = (1 << 11) + (lzo_nextbyte(stream) << 2) + (byte >> 2) + 1;
            if (stream->error) return STATUS_INTERNAL_ERROR;

            break;
        }

        lzo_copyback(stream, back, min(len + 2, stream->outlen - stream->outpos));
        if (stream->error) return STATUS_INTERNAL_ERROR;

        if (stream->outlen == stream->outpos)
            return STATUS_SUCCESS;

        len = byte & 3;

        if (len) {
            lzo_copy(stream, min(len, stream->outlen - stream->outpos));
            if (stream->error) return STATUS_INTERNAL_ERROR;

            if (stream->outlen == stream->outpos)
                return STATUS_SUCCESS;
        } else
            backcopy = !backcopy;

        byte = lzo_nextbyte(stream);
        if (stream->error) return STATUS_INTERNAL_ERROR;
    }

    return STATUS_SUCCESS;
}