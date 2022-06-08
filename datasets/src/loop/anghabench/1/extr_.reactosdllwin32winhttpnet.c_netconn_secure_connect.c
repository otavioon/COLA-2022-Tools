#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_11__ {scalar_t__ cbHeader; scalar_t__ cbMaximumMessage; scalar_t__ cbTrailer; } ;
struct TYPE_8__ {int /*<<< orphan*/  ssl_ctx; int /*<<< orphan*/  secure; int /*<<< orphan*/ * ssl_buf; TYPE_5__ ssl_sizes; int /*<<< orphan*/  socket; } ;
typedef  TYPE_1__ netconn_t ;
typedef  int /*<<< orphan*/  WCHAR ;
typedef  int /*<<< orphan*/  ULONG ;
struct TYPE_10__ {scalar_t__ member_1; int cbBuffer; scalar_t__ BufferType; int /*<<< orphan*/ * pvBuffer; int /*<<< orphan*/  member_0; int /*<<< orphan*/ * member_2; } ;
struct TYPE_9__ {int member_1; TYPE_3__* member_2; int /*<<< orphan*/  member_0; } ;
typedef  TYPE_2__ SecBufferDesc ;
typedef  TYPE_3__ SecBuffer ;
typedef  int SSIZE_T ;
typedef  scalar_t__ SIZE_T ;
typedef  scalar_t__ SECURITY_STATUS ;
typedef  scalar_t__ DWORD ;
typedef  int /*<<< orphan*/  CtxtHandle ;
typedef  int /*<<< orphan*/  CredHandle ;
typedef  int /*<<< orphan*/  CERT_CONTEXT ;
typedef  int /*<<< orphan*/  BYTE ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  CertFreeCertificateContext (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  DeleteSecurityContext (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ERR (char*) ; 
 scalar_t__ ERROR_SUCCESS ; 
 scalar_t__ ERROR_WINHTTP_SECURE_CHANNEL_ERROR ; 
 scalar_t__ E_OUTOFMEMORY ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  FIXME (char*) ; 
 int /*<<< orphan*/  FreeContextBuffer (int /*<<< orphan*/ *) ; 
 scalar_t__ GetLastError () ; 
 scalar_t__ ISC_REQ_ALLOCATE_MEMORY ; 
 scalar_t__ ISC_REQ_CONFIDENTIALITY ; 
 scalar_t__ ISC_REQ_MANUAL_CRED_VALIDATION ; 
 scalar_t__ ISC_REQ_REPLAY_DETECT ; 
 scalar_t__ ISC_REQ_SEQUENCE_DETECT ; 
 scalar_t__ ISC_REQ_USE_SESSION_KEY ; 
 scalar_t__ InitializeSecurityContextW (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,scalar_t__ const,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ QueryContextAttributesW (int /*<<< orphan*/ *,int /*<<< orphan*/ ,TYPE_5__*) ; 
 scalar_t__ SECBUFFER_EMPTY ; 
 scalar_t__ SECBUFFER_EXTRA ; 
 scalar_t__ SECBUFFER_TOKEN ; 
 int /*<<< orphan*/  SECBUFFER_VERSION ; 
 int /*<<< orphan*/  SECPKG_ATTR_REMOTE_CERT_CONTEXT ; 
 int /*<<< orphan*/  SECPKG_ATTR_STREAM_SIZES ; 
 scalar_t__ SEC_E_INCOMPLETE_MESSAGE ; 
 scalar_t__ SEC_E_OK ; 
 scalar_t__ SEC_I_CONTINUE_NEEDED ; 
 int /*<<< orphan*/  TRACE (char*,...) ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  WARN (char*,...) ; 
 int /*<<< orphan*/  assert (int) ; 
 void* heap_alloc (scalar_t__) ; 
 int /*<<< orphan*/  heap_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * heap_realloc (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  memmove (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 scalar_t__ netconn_verify_cert (int /*<<< orphan*/  const*,int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  set_last_error (scalar_t__) ; 
 int sock_recv (int /*<<< orphan*/ ,int /*<<< orphan*/ *,scalar_t__,int /*<<< orphan*/ ) ; 
 int sock_send (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 

BOOL netconn_secure_connect( netconn_t *conn, WCHAR *hostname, DWORD security_flags, CredHandle *cred_handle )
{
    SecBuffer out_buf = {0, SECBUFFER_TOKEN, NULL}, in_bufs[2] = {{0, SECBUFFER_TOKEN}, {0, SECBUFFER_EMPTY}};
    SecBufferDesc out_desc = {SECBUFFER_VERSION, 1, &out_buf}, in_desc = {SECBUFFER_VERSION, 2, in_bufs};
    BYTE *read_buf;
    SIZE_T read_buf_size = 2048;
    ULONG attrs = 0;
    CtxtHandle ctx;
    SSIZE_T size;
    const CERT_CONTEXT *cert;
    SECURITY_STATUS status;
    DWORD res = ERROR_SUCCESS;

    const DWORD isc_req_flags = ISC_REQ_ALLOCATE_MEMORY|ISC_REQ_USE_SESSION_KEY|ISC_REQ_CONFIDENTIALITY
        |ISC_REQ_SEQUENCE_DETECT|ISC_REQ_REPLAY_DETECT|ISC_REQ_MANUAL_CRED_VALIDATION;

    read_buf = heap_alloc(read_buf_size);
    if(!read_buf)
        return FALSE;

    status = InitializeSecurityContextW(cred_handle, NULL, hostname, isc_req_flags, 0, 0, NULL, 0,
            &ctx, &out_desc, &attrs, NULL);

    assert(status != SEC_E_OK);

    while(status == SEC_I_CONTINUE_NEEDED || status == SEC_E_INCOMPLETE_MESSAGE) {
        if(out_buf.cbBuffer) {
            assert(status == SEC_I_CONTINUE_NEEDED);

            TRACE("sending %u bytes\n", out_buf.cbBuffer);

            size = sock_send(conn->socket, out_buf.pvBuffer, out_buf.cbBuffer, 0);
            if(size != out_buf.cbBuffer) {
                ERR("send failed\n");
                res = ERROR_WINHTTP_SECURE_CHANNEL_ERROR;
                break;
            }

            FreeContextBuffer(out_buf.pvBuffer);
            out_buf.pvBuffer = NULL;
            out_buf.cbBuffer = 0;
        }

        if(status == SEC_I_CONTINUE_NEEDED) {
            assert(in_bufs[1].cbBuffer < read_buf_size);

            memmove(read_buf, (BYTE*)in_bufs[0].pvBuffer+in_bufs[0].cbBuffer-in_bufs[1].cbBuffer, in_bufs[1].cbBuffer);
            in_bufs[0].cbBuffer = in_bufs[1].cbBuffer;

            in_bufs[1].BufferType = SECBUFFER_EMPTY;
            in_bufs[1].cbBuffer = 0;
            in_bufs[1].pvBuffer = NULL;
        }

        assert(in_bufs[0].BufferType == SECBUFFER_TOKEN);
        assert(in_bufs[1].BufferType == SECBUFFER_EMPTY);

        if(in_bufs[0].cbBuffer + 1024 > read_buf_size) {
            BYTE *new_read_buf;

            new_read_buf = heap_realloc(read_buf, read_buf_size + 1024);
            if(!new_read_buf) {
                status = E_OUTOFMEMORY;
                break;
            }

            in_bufs[0].pvBuffer = read_buf = new_read_buf;
            read_buf_size += 1024;
        }

        size = sock_recv(conn->socket, read_buf+in_bufs[0].cbBuffer, read_buf_size-in_bufs[0].cbBuffer, 0);
        if(size < 1) {
            status = ERROR_WINHTTP_SECURE_CHANNEL_ERROR;
            break;
        }

        TRACE("recv %lu bytes\n", size);

        in_bufs[0].cbBuffer += size;
        in_bufs[0].pvBuffer = read_buf;
        status = InitializeSecurityContextW(cred_handle, &ctx, hostname,  isc_req_flags, 0, 0, &in_desc,
                0, NULL, &out_desc, &attrs, NULL);
        TRACE("InitializeSecurityContext ret %08x\n", status);

        if(status == SEC_E_OK) {
            if(in_bufs[1].BufferType == SECBUFFER_EXTRA)
                FIXME("SECBUFFER_EXTRA not supported\n");

            status = QueryContextAttributesW(&ctx, SECPKG_ATTR_STREAM_SIZES, &conn->ssl_sizes);
            if(status != SEC_E_OK) {
                WARN("Could not get sizes\n");
                break;
            }

            status = QueryContextAttributesW(&ctx, SECPKG_ATTR_REMOTE_CERT_CONTEXT, (void*)&cert);
            if(status == SEC_E_OK) {
                res = netconn_verify_cert(cert, hostname, security_flags);
                CertFreeCertificateContext(cert);
                if(res != ERROR_SUCCESS) {
                    WARN("cert verify failed: %u\n", res);
                    break;
                }
            }else {
                WARN("Could not get cert\n");
                break;
            }

            conn->ssl_buf = heap_alloc(conn->ssl_sizes.cbHeader + conn->ssl_sizes.cbMaximumMessage + conn->ssl_sizes.cbTrailer);
            if(!conn->ssl_buf) {
                res = GetLastError();
                break;
            }
        }
    }

    heap_free(read_buf);

    if(status != SEC_E_OK || res != ERROR_SUCCESS) {
        WARN("Failed to initialize security context failed: %08x\n", status);
        heap_free(conn->ssl_buf);
        conn->ssl_buf = NULL;
        DeleteSecurityContext(&ctx);
        set_last_error(res ? res : ERROR_WINHTTP_SECURE_CHANNEL_ERROR);
        return FALSE;
    }


    TRACE("established SSL connection\n");
    conn->secure = TRUE;
    conn->ssl_ctx = ctx;
    return TRUE;
}