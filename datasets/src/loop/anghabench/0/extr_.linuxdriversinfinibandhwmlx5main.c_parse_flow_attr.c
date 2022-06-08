#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_54__   TYPE_9__ ;
typedef  struct TYPE_53__   TYPE_8__ ;
typedef  struct TYPE_52__   TYPE_7__ ;
typedef  struct TYPE_51__   TYPE_6__ ;
typedef  struct TYPE_50__   TYPE_5__ ;
typedef  struct TYPE_49__   TYPE_4__ ;
typedef  struct TYPE_48__   TYPE_3__ ;
typedef  struct TYPE_47__   TYPE_2__ ;
typedef  struct TYPE_46__   TYPE_27__ ;
typedef  struct TYPE_45__   TYPE_26__ ;
typedef  struct TYPE_44__   TYPE_25__ ;
typedef  struct TYPE_43__   TYPE_24__ ;
typedef  struct TYPE_42__   TYPE_23__ ;
typedef  struct TYPE_41__   TYPE_22__ ;
typedef  struct TYPE_40__   TYPE_21__ ;
typedef  struct TYPE_39__   TYPE_20__ ;
typedef  struct TYPE_38__   TYPE_1__ ;
typedef  struct TYPE_37__   TYPE_19__ ;
typedef  struct TYPE_36__   TYPE_18__ ;
typedef  struct TYPE_35__   TYPE_17__ ;
typedef  struct TYPE_34__   TYPE_16__ ;
typedef  struct TYPE_33__   TYPE_15__ ;
typedef  struct TYPE_32__   TYPE_14__ ;
typedef  struct TYPE_31__   TYPE_13__ ;
typedef  struct TYPE_30__   TYPE_12__ ;
typedef  struct TYPE_29__   TYPE_11__ ;
typedef  struct TYPE_28__   TYPE_10__ ;

/* Type definitions */
struct TYPE_46__ {int /*<<< orphan*/  counters; int /*<<< orphan*/  tag_id; int /*<<< orphan*/  tunnel_id; int /*<<< orphan*/  dst_port; int /*<<< orphan*/  src_port; int /*<<< orphan*/  flow_label; int /*<<< orphan*/  next_hdr; int /*<<< orphan*/  traffic_class; int /*<<< orphan*/  dst_ip; int /*<<< orphan*/  src_ip; int /*<<< orphan*/  proto; int /*<<< orphan*/  tos; int /*<<< orphan*/  ether_type; int /*<<< orphan*/  vlan_tag; int /*<<< orphan*/  src_mac; int /*<<< orphan*/  dst_mac; } ;
struct TYPE_41__ {int /*<<< orphan*/  tunnel_id; } ;
struct TYPE_42__ {TYPE_22__ val; TYPE_27__ mask; } ;
struct TYPE_39__ {int /*<<< orphan*/  tag; } ;
struct TYPE_37__ {int /*<<< orphan*/  tag; } ;
struct TYPE_40__ {TYPE_20__ mask; TYPE_19__ val; } ;
struct TYPE_35__ {int /*<<< orphan*/  key; int /*<<< orphan*/  protocol; } ;
struct TYPE_34__ {int /*<<< orphan*/  key; int /*<<< orphan*/  protocol; int /*<<< orphan*/  c_ks_res0_ver; } ;
struct TYPE_36__ {TYPE_17__ val; TYPE_16__ mask; } ;
struct TYPE_32__ {int /*<<< orphan*/  dst_port; int /*<<< orphan*/  src_port; } ;
struct TYPE_33__ {TYPE_14__ val; TYPE_27__ mask; } ;
struct TYPE_30__ {int /*<<< orphan*/  spi; } ;
struct TYPE_29__ {int /*<<< orphan*/  spi; int /*<<< orphan*/  seq; } ;
struct TYPE_31__ {TYPE_12__ val; TYPE_11__ mask; } ;
struct TYPE_54__ {int /*<<< orphan*/  flow_label; int /*<<< orphan*/  next_hdr; int /*<<< orphan*/  traffic_class; int /*<<< orphan*/  dst_ip; int /*<<< orphan*/  src_ip; } ;
struct TYPE_28__ {TYPE_9__ val; TYPE_27__ mask; } ;
struct TYPE_50__ {int /*<<< orphan*/  proto; int /*<<< orphan*/  tos; int /*<<< orphan*/  dst_ip; int /*<<< orphan*/  src_ip; } ;
struct TYPE_51__ {TYPE_5__ val; TYPE_27__ mask; } ;
struct TYPE_38__ {int /*<<< orphan*/  ether_type; int /*<<< orphan*/  vlan_tag; int /*<<< orphan*/  src_mac; int /*<<< orphan*/  dst_mac; } ;
struct TYPE_47__ {TYPE_1__ val; TYPE_27__ mask; } ;
union ib_flow_spec {int type; TYPE_27__ flow_count; TYPE_27__ drop; TYPE_27__ flow_tag; TYPE_23__ tunnel; TYPE_21__ mpls; TYPE_18__ gre; TYPE_15__ tcp_udp; TYPE_13__ esp; TYPE_10__ ipv6; TYPE_6__ ipv4; TYPE_2__ eth; } ;
typedef  int /*<<< orphan*/  u32 ;
struct mlx5_flow_act {int has_flow_tag; int action; int /*<<< orphan*/  counters; int /*<<< orphan*/  flow_tag; } ;
struct mlx5_core_dev {int dummy; } ;
struct ib_flow_attr {int dummy; } ;
struct TYPE_53__ {int /*<<< orphan*/  ipv6; } ;
struct TYPE_52__ {int /*<<< orphan*/  ipv6; } ;
struct TYPE_49__ {int /*<<< orphan*/  ipv4; } ;
struct TYPE_48__ {int /*<<< orphan*/  ipv4; } ;
struct TYPE_45__ {TYPE_8__ ipv6_layout; TYPE_4__ ipv4_layout; } ;
struct TYPE_44__ {int /*<<< orphan*/  outer_first_mpls; int /*<<< orphan*/  inner_first_mpls; int /*<<< orphan*/  outer_first_mpls_over_gre; int /*<<< orphan*/  outer_first_mpls_over_udp; int /*<<< orphan*/  outer_ip_version; int /*<<< orphan*/  inner_ip_version; } ;
struct TYPE_43__ {TYPE_7__ ipv6_layout; TYPE_3__ ipv4_layout; } ;

