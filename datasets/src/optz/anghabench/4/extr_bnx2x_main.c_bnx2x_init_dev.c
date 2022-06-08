#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
struct pci_dev {int needs_freset; int /*<<< orphan*/  enable_cnt; int /*<<< orphan*/  devfn; int /*<<< orphan*/  dev; int /*<<< orphan*/  irq; int /*<<< orphan*/  pm_cap; } ;
struct net_device {int hw_features; int hw_enc_features; int gso_partial_features; int vlan_features; int features; int /*<<< orphan*/  max_mtu; int /*<<< orphan*/  min_mtu; int /*<<< orphan*/ * dcbnl_ops; int /*<<< orphan*/  priv_flags; int /*<<< orphan*/ * netdev_ops; int /*<<< orphan*/  watchdog_timeo; int /*<<< orphan*/  irq; int /*<<< orphan*/  mem_end; int /*<<< orphan*/  mem_start; int /*<<< orphan*/  base_addr; } ;
struct TYPE_2__ {int mode_support; int /*<<< orphan*/  mdio_write; int /*<<< orphan*/  mdio_read; struct net_device* dev; scalar_t__ mmds; int /*<<< orphan*/  prtad; } ;
struct bnx2x {int pf_num; int accept_any_vlan; TYPE_1__ mdio; int /*<<< orphan*/  flags; struct pci_dev* pdev; int /*<<< orphan*/  regview; struct net_device* dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  AER_ENABLED ; 
 unsigned long BCM57710 ; 
 unsigned long BCM57711 ; 
 unsigned long BCM57711E ; 
 int /*<<< orphan*/  BNX2X_DEV_INFO (char*,int) ; 
 int /*<<< orphan*/  DRV_MODULE_NAME ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  ETH_MAX_JUMBO_PACKET_SIZE ; 
 int /*<<< orphan*/  ETH_MIN_PACKET_SIZE ; 
 int /*<<< orphan*/  IFF_UNICAST_FLT ; 
 int IORESOURCE_MEM ; 
 scalar_t__ IS_PF (struct bnx2x*) ; 
 int MDIO_EMULATE_C22 ; 
 int /*<<< orphan*/  MDIO_PRTAD_NONE ; 
 int MDIO_SUPPORTS_C45 ; 
 int ME_REG_ABS_PF_NUM ; 
 int ME_REG_ABS_PF_NUM_SHIFT ; 
 int NETIF_F_GRO ; 
 int NETIF_F_GRO_HW ; 
 int NETIF_F_GSO_GRE ; 
 int NETIF_F_GSO_GRE_CSUM ; 
 int NETIF_F_GSO_IPXIP4 ; 
 int NETIF_F_GSO_PARTIAL ; 
 int NETIF_F_GSO_UDP_TUNNEL ; 
 int NETIF_F_GSO_UDP_TUNNEL_CSUM ; 
 int NETIF_F_HIGHDMA ; 
 int NETIF_F_HW_VLAN_CTAG_FILTER ; 
 int NETIF_F_HW_VLAN_CTAG_RX ; 
 int NETIF_F_HW_VLAN_CTAG_TX ; 
 int NETIF_F_IPV6_CSUM ; 
 int NETIF_F_IP_CSUM ; 
 int NETIF_F_LOOPBACK ; 
 int NETIF_F_LRO ; 
 int NETIF_F_RXCSUM ; 
 int NETIF_F_RXHASH ; 
 int NETIF_F_SG ; 
 int NETIF_F_TSO ; 
 int NETIF_F_TSO6 ; 
 int NETIF_F_TSO_ECN ; 
 int /*<<< orphan*/  PCICFG_GRC_ADDRESS ; 
 int /*<<< orphan*/  PCICFG_ME_REGISTER ; 
 int PCICFG_REVESION_ID_ERROR_VAL ; 
 int PCICFG_REVESION_ID_MASK ; 
 int /*<<< orphan*/  PCICFG_REVISION_ID_OFFSET ; 
 int /*<<< orphan*/  PCICFG_VENDOR_ID_OFFSET ; 
 int PCI_FUNC (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PGLUE_B_REG_INTERNAL_PFID_ENABLE_TARGET_READ ; 
 int /*<<< orphan*/  PXP2_REG_PGL_ADDR_88_F0 ; 
 int /*<<< orphan*/  PXP2_REG_PGL_ADDR_88_F1 ; 
 int /*<<< orphan*/  PXP2_REG_PGL_ADDR_8C_F0 ; 
 int /*<<< orphan*/  PXP2_REG_PGL_ADDR_8C_F1 ; 
 int /*<<< orphan*/  PXP2_REG_PGL_ADDR_90_F0 ; 
 int /*<<< orphan*/  PXP2_REG_PGL_ADDR_90_F1 ; 
 int /*<<< orphan*/  PXP2_REG_PGL_ADDR_94_F0 ; 
 int /*<<< orphan*/  PXP2_REG_PGL_ADDR_94_F1 ; 
 int /*<<< orphan*/  REG_WR (struct bnx2x*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  SET_NETDEV_DEV (struct net_device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TX_TIMEOUT ; 
 int atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bnx2x_dcbnl_ops ; 
 int /*<<< orphan*/  bnx2x_mdio_read ; 
 int /*<<< orphan*/  bnx2x_mdio_write ; 
 int /*<<< orphan*/  bnx2x_netdev_ops ; 
 int bnx2x_set_coherency_mask (struct bnx2x*) ; 
 int /*<<< orphan*/  bnx2x_set_ethtool_ops (struct bnx2x*,struct net_device*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  pci_disable_device (struct pci_dev*) ; 
 int pci_enable_device (struct pci_dev*) ; 
 int pci_enable_pcie_error_reporting (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_ioremap_bar (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_is_pcie (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_read_config_dword (struct pci_dev*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  pci_release_regions (struct pci_dev*) ; 
 int pci_request_regions (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_resource_end (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int pci_resource_flags (struct pci_dev*,int) ; 
 int /*<<< orphan*/  pci_resource_start (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_save_state (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_set_master (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_write_config_dword (struct pci_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_err (char*) ; 

__attribute__((used)) static int bnx2x_init_dev(struct bnx2x *bp, struct pci_dev *pdev,
			  struct net_device *dev, unsigned long board_type)
{
	int rc;
	u32 pci_cfg_dword;
	bool chip_is_e1x = (board_type == BCM57710 ||
			    board_type == BCM57711 ||
			    board_type == BCM57711E);

	SET_NETDEV_DEV(dev, &pdev->dev);

	bp->dev = dev;
	bp->pdev = pdev;

	rc = pci_enable_device(pdev);
	if (rc) {
		dev_err(&bp->pdev->dev,
			"Cannot enable PCI device, aborting\n");
		goto err_out;
	}

	if (!(pci_resource_flags(pdev, 0) & IORESOURCE_MEM)) {
		dev_err(&bp->pdev->dev,
			"Cannot find PCI device base address, aborting\n");
		rc = -ENODEV;
		goto err_out_disable;
	}

	if (IS_PF(bp) && !(pci_resource_flags(pdev, 2) & IORESOURCE_MEM)) {
		dev_err(&bp->pdev->dev, "Cannot find second PCI device base address, aborting\n");
		rc = -ENODEV;
		goto err_out_disable;
	}

	pci_read_config_dword(pdev, PCICFG_REVISION_ID_OFFSET, &pci_cfg_dword);
	if ((pci_cfg_dword & PCICFG_REVESION_ID_MASK) ==
	    PCICFG_REVESION_ID_ERROR_VAL) {
		pr_err("PCI device error, probably due to fan failure, aborting\n");
		rc = -ENODEV;
		goto err_out_disable;
	}

	if (atomic_read(&pdev->enable_cnt) == 1) {
		rc = pci_request_regions(pdev, DRV_MODULE_NAME);
		if (rc) {
			dev_err(&bp->pdev->dev,
				"Cannot obtain PCI resources, aborting\n");
			goto err_out_disable;
		}

		pci_set_master(pdev);
		pci_save_state(pdev);
	}

	if (IS_PF(bp)) {
		if (!pdev->pm_cap) {
			dev_err(&bp->pdev->dev,
				"Cannot find power management capability, aborting\n");
			rc = -EIO;
			goto err_out_release;
		}
	}

	if (!pci_is_pcie(pdev)) {
		dev_err(&bp->pdev->dev, "Not PCI Express, aborting\n");
		rc = -EIO;
		goto err_out_release;
	}

	rc = bnx2x_set_coherency_mask(bp);
	if (rc)
		goto err_out_release;

	dev->mem_start = pci_resource_start(pdev, 0);
	dev->base_addr = dev->mem_start;
	dev->mem_end = pci_resource_end(pdev, 0);

	dev->irq = pdev->irq;

	bp->regview = pci_ioremap_bar(pdev, 0);
	if (!bp->regview) {
		dev_err(&bp->pdev->dev,
			"Cannot map register space, aborting\n");
		rc = -ENOMEM;
		goto err_out_release;
	}

	/* In E1/E1H use pci device function given by kernel.
	 * In E2/E3 read physical function from ME register since these chips
	 * support Physical Device Assignment where kernel BDF maybe arbitrary
	 * (depending on hypervisor).
	 */
	if (chip_is_e1x) {
		bp->pf_num = PCI_FUNC(pdev->devfn);
	} else {
		/* chip is E2/3*/
		pci_read_config_dword(bp->pdev,
				      PCICFG_ME_REGISTER, &pci_cfg_dword);
		bp->pf_num = (u8)((pci_cfg_dword & ME_REG_ABS_PF_NUM) >>
				  ME_REG_ABS_PF_NUM_SHIFT);
	}
	BNX2X_DEV_INFO("me reg PF num: %d\n", bp->pf_num);

	/* clean indirect addresses */
	pci_write_config_dword(bp->pdev, PCICFG_GRC_ADDRESS,
			       PCICFG_VENDOR_ID_OFFSET);

	/* Set PCIe reset type to fundamental for EEH recovery */
	pdev->needs_freset = 1;

	/* AER (Advanced Error reporting) configuration */
	rc = pci_enable_pcie_error_reporting(pdev);
	if (!rc)
		bp->flags |= AER_ENABLED;
	else
		BNX2X_DEV_INFO("Failed To configure PCIe AER [%d]\n", rc);

	/*
	 * Clean the following indirect addresses for all functions since it
	 * is not used by the driver.
	 */
	if (IS_PF(bp)) {
		REG_WR(bp, PXP2_REG_PGL_ADDR_88_F0, 0);
		REG_WR(bp, PXP2_REG_PGL_ADDR_8C_F0, 0);
		REG_WR(bp, PXP2_REG_PGL_ADDR_90_F0, 0);
		REG_WR(bp, PXP2_REG_PGL_ADDR_94_F0, 0);

		if (chip_is_e1x) {
			REG_WR(bp, PXP2_REG_PGL_ADDR_88_F1, 0);
			REG_WR(bp, PXP2_REG_PGL_ADDR_8C_F1, 0);
			REG_WR(bp, PXP2_REG_PGL_ADDR_90_F1, 0);
			REG_WR(bp, PXP2_REG_PGL_ADDR_94_F1, 0);
		}

		/* Enable internal target-read (in case we are probed after PF
		 * FLR). Must be done prior to any BAR read access. Only for
		 * 57712 and up
		 */
		if (!chip_is_e1x)
			REG_WR(bp,
			       PGLUE_B_REG_INTERNAL_PFID_ENABLE_TARGET_READ, 1);
	}

	dev->watchdog_timeo = TX_TIMEOUT;

	dev->netdev_ops = &bnx2x_netdev_ops;
	bnx2x_set_ethtool_ops(bp, dev);

	dev->priv_flags |= IFF_UNICAST_FLT;

	dev->hw_features = NETIF_F_SG | NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM |
		NETIF_F_TSO | NETIF_F_TSO_ECN | NETIF_F_TSO6 |
		NETIF_F_RXCSUM | NETIF_F_LRO | NETIF_F_GRO | NETIF_F_GRO_HW |
		NETIF_F_RXHASH | NETIF_F_HW_VLAN_CTAG_TX;
	if (!chip_is_e1x) {
		dev->hw_features |= NETIF_F_GSO_GRE | NETIF_F_GSO_GRE_CSUM |
				    NETIF_F_GSO_IPXIP4 |
				    NETIF_F_GSO_UDP_TUNNEL |
				    NETIF_F_GSO_UDP_TUNNEL_CSUM |
				    NETIF_F_GSO_PARTIAL;

		dev->hw_enc_features =
			NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM | NETIF_F_SG |
			NETIF_F_TSO | NETIF_F_TSO_ECN | NETIF_F_TSO6 |
			NETIF_F_GSO_IPXIP4 |
			NETIF_F_GSO_GRE | NETIF_F_GSO_GRE_CSUM |
			NETIF_F_GSO_UDP_TUNNEL | NETIF_F_GSO_UDP_TUNNEL_CSUM |
			NETIF_F_GSO_PARTIAL;

		dev->gso_partial_features = NETIF_F_GSO_GRE_CSUM |
					    NETIF_F_GSO_UDP_TUNNEL_CSUM;
	}

	dev->vlan_features = NETIF_F_SG | NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM |
		NETIF_F_TSO | NETIF_F_TSO_ECN | NETIF_F_TSO6 | NETIF_F_HIGHDMA;

	if (IS_PF(bp)) {
		if (chip_is_e1x)
			bp->accept_any_vlan = true;
		else
			dev->hw_features |= NETIF_F_HW_VLAN_CTAG_FILTER;
	}
	/* For VF we'll know whether to enable VLAN filtering after
	 * getting a response to CHANNEL_TLV_ACQUIRE from PF.
	 */

	dev->features |= dev->hw_features | NETIF_F_HW_VLAN_CTAG_RX;
	dev->features |= NETIF_F_HIGHDMA;
	if (dev->features & NETIF_F_LRO)
		dev->features &= ~NETIF_F_GRO_HW;

	/* Add Loopback capability to the device */
	dev->hw_features |= NETIF_F_LOOPBACK;

#ifdef BCM_DCBNL
	dev->dcbnl_ops = &bnx2x_dcbnl_ops;
#endif

	/* MTU range, 46 - 9600 */
	dev->min_mtu = ETH_MIN_PACKET_SIZE;
	dev->max_mtu = ETH_MAX_JUMBO_PACKET_SIZE;

	/* get_port_hwinfo() will set prtad and mmds properly */
	bp->mdio.prtad = MDIO_PRTAD_NONE;
	bp->mdio.mmds = 0;
	bp->mdio.mode_support = MDIO_SUPPORTS_C45 | MDIO_EMULATE_C22;
	bp->mdio.dev = dev;
	bp->mdio.mdio_read = bnx2x_mdio_read;
	bp->mdio.mdio_write = bnx2x_mdio_write;

	return 0;

err_out_release:
	if (atomic_read(&pdev->enable_cnt) == 1)
		pci_release_regions(pdev);

err_out_disable:
	pci_disable_device(pdev);

err_out:
	return rc;
}