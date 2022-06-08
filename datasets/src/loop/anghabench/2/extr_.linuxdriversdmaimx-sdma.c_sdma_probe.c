#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_4__ ;
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;

/* Type definitions */
struct sdma_platform_data {char const* fw_name; scalar_t__ script_addrs; } ;
struct TYPE_18__ {TYPE_4__* dev; int /*<<< orphan*/  device_issue_pending; int /*<<< orphan*/  device_prep_dma_memcpy; int /*<<< orphan*/  residue_granularity; int /*<<< orphan*/  directions; void* dst_addr_widths; void* src_addr_widths; int /*<<< orphan*/  device_synchronize; int /*<<< orphan*/  device_terminate_all; int /*<<< orphan*/  device_config; int /*<<< orphan*/  device_prep_dma_cyclic; int /*<<< orphan*/  device_prep_slave_sg; int /*<<< orphan*/  device_tx_status; int /*<<< orphan*/  device_free_chan_resources; int /*<<< orphan*/  device_alloc_chan_resources; int /*<<< orphan*/  channels; int /*<<< orphan*/  cap_mask; } ;
struct sdma_engine {int irq; void* clk_ipg; void* clk_ahb; int /*<<< orphan*/ * script_addrs; TYPE_3__ dma_device; int /*<<< orphan*/  spba_end_addr; int /*<<< orphan*/  spba_start_addr; int /*<<< orphan*/  dma_parms; struct sdma_driver_data const* drvdata; struct sdma_channel* channel; void* regs; TYPE_4__* dev; int /*<<< orphan*/  channel_0_lock; } ;
struct sdma_driver_data {scalar_t__ script_addrs; } ;
struct TYPE_17__ {int /*<<< orphan*/  desc_free; } ;
struct sdma_channel {int channel; TYPE_2__ vc; int /*<<< orphan*/  terminate_worker; struct sdma_engine* sdma; } ;
struct resource {int /*<<< orphan*/  end; int /*<<< orphan*/  start; } ;
struct TYPE_19__ {int /*<<< orphan*/ * dma_parms; struct device_node* of_node; } ;
struct platform_device {TYPE_4__ dev; TYPE_1__* id_entry; } ;
struct of_device_id {struct sdma_driver_data* data; } ;
struct device_node {int dummy; } ;
typedef  int s32 ;
struct TYPE_16__ {int /*<<< orphan*/ * driver_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  DMA_BIT_MASK (int) ; 
 int /*<<< orphan*/  DMA_CYCLIC ; 
 int /*<<< orphan*/  DMA_MEMCPY ; 
 int /*<<< orphan*/  DMA_RESIDUE_GRANULARITY_SEGMENT ; 
 int /*<<< orphan*/  DMA_SLAVE ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  INIT_WORK (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (void*) ; 
 int MAX_DMA_CHANNELS ; 
 int PTR_ERR (void*) ; 
 int /*<<< orphan*/  SDMA_BD_MAX_CNT ; 
 void* SDMA_DMA_BUSWIDTHS ; 
 int /*<<< orphan*/  SDMA_DMA_DIRECTIONS ; 
 int SDMA_SCRIPT_ADDRS_ARRAY_SIZE_V1 ; 
 int clk_prepare (void*) ; 
 int /*<<< orphan*/  clk_unprepare (void*) ; 
 int /*<<< orphan*/  dev_err (TYPE_4__*,char*) ; 
 struct sdma_platform_data* dev_get_platdata (TYPE_4__*) ; 
 int /*<<< orphan*/  dev_warn (TYPE_4__*,char*) ; 
 void* devm_clk_get (TYPE_4__*,char*) ; 
 void* devm_ioremap_resource (TYPE_4__*,struct resource*) ; 
 struct sdma_engine* devm_kzalloc (TYPE_4__*,int,int /*<<< orphan*/ ) ; 
 int devm_request_irq (TYPE_4__*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,struct sdma_engine*) ; 
 int dma_async_device_register (TYPE_3__*) ; 
 int /*<<< orphan*/  dma_async_device_unregister (TYPE_3__*) ; 
 int /*<<< orphan*/  dma_cap_set (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int dma_coerce_mask_and_coherent (TYPE_4__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_set_max_seg_size (TYPE_4__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * kzalloc (int,int /*<<< orphan*/ ) ; 
 int of_address_to_resource (struct device_node*,int /*<<< orphan*/ ,struct resource*) ; 
 int of_dma_controller_register (struct device_node*,int /*<<< orphan*/ ,struct sdma_engine*) ; 
 struct device_node* of_find_compatible_node (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*) ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,TYPE_4__*) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 int of_property_read_string (struct device_node*,char*,char const**) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct sdma_engine*) ; 
 int /*<<< orphan*/  sdma_add_scripts (struct sdma_engine*,scalar_t__) ; 
 int /*<<< orphan*/  sdma_alloc_chan_resources ; 
 int /*<<< orphan*/  sdma_channel_synchronize ; 
 int /*<<< orphan*/  sdma_channel_terminate_work ; 
 int /*<<< orphan*/  sdma_config ; 
 int /*<<< orphan*/  sdma_desc_free ; 
 int /*<<< orphan*/  sdma_disable_channel_async ; 
 int /*<<< orphan*/  sdma_dt_ids ; 
 int sdma_event_remap (struct sdma_engine*) ; 
 int /*<<< orphan*/  sdma_free_chan_resources ; 
 int sdma_get_firmware (struct sdma_engine*,char const*) ; 
 int sdma_init (struct sdma_engine*) ; 
 int /*<<< orphan*/  sdma_int_handler ; 
 int /*<<< orphan*/  sdma_issue_pending ; 
 int /*<<< orphan*/  sdma_prep_dma_cyclic ; 
 int /*<<< orphan*/  sdma_prep_memcpy ; 
 int /*<<< orphan*/  sdma_prep_slave_sg ; 
 int /*<<< orphan*/  sdma_tx_status ; 
 int /*<<< orphan*/  sdma_xlate ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vchan_init (TYPE_2__*,TYPE_3__*) ; 

__attribute__((used)) static int sdma_probe(struct platform_device *pdev)
{
	const struct of_device_id *of_id =
			of_match_device(sdma_dt_ids, &pdev->dev);
	struct device_node *np = pdev->dev.of_node;
	struct device_node *spba_bus;
	const char *fw_name;
	int ret;
	int irq;
	struct resource *iores;
	struct resource spba_res;
	struct sdma_platform_data *pdata = dev_get_platdata(&pdev->dev);
	int i;
	struct sdma_engine *sdma;
	s32 *saddr_arr;
	const struct sdma_driver_data *drvdata = NULL;

	if (of_id)
		drvdata = of_id->data;
	else if (pdev->id_entry)
		drvdata = (void *)pdev->id_entry->driver_data;

	if (!drvdata) {
		dev_err(&pdev->dev, "unable to find driver data\n");
		return -EINVAL;
	}

	ret = dma_coerce_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(32));
	if (ret)
		return ret;

	sdma = devm_kzalloc(&pdev->dev, sizeof(*sdma), GFP_KERNEL);
	if (!sdma)
		return -ENOMEM;

	spin_lock_init(&sdma->channel_0_lock);

	sdma->dev = &pdev->dev;
	sdma->drvdata = drvdata;

	irq = platform_get_irq(pdev, 0);
	if (irq < 0)
		return irq;

	iores = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	sdma->regs = devm_ioremap_resource(&pdev->dev, iores);
	if (IS_ERR(sdma->regs))
		return PTR_ERR(sdma->regs);

	sdma->clk_ipg = devm_clk_get(&pdev->dev, "ipg");
	if (IS_ERR(sdma->clk_ipg))
		return PTR_ERR(sdma->clk_ipg);

	sdma->clk_ahb = devm_clk_get(&pdev->dev, "ahb");
	if (IS_ERR(sdma->clk_ahb))
		return PTR_ERR(sdma->clk_ahb);

	ret = clk_prepare(sdma->clk_ipg);
	if (ret)
		return ret;

	ret = clk_prepare(sdma->clk_ahb);
	if (ret)
		goto err_clk;

	ret = devm_request_irq(&pdev->dev, irq, sdma_int_handler, 0, "sdma",
			       sdma);
	if (ret)
		goto err_irq;

	sdma->irq = irq;

	sdma->script_addrs = kzalloc(sizeof(*sdma->script_addrs), GFP_KERNEL);
	if (!sdma->script_addrs) {
		ret = -ENOMEM;
		goto err_irq;
	}

	/* initially no scripts available */
	saddr_arr = (s32 *)sdma->script_addrs;
	for (i = 0; i < SDMA_SCRIPT_ADDRS_ARRAY_SIZE_V1; i++)
		saddr_arr[i] = -EINVAL;

	dma_cap_set(DMA_SLAVE, sdma->dma_device.cap_mask);
	dma_cap_set(DMA_CYCLIC, sdma->dma_device.cap_mask);
	dma_cap_set(DMA_MEMCPY, sdma->dma_device.cap_mask);

	INIT_LIST_HEAD(&sdma->dma_device.channels);
	/* Initialize channel parameters */
	for (i = 0; i < MAX_DMA_CHANNELS; i++) {
		struct sdma_channel *sdmac = &sdma->channel[i];

		sdmac->sdma = sdma;

		sdmac->channel = i;
		sdmac->vc.desc_free = sdma_desc_free;
		INIT_WORK(&sdmac->terminate_worker,
				sdma_channel_terminate_work);
		/*
		 * Add the channel to the DMAC list. Do not add channel 0 though
		 * because we need it internally in the SDMA driver. This also means
		 * that channel 0 in dmaengine counting matches sdma channel 1.
		 */
		if (i)
			vchan_init(&sdmac->vc, &sdma->dma_device);
	}

	ret = sdma_init(sdma);
	if (ret)
		goto err_init;

	ret = sdma_event_remap(sdma);
	if (ret)
		goto err_init;

	if (sdma->drvdata->script_addrs)
		sdma_add_scripts(sdma, sdma->drvdata->script_addrs);
	if (pdata && pdata->script_addrs)
		sdma_add_scripts(sdma, pdata->script_addrs);

	if (pdata) {
		ret = sdma_get_firmware(sdma, pdata->fw_name);
		if (ret)
			dev_warn(&pdev->dev, "failed to get firmware from platform data\n");
	} else {
		/*
		 * Because that device tree does not encode ROM script address,
		 * the RAM script in firmware is mandatory for device tree
		 * probe, otherwise it fails.
		 */
		ret = of_property_read_string(np, "fsl,sdma-ram-script-name",
					      &fw_name);
		if (ret)
			dev_warn(&pdev->dev, "failed to get firmware name\n");
		else {
			ret = sdma_get_firmware(sdma, fw_name);
			if (ret)
				dev_warn(&pdev->dev, "failed to get firmware from device tree\n");
		}
	}

	sdma->dma_device.dev = &pdev->dev;

	sdma->dma_device.device_alloc_chan_resources = sdma_alloc_chan_resources;
	sdma->dma_device.device_free_chan_resources = sdma_free_chan_resources;
	sdma->dma_device.device_tx_status = sdma_tx_status;
	sdma->dma_device.device_prep_slave_sg = sdma_prep_slave_sg;
	sdma->dma_device.device_prep_dma_cyclic = sdma_prep_dma_cyclic;
	sdma->dma_device.device_config = sdma_config;
	sdma->dma_device.device_terminate_all = sdma_disable_channel_async;
	sdma->dma_device.device_synchronize = sdma_channel_synchronize;
	sdma->dma_device.src_addr_widths = SDMA_DMA_BUSWIDTHS;
	sdma->dma_device.dst_addr_widths = SDMA_DMA_BUSWIDTHS;
	sdma->dma_device.directions = SDMA_DMA_DIRECTIONS;
	sdma->dma_device.residue_granularity = DMA_RESIDUE_GRANULARITY_SEGMENT;
	sdma->dma_device.device_prep_dma_memcpy = sdma_prep_memcpy;
	sdma->dma_device.device_issue_pending = sdma_issue_pending;
	sdma->dma_device.dev->dma_parms = &sdma->dma_parms;
	dma_set_max_seg_size(sdma->dma_device.dev, SDMA_BD_MAX_CNT);

	platform_set_drvdata(pdev, sdma);

	ret = dma_async_device_register(&sdma->dma_device);
	if (ret) {
		dev_err(&pdev->dev, "unable to register\n");
		goto err_init;
	}

	if (np) {
		ret = of_dma_controller_register(np, sdma_xlate, sdma);
		if (ret) {
			dev_err(&pdev->dev, "failed to register controller\n");
			goto err_register;
		}

		spba_bus = of_find_compatible_node(NULL, NULL, "fsl,spba-bus");
		ret = of_address_to_resource(spba_bus, 0, &spba_res);
		if (!ret) {
			sdma->spba_start_addr = spba_res.start;
			sdma->spba_end_addr = spba_res.end;
		}
		of_node_put(spba_bus);
	}

	return 0;

err_register:
	dma_async_device_unregister(&sdma->dma_device);
err_init:
	kfree(sdma->script_addrs);
err_irq:
	clk_unprepare(sdma->clk_ahb);
err_clk:
	clk_unprepare(sdma->clk_ipg);
	return ret;
}