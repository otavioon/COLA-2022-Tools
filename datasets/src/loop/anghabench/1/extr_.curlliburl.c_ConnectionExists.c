#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_21__   TYPE_9__ ;
typedef  struct TYPE_20__   TYPE_8__ ;
typedef  struct TYPE_19__   TYPE_7__ ;
typedef  struct TYPE_18__   TYPE_6__ ;
typedef  struct TYPE_17__   TYPE_5__ ;
typedef  struct TYPE_16__   TYPE_4__ ;
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;
typedef  struct TYPE_12__   TYPE_10__ ;

/* Type definitions */
struct curltime {int dummy; } ;
struct curl_llist_element {struct curl_llist_element* next; struct connectdata* ptr; } ;
struct TYPE_18__ {int /*<<< orphan*/  name; } ;
struct TYPE_21__ {scalar_t__ conn_to_host; scalar_t__ httpproxy; scalar_t__ socksproxy; scalar_t__ conn_to_port; scalar_t__ tunnel_proxy; scalar_t__ close; scalar_t__ protoconnstart; scalar_t__ connect_only; } ;
struct TYPE_17__ {int /*<<< orphan*/  name; } ;
struct TYPE_12__ {scalar_t__ proxytype; } ;
struct connectdata {scalar_t__* sock; scalar_t__ localport; scalar_t__ localportrange; scalar_t__ conn_to_port; scalar_t__ remote_port; struct Curl_easy* data; int /*<<< orphan*/  connection_id; TYPE_3__* ssl; int /*<<< orphan*/  ssl_config; TYPE_2__* handler; TYPE_6__ host; TYPE_9__ bits; TYPE_5__ conn_to_host; scalar_t__ tls_upgraded; scalar_t__ passwd; scalar_t__ user; scalar_t__ localdev; TYPE_1__* proxy_ssl; int /*<<< orphan*/  proxy_ssl_config; TYPE_10__ http_proxy; TYPE_10__ socks_proxy; int /*<<< orphan*/ * ip_addr_str; } ;
struct TYPE_20__ {struct curl_llist_element* head; } ;
struct connectbundle {scalar_t__ multiuse; TYPE_8__ conn_list; } ;
struct TYPE_19__ {scalar_t__ pipewait; } ;
struct TYPE_16__ {int /*<<< orphan*/  conn_cache; } ;
struct Curl_easy {scalar_t__ multi; TYPE_7__ set; TYPE_4__ state; } ;
struct TYPE_15__ {scalar_t__ state; } ;
struct TYPE_14__ {int flags; scalar_t__ protocol; int /*<<< orphan*/  scheme; } ;
struct TYPE_13__ {scalar_t__ state; } ;

