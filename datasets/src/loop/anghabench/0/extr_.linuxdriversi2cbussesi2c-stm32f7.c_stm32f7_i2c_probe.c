#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct stm32f7_i2c_setup {int rise_time; int fall_time; } ;
struct TYPE_13__ {struct device_node* of_node; TYPE_2__* parent; } ;
struct i2c_adapter {int timeout; int retries; int /*<<< orphan*/  nr; TYPE_1__ dev; int /*<<< orphan*/ * algo; int /*<<< orphan*/  owner; int /*<<< orphan*/  name; } ;
struct stm32f7_i2c_dev {struct reset_control* clk; TYPE_2__* dev; int /*<<< orphan*/  dma; int /*<<< orphan*/  complete; struct i2c_adapter adap; struct stm32f7_i2c_setup setup; void* speed; struct reset_control* base; } ;
struct resource {int start; } ;
struct reset_control {int dummy; } ;
struct TYPE_14__ {struct device_node* of_node; } ;
struct platform_device {TYPE_2__ dev; int /*<<< orphan*/  name; } ;
struct device_node {int dummy; } ;
typedef  scalar_t__ dma_addr_t ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQF_ONESHOT ; 
 scalar_t__ IS_ERR (struct reset_control*) ; 
 int PTR_ERR (struct reset_control*) ; 
 int /*<<< orphan*/  STM32F7_I2C_RXDR ; 
 int /*<<< orphan*/  STM32F7_I2C_TXDR ; 
 void* STM32_I2C_SPEED_FAST ; 
 void* STM32_I2C_SPEED_FAST_PLUS ; 
 void* STM32_I2C_SPEED_STANDARD ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  clk_disable (struct reset_control*) ; 
 int /*<<< orphan*/  clk_disable_unprepare (struct reset_control*) ; 
 int clk_prepare_enable (struct reset_control*) ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,...) ; 
 int /*<<< orphan*/  dev_info (TYPE_2__*,char*,int /*<<< orphan*/ ) ; 
 int device_property_read_u32 (TYPE_2__*,char*,int*) ; 
 struct reset_control* devm_clk_get (TYPE_2__*,int /*<<< orphan*/ *) ; 
 struct reset_control* devm_ioremap_resource (TYPE_2__*,struct resource*) ; 
 struct stm32f7_i2c_dev* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 int devm_request_irq (TYPE_2__*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct stm32f7_i2c_dev*) ; 
 int devm_request_threaded_irq (TYPE_2__*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct stm32f7_i2c_dev*) ; 
 struct reset_control* devm_reset_control_get (TYPE_2__*,int /*<<< orphan*/ *) ; 
 int i2c_add_adapter (struct i2c_adapter*) ; 
 int /*<<< orphan*/  i2c_set_adapdata (struct i2c_adapter*,struct stm32f7_i2c_dev*) ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 int irq_of_parse_and_map (struct device_node*,int) ; 
 struct stm32f7_i2c_setup* of_device_get_match_data (TYPE_2__*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct stm32f7_i2c_dev*) ; 
 int /*<<< orphan*/  reset_control_assert (struct reset_control*) ; 
 int /*<<< orphan*/  reset_control_deassert (struct reset_control*) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,int*) ; 
 int /*<<< orphan*/  stm32_i2c_dma_request (TYPE_2__*,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stm32f7_i2c_algo ; 
 int /*<<< orphan*/  stm32f7_i2c_hw_config (struct stm32f7_i2c_dev*) ; 
 int /*<<< orphan*/  stm32f7_i2c_isr_error ; 
 int /*<<< orphan*/  stm32f7_i2c_isr_event ; 
 int /*<<< orphan*/  stm32f7_i2c_isr_event_thread ; 
 int stm32f7_i2c_setup_timing (struct stm32f7_i2c_dev*,struct stm32f7_i2c_setup*) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static int stm32f7_i2c_probe(struct platform_device *pdev)
{
	struct device_node *np = pdev->dev.of_node;
	struct stm32f7_i2c_dev *i2c_dev;
	const struct stm32f7_i2c_setup *setup;
	struct resource *res;
	u32 irq_error, irq_event, clk_rate, rise_time, fall_time;
	struct i2c_adapter *adap;
	struct reset_control *rst;
	dma_addr_t phy_addr;
	int ret;

	i2c_dev = devm_kzalloc(&pdev->dev, sizeof(*i2c_dev), GFP_KERNEL);
	if (!i2c_dev)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	i2c_dev->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(i2c_dev->base))
		return PTR_ERR(i2c_dev->base);
	phy_addr = (dma_addr_t)res->start;

	irq_event = irq_of_parse_and_map(np, 0);
	if (!irq_event) {
		dev_err(&pdev->dev, "IRQ event missing or invalid\n");
		return -EINVAL;
	}

	irq_error = irq_of_parse_and_map(np, 1);
	if (!irq_error) {
		dev_err(&pdev->dev, "IRQ error missing or invalid\n");
		return -EINVAL;
	}

	i2c_dev->clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(i2c_dev->clk)) {
		dev_err(&pdev->dev, "Error: Missing controller clock\n");
		return PTR_ERR(i2c_dev->clk);
	}
	ret = clk_prepare_enable(i2c_dev->clk);
	if (ret) {
		dev_err(&pdev->dev, "Failed to prepare_enable clock\n");
		return ret;
	}

	i2c_dev->speed = STM32_I2C_SPEED_STANDARD;
	ret = device_property_read_u32(&pdev->dev, "clock-frequency",
				       &clk_rate);
	if (!ret && clk_rate >= 1000000)
		i2c_dev->speed = STM32_I2C_SPEED_FAST_PLUS;
	else if (!ret && clk_rate >= 400000)
		i2c_dev->speed = STM32_I2C_SPEED_FAST;
	else if (!ret && clk_rate >= 100000)
		i2c_dev->speed = STM32_I2C_SPEED_STANDARD;

	rst = devm_reset_control_get(&pdev->dev, NULL);
	if (IS_ERR(rst)) {
		dev_err(&pdev->dev, "Error: Missing controller reset\n");
		ret = PTR_ERR(rst);
		goto clk_free;
	}
	reset_control_assert(rst);
	udelay(2);
	reset_control_deassert(rst);

	i2c_dev->dev = &pdev->dev;

	ret = devm_request_threaded_irq(&pdev->dev, irq_event,
					stm32f7_i2c_isr_event,
					stm32f7_i2c_isr_event_thread,
					IRQF_ONESHOT,
					pdev->name, i2c_dev);
	if (ret) {
		dev_err(&pdev->dev, "Failed to request irq event %i\n",
			irq_event);
		goto clk_free;
	}

	ret = devm_request_irq(&pdev->dev, irq_error, stm32f7_i2c_isr_error, 0,
			       pdev->name, i2c_dev);
	if (ret) {
		dev_err(&pdev->dev, "Failed to request irq error %i\n",
			irq_error);
		goto clk_free;
	}

	setup = of_device_get_match_data(&pdev->dev);
	if (!setup) {
		dev_err(&pdev->dev, "Can't get device data\n");
		ret = -ENODEV;
		goto clk_free;
	}
	i2c_dev->setup = *setup;

	ret = device_property_read_u32(i2c_dev->dev, "i2c-scl-rising-time-ns",
				       &rise_time);
	if (!ret)
		i2c_dev->setup.rise_time = rise_time;

	ret = device_property_read_u32(i2c_dev->dev, "i2c-scl-falling-time-ns",
				       &fall_time);
	if (!ret)
		i2c_dev->setup.fall_time = fall_time;

	ret = stm32f7_i2c_setup_timing(i2c_dev, &i2c_dev->setup);
	if (ret)
		goto clk_free;

	stm32f7_i2c_hw_config(i2c_dev);

	adap = &i2c_dev->adap;
	i2c_set_adapdata(adap, i2c_dev);
	snprintf(adap->name, sizeof(adap->name), "STM32F7 I2C(%pa)",
		 &res->start);
	adap->owner = THIS_MODULE;
	adap->timeout = 2 * HZ;
	adap->retries = 3;
	adap->algo = &stm32f7_i2c_algo;
	adap->dev.parent = &pdev->dev;
	adap->dev.of_node = pdev->dev.of_node;

	init_completion(&i2c_dev->complete);

	/* Init DMA config if supported */
	i2c_dev->dma = stm32_i2c_dma_request(i2c_dev->dev, phy_addr,
					     STM32F7_I2C_TXDR,
					     STM32F7_I2C_RXDR);

	ret = i2c_add_adapter(adap);
	if (ret)
		goto clk_free;

	platform_set_drvdata(pdev, i2c_dev);

	clk_disable(i2c_dev->clk);

	dev_info(i2c_dev->dev, "STM32F7 I2C-%d bus adapter\n", adap->nr);

	return 0;

clk_free:
	clk_disable_unprepare(i2c_dev->clk);

	return ret;
}