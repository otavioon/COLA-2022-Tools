#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_49__   TYPE_3__ ;
typedef  struct TYPE_48__   TYPE_2__ ;
typedef  struct TYPE_47__   TYPE_1__ ;
typedef  struct TYPE_46__   TYPE_14__ ;
typedef  struct TYPE_45__   TYPE_11__ ;
typedef  struct TYPE_44__   TYPE_10__ ;

/* Type definitions */
struct TYPE_44__ {int /*<<< orphan*/  log; } ;
struct TYPE_45__ {scalar_t__ len; } ;
struct TYPE_47__ {int verify; int verify_depth; TYPE_14__* session_ticket_keys; TYPE_10__ ssl; int /*<<< orphan*/  session_tickets; int /*<<< orphan*/  session_timeout; int /*<<< orphan*/ * shm_zone; int /*<<< orphan*/  builtin_session_cache; TYPE_14__* certificates; TYPE_11__ ecdh_curve; TYPE_11__ dhparam; TYPE_11__ crl; TYPE_11__ trusted_certificate; TYPE_11__ client_certificate; int /*<<< orphan*/  prefer_server_ciphers; TYPE_11__ ciphers; TYPE_14__* passwords; TYPE_14__* certificate_keys; scalar_t__ certificate_values; int /*<<< orphan*/  protocols; int /*<<< orphan*/  line; int /*<<< orphan*/  file; int /*<<< orphan*/  listen; int /*<<< orphan*/  handshake_timeout; } ;
typedef  TYPE_1__ ngx_stream_ssl_conf_t ;
typedef  int /*<<< orphan*/  ngx_str_t ;
struct TYPE_48__ {TYPE_10__* data; int /*<<< orphan*/  (* handler ) (TYPE_10__*) ;} ;
typedef  TYPE_2__ ngx_pool_cleanup_t ;
struct TYPE_49__ {int /*<<< orphan*/  log; int /*<<< orphan*/  pool; } ;
typedef  TYPE_3__ ngx_conf_t ;
struct TYPE_46__ {scalar_t__ nelts; int /*<<< orphan*/ * elts; } ;