/* Variables and functions */
 scalar_t__ BUNDLE_MULTIPLEX ; 
 scalar_t__ BUNDLE_NO_MULTIUSE ; 
 scalar_t__ BUNDLE_UNKNOWN ; 
 scalar_t__ CONN_INUSE (struct connectdata*) ; 
 scalar_t__ CURLPROXY_HTTPS ; 
 scalar_t__ CURL_SOCKET_BAD ; 
 struct connectbundle* Curl_conncache_find_bundle (struct connectdata*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Curl_conncache_unlock (struct Curl_easy*) ; 
 int /*<<< orphan*/  Curl_disconnect (struct Curl_easy*,struct connectdata*,int) ; 
 int /*<<< orphan*/  Curl_multiplex_wanted (scalar_t__) ; 
 struct curltime Curl_now () ; 
 scalar_t__ Curl_resolver_asynch () ; 
 int /*<<< orphan*/  Curl_ssl_config_matches (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DEBUGF (int /*<<< orphan*/ ) ; 
 int FALSE ; 
 size_t FIRSTSOCKET ; 
 int IsMultiplexingPossible (struct Curl_easy*,struct connectdata*) ; 
 int PROTOPT_CREDSPERREQUEST ; 
 int PROTOPT_SSL ; 
 int TRUE ; 
 scalar_t__ conn_maxage (struct Curl_easy*,struct connectdata*,struct curltime) ; 
 scalar_t__ extract_if_dead (struct connectdata*,struct Curl_easy*) ; 
 scalar_t__ get_protocol_family (scalar_t__) ; 
 int /*<<< orphan*/  infof (struct Curl_easy*,char*,...) ; 
 int /*<<< orphan*/  proxy_info_matches (TYPE_10__*,TYPE_10__*) ; 
 scalar_t__ ssl_connection_complete ; 
 scalar_t__ strcasecompare (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ strcmp (scalar_t__,scalar_t__) ; 

__attribute__((used)) static bool
ConnectionExists(struct Curl_easy *data,
                 struct connectdata *needle,
                 struct connectdata **usethis,
                 bool *force_reuse,
                 bool *waitpipe)
{
  struct connectdata *check;
  struct connectdata *chosen = 0;
  bool foundPendingCandidate = FALSE;
  bool canmultiplex = IsMultiplexingPossible(data, needle);
  struct connectbundle *bundle;
  struct curltime now = Curl_now();

#ifdef USE_NTLM
  bool wantNTLMhttp = ((data->state.authhost.want &
                      (CURLAUTH_NTLM | CURLAUTH_NTLM_WB)) &&
                      (needle->handler->protocol & PROTO_FAMILY_HTTP));
  bool wantProxyNTLMhttp = (needle->bits.proxy_user_passwd &&
                           ((data->state.authproxy.want &
                           (CURLAUTH_NTLM | CURLAUTH_NTLM_WB)) &&
                           (needle->handler->protocol & PROTO_FAMILY_HTTP)));
#endif

  *force_reuse = FALSE;
  *waitpipe = FALSE;

  /* Look up the bundle with all the connections to this particular host.
     Locks the connection cache, beware of early returns! */
  bundle = Curl_conncache_find_bundle(needle, data->state.conn_cache);
  if(bundle) {
    /* Max pipe length is zero (unlimited) for multiplexed connections */
    struct curl_llist_element *curr;

    infof(data, "Found bundle for host %s: %p [%s]\n",
          (needle->bits.conn_to_host ? needle->conn_to_host.name :
           needle->host.name), (void *)bundle,
          (bundle->multiuse == BUNDLE_MULTIPLEX ?
           "can multiplex" : "serially"));

    /* We can't multiplex if we don't know anything about the server */
    if(canmultiplex) {
      if(bundle->multiuse == BUNDLE_UNKNOWN) {
        if((bundle->multiuse == BUNDLE_UNKNOWN) && data->set.pipewait) {
          infof(data, "Server doesn't support multiplex yet, wait\n");
          *waitpipe = TRUE;
          Curl_conncache_unlock(data);
          return FALSE; /* no re-use */
        }

        infof(data, "Server doesn't support multiplex (yet)\n");
        canmultiplex = FALSE;
      }
      if((bundle->multiuse == BUNDLE_MULTIPLEX) &&
         !Curl_multiplex_wanted(data->multi)) {
        infof(data, "Could multiplex, but not asked to!\n");
        canmultiplex = FALSE;
      }
      if(bundle->multiuse == BUNDLE_NO_MULTIUSE) {
        infof(data, "Can not multiplex, even if we wanted to!\n");
        canmultiplex = FALSE;
      }
    }

    curr = bundle->conn_list.head;
    while(curr) {
      bool match = FALSE;
      size_t multiplexed;

      /*
       * Note that if we use a HTTP proxy in normal mode (no tunneling), we
       * check connections to that proxy and not to the actual remote server.
       */
      check = curr->ptr;
      curr = curr->next;

      if(check->bits.connect_only)
        /* connect-only connections will not be reused */
        continue;

      if(conn_maxage(data, check, now) || extract_if_dead(check, data)) {
        /* disconnect it */
        (void)Curl_disconnect(data, check, /* dead_connection */TRUE);
        continue;
      }

      multiplexed = CONN_INUSE(check) &&
        (bundle->multiuse == BUNDLE_MULTIPLEX);

      if(canmultiplex) {
        if(check->bits.protoconnstart && check->bits.close)
          continue;
      }
      else {
        if(multiplexed) {
          /* can only happen within multi handles, and means that another easy
             handle is using this connection */
          continue;
        }

        if(Curl_resolver_asynch()) {
          /* ip_addr_str[0] is NUL only if the resolving of the name hasn't
             completed yet and until then we don't re-use this connection */
          if(!check->ip_addr_str[0]) {
            infof(data,
                  "Connection #%ld is still name resolving, can't reuse\n",
                  check->connection_id);
            continue;
          }
        }

        if((check->sock[FIRSTSOCKET] == CURL_SOCKET_BAD) ||
           check->bits.close) {
          if(!check->bits.close)
            foundPendingCandidate = TRUE;
          /* Don't pick a connection that hasn't connected yet or that is going
             to get closed. */
          infof(data, "Connection #%ld isn't open enough, can't reuse\n",
                check->connection_id);
          continue;
        }
      }

#ifdef USE_UNIX_SOCKETS
      if(needle->unix_domain_socket) {
        if(!check->unix_domain_socket)
          continue;
        if(strcmp(needle->unix_domain_socket, check->unix_domain_socket))
          continue;
        if(needle->abstract_unix_socket != check->abstract_unix_socket)
          continue;
      }
      else if(check->unix_domain_socket)
        continue;
#endif

      if((needle->handler->flags&PROTOPT_SSL) !=
         (check->handler->flags&PROTOPT_SSL))
        /* don't do mixed SSL and non-SSL connections */
        if(get_protocol_family(check->handler->protocol) !=
           needle->handler->protocol || !check->tls_upgraded)
          /* except protocols that have been upgraded via TLS */
          continue;

      if(needle->bits.httpproxy != check->bits.httpproxy ||
         needle->bits.socksproxy != check->bits.socksproxy)
        continue;

      if(needle->bits.socksproxy && !proxy_info_matches(&needle->socks_proxy,
                                                        &check->socks_proxy))
        continue;

      if(needle->bits.conn_to_host != check->bits.conn_to_host)
        /* don't mix connections that use the "connect to host" feature and
         * connections that don't use this feature */
        continue;

      if(needle->bits.conn_to_port != check->bits.conn_to_port)
        /* don't mix connections that use the "connect to port" feature and
         * connections that don't use this feature */
        continue;

      if(needle->bits.httpproxy) {
        if(!proxy_info_matches(&needle->http_proxy, &check->http_proxy))
          continue;

        if(needle->bits.tunnel_proxy != check->bits.tunnel_proxy)
          continue;

        if(needle->http_proxy.proxytype == CURLPROXY_HTTPS) {
          /* use https proxy */
          if(needle->handler->flags&PROTOPT_SSL) {
            /* use double layer ssl */
            if(!Curl_ssl_config_matches(&needle->proxy_ssl_config,
                                        &check->proxy_ssl_config))
              continue;
            if(check->proxy_ssl[FIRSTSOCKET].state != ssl_connection_complete)
              continue;
          }
          else {
            if(!Curl_ssl_config_matches(&needle->ssl_config,
                                        &check->ssl_config))
              continue;
            if(check->ssl[FIRSTSOCKET].state != ssl_connection_complete)
              continue;
          }
        }
      }

      if(!canmultiplex && check->data)
        /* this request can't be multiplexed but the checked connection is
           already in use so we skip it */
        continue;

      if(CONN_INUSE(check) && check->data &&
         (check->data->multi != needle->data->multi))
        /* this could be subject for multiplex use, but only if they belong to
         * the same multi handle */
        continue;

      if(needle->localdev || needle->localport) {
        /* If we are bound to a specific local end (IP+port), we must not
           re-use a random other one, although if we didn't ask for a
           particular one we can reuse one that was bound.

           This comparison is a bit rough and too strict. Since the input
           parameters can be specified in numerous ways and still end up the
           same it would take a lot of processing to make it really accurate.
           Instead, this matching will assume that re-uses of bound connections
           will most likely also re-use the exact same binding parameters and
           missing out a few edge cases shouldn't hurt anyone very much.
        */
        if((check->localport != needle->localport) ||
           (check->localportrange != needle->localportrange) ||
           (needle->localdev &&
            (!check->localdev || strcmp(check->localdev, needle->localdev))))
          continue;
      }

      if(!(needle->handler->flags & PROTOPT_CREDSPERREQUEST)) {
        /* This protocol requires credentials per connection,
           so verify that we're using the same name and password as well */
        if(strcmp(needle->user, check->user) ||
           strcmp(needle->passwd, check->passwd)) {
          /* one of them was different */
          continue;
        }
      }

      if(!needle->bits.httpproxy || (needle->handler->flags&PROTOPT_SSL) ||
         needle->bits.tunnel_proxy) {
        /* The requested connection does not use a HTTP proxy or it uses SSL or
           it is a non-SSL protocol tunneled or it is a non-SSL protocol which
           is allowed to be upgraded via TLS */

        if((strcasecompare(needle->handler->scheme, check->handler->scheme) ||
            (get_protocol_family(check->handler->protocol) ==
             needle->handler->protocol && check->tls_upgraded)) &&
           (!needle->bits.conn_to_host || strcasecompare(
            needle->conn_to_host.name, check->conn_to_host.name)) &&
           (!needle->bits.conn_to_port ||
             needle->conn_to_port == check->conn_to_port) &&
           strcasecompare(needle->host.name, check->host.name) &&
           needle->remote_port == check->remote_port) {
          /* The schemes match or the the protocol family is the same and the
             previous connection was TLS upgraded, and the hostname and host
             port match */
          if(needle->handler->flags & PROTOPT_SSL) {
            /* This is a SSL connection so verify that we're using the same
               SSL options as well */
            if(!Curl_ssl_config_matches(&needle->ssl_config,
                                        &check->ssl_config)) {
              DEBUGF(infof(data,
                           "Connection #%ld has different SSL parameters, "
                           "can't reuse\n",
                           check->connection_id));
              continue;
            }
            if(check->ssl[FIRSTSOCKET].state != ssl_connection_complete) {
              foundPendingCandidate = TRUE;
              DEBUGF(infof(data,
                           "Connection #%ld has not started SSL connect, "
                           "can't reuse\n",
                           check->connection_id));
              continue;
            }
          }
          match = TRUE;
        }
      }
      else {
        /* The requested connection is using the same HTTP proxy in normal
           mode (no tunneling) */
        match = TRUE;
      }

      if(match) {
#if defined(USE_NTLM)
        /* If we are looking for an HTTP+NTLM connection, check if this is
           already authenticating with the right credentials. If not, keep
           looking so that we can reuse NTLM connections if
           possible. (Especially we must not reuse the same connection if
           partway through a handshake!) */
        if(wantNTLMhttp) {
          if(strcmp(needle->user, check->user) ||
             strcmp(needle->passwd, check->passwd))
            continue;
        }
        else if(check->ntlm.state != NTLMSTATE_NONE) {
          /* Connection is using NTLM auth but we don't want NTLM */
          continue;
        }

        /* Same for Proxy NTLM authentication */
        if(wantProxyNTLMhttp) {
          /* Both check->http_proxy.user and check->http_proxy.passwd can be
           * NULL */
          if(!check->http_proxy.user || !check->http_proxy.passwd)
            continue;

          if(strcmp(needle->http_proxy.user, check->http_proxy.user) ||
             strcmp(needle->http_proxy.passwd, check->http_proxy.passwd))
            continue;
        }
        else if(check->proxyntlm.state != NTLMSTATE_NONE) {
          /* Proxy connection is using NTLM auth but we don't want NTLM */
          continue;
        }

        if(wantNTLMhttp || wantProxyNTLMhttp) {
          /* Credentials are already checked, we can use this connection */
          chosen = check;

          if((wantNTLMhttp &&
             (check->ntlm.state != NTLMSTATE_NONE)) ||
              (wantProxyNTLMhttp &&
               (check->proxyntlm.state != NTLMSTATE_NONE))) {
            /* We must use this connection, no other */
            *force_reuse = TRUE;
            break;
          }

          /* Continue look up for a better connection */
          continue;
        }
#endif
        if(canmultiplex) {
          /* We can multiplex if we want to. Let's continue looking for
             the optimal connection to use. */

          if(!multiplexed) {
            /* We have the optimal connection. Let's stop looking. */
            chosen = check;
            break;
          }

#ifdef USE_NGHTTP2
          /* If multiplexed, make sure we don't go over concurrency limit */
          if(check->bits.multiplex) {
            /* Multiplexed connections can only be HTTP/2 for now */
            struct http_conn *httpc = &check->proto.httpc;
            if(multiplexed >= httpc->settings.max_concurrent_streams) {
              infof(data, "MAX_CONCURRENT_STREAMS reached, skip (%zu)\n",
                    multiplexed);
              continue;
            }
          }
#endif
          /* When not multiplexed, we have a match here! */
          chosen = check;
          infof(data, "Multiplexed connection found!\n");
          break;
        }
        else {
          /* We have found a connection. Let's stop searching. */
          chosen = check;
          break;
        }
      }
    }
  }

  if(chosen) {
    /* mark it as used before releasing the lock */
    chosen->data = data; /* own it! */
    Curl_conncache_unlock(data);
    *usethis = chosen;
    return TRUE; /* yes, we found one to use! */
  }
  Curl_conncache_unlock(data);

  if(foundPendingCandidate && data->set.pipewait) {
    infof(data,
          "Found pending candidate for reuse and CURLOPT_PIPEWAIT is set\n");
    *waitpipe = TRUE;
  }

  return FALSE; /* no matching connecting exists */
}