/* Variables and functions */
 int /*<<< orphan*/  BIT (int) ; 
 int EINVAL ; 
 int EOPNOTSUPP ; 
 int ETH_P_IP ; 
 int ETH_P_IPV6 ; 
 int /*<<< orphan*/  FIELDS_NOT_SUPPORTED (TYPE_27__,int /*<<< orphan*/ ) ; 
#define  IB_FLOW_SPEC_ACTION_COUNT 140 
#define  IB_FLOW_SPEC_ACTION_DROP 139 
#define  IB_FLOW_SPEC_ACTION_HANDLE 138 
#define  IB_FLOW_SPEC_ACTION_TAG 137 
#define  IB_FLOW_SPEC_ESP 136 
#define  IB_FLOW_SPEC_ETH 135 
#define  IB_FLOW_SPEC_GRE 134 
 int IB_FLOW_SPEC_INNER ; 
#define  IB_FLOW_SPEC_IPV4 133 
#define  IB_FLOW_SPEC_IPV6 132 
#define  IB_FLOW_SPEC_MPLS 131 
#define  IB_FLOW_SPEC_TCP 130 
#define  IB_FLOW_SPEC_UDP 129 
#define  IB_FLOW_SPEC_VXLAN_TUNNEL 128 
 int IPPROTO_GRE ; 
 int IPPROTO_TCP ; 
 int IPPROTO_UDP ; 
 int /*<<< orphan*/  LAST_COUNTERS_FIELD ; 
 int /*<<< orphan*/  LAST_DROP_FIELD ; 
 int /*<<< orphan*/  LAST_ETH_FIELD ; 
 int /*<<< orphan*/  LAST_FLOW_TAG_FIELD ; 
 int /*<<< orphan*/  LAST_IPV4_FIELD ; 
 int /*<<< orphan*/  LAST_IPV6_FIELD ; 
 int /*<<< orphan*/  LAST_TCP_UDP_FIELD ; 
 int /*<<< orphan*/  LAST_TUNNEL_FIELD ; 
 int /*<<< orphan*/ * MLX5_ADDR_OF (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int MLX5_CAP_FLOWTABLE_NIC_RX (struct mlx5_core_dev*,int /*<<< orphan*/ ) ; 
 int MLX5_FLOW_CONTEXT_ACTION_COUNT ; 
 int MLX5_FLOW_CONTEXT_ACTION_DROP ; 
 int MLX5_FS_IPV4_VERSION ; 
 int MLX5_FS_IPV6_VERSION ; 
 int /*<<< orphan*/  MLX5_SET (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  check_mpls_supp_fields (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cvlan_tag ; 
 int /*<<< orphan*/  dmac_47_16 ; 
 TYPE_26__ dst_ipv4_dst_ipv6 ; 
 int /*<<< orphan*/  ether_addr_copy (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ethertype ; 
 int /*<<< orphan*/  first_cfi ; 
 int /*<<< orphan*/  first_prio ; 
 int /*<<< orphan*/  first_vid ; 
 TYPE_25__ ft_field_support ; 
 int /*<<< orphan*/  fte_match_param ; 
 int /*<<< orphan*/  fte_match_set_lyr_2_4 ; 
 int /*<<< orphan*/  fte_match_set_misc ; 
 int /*<<< orphan*/  fte_match_set_misc2 ; 
 int /*<<< orphan*/  gre_key_h ; 
 int /*<<< orphan*/  gre_protocol ; 
 int /*<<< orphan*/  inner_first_mpls ; 
 int /*<<< orphan*/  inner_headers ; 
 int /*<<< orphan*/  ip_protocol ; 
 int /*<<< orphan*/  ip_version ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  misc_parameters ; 
 int /*<<< orphan*/  misc_parameters_2 ; 
 int ntohl (int /*<<< orphan*/ ) ; 
 int ntohs (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  outer_esp_spi ; 
 int /*<<< orphan*/  outer_first_mpls ; 
 int /*<<< orphan*/  outer_first_mpls_over_gre ; 
 int /*<<< orphan*/  outer_first_mpls_over_udp ; 
 int /*<<< orphan*/  outer_headers ; 
 int parse_flow_flow_action (union ib_flow_spec const*,struct ib_flow_attr const*,struct mlx5_flow_act*) ; 
 int /*<<< orphan*/  set_flow_label (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int,int) ; 
 int /*<<< orphan*/  set_proto (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_tos (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  smac_47_16 ; 
 TYPE_24__ src_ipv4_src_ipv6 ; 
 int /*<<< orphan*/  tcp_dport ; 
 int /*<<< orphan*/  tcp_sport ; 
 int /*<<< orphan*/  udp_dport ; 
 int /*<<< orphan*/  udp_sport ; 
 int /*<<< orphan*/  vxlan_vni ; 

__attribute__((used)) static int parse_flow_attr(struct mlx5_core_dev *mdev, u32 *match_c,
			   u32 *match_v, const union ib_flow_spec *ib_spec,
			   const struct ib_flow_attr *flow_attr,
			   struct mlx5_flow_act *action, u32 prev_type)
{
	void *misc_params_c = MLX5_ADDR_OF(fte_match_param, match_c,
					   misc_parameters);
	void *misc_params_v = MLX5_ADDR_OF(fte_match_param, match_v,
					   misc_parameters);
	void *misc_params2_c = MLX5_ADDR_OF(fte_match_param, match_c,
					    misc_parameters_2);
	void *misc_params2_v = MLX5_ADDR_OF(fte_match_param, match_v,
					    misc_parameters_2);
	void *headers_c;
	void *headers_v;
	int match_ipv;
	int ret;

	if (ib_spec->type & IB_FLOW_SPEC_INNER) {
		headers_c = MLX5_ADDR_OF(fte_match_param, match_c,
					 inner_headers);
		headers_v = MLX5_ADDR_OF(fte_match_param, match_v,
					 inner_headers);
		match_ipv = MLX5_CAP_FLOWTABLE_NIC_RX(mdev,
					ft_field_support.inner_ip_version);
	} else {
		headers_c = MLX5_ADDR_OF(fte_match_param, match_c,
					 outer_headers);
		headers_v = MLX5_ADDR_OF(fte_match_param, match_v,
					 outer_headers);
		match_ipv = MLX5_CAP_FLOWTABLE_NIC_RX(mdev,
					ft_field_support.outer_ip_version);
	}

	switch (ib_spec->type & ~IB_FLOW_SPEC_INNER) {
	case IB_FLOW_SPEC_ETH:
		if (FIELDS_NOT_SUPPORTED(ib_spec->eth.mask, LAST_ETH_FIELD))
			return -EOPNOTSUPP;

		ether_addr_copy(MLX5_ADDR_OF(fte_match_set_lyr_2_4, headers_c,
					     dmac_47_16),
				ib_spec->eth.mask.dst_mac);
		ether_addr_copy(MLX5_ADDR_OF(fte_match_set_lyr_2_4, headers_v,
					     dmac_47_16),
				ib_spec->eth.val.dst_mac);

		ether_addr_copy(MLX5_ADDR_OF(fte_match_set_lyr_2_4, headers_c,
					     smac_47_16),
				ib_spec->eth.mask.src_mac);
		ether_addr_copy(MLX5_ADDR_OF(fte_match_set_lyr_2_4, headers_v,
					     smac_47_16),
				ib_spec->eth.val.src_mac);

		if (ib_spec->eth.mask.vlan_tag) {
			MLX5_SET(fte_match_set_lyr_2_4, headers_c,
				 cvlan_tag, 1);
			MLX5_SET(fte_match_set_lyr_2_4, headers_v,
				 cvlan_tag, 1);

			MLX5_SET(fte_match_set_lyr_2_4, headers_c,
				 first_vid, ntohs(ib_spec->eth.mask.vlan_tag));
			MLX5_SET(fte_match_set_lyr_2_4, headers_v,
				 first_vid, ntohs(ib_spec->eth.val.vlan_tag));

			MLX5_SET(fte_match_set_lyr_2_4, headers_c,
				 first_cfi,
				 ntohs(ib_spec->eth.mask.vlan_tag) >> 12);
			MLX5_SET(fte_match_set_lyr_2_4, headers_v,
				 first_cfi,
				 ntohs(ib_spec->eth.val.vlan_tag) >> 12);

			MLX5_SET(fte_match_set_lyr_2_4, headers_c,
				 first_prio,
				 ntohs(ib_spec->eth.mask.vlan_tag) >> 13);
			MLX5_SET(fte_match_set_lyr_2_4, headers_v,
				 first_prio,
				 ntohs(ib_spec->eth.val.vlan_tag) >> 13);
		}
		MLX5_SET(fte_match_set_lyr_2_4, headers_c,
			 ethertype, ntohs(ib_spec->eth.mask.ether_type));
		MLX5_SET(fte_match_set_lyr_2_4, headers_v,
			 ethertype, ntohs(ib_spec->eth.val.ether_type));
		break;
	case IB_FLOW_SPEC_IPV4:
		if (FIELDS_NOT_SUPPORTED(ib_spec->ipv4.mask, LAST_IPV4_FIELD))
			return -EOPNOTSUPP;

		if (match_ipv) {
			MLX5_SET(fte_match_set_lyr_2_4, headers_c,
				 ip_version, 0xf);
			MLX5_SET(fte_match_set_lyr_2_4, headers_v,
				 ip_version, MLX5_FS_IPV4_VERSION);
		} else {
			MLX5_SET(fte_match_set_lyr_2_4, headers_c,
				 ethertype, 0xffff);
			MLX5_SET(fte_match_set_lyr_2_4, headers_v,
				 ethertype, ETH_P_IP);
		}

		memcpy(MLX5_ADDR_OF(fte_match_set_lyr_2_4, headers_c,
				    src_ipv4_src_ipv6.ipv4_layout.ipv4),
		       &ib_spec->ipv4.mask.src_ip,
		       sizeof(ib_spec->ipv4.mask.src_ip));
		memcpy(MLX5_ADDR_OF(fte_match_set_lyr_2_4, headers_v,
				    src_ipv4_src_ipv6.ipv4_layout.ipv4),
		       &ib_spec->ipv4.val.src_ip,
		       sizeof(ib_spec->ipv4.val.src_ip));
		memcpy(MLX5_ADDR_OF(fte_match_set_lyr_2_4, headers_c,
				    dst_ipv4_dst_ipv6.ipv4_layout.ipv4),
		       &ib_spec->ipv4.mask.dst_ip,
		       sizeof(ib_spec->ipv4.mask.dst_ip));
		memcpy(MLX5_ADDR_OF(fte_match_set_lyr_2_4, headers_v,
				    dst_ipv4_dst_ipv6.ipv4_layout.ipv4),
		       &ib_spec->ipv4.val.dst_ip,
		       sizeof(ib_spec->ipv4.val.dst_ip));

		set_tos(headers_c, headers_v,
			ib_spec->ipv4.mask.tos, ib_spec->ipv4.val.tos);

		set_proto(headers_c, headers_v,
			  ib_spec->ipv4.mask.proto, ib_spec->ipv4.val.proto);
		break;
	case IB_FLOW_SPEC_IPV6:
		if (FIELDS_NOT_SUPPORTED(ib_spec->ipv6.mask, LAST_IPV6_FIELD))
			return -EOPNOTSUPP;

		if (match_ipv) {
			MLX5_SET(fte_match_set_lyr_2_4, headers_c,
				 ip_version, 0xf);
			MLX5_SET(fte_match_set_lyr_2_4, headers_v,
				 ip_version, MLX5_FS_IPV6_VERSION);
		} else {
			MLX5_SET(fte_match_set_lyr_2_4, headers_c,
				 ethertype, 0xffff);
			MLX5_SET(fte_match_set_lyr_2_4, headers_v,
				 ethertype, ETH_P_IPV6);
		}

		memcpy(MLX5_ADDR_OF(fte_match_set_lyr_2_4, headers_c,
				    src_ipv4_src_ipv6.ipv6_layout.ipv6),
		       &ib_spec->ipv6.mask.src_ip,
		       sizeof(ib_spec->ipv6.mask.src_ip));
		memcpy(MLX5_ADDR_OF(fte_match_set_lyr_2_4, headers_v,
				    src_ipv4_src_ipv6.ipv6_layout.ipv6),
		       &ib_spec->ipv6.val.src_ip,
		       sizeof(ib_spec->ipv6.val.src_ip));
		memcpy(MLX5_ADDR_OF(fte_match_set_lyr_2_4, headers_c,
				    dst_ipv4_dst_ipv6.ipv6_layout.ipv6),
		       &ib_spec->ipv6.mask.dst_ip,
		       sizeof(ib_spec->ipv6.mask.dst_ip));
		memcpy(MLX5_ADDR_OF(fte_match_set_lyr_2_4, headers_v,
				    dst_ipv4_dst_ipv6.ipv6_layout.ipv6),
		       &ib_spec->ipv6.val.dst_ip,
		       sizeof(ib_spec->ipv6.val.dst_ip));

		set_tos(headers_c, headers_v,
			ib_spec->ipv6.mask.traffic_class,
			ib_spec->ipv6.val.traffic_class);

		set_proto(headers_c, headers_v,
			  ib_spec->ipv6.mask.next_hdr,
			  ib_spec->ipv6.val.next_hdr);

		set_flow_label(misc_params_c, misc_params_v,
			       ntohl(ib_spec->ipv6.mask.flow_label),
			       ntohl(ib_spec->ipv6.val.flow_label),
			       ib_spec->type & IB_FLOW_SPEC_INNER);
		break;
	case IB_FLOW_SPEC_ESP:
		if (ib_spec->esp.mask.seq)
			return -EOPNOTSUPP;

		MLX5_SET(fte_match_set_misc, misc_params_c, outer_esp_spi,
			 ntohl(ib_spec->esp.mask.spi));
		MLX5_SET(fte_match_set_misc, misc_params_v, outer_esp_spi,
			 ntohl(ib_spec->esp.val.spi));
		break;
	case IB_FLOW_SPEC_TCP:
		if (FIELDS_NOT_SUPPORTED(ib_spec->tcp_udp.mask,
					 LAST_TCP_UDP_FIELD))
			return -EOPNOTSUPP;

		MLX5_SET(fte_match_set_lyr_2_4, headers_c, ip_protocol,
			 0xff);
		MLX5_SET(fte_match_set_lyr_2_4, headers_v, ip_protocol,
			 IPPROTO_TCP);

		MLX5_SET(fte_match_set_lyr_2_4, headers_c, tcp_sport,
			 ntohs(ib_spec->tcp_udp.mask.src_port));
		MLX5_SET(fte_match_set_lyr_2_4, headers_v, tcp_sport,
			 ntohs(ib_spec->tcp_udp.val.src_port));

		MLX5_SET(fte_match_set_lyr_2_4, headers_c, tcp_dport,
			 ntohs(ib_spec->tcp_udp.mask.dst_port));
		MLX5_SET(fte_match_set_lyr_2_4, headers_v, tcp_dport,
			 ntohs(ib_spec->tcp_udp.val.dst_port));
		break;
	case IB_FLOW_SPEC_UDP:
		if (FIELDS_NOT_SUPPORTED(ib_spec->tcp_udp.mask,
					 LAST_TCP_UDP_FIELD))
			return -EOPNOTSUPP;

		MLX5_SET(fte_match_set_lyr_2_4, headers_c, ip_protocol,
			 0xff);
		MLX5_SET(fte_match_set_lyr_2_4, headers_v, ip_protocol,
			 IPPROTO_UDP);

		MLX5_SET(fte_match_set_lyr_2_4, headers_c, udp_sport,
			 ntohs(ib_spec->tcp_udp.mask.src_port));
		MLX5_SET(fte_match_set_lyr_2_4, headers_v, udp_sport,
			 ntohs(ib_spec->tcp_udp.val.src_port));

		MLX5_SET(fte_match_set_lyr_2_4, headers_c, udp_dport,
			 ntohs(ib_spec->tcp_udp.mask.dst_port));
		MLX5_SET(fte_match_set_lyr_2_4, headers_v, udp_dport,
			 ntohs(ib_spec->tcp_udp.val.dst_port));
		break;
	case IB_FLOW_SPEC_GRE:
		if (ib_spec->gre.mask.c_ks_res0_ver)
			return -EOPNOTSUPP;

		MLX5_SET(fte_match_set_lyr_2_4, headers_c, ip_protocol,
			 0xff);
		MLX5_SET(fte_match_set_lyr_2_4, headers_v, ip_protocol,
			 IPPROTO_GRE);

		MLX5_SET(fte_match_set_misc, misc_params_c, gre_protocol,
			 ntohs(ib_spec->gre.mask.protocol));
		MLX5_SET(fte_match_set_misc, misc_params_v, gre_protocol,
			 ntohs(ib_spec->gre.val.protocol));

		memcpy(MLX5_ADDR_OF(fte_match_set_misc, misc_params_c,
				    gre_key_h),
		       &ib_spec->gre.mask.key,
		       sizeof(ib_spec->gre.mask.key));
		memcpy(MLX5_ADDR_OF(fte_match_set_misc, misc_params_v,
				    gre_key_h),
		       &ib_spec->gre.val.key,
		       sizeof(ib_spec->gre.val.key));
		break;
	case IB_FLOW_SPEC_MPLS:
		switch (prev_type) {
		case IB_FLOW_SPEC_UDP:
			if (check_mpls_supp_fields(MLX5_CAP_FLOWTABLE_NIC_RX(mdev,
						   ft_field_support.outer_first_mpls_over_udp),
						   &ib_spec->mpls.mask.tag))
				return -EOPNOTSUPP;

			memcpy(MLX5_ADDR_OF(fte_match_set_misc2, misc_params2_v,
					    outer_first_mpls_over_udp),
			       &ib_spec->mpls.val.tag,
			       sizeof(ib_spec->mpls.val.tag));
			memcpy(MLX5_ADDR_OF(fte_match_set_misc2, misc_params2_c,
					    outer_first_mpls_over_udp),
			       &ib_spec->mpls.mask.tag,
			       sizeof(ib_spec->mpls.mask.tag));
			break;
		case IB_FLOW_SPEC_GRE:
			if (check_mpls_supp_fields(MLX5_CAP_FLOWTABLE_NIC_RX(mdev,
						   ft_field_support.outer_first_mpls_over_gre),
						   &ib_spec->mpls.mask.tag))
				return -EOPNOTSUPP;

			memcpy(MLX5_ADDR_OF(fte_match_set_misc2, misc_params2_v,
					    outer_first_mpls_over_gre),
			       &ib_spec->mpls.val.tag,
			       sizeof(ib_spec->mpls.val.tag));
			memcpy(MLX5_ADDR_OF(fte_match_set_misc2, misc_params2_c,
					    outer_first_mpls_over_gre),
			       &ib_spec->mpls.mask.tag,
			       sizeof(ib_spec->mpls.mask.tag));
			break;
		default:
			if (ib_spec->type & IB_FLOW_SPEC_INNER) {
				if (check_mpls_supp_fields(MLX5_CAP_FLOWTABLE_NIC_RX(mdev,
							   ft_field_support.inner_first_mpls),
							   &ib_spec->mpls.mask.tag))
					return -EOPNOTSUPP;

				memcpy(MLX5_ADDR_OF(fte_match_set_misc2, misc_params2_v,
						    inner_first_mpls),
				       &ib_spec->mpls.val.tag,
				       sizeof(ib_spec->mpls.val.tag));
				memcpy(MLX5_ADDR_OF(fte_match_set_misc2, misc_params2_c,
						    inner_first_mpls),
				       &ib_spec->mpls.mask.tag,
				       sizeof(ib_spec->mpls.mask.tag));
			} else {
				if (check_mpls_supp_fields(MLX5_CAP_FLOWTABLE_NIC_RX(mdev,
							   ft_field_support.outer_first_mpls),
							   &ib_spec->mpls.mask.tag))
					return -EOPNOTSUPP;

				memcpy(MLX5_ADDR_OF(fte_match_set_misc2, misc_params2_v,
						    outer_first_mpls),
				       &ib_spec->mpls.val.tag,
				       sizeof(ib_spec->mpls.val.tag));
				memcpy(MLX5_ADDR_OF(fte_match_set_misc2, misc_params2_c,
						    outer_first_mpls),
				       &ib_spec->mpls.mask.tag,
				       sizeof(ib_spec->mpls.mask.tag));
			}
		}
		break;
	case IB_FLOW_SPEC_VXLAN_TUNNEL:
		if (FIELDS_NOT_SUPPORTED(ib_spec->tunnel.mask,
					 LAST_TUNNEL_FIELD))
			return -EOPNOTSUPP;

		MLX5_SET(fte_match_set_misc, misc_params_c, vxlan_vni,
			 ntohl(ib_spec->tunnel.mask.tunnel_id));
		MLX5_SET(fte_match_set_misc, misc_params_v, vxlan_vni,
			 ntohl(ib_spec->tunnel.val.tunnel_id));
		break;
	case IB_FLOW_SPEC_ACTION_TAG:
		if (FIELDS_NOT_SUPPORTED(ib_spec->flow_tag,
					 LAST_FLOW_TAG_FIELD))
			return -EOPNOTSUPP;
		if (ib_spec->flow_tag.tag_id >= BIT(24))
			return -EINVAL;

		action->flow_tag = ib_spec->flow_tag.tag_id;
		action->has_flow_tag = true;
		break;
	case IB_FLOW_SPEC_ACTION_DROP:
		if (FIELDS_NOT_SUPPORTED(ib_spec->drop,
					 LAST_DROP_FIELD))
			return -EOPNOTSUPP;
		action->action |= MLX5_FLOW_CONTEXT_ACTION_DROP;
		break;
	case IB_FLOW_SPEC_ACTION_HANDLE:
		ret = parse_flow_flow_action(ib_spec, flow_attr, action);
		if (ret)
			return ret;
		break;
	case IB_FLOW_SPEC_ACTION_COUNT:
		if (FIELDS_NOT_SUPPORTED(ib_spec->flow_count,
					 LAST_COUNTERS_FIELD))
			return -EOPNOTSUPP;

		/* for now support only one counters spec per flow */
		if (action->action & MLX5_FLOW_CONTEXT_ACTION_COUNT)
			return -EINVAL;

		action->counters = ib_spec->flow_count.counters;
		action->action |= MLX5_FLOW_CONTEXT_ACTION_COUNT;
		break;
	default:
		return -EINVAL;
	}

	return 0;
}