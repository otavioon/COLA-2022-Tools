#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct efx_filter_spec {int flags; int match_flags; int* loc_mac; void* outer_vid; void* rem_port; void* loc_port; int /*<<< orphan*/  ip_proto; void** rem_host; void** loc_host; void* ether_type; int /*<<< orphan*/  dmaq_id; int /*<<< orphan*/  priority; } ;
struct efx_farch_filter_spec {int flags; int type; int* data; int /*<<< orphan*/  dmaq_id; int /*<<< orphan*/  priority; } ;
typedef  void* __be32 ;
typedef  void* __be16 ;

/* Variables and functions */
#define  EFX_FARCH_FILTER_MAC_FULL 135 
#define  EFX_FARCH_FILTER_MAC_WILD 134 
#define  EFX_FARCH_FILTER_MC_DEF 133 
#define  EFX_FARCH_FILTER_TCP_FULL 132 
#define  EFX_FARCH_FILTER_TCP_WILD 131 
#define  EFX_FARCH_FILTER_UC_DEF 130 
#define  EFX_FARCH_FILTER_UDP_FULL 129 
#define  EFX_FARCH_FILTER_UDP_WILD 128 
 int EFX_FILTER_FLAG_TX ; 
 int EFX_FILTER_MATCH_ETHER_TYPE ; 
 int EFX_FILTER_MATCH_IP_PROTO ; 
 int EFX_FILTER_MATCH_LOC_HOST ; 
 int EFX_FILTER_MATCH_LOC_MAC ; 
 int EFX_FILTER_MATCH_LOC_MAC_IG ; 
 int EFX_FILTER_MATCH_LOC_PORT ; 
 int EFX_FILTER_MATCH_OUTER_VID ; 
 int EFX_FILTER_MATCH_REM_HOST ; 
 int EFX_FILTER_MATCH_REM_PORT ; 
 int ETH_P_IP ; 
 int /*<<< orphan*/  IPPROTO_TCP ; 
 int /*<<< orphan*/  IPPROTO_UDP ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 void* htonl (int) ; 
 void* htons (int) ; 
 int /*<<< orphan*/  memset (struct efx_filter_spec*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void
efx_farch_filter_to_gen_spec(struct efx_filter_spec *gen_spec,
			     const struct efx_farch_filter_spec *spec)
{
	bool is_full = false;

	/* *gen_spec should be completely initialised, to be consistent
	 * with efx_filter_init_{rx,tx}() and in case we want to copy
	 * it back to userland.
	 */
	memset(gen_spec, 0, sizeof(*gen_spec));

	gen_spec->priority = spec->priority;
	gen_spec->flags = spec->flags;
	gen_spec->dmaq_id = spec->dmaq_id;

	switch (spec->type) {
	case EFX_FARCH_FILTER_TCP_FULL:
	case EFX_FARCH_FILTER_UDP_FULL:
		is_full = true;
		/* fall through */
	case EFX_FARCH_FILTER_TCP_WILD:
	case EFX_FARCH_FILTER_UDP_WILD: {
		__be32 host1, host2;
		__be16 port1, port2;

		gen_spec->match_flags =
			EFX_FILTER_MATCH_ETHER_TYPE |
			EFX_FILTER_MATCH_IP_PROTO |
			EFX_FILTER_MATCH_LOC_HOST | EFX_FILTER_MATCH_LOC_PORT;
		if (is_full)
			gen_spec->match_flags |= (EFX_FILTER_MATCH_REM_HOST |
						  EFX_FILTER_MATCH_REM_PORT);
		gen_spec->ether_type = htons(ETH_P_IP);
		gen_spec->ip_proto =
			(spec->type == EFX_FARCH_FILTER_TCP_FULL ||
			 spec->type == EFX_FARCH_FILTER_TCP_WILD) ?
			IPPROTO_TCP : IPPROTO_UDP;

		host1 = htonl(spec->data[0] >> 16 | spec->data[1] << 16);
		port1 = htons(spec->data[0]);
		host2 = htonl(spec->data[2]);
		port2 = htons(spec->data[1] >> 16);
		if (spec->flags & EFX_FILTER_FLAG_TX) {
			gen_spec->loc_host[0] = host1;
			gen_spec->rem_host[0] = host2;
		} else {
			gen_spec->loc_host[0] = host2;
			gen_spec->rem_host[0] = host1;
		}
		if (!!(gen_spec->flags & EFX_FILTER_FLAG_TX) ^
		    (!is_full && gen_spec->ip_proto == IPPROTO_UDP)) {
			gen_spec->loc_port = port1;
			gen_spec->rem_port = port2;
		} else {
			gen_spec->loc_port = port2;
			gen_spec->rem_port = port1;
		}

		break;
	}

	case EFX_FARCH_FILTER_MAC_FULL:
		is_full = true;
		/* fall through */
	case EFX_FARCH_FILTER_MAC_WILD:
		gen_spec->match_flags = EFX_FILTER_MATCH_LOC_MAC;
		if (is_full)
			gen_spec->match_flags |= EFX_FILTER_MATCH_OUTER_VID;
		gen_spec->loc_mac[0] = spec->data[2] >> 8;
		gen_spec->loc_mac[1] = spec->data[2];
		gen_spec->loc_mac[2] = spec->data[1] >> 24;
		gen_spec->loc_mac[3] = spec->data[1] >> 16;
		gen_spec->loc_mac[4] = spec->data[1] >> 8;
		gen_spec->loc_mac[5] = spec->data[1];
		gen_spec->outer_vid = htons(spec->data[0]);
		break;

	case EFX_FARCH_FILTER_UC_DEF:
	case EFX_FARCH_FILTER_MC_DEF:
		gen_spec->match_flags = EFX_FILTER_MATCH_LOC_MAC_IG;
		gen_spec->loc_mac[0] = spec->type == EFX_FARCH_FILTER_MC_DEF;
		break;

	default:
		WARN_ON(1);
		break;
	}
}