/* Variables and functions */
 int NGX_CONF_BITMASK_SET ; 
 char* NGX_CONF_ERROR ; 
 char* NGX_CONF_OK ; 
 char* NGX_DEFAULT_CIPHERS ; 
 char* NGX_DEFAULT_ECDH_CURVE ; 
 int /*<<< orphan*/  NGX_LOG_EMERG ; 
 scalar_t__ NGX_OK ; 
 int NGX_SSL_NONE_SCACHE ; 
 int NGX_SSL_TLSv1 ; 
 int NGX_SSL_TLSv1_1 ; 
 int NGX_SSL_TLSv1_2 ; 
 int /*<<< orphan*/  ngx_conf_merge_bitmask_value (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ngx_conf_merge_msec_value (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ngx_conf_merge_ptr_value (TYPE_14__*,TYPE_14__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ngx_conf_merge_str_value (TYPE_11__,TYPE_11__,char*) ; 
 int /*<<< orphan*/  ngx_conf_merge_uint_value (int,int,int) ; 
 int /*<<< orphan*/  ngx_conf_merge_value (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ngx_log_error (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,...) ; 
 TYPE_2__* ngx_pool_cleanup_add (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ ngx_ssl_certificates (TYPE_3__*,TYPE_10__*,TYPE_14__*,TYPE_14__*,TYPE_14__*) ; 
 scalar_t__ ngx_ssl_ciphers (TYPE_3__*,TYPE_10__*,TYPE_11__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ngx_ssl_cleanup_ctx (TYPE_10__*) ; 
 scalar_t__ ngx_ssl_client_certificate (TYPE_3__*,TYPE_10__*,TYPE_11__*,int) ; 
 scalar_t__ ngx_ssl_create (TYPE_10__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ ngx_ssl_crl (TYPE_3__*,TYPE_10__*,TYPE_11__*) ; 
 scalar_t__ ngx_ssl_dhparam (TYPE_3__*,TYPE_10__*,TYPE_11__*) ; 
 scalar_t__ ngx_ssl_ecdh_curve (TYPE_3__*,TYPE_10__*,TYPE_11__*) ; 
 scalar_t__ ngx_ssl_session_cache (TYPE_10__*,int /*<<< orphan*/ *,TYPE_14__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ ngx_ssl_session_ticket_keys (TYPE_3__*,TYPE_10__*,TYPE_14__*) ; 
 scalar_t__ ngx_ssl_trusted_certificate (TYPE_3__*,TYPE_10__*,TYPE_11__*,int) ; 
 scalar_t__ ngx_stream_ssl_compile_certificates (TYPE_3__*,TYPE_1__*) ; 
 int /*<<< orphan*/  ngx_stream_ssl_sess_id_ctx ; 

__attribute__((used)) static char *
ngx_stream_ssl_merge_conf(ngx_conf_t *cf, void *parent, void *child)
{
    ngx_stream_ssl_conf_t *prev = parent;
    ngx_stream_ssl_conf_t *conf = child;

    ngx_pool_cleanup_t  *cln;

    ngx_conf_merge_msec_value(conf->handshake_timeout,
                         prev->handshake_timeout, 60000);

    ngx_conf_merge_value(conf->session_timeout,
                         prev->session_timeout, 300);

    ngx_conf_merge_value(conf->prefer_server_ciphers,
                         prev->prefer_server_ciphers, 0);

    ngx_conf_merge_bitmask_value(conf->protocols, prev->protocols,
                         (NGX_CONF_BITMASK_SET|NGX_SSL_TLSv1
                          |NGX_SSL_TLSv1_1|NGX_SSL_TLSv1_2));

    ngx_conf_merge_uint_value(conf->verify, prev->verify, 0);
    ngx_conf_merge_uint_value(conf->verify_depth, prev->verify_depth, 1);

    ngx_conf_merge_ptr_value(conf->certificates, prev->certificates, NULL);
    ngx_conf_merge_ptr_value(conf->certificate_keys, prev->certificate_keys,
                         NULL);

    ngx_conf_merge_ptr_value(conf->passwords, prev->passwords, NULL);

    ngx_conf_merge_str_value(conf->dhparam, prev->dhparam, "");

    ngx_conf_merge_str_value(conf->client_certificate, prev->client_certificate,
                         "");
    ngx_conf_merge_str_value(conf->trusted_certificate,
                         prev->trusted_certificate, "");
    ngx_conf_merge_str_value(conf->crl, prev->crl, "");

    ngx_conf_merge_str_value(conf->ecdh_curve, prev->ecdh_curve,
                         NGX_DEFAULT_ECDH_CURVE);

    ngx_conf_merge_str_value(conf->ciphers, prev->ciphers, NGX_DEFAULT_CIPHERS);


    conf->ssl.log = cf->log;

    if (!conf->listen) {
        return NGX_CONF_OK;
    }

    if (conf->certificates == NULL) {
        ngx_log_error(NGX_LOG_EMERG, cf->log, 0,
                      "no \"ssl_certificate\" is defined for "
                      "the \"listen ... ssl\" directive in %s:%ui",
                      conf->file, conf->line);
        return NGX_CONF_ERROR;
    }

    if (conf->certificate_keys == NULL) {
        ngx_log_error(NGX_LOG_EMERG, cf->log, 0,
                      "no \"ssl_certificate_key\" is defined for "
                      "the \"listen ... ssl\" directive in %s:%ui",
                      conf->file, conf->line);
        return NGX_CONF_ERROR;
    }

    if (conf->certificate_keys->nelts < conf->certificates->nelts) {
        ngx_log_error(NGX_LOG_EMERG, cf->log, 0,
                      "no \"ssl_certificate_key\" is defined "
                      "for certificate \"%V\" and "
                      "the \"listen ... ssl\" directive in %s:%ui",
                      ((ngx_str_t *) conf->certificates->elts)
                      + conf->certificates->nelts - 1,
                      conf->file, conf->line);
        return NGX_CONF_ERROR;
    }

    if (ngx_ssl_create(&conf->ssl, conf->protocols, NULL) != NGX_OK) {
        return NGX_CONF_ERROR;
    }

    cln = ngx_pool_cleanup_add(cf->pool, 0);
    if (cln == NULL) {
        ngx_ssl_cleanup_ctx(&conf->ssl);
        return NGX_CONF_ERROR;
    }

    cln->handler = ngx_ssl_cleanup_ctx;
    cln->data = &conf->ssl;

#ifdef SSL_CTRL_SET_TLSEXT_HOSTNAME
    SSL_CTX_set_tlsext_servername_callback(conf->ssl.ctx,
                                           ngx_stream_ssl_servername);
#endif

    if (ngx_stream_ssl_compile_certificates(cf, conf) != NGX_OK) {
        return NGX_CONF_ERROR;
    }

    if (conf->certificate_values) {

#ifdef SSL_R_CERT_CB_ERROR

        /* install callback to lookup certificates */

        SSL_CTX_set_cert_cb(conf->ssl.ctx, ngx_stream_ssl_certificate, conf);

#else
        ngx_log_error(NGX_LOG_EMERG, cf->log, 0,
                      "variables in "
                      "\"ssl_certificate\" and \"ssl_certificate_key\" "
                      "directives are not supported on this platform");
        return NGX_CONF_ERROR;
#endif

    } else {

        /* configure certificates */

        if (ngx_ssl_certificates(cf, &conf->ssl, conf->certificates,
                                 conf->certificate_keys, conf->passwords)
            != NGX_OK)
        {
            return NGX_CONF_ERROR;
        }
    }

    if (ngx_ssl_ciphers(cf, &conf->ssl, &conf->ciphers,
                        conf->prefer_server_ciphers)
        != NGX_OK)
    {
        return NGX_CONF_ERROR;
    }

    if (conf->verify) {

        if (conf->client_certificate.len == 0 && conf->verify != 3) {
            ngx_log_error(NGX_LOG_EMERG, cf->log, 0,
                          "no ssl_client_certificate for ssl_client_verify");
            return NGX_CONF_ERROR;
        }

        if (ngx_ssl_client_certificate(cf, &conf->ssl,
                                       &conf->client_certificate,
                                       conf->verify_depth)
            != NGX_OK)
        {
            return NGX_CONF_ERROR;
        }

        if (ngx_ssl_trusted_certificate(cf, &conf->ssl,
                                        &conf->trusted_certificate,
                                        conf->verify_depth)
            != NGX_OK)
        {
            return NGX_CONF_ERROR;
        }

        if (ngx_ssl_crl(cf, &conf->ssl, &conf->crl) != NGX_OK) {
            return NGX_CONF_ERROR;
        }
    }

    if (ngx_ssl_dhparam(cf, &conf->ssl, &conf->dhparam) != NGX_OK) {
        return NGX_CONF_ERROR;
    }

    if (ngx_ssl_ecdh_curve(cf, &conf->ssl, &conf->ecdh_curve) != NGX_OK) {
        return NGX_CONF_ERROR;
    }

    ngx_conf_merge_value(conf->builtin_session_cache,
                         prev->builtin_session_cache, NGX_SSL_NONE_SCACHE);

    if (conf->shm_zone == NULL) {
        conf->shm_zone = prev->shm_zone;
    }

    if (ngx_ssl_session_cache(&conf->ssl, &ngx_stream_ssl_sess_id_ctx,
                              conf->certificates, conf->builtin_session_cache,
                              conf->shm_zone, conf->session_timeout)
        != NGX_OK)
    {
        return NGX_CONF_ERROR;
    }

    ngx_conf_merge_value(conf->session_tickets,
                         prev->session_tickets, 1);

#ifdef SSL_OP_NO_TICKET
    if (!conf->session_tickets) {
        SSL_CTX_set_options(conf->ssl.ctx, SSL_OP_NO_TICKET);
    }
#endif

    ngx_conf_merge_ptr_value(conf->session_ticket_keys,
                         prev->session_ticket_keys, NULL);

    if (ngx_ssl_session_ticket_keys(cf, &conf->ssl, conf->session_ticket_keys)
        != NGX_OK)
    {
        return NGX_CONF_ERROR;
    }

    return NGX_CONF_OK;
}