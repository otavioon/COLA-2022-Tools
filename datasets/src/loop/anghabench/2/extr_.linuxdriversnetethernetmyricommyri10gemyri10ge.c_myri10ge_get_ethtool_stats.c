#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u64 ;
struct rtnl_link_stats64 {int dummy; } ;
struct net_device {int dummy; } ;
struct TYPE_10__ {int pkt_start; int pkt_done; int req; int done; int wake_queue; int stop_queue; int linearized; } ;
struct TYPE_7__ {int cnt; } ;
struct TYPE_6__ {int cnt; } ;
struct myri10ge_slice_state {TYPE_5__ tx; TYPE_2__ rx_big; TYPE_1__ rx_small; TYPE_4__* fw_stats; } ;
struct myri10ge_priv {int tx_boundary; int msi_enabled; int msix_enabled; int read_dma; int write_dma; int read_write_dma; int serial_number; int watchdog_resets; int link_changes; int num_slices; struct myri10ge_slice_state* ss; TYPE_3__* pdev; } ;
struct ethtool_stats {int dummy; } ;
typedef  int /*<<< orphan*/  link_stats ;
struct TYPE_9__ {int /*<<< orphan*/  dropped_no_big_buffer; int /*<<< orphan*/  dropped_no_small_buffer; int /*<<< orphan*/  dropped_overrun; int /*<<< orphan*/  dropped_runt; int /*<<< orphan*/  dropped_multicast_filtered; int /*<<< orphan*/  dropped_unicast_filtered; int /*<<< orphan*/  dropped_bad_crc32; int /*<<< orphan*/  dropped_bad_phy; int /*<<< orphan*/  dropped_pause; int /*<<< orphan*/  dropped_link_error_or_filtered; int /*<<< orphan*/  dropped_link_overflow; int /*<<< orphan*/  link_up; } ;
struct TYPE_8__ {int irq; } ;

/* Variables and functions */
 int MYRI10GE_NET_STATS_LEN ; 
 int /*<<< orphan*/  memset (struct rtnl_link_stats64*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  myri10ge_get_stats (struct net_device*,struct rtnl_link_stats64*) ; 
 struct myri10ge_priv* netdev_priv (struct net_device*) ; 
 int ntohl (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
myri10ge_get_ethtool_stats(struct net_device *netdev,
			   struct ethtool_stats *stats, u64 * data)
{
	struct myri10ge_priv *mgp = netdev_priv(netdev);
	struct myri10ge_slice_state *ss;
	struct rtnl_link_stats64 link_stats;
	int slice;
	int i;

	/* force stats update */
	memset(&link_stats, 0, sizeof(link_stats));
	(void)myri10ge_get_stats(netdev, &link_stats);
	for (i = 0; i < MYRI10GE_NET_STATS_LEN; i++)
		data[i] = ((u64 *)&link_stats)[i];

	data[i++] = (unsigned int)mgp->tx_boundary;
	data[i++] = (unsigned int)mgp->pdev->irq;
	data[i++] = (unsigned int)mgp->msi_enabled;
	data[i++] = (unsigned int)mgp->msix_enabled;
	data[i++] = (unsigned int)mgp->read_dma;
	data[i++] = (unsigned int)mgp->write_dma;
	data[i++] = (unsigned int)mgp->read_write_dma;
	data[i++] = (unsigned int)mgp->serial_number;
	data[i++] = (unsigned int)mgp->watchdog_resets;
#ifdef CONFIG_MYRI10GE_DCA
	data[i++] = (unsigned int)(mgp->ss[0].dca_tag != NULL);
	data[i++] = (unsigned int)(mgp->dca_enabled);
#endif
	data[i++] = (unsigned int)mgp->link_changes;

	/* firmware stats are useful only in the first slice */
	ss = &mgp->ss[0];
	data[i++] = (unsigned int)ntohl(ss->fw_stats->link_up);
	data[i++] = (unsigned int)ntohl(ss->fw_stats->dropped_link_overflow);
	data[i++] =
	    (unsigned int)ntohl(ss->fw_stats->dropped_link_error_or_filtered);
	data[i++] = (unsigned int)ntohl(ss->fw_stats->dropped_pause);
	data[i++] = (unsigned int)ntohl(ss->fw_stats->dropped_bad_phy);
	data[i++] = (unsigned int)ntohl(ss->fw_stats->dropped_bad_crc32);
	data[i++] = (unsigned int)ntohl(ss->fw_stats->dropped_unicast_filtered);
	data[i++] =
	    (unsigned int)ntohl(ss->fw_stats->dropped_multicast_filtered);
	data[i++] = (unsigned int)ntohl(ss->fw_stats->dropped_runt);
	data[i++] = (unsigned int)ntohl(ss->fw_stats->dropped_overrun);
	data[i++] = (unsigned int)ntohl(ss->fw_stats->dropped_no_small_buffer);
	data[i++] = (unsigned int)ntohl(ss->fw_stats->dropped_no_big_buffer);

	for (slice = 0; slice < mgp->num_slices; slice++) {
		ss = &mgp->ss[slice];
		data[i++] = slice;
		data[i++] = (unsigned int)ss->tx.pkt_start;
		data[i++] = (unsigned int)ss->tx.pkt_done;
		data[i++] = (unsigned int)ss->tx.req;
		data[i++] = (unsigned int)ss->tx.done;
		data[i++] = (unsigned int)ss->rx_small.cnt;
		data[i++] = (unsigned int)ss->rx_big.cnt;
		data[i++] = (unsigned int)ss->tx.wake_queue;
		data[i++] = (unsigned int)ss->tx.stop_queue;
		data[i++] = (unsigned int)ss->tx.linearized;
	}
}