#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {int size; int pos; int /*<<< orphan*/ * dst; } ;
typedef  TYPE_1__ ZSTD_outBuffer ;
struct TYPE_11__ {int size; int pos; int /*<<< orphan*/ * src; } ;
typedef  TYPE_2__ ZSTD_inBuffer ;
typedef  int ZSTD_EndDirective ;
struct TYPE_12__ {char* inBuff; scalar_t__ inBuffSize; char* outBuff; scalar_t__ outBuffSize; int streamStage; scalar_t__ inBuffPos; int frameEnded; size_t inBuffTarget; scalar_t__ inToCompress; size_t blockSize; size_t outBuffContentSize; size_t outBuffFlushedSize; } ;
typedef  TYPE_3__ ZSTD_CStream ;
typedef  int U32 ;

/* Variables and functions */
 int /*<<< orphan*/  DEBUGLOG (int,char*,...) ; 
 size_t ERROR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ZSTD_CCtx_reset (TYPE_3__*) ; 
 size_t ZSTD_compressBound (size_t const) ; 
 void* ZSTD_compressContinue (TYPE_3__*,char*,size_t,char const*,size_t const) ; 
 void* ZSTD_compressEnd (TYPE_3__*,char*,size_t,char const*,size_t const) ; 
 int const ZSTD_e_continue ; 
 int const ZSTD_e_end ; 
 int const ZSTD_e_flush ; 
 int /*<<< orphan*/  ZSTD_isError (size_t const) ; 
 size_t ZSTD_limitCopy (char*,size_t const,char const*,size_t const) ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  init_missing ; 
#define  zcss_flush 130 
#define  zcss_init 129 
#define  zcss_load 128 

