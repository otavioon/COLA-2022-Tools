#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u8 ;
typedef  scalar_t__ u16 ;
struct TYPE_6__ {int /*<<< orphan*/  extack; int /*<<< orphan*/  prio; } ;
struct tc_cls_flower_offload {TYPE_2__ common; int /*<<< orphan*/  exts; int /*<<< orphan*/  mask; TYPE_3__* dissector; int /*<<< orphan*/  key; } ;
struct mlxsw_sp_acl_rule_info {int dummy; } ;
struct mlxsw_sp_acl_block {int dummy; } ;
struct mlxsw_sp {TYPE_1__* bus_info; } ;
struct flow_dissector_key_vlan {scalar_t__ vlan_id; scalar_t__ vlan_priority; } ;
struct flow_dissector_key_eth_addrs {scalar_t__ src; scalar_t__ dst; } ;
struct flow_dissector_key_control {scalar_t__ addr_type; } ;
struct flow_dissector_key_basic {scalar_t__ ip_proto; int /*<<< orphan*/  n_proto; } ;
struct TYPE_7__ {int used_keys; } ;
struct TYPE_5__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int BIT (scalar_t__) ; 
 int EOPNOTSUPP ; 
 scalar_t__ ETH_P_ALL ; 
 scalar_t__ FLOW_DISSECTOR_KEY_BASIC ; 
 scalar_t__ FLOW_DISSECTOR_KEY_CONTROL ; 
 scalar_t__ FLOW_DISSECTOR_KEY_ETH_ADDRS ; 
 scalar_t__ FLOW_DISSECTOR_KEY_IP ; 
 scalar_t__ FLOW_DISSECTOR_KEY_IPV4_ADDRS ; 
 scalar_t__ FLOW_DISSECTOR_KEY_IPV6_ADDRS ; 
 scalar_t__ FLOW_DISSECTOR_KEY_PORTS ; 
 scalar_t__ FLOW_DISSECTOR_KEY_TCP ; 
 scalar_t__ FLOW_DISSECTOR_KEY_VLAN ; 
 int /*<<< orphan*/  MLXSW_AFK_ELEMENT_DMAC_0_31 ; 
 int /*<<< orphan*/  MLXSW_AFK_ELEMENT_DMAC_32_47 ; 
 int /*<<< orphan*/  MLXSW_AFK_ELEMENT_ETHERTYPE ; 
 int /*<<< orphan*/  MLXSW_AFK_ELEMENT_IP_PROTO ; 
 int /*<<< orphan*/  MLXSW_AFK_ELEMENT_PCP ; 
 int /*<<< orphan*/  MLXSW_AFK_ELEMENT_SMAC_0_31 ; 
 int /*<<< orphan*/  MLXSW_AFK_ELEMENT_SMAC_32_47 ; 
 int /*<<< orphan*/  MLXSW_AFK_ELEMENT_VID ; 
 int /*<<< orphan*/  NL_SET_ERR_MSG_MOD (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 scalar_t__ dissector_uses_key (TYPE_3__*,scalar_t__) ; 
 scalar_t__ mlxsw_sp_acl_block_is_egress_bound (struct mlxsw_sp_acl_block*) ; 
 int /*<<< orphan*/  mlxsw_sp_acl_rulei_keymask_buf (struct mlxsw_sp_acl_rule_info*,int /*<<< orphan*/ ,scalar_t__,scalar_t__,int) ; 
 int /*<<< orphan*/  mlxsw_sp_acl_rulei_keymask_u32 (struct mlxsw_sp_acl_rule_info*,int /*<<< orphan*/ ,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  mlxsw_sp_acl_rulei_priority (struct mlxsw_sp_acl_rule_info*,int /*<<< orphan*/ ) ; 
 int mlxsw_sp_flower_parse_actions (struct mlxsw_sp*,struct mlxsw_sp_acl_block*,struct mlxsw_sp_acl_rule_info*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int mlxsw_sp_flower_parse_ip (struct mlxsw_sp*,struct mlxsw_sp_acl_rule_info*,struct tc_cls_flower_offload*,scalar_t__) ; 
 int /*<<< orphan*/  mlxsw_sp_flower_parse_ipv4 (struct mlxsw_sp_acl_rule_info*,struct tc_cls_flower_offload*) ; 
 int /*<<< orphan*/  mlxsw_sp_flower_parse_ipv6 (struct mlxsw_sp_acl_rule_info*,struct tc_cls_flower_offload*) ; 
 int mlxsw_sp_flower_parse_ports (struct mlxsw_sp*,struct mlxsw_sp_acl_rule_info*,struct tc_cls_flower_offload*,scalar_t__) ; 
 int mlxsw_sp_flower_parse_tcp (struct mlxsw_sp*,struct mlxsw_sp_acl_rule_info*,struct tc_cls_flower_offload*,scalar_t__) ; 
 scalar_t__ ntohs (int /*<<< orphan*/ ) ; 
 void* skb_flow_dissector_target (TYPE_3__*,scalar_t__,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int mlxsw_sp_flower_parse(struct mlxsw_sp *mlxsw_sp,
				 struct mlxsw_sp_acl_block *block,
				 struct mlxsw_sp_acl_rule_info *rulei,
				 struct tc_cls_flower_offload *f)
{
	u16 n_proto_mask = 0;
	u16 n_proto_key = 0;
	u16 addr_type = 0;
	u8 ip_proto = 0;
	int err;

	if (f->dissector->used_keys &
	    ~(BIT(FLOW_DISSECTOR_KEY_CONTROL) |
	      BIT(FLOW_DISSECTOR_KEY_BASIC) |
	      BIT(FLOW_DISSECTOR_KEY_ETH_ADDRS) |
	      BIT(FLOW_DISSECTOR_KEY_IPV4_ADDRS) |
	      BIT(FLOW_DISSECTOR_KEY_IPV6_ADDRS) |
	      BIT(FLOW_DISSECTOR_KEY_PORTS) |
	      BIT(FLOW_DISSECTOR_KEY_TCP) |
	      BIT(FLOW_DISSECTOR_KEY_IP) |
	      BIT(FLOW_DISSECTOR_KEY_VLAN))) {
		dev_err(mlxsw_sp->bus_info->dev, "Unsupported key\n");
		NL_SET_ERR_MSG_MOD(f->common.extack, "Unsupported key");
		return -EOPNOTSUPP;
	}

	mlxsw_sp_acl_rulei_priority(rulei, f->common.prio);

	if (dissector_uses_key(f->dissector, FLOW_DISSECTOR_KEY_CONTROL)) {
		struct flow_dissector_key_control *key =
			skb_flow_dissector_target(f->dissector,
						  FLOW_DISSECTOR_KEY_CONTROL,
						  f->key);
		addr_type = key->addr_type;
	}

	if (dissector_uses_key(f->dissector, FLOW_DISSECTOR_KEY_BASIC)) {
		struct flow_dissector_key_basic *key =
			skb_flow_dissector_target(f->dissector,
						  FLOW_DISSECTOR_KEY_BASIC,
						  f->key);
		struct flow_dissector_key_basic *mask =
			skb_flow_dissector_target(f->dissector,
						  FLOW_DISSECTOR_KEY_BASIC,
						  f->mask);
		n_proto_key = ntohs(key->n_proto);
		n_proto_mask = ntohs(mask->n_proto);

		if (n_proto_key == ETH_P_ALL) {
			n_proto_key = 0;
			n_proto_mask = 0;
		}
		mlxsw_sp_acl_rulei_keymask_u32(rulei,
					       MLXSW_AFK_ELEMENT_ETHERTYPE,
					       n_proto_key, n_proto_mask);

		ip_proto = key->ip_proto;
		mlxsw_sp_acl_rulei_keymask_u32(rulei,
					       MLXSW_AFK_ELEMENT_IP_PROTO,
					       key->ip_proto, mask->ip_proto);
	}

	if (dissector_uses_key(f->dissector, FLOW_DISSECTOR_KEY_ETH_ADDRS)) {
		struct flow_dissector_key_eth_addrs *key =
			skb_flow_dissector_target(f->dissector,
						  FLOW_DISSECTOR_KEY_ETH_ADDRS,
						  f->key);
		struct flow_dissector_key_eth_addrs *mask =
			skb_flow_dissector_target(f->dissector,
						  FLOW_DISSECTOR_KEY_ETH_ADDRS,
						  f->mask);

		mlxsw_sp_acl_rulei_keymask_buf(rulei,
					       MLXSW_AFK_ELEMENT_DMAC_32_47,
					       key->dst, mask->dst, 2);
		mlxsw_sp_acl_rulei_keymask_buf(rulei,
					       MLXSW_AFK_ELEMENT_DMAC_0_31,
					       key->dst + 2, mask->dst + 2, 4);
		mlxsw_sp_acl_rulei_keymask_buf(rulei,
					       MLXSW_AFK_ELEMENT_SMAC_32_47,
					       key->src, mask->src, 2);
		mlxsw_sp_acl_rulei_keymask_buf(rulei,
					       MLXSW_AFK_ELEMENT_SMAC_0_31,
					       key->src + 2, mask->src + 2, 4);
	}

	if (dissector_uses_key(f->dissector, FLOW_DISSECTOR_KEY_VLAN)) {
		struct flow_dissector_key_vlan *key =
			skb_flow_dissector_target(f->dissector,
						  FLOW_DISSECTOR_KEY_VLAN,
						  f->key);
		struct flow_dissector_key_vlan *mask =
			skb_flow_dissector_target(f->dissector,
						  FLOW_DISSECTOR_KEY_VLAN,
						  f->mask);

		if (mlxsw_sp_acl_block_is_egress_bound(block)) {
			NL_SET_ERR_MSG_MOD(f->common.extack, "vlan_id key is not supported on egress");
			return -EOPNOTSUPP;
		}
		if (mask->vlan_id != 0)
			mlxsw_sp_acl_rulei_keymask_u32(rulei,
						       MLXSW_AFK_ELEMENT_VID,
						       key->vlan_id,
						       mask->vlan_id);
		if (mask->vlan_priority != 0)
			mlxsw_sp_acl_rulei_keymask_u32(rulei,
						       MLXSW_AFK_ELEMENT_PCP,
						       key->vlan_priority,
						       mask->vlan_priority);
	}

	if (addr_type == FLOW_DISSECTOR_KEY_IPV4_ADDRS)
		mlxsw_sp_flower_parse_ipv4(rulei, f);

	if (addr_type == FLOW_DISSECTOR_KEY_IPV6_ADDRS)
		mlxsw_sp_flower_parse_ipv6(rulei, f);

	err = mlxsw_sp_flower_parse_ports(mlxsw_sp, rulei, f, ip_proto);
	if (err)
		return err;
	err = mlxsw_sp_flower_parse_tcp(mlxsw_sp, rulei, f, ip_proto);
	if (err)
		return err;

	err = mlxsw_sp_flower_parse_ip(mlxsw_sp, rulei, f, n_proto_key & n_proto_mask);
	if (err)
		return err;

	return mlxsw_sp_flower_parse_actions(mlxsw_sp, block, rulei, f->exts,
					     f->common.extack);
}