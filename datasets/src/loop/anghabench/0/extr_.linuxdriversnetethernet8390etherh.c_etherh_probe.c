#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct net_device {int /*<<< orphan*/  dev_addr; int /*<<< orphan*/  name; scalar_t__ base_addr; int /*<<< orphan*/  if_port; int /*<<< orphan*/  flags; int /*<<< orphan*/ * ethtool_ops; int /*<<< orphan*/  irq; int /*<<< orphan*/ * netdev_ops; } ;
struct TYPE_2__ {scalar_t__ product; } ;
struct expansion_card {int slot_no; TYPE_1__ cid; int /*<<< orphan*/  irq; int /*<<< orphan*/  dev; } ;
struct etherh_priv {int supported; scalar_t__ id; int memc; int ctrl_port; int ioc_fast; int dma_base; scalar_t__ ctrl; } ;
struct etherh_data {int supported; int dataport_offset; int ctrlport_offset; int /*<<< orphan*/  name; int /*<<< orphan*/  stop_page; scalar_t__ tx_start_page; scalar_t__ ns8390_offset; scalar_t__ ctrl_ioc; } ;
struct ei_device {int word16; scalar_t__ interface_num; int /*<<< orphan*/  get_8390_hdr; int /*<<< orphan*/  block_output; int /*<<< orphan*/  block_input; int /*<<< orphan*/  (* reset_8390 ) (struct net_device*) ;int /*<<< orphan*/  stop_page; scalar_t__ tx_start_page; scalar_t__ rx_start_page; int /*<<< orphan*/  name; int /*<<< orphan*/  reg_offset; int /*<<< orphan*/  page_lock; } ;
struct ecard_id {struct etherh_data* data; } ;