size_t ZSTD_compressStream_generic(ZSTD_CStream* zcs,
                                   ZSTD_outBuffer* output,
                                   ZSTD_inBuffer* input,
                                   ZSTD_EndDirective const flushMode)
{
    const char* const istart = (const char*)input->src;
    const char* const iend = istart + input->size;
    const char* ip = istart + input->pos;
    char* const ostart = (char*)output->dst;
    char* const oend = ostart + output->size;
    char* op = ostart + output->pos;
    U32 someMoreWork = 1;

    /* check expectations */
    DEBUGLOG(5, "ZSTD_compressStream_generic, flush=%u", (U32)flushMode);
    assert(zcs->inBuff != NULL);
    assert(zcs->inBuffSize > 0);
    assert(zcs->outBuff !=  NULL);
    assert(zcs->outBuffSize > 0);
    assert(output->pos <= output->size);
    assert(input->pos <= input->size);

    while (someMoreWork) {
        switch(zcs->streamStage)
        {
        case zcss_init:
            /* call ZSTD_initCStream() first ! */
            return ERROR(init_missing);

        case zcss_load:
            if ( (flushMode == ZSTD_e_end)
              && ((size_t)(oend-op) >= ZSTD_compressBound(iend-ip))  /* enough dstCapacity */
              && (zcs->inBuffPos == 0) ) {
                /* shortcut to compression pass directly into output buffer */
                size_t const cSize = ZSTD_compressEnd(zcs,
                                                op, oend-op, ip, iend-ip);
                DEBUGLOG(4, "ZSTD_compressEnd : %u", (U32)cSize);
                if (ZSTD_isError(cSize)) return cSize;
                ip = iend;
                op += cSize;
                zcs->frameEnded = 1;
                ZSTD_CCtx_reset(zcs);
                someMoreWork = 0; break;
            }
            /* complete loading into inBuffer */
            {   size_t const toLoad = zcs->inBuffTarget - zcs->inBuffPos;
                size_t const loaded = ZSTD_limitCopy(
                                        zcs->inBuff + zcs->inBuffPos, toLoad,
                                        ip, iend-ip);
                zcs->inBuffPos += loaded;
                ip += loaded;
                if ( (flushMode == ZSTD_e_continue)
                  && (zcs->inBuffPos < zcs->inBuffTarget) ) {
                    /* not enough input to fill full block : stop here */
                    someMoreWork = 0; break;
                }
                if ( (flushMode == ZSTD_e_flush)
                  && (zcs->inBuffPos == zcs->inToCompress) ) {
                    /* empty */
                    someMoreWork = 0; break;
                }
            }
            /* compress current block (note : this stage cannot be stopped in the middle) */
            DEBUGLOG(5, "stream compression stage (flushMode==%u)", flushMode);
            {   void* cDst;
                size_t cSize;
                size_t const iSize = zcs->inBuffPos - zcs->inToCompress;
                size_t oSize = oend-op;
                unsigned const lastBlock = (flushMode == ZSTD_e_end) && (ip==iend);
                if (oSize >= ZSTD_compressBound(iSize))
                    cDst = op;   /* compress into output buffer, to skip flush stage */
                else
                    cDst = zcs->outBuff, oSize = zcs->outBuffSize;
                cSize = lastBlock ?
                        ZSTD_compressEnd(zcs, cDst, oSize,
                                    zcs->inBuff + zcs->inToCompress, iSize) :
                        ZSTD_compressContinue(zcs, cDst, oSize,
                                    zcs->inBuff + zcs->inToCompress, iSize);
                if (ZSTD_isError(cSize)) return cSize;
                zcs->frameEnded = lastBlock;
                /* prepare next block */
                zcs->inBuffTarget = zcs->inBuffPos + zcs->blockSize;
                if (zcs->inBuffTarget > zcs->inBuffSize)
                    zcs->inBuffPos = 0, zcs->inBuffTarget = zcs->blockSize;
                DEBUGLOG(5, "inBuffTarget:%u / inBuffSize:%u",
                         (U32)zcs->inBuffTarget, (U32)zcs->inBuffSize);
                if (!lastBlock)
                    assert(zcs->inBuffTarget <= zcs->inBuffSize);
                zcs->inToCompress = zcs->inBuffPos;
                if (cDst == op) {  /* no need to flush */
                    op += cSize;
                    if (zcs->frameEnded) {
                        DEBUGLOG(5, "Frame completed directly in outBuffer");
                        someMoreWork = 0;
                        ZSTD_CCtx_reset(zcs);
                    }
                    break;
                }
                zcs->outBuffContentSize = cSize;
                zcs->outBuffFlushedSize = 0;
                zcs->streamStage = zcss_flush; /* pass-through to flush stage */
            }
	    /* fall-through */
        case zcss_flush:
            DEBUGLOG(5, "flush stage");
            {   size_t const toFlush = zcs->outBuffContentSize - zcs->outBuffFlushedSize;
                size_t const flushed = ZSTD_limitCopy(op, oend-op,
                            zcs->outBuff + zcs->outBuffFlushedSize, toFlush);
                DEBUGLOG(5, "toFlush: %u into %u ==> flushed: %u",
                            (U32)toFlush, (U32)(oend-op), (U32)flushed);
                op += flushed;
                zcs->outBuffFlushedSize += flushed;
                if (toFlush!=flushed) {
                    /* flush not fully completed, presumably because dst is too small */
                    assert(op==oend);
                    someMoreWork = 0;
                    break;
                }
                zcs->outBuffContentSize = zcs->outBuffFlushedSize = 0;
                if (zcs->frameEnded) {
                    DEBUGLOG(5, "Frame completed on flush");
                    someMoreWork = 0;
                    ZSTD_CCtx_reset(zcs);
                    break;
                }
                zcs->streamStage = zcss_load;
                break;
            }

        default: /* impossible */
            assert(0);
        }
    }

    input->pos = ip - istart;
    output->pos = op - ostart;
    if (zcs->frameEnded) return 0;
    {   size_t hintInSize = zcs->inBuffTarget - zcs->inBuffPos;
        if (hintInSize==0) hintInSize = zcs->blockSize;
        return hintInSize;
    }
}