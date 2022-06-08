#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_9__ ;
typedef  struct TYPE_17__   TYPE_8__ ;
typedef  struct TYPE_16__   TYPE_7__ ;
typedef  struct TYPE_15__   TYPE_6__ ;
typedef  struct TYPE_14__   TYPE_5__ ;
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct sk_buff {int /*<<< orphan*/  len; int /*<<< orphan*/ * data; } ;
struct TYPE_17__ {int /*<<< orphan*/  data; int /*<<< orphan*/  tx_cmd; void* switch_time_offset; } ;
struct TYPE_13__ {void* max_offchan_duration; void* switch_timeout; void* switch_time; void* frame_timestamp; } ;
struct TYPE_12__ {int /*<<< orphan*/  ctrl_pos; int /*<<< orphan*/  width; int /*<<< orphan*/  channel; int /*<<< orphan*/  band; } ;
struct iwl_tdls_channel_switch_cmd {int switch_type; TYPE_8__ frame; TYPE_4__ timing; TYPE_3__ ci; void* peer_sta_id; int /*<<< orphan*/  member_0; } ;
struct iwl_mvm_sta {int sta_id; } ;
struct cfg80211_chan_def {TYPE_2__* chan; } ;
struct TYPE_10__ {struct cfg80211_chan_def chandef; } ;
struct TYPE_18__ {scalar_t__ state; int cur_sta_id; TYPE_1__ peer; } ;
struct iwl_mvm {TYPE_9__ tdls_cs; int /*<<< orphan*/  mutex; } ;
struct TYPE_14__ {int dtim_period; int beacon_int; } ;
struct ieee80211_vif {TYPE_5__ bss_conf; int /*<<< orphan*/  chanctx_conf; } ;
struct TYPE_16__ {TYPE_6__* hw_key; } ;
struct ieee80211_tx_info {TYPE_7__ control; } ;
struct ieee80211_sta {int dummy; } ;
struct ieee80211_hdr {int /*<<< orphan*/  frame_control; } ;
struct ieee80211_chanctx_conf {struct cfg80211_chan_def def; } ;
typedef  enum iwl_tdls_channel_switch_type { ____Placeholder_iwl_tdls_channel_switch_type } iwl_tdls_channel_switch_type ;
typedef  int /*<<< orphan*/  cmd ;
struct TYPE_15__ {scalar_t__ cipher; } ;
struct TYPE_11__ {scalar_t__ band; int /*<<< orphan*/  hw_value; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOENT ; 
 struct ieee80211_tx_info* IEEE80211_SKB_CB (struct sk_buff*) ; 
 int /*<<< orphan*/  IWL_ERR (struct iwl_mvm*,char*,int) ; 
 scalar_t__ IWL_MVM_TDLS_SW_ACTIVE ; 
 scalar_t__ IWL_MVM_TDLS_SW_IDLE ; 
 scalar_t__ IWL_MVM_TDLS_SW_REQ_RCVD ; 
 scalar_t__ IWL_MVM_TDLS_SW_REQ_SENT ; 
 scalar_t__ IWL_MVM_TDLS_SW_RESP_RCVD ; 
 int /*<<< orphan*/  IWL_TDLS_CH_SW_FRAME_MAX_SIZE ; 
 scalar_t__ NL80211_BAND_2GHZ ; 
 int /*<<< orphan*/  PHY_BAND_24 ; 
 int /*<<< orphan*/  PHY_BAND_5 ; 
 int /*<<< orphan*/  TDLS_CHANNEL_SWITCH_CMD ; 
 int TDLS_MOVE_CH ; 
 int TDLS_SEND_CHAN_SW_REQ ; 
 int TU_TO_US (int) ; 
 scalar_t__ WARN_ON (int) ; 
 scalar_t__ WARN_ON_ONCE (int) ; 
 scalar_t__ WLAN_CIPHER_SUITE_CCMP ; 
 void* cpu_to_le32 (int) ; 
 struct ieee80211_sta* ieee80211_find_sta (struct ieee80211_vif*,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  iwl_mvm_get_channel_width (struct cfg80211_chan_def*) ; 
 int /*<<< orphan*/  iwl_mvm_get_ctrl_pos (struct cfg80211_chan_def*) ; 
 int iwl_mvm_send_cmd_pdu (struct iwl_mvm*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,struct iwl_tdls_channel_switch_cmd*) ; 
 int /*<<< orphan*/  iwl_mvm_set_tx_cmd (struct iwl_mvm*,struct sk_buff*,int /*<<< orphan*/ *,struct ieee80211_tx_info*,int) ; 
 int /*<<< orphan*/  iwl_mvm_set_tx_cmd_ccmp (struct ieee80211_tx_info*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  iwl_mvm_set_tx_cmd_rate (struct iwl_mvm*,int /*<<< orphan*/ *,struct ieee80211_tx_info*,struct ieee80211_sta*,int /*<<< orphan*/ ) ; 
 struct iwl_mvm_sta* iwl_mvm_sta_from_mac80211 (struct ieee80211_sta*) ; 
 int iwl_mvm_tdls_check_action (struct iwl_mvm*,int,int /*<<< orphan*/  const*,int,int) ; 
 int /*<<< orphan*/  iwl_mvm_tdls_update_cs_state (struct iwl_mvm*,scalar_t__) ; 
 int /*<<< orphan*/  lockdep_assert_held (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct ieee80211_chanctx_conf* rcu_dereference (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rcu_read_lock () ; 
 int /*<<< orphan*/  rcu_read_unlock () ; 

__attribute__((used)) static int
iwl_mvm_tdls_config_channel_switch(struct iwl_mvm *mvm,
				   struct ieee80211_vif *vif,
				   enum iwl_tdls_channel_switch_type type,
				   const u8 *peer, bool peer_initiator,
				   u8 oper_class,
				   struct cfg80211_chan_def *chandef,
				   u32 timestamp, u16 switch_time,
				   u16 switch_timeout, struct sk_buff *skb,
				   u32 ch_sw_tm_ie)
{
	struct ieee80211_sta *sta;
	struct iwl_mvm_sta *mvmsta;
	struct ieee80211_tx_info *info;
	struct ieee80211_hdr *hdr;
	struct iwl_tdls_channel_switch_cmd cmd = {0};
	int ret;

	lockdep_assert_held(&mvm->mutex);

	ret = iwl_mvm_tdls_check_action(mvm, type, peer, peer_initiator,
					timestamp);
	if (ret)
		return ret;

	if (!skb || WARN_ON(skb->len > IWL_TDLS_CH_SW_FRAME_MAX_SIZE)) {
		ret = -EINVAL;
		goto out;
	}

	cmd.switch_type = type;
	cmd.timing.frame_timestamp = cpu_to_le32(timestamp);
	cmd.timing.switch_time = cpu_to_le32(switch_time);
	cmd.timing.switch_timeout = cpu_to_le32(switch_timeout);

	rcu_read_lock();
	sta = ieee80211_find_sta(vif, peer);
	if (!sta) {
		rcu_read_unlock();
		ret = -ENOENT;
		goto out;
	}
	mvmsta = iwl_mvm_sta_from_mac80211(sta);
	cmd.peer_sta_id = cpu_to_le32(mvmsta->sta_id);

	if (!chandef) {
		if (mvm->tdls_cs.state == IWL_MVM_TDLS_SW_REQ_SENT &&
		    mvm->tdls_cs.peer.chandef.chan) {
			/* actually moving to the channel */
			chandef = &mvm->tdls_cs.peer.chandef;
		} else if (mvm->tdls_cs.state == IWL_MVM_TDLS_SW_ACTIVE &&
			   type == TDLS_MOVE_CH) {
			/* we need to return to base channel */
			struct ieee80211_chanctx_conf *chanctx =
					rcu_dereference(vif->chanctx_conf);

			if (WARN_ON_ONCE(!chanctx)) {
				rcu_read_unlock();
				goto out;
			}

			chandef = &chanctx->def;
		}
	}

	if (chandef) {
		cmd.ci.band = (chandef->chan->band == NL80211_BAND_2GHZ ?
			       PHY_BAND_24 : PHY_BAND_5);
		cmd.ci.channel = chandef->chan->hw_value;
		cmd.ci.width = iwl_mvm_get_channel_width(chandef);
		cmd.ci.ctrl_pos = iwl_mvm_get_ctrl_pos(chandef);
	}

	/* keep quota calculation simple for now - 50% of DTIM for TDLS */
	cmd.timing.max_offchan_duration =
			cpu_to_le32(TU_TO_US(vif->bss_conf.dtim_period *
					     vif->bss_conf.beacon_int) / 2);

	/* Switch time is the first element in the switch-timing IE. */
	cmd.frame.switch_time_offset = cpu_to_le32(ch_sw_tm_ie + 2);

	info = IEEE80211_SKB_CB(skb);
	hdr = (void *)skb->data;
	if (info->control.hw_key) {
		if (info->control.hw_key->cipher != WLAN_CIPHER_SUITE_CCMP) {
			rcu_read_unlock();
			ret = -EINVAL;
			goto out;
		}
		iwl_mvm_set_tx_cmd_ccmp(info, &cmd.frame.tx_cmd);
	}

	iwl_mvm_set_tx_cmd(mvm, skb, &cmd.frame.tx_cmd, info,
			   mvmsta->sta_id);

	iwl_mvm_set_tx_cmd_rate(mvm, &cmd.frame.tx_cmd, info, sta,
				hdr->frame_control);
	rcu_read_unlock();

	memcpy(cmd.frame.data, skb->data, skb->len);

	ret = iwl_mvm_send_cmd_pdu(mvm, TDLS_CHANNEL_SWITCH_CMD, 0,
				   sizeof(cmd), &cmd);
	if (ret) {
		IWL_ERR(mvm, "Failed to send TDLS_CHANNEL_SWITCH cmd: %d\n",
			ret);
		goto out;
	}

	/* channel switch has started, update state */
	if (type != TDLS_MOVE_CH) {
		mvm->tdls_cs.cur_sta_id = mvmsta->sta_id;
		iwl_mvm_tdls_update_cs_state(mvm,
					     type == TDLS_SEND_CHAN_SW_REQ ?
					     IWL_MVM_TDLS_SW_REQ_SENT :
					     IWL_MVM_TDLS_SW_REQ_RCVD);
	} else {
		iwl_mvm_tdls_update_cs_state(mvm, IWL_MVM_TDLS_SW_RESP_RCVD);
	}

out:

	/* channel switch failed - we are idle */
	if (ret)
		iwl_mvm_tdls_update_cs_state(mvm, IWL_MVM_TDLS_SW_IDLE);

	return ret;
}