/* Variables and functions */
 int /*<<< orphan*/  ECARD_RES_IOCFAST ; 
 int /*<<< orphan*/  ECARD_RES_MEMC ; 
 int ENOMEM ; 
 int /*<<< orphan*/  ETHERH_CP_IE ; 
 int /*<<< orphan*/  IFF_AUTOMEDIA ; 
 int /*<<< orphan*/  IFF_PORTSEL ; 
 int /*<<< orphan*/  IF_PORT_10BASE2 ; 
 int /*<<< orphan*/  IF_PORT_10BASET ; 
 int /*<<< orphan*/  IF_PORT_UNKNOWN ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 scalar_t__ PROD_ANT_ETHERM ; 
 int /*<<< orphan*/  SET_NETDEV_DEV (struct net_device*,int /*<<< orphan*/ *) ; 
 int SUPPORTED_Autoneg ; 
 int SUPPORTED_BNC ; 
 int SUPPORTED_TP ; 
 scalar_t__ TX_PAGES ; 
 int /*<<< orphan*/  __NS8390_init (struct net_device*,int /*<<< orphan*/ ) ; 
 struct net_device* ____alloc_ei_netdev (int) ; 
 int /*<<< orphan*/  ecard_release_resources (struct expansion_card*) ; 
 int ecard_request_resources (struct expansion_card*) ; 
 int /*<<< orphan*/  ecard_set_drvdata (struct expansion_card*,struct net_device*) ; 
 int /*<<< orphan*/  ecard_setirq (struct expansion_card*,int /*<<< orphan*/ *,struct etherh_priv*) ; 
 void* ecardm_iomap (struct expansion_card*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  etherh_addr (int /*<<< orphan*/ ,struct expansion_card*) ; 
 int /*<<< orphan*/  etherh_block_input ; 
 int /*<<< orphan*/  etherh_block_output ; 
 int /*<<< orphan*/  etherh_ethtool_ops ; 
 int /*<<< orphan*/  etherh_get_header ; 
 int /*<<< orphan*/  etherh_netdev_ops ; 
 int /*<<< orphan*/  etherh_ops ; 
 struct etherh_priv* etherh_priv (struct net_device*) ; 
 int /*<<< orphan*/  etherh_regoffsets ; 
 int /*<<< orphan*/  etherh_reset (struct net_device*) ; 
 int /*<<< orphan*/  etherh_set_ctrl (struct etherh_priv*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  etherm_addr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  etherm_regoffsets ; 
 int /*<<< orphan*/  free_netdev (struct net_device*) ; 
 int /*<<< orphan*/  netdev_info (struct net_device*,char*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 struct ei_device* netdev_priv (struct net_device*) ; 
 int register_netdev (struct net_device*) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int
etherh_probe(struct expansion_card *ec, const struct ecard_id *id)
{
	const struct etherh_data *data = id->data;
	struct ei_device *ei_local;
	struct net_device *dev;
	struct etherh_priv *eh;
	int ret;

	ret = ecard_request_resources(ec);
	if (ret)
		goto out;

	dev = ____alloc_ei_netdev(sizeof(struct etherh_priv));
	if (!dev) {
		ret = -ENOMEM;
		goto release;
	}

	SET_NETDEV_DEV(dev, &ec->dev);

	dev->netdev_ops		= &etherh_netdev_ops;
	dev->irq		= ec->irq;
	dev->ethtool_ops	= &etherh_ethtool_ops;

	if (data->supported & SUPPORTED_Autoneg)
		dev->flags |= IFF_AUTOMEDIA;
	if (data->supported & SUPPORTED_TP) {
		dev->flags |= IFF_PORTSEL;
		dev->if_port = IF_PORT_10BASET;
	} else if (data->supported & SUPPORTED_BNC) {
		dev->flags |= IFF_PORTSEL;
		dev->if_port = IF_PORT_10BASE2;
	} else
		dev->if_port = IF_PORT_UNKNOWN;

	eh = etherh_priv(dev);
	eh->supported		= data->supported;
	eh->ctrl		= 0;
	eh->id			= ec->cid.product;
	eh->memc		= ecardm_iomap(ec, ECARD_RES_MEMC, 0, PAGE_SIZE);
	if (!eh->memc) {
		ret = -ENOMEM;
		goto free;
	}

	eh->ctrl_port = eh->memc;
	if (data->ctrl_ioc) {
		eh->ioc_fast = ecardm_iomap(ec, ECARD_RES_IOCFAST, 0, PAGE_SIZE);
		if (!eh->ioc_fast) {
			ret = -ENOMEM;
			goto free;
		}
		eh->ctrl_port = eh->ioc_fast;
	}

	dev->base_addr = (unsigned long)eh->memc + data->ns8390_offset;
	eh->dma_base = eh->memc + data->dataport_offset;
	eh->ctrl_port += data->ctrlport_offset;

	/*
	 * IRQ and control port handling - only for non-NIC slot cards.
	 */
	if (ec->slot_no != 8) {
		ecard_setirq(ec, &etherh_ops, eh);
	} else {
		/*
		 * If we're in the NIC slot, make sure the IRQ is enabled
		 */
		etherh_set_ctrl(eh, ETHERH_CP_IE);
	}

	ei_local = netdev_priv(dev);
	spin_lock_init(&ei_local->page_lock);

	if (ec->cid.product == PROD_ANT_ETHERM) {
		etherm_addr(dev->dev_addr);
		ei_local->reg_offset = etherm_regoffsets;
	} else {
		etherh_addr(dev->dev_addr, ec);
		ei_local->reg_offset = etherh_regoffsets;
	}

	ei_local->name          = dev->name;
	ei_local->word16        = 1;
	ei_local->tx_start_page = data->tx_start_page;
	ei_local->rx_start_page = ei_local->tx_start_page + TX_PAGES;
	ei_local->stop_page     = data->stop_page;
	ei_local->reset_8390    = etherh_reset;
	ei_local->block_input   = etherh_block_input;
	ei_local->block_output  = etherh_block_output;
	ei_local->get_8390_hdr  = etherh_get_header;
	ei_local->interface_num = 0;

	etherh_reset(dev);
	__NS8390_init(dev, 0);

	ret = register_netdev(dev);
	if (ret)
		goto free;

	netdev_info(dev, "%s in slot %d, %pM\n",
		    data->name, ec->slot_no, dev->dev_addr);

	ecard_set_drvdata(ec, dev);

	return 0;

 free:
	free_netdev(dev);
 release:
	ecard_release_resources(ec);
 out:
	return ret;
}