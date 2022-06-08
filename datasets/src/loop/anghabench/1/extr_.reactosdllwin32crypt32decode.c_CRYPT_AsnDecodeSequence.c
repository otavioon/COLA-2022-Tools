#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct AsnDecodeSequenceItem {scalar_t__ size; scalar_t__ minSize; scalar_t__ offset; } ;
typedef  int /*<<< orphan*/  PCRYPT_DECODE_PARA ;
typedef  int DWORD ;
typedef  scalar_t__ BYTE ;
typedef  int BOOL ;

/* Variables and functions */
 scalar_t__ const ASN_SEQUENCE ; 
 int CMSG_INDEFINITE_LENGTH ; 
 int CRYPT_AsnDecodeSequenceItems (struct AsnDecodeSequenceItem*,int,scalar_t__ const*,int,int,scalar_t__*,scalar_t__*,int*) ; 
 int CRYPT_DECODE_ALLOC_FLAG ; 
 int CRYPT_DecodeEnsureSpace (int,int /*<<< orphan*/ ,scalar_t__*,int*,int) ; 
 int /*<<< orphan*/  CRYPT_E_ASN1_BADTAG ; 
 int /*<<< orphan*/  CRYPT_E_ASN1_CORRUPT ; 
 int /*<<< orphan*/  CRYPT_E_ASN1_EOD ; 
 int /*<<< orphan*/  CRYPT_FreeSpace (int /*<<< orphan*/ ,scalar_t__*) ; 
 int CRYPT_GetLengthIndefinite (scalar_t__ const*,int,int*) ; 
 int FALSE ; 
 int GET_LEN_BYTES (scalar_t__ const) ; 
 int GetLastError () ; 
 int /*<<< orphan*/  SetLastError (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TRACE (char*,...) ; 
 int TRUE ; 
 int max (int,scalar_t__) ; 
 int /*<<< orphan*/  memset (scalar_t__*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static BOOL CRYPT_AsnDecodeSequence(struct AsnDecodeSequenceItem items[],
 DWORD cItem, const BYTE *pbEncoded, DWORD cbEncoded, DWORD dwFlags,
 PCRYPT_DECODE_PARA pDecodePara, void *pvStructInfo, DWORD *pcbStructInfo,
 DWORD *pcbDecoded, void *startingPointer)
{
    BOOL ret;

    TRACE("%p, %d, %p, %d, %08x, %p, %p, %d, %p\n", items, cItem, pbEncoded,
     cbEncoded, dwFlags, pDecodePara, pvStructInfo, *pcbStructInfo,
     startingPointer);

    if (!cbEncoded)
    {
        SetLastError(CRYPT_E_ASN1_EOD);
        return FALSE;
    }
    if (pbEncoded[0] == ASN_SEQUENCE)
    {
        DWORD dataLen;

        if ((ret = CRYPT_GetLengthIndefinite(pbEncoded, cbEncoded, &dataLen)))
        {
            DWORD lenBytes = GET_LEN_BYTES(pbEncoded[1]), cbDecoded;
            const BYTE *ptr = pbEncoded + 1 + lenBytes;
            BOOL indefinite = FALSE;

            cbEncoded -= 1 + lenBytes;
            if (dataLen == CMSG_INDEFINITE_LENGTH)
            {
                dataLen = cbEncoded;
                indefinite = TRUE;
                lenBytes += 2;
            }
            else if (cbEncoded < dataLen)
            {
                TRACE("dataLen %d exceeds cbEncoded %d, failing\n", dataLen,
                 cbEncoded);
                SetLastError(CRYPT_E_ASN1_CORRUPT);
                ret = FALSE;
            }
            if (ret)
            {
                ret = CRYPT_AsnDecodeSequenceItems(items, cItem,
                 ptr, dataLen, dwFlags, NULL, NULL, &cbDecoded);
                if (ret && dataLen == CMSG_INDEFINITE_LENGTH)
                {
                    if (cbDecoded > cbEncoded - 2)
                    {
                        /* Not enough space for 0 TLV */
                        SetLastError(CRYPT_E_ASN1_CORRUPT);
                        ret = FALSE;
                    }
                    else if (*(ptr + cbDecoded) != 0 ||
                     *(ptr + cbDecoded + 1) != 0)
                    {
                        TRACE("expected 0 TLV\n");
                        SetLastError(CRYPT_E_ASN1_CORRUPT);
                        ret = FALSE;
                    }
                    else
                        cbDecoded += 2;
                }
            }
            if (ret && !indefinite && cbDecoded != dataLen)
            {
                TRACE("expected %d decoded, got %d, failing\n", dataLen,
                 cbDecoded);
                SetLastError(CRYPT_E_ASN1_CORRUPT);
                ret = FALSE;
            }
            if (ret)
            {
                DWORD i, bytesNeeded = 0, structSize = 0;

                for (i = 0; i < cItem; i++)
                {
                    if (items[i].size > items[i].minSize)
                        bytesNeeded += items[i].size - items[i].minSize;
                    structSize = max( structSize, items[i].offset + items[i].minSize );
                }
                bytesNeeded += structSize;
                if (pcbDecoded)
                    *pcbDecoded = 1 + lenBytes + cbDecoded;
                if (!pvStructInfo)
                    *pcbStructInfo = bytesNeeded;
                else if ((ret = CRYPT_DecodeEnsureSpace(dwFlags,
                 pDecodePara, pvStructInfo, pcbStructInfo, bytesNeeded)))
                {
                    BYTE *nextData;

                    if (dwFlags & CRYPT_DECODE_ALLOC_FLAG)
                        pvStructInfo = *(BYTE **)pvStructInfo;
                    if (startingPointer)
                        nextData = startingPointer;
                    else
                        nextData = (BYTE *)pvStructInfo + structSize;
                    memset(pvStructInfo, 0, structSize);
                    ret = CRYPT_AsnDecodeSequenceItems(items, cItem,
                     ptr, dataLen, dwFlags, pvStructInfo, nextData,
                     &cbDecoded);
                    if (!ret && (dwFlags & CRYPT_DECODE_ALLOC_FLAG))
                        CRYPT_FreeSpace(pDecodePara, pvStructInfo);
                }
            }
        }
    }
    else
    {
        SetLastError(CRYPT_E_ASN1_BADTAG);
        ret = FALSE;
    }
    TRACE("returning %d (%08x)\n", ret, GetLastError());
    return ret;
}