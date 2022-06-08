#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_8__ ;
typedef  struct TYPE_16__   TYPE_5__ ;
typedef  struct TYPE_15__   TYPE_4__ ;
typedef  struct TYPE_14__   TYPE_3__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
struct TYPE_17__ {struct clk_init_data* init; } ;
struct TYPE_12__ {TYPE_8__ hw; struct vc5_driver_data* vc5; scalar_t__ num; } ;
struct vc5_driver_data {void* pin_xin; TYPE_4__* chip_info; TYPE_3__* clk_out; TYPE_2__* clk_fod; TYPE_1__ clk_pll; TYPE_8__ clk_pfd; TYPE_8__ clk_mul; TYPE_8__ clk_mux; void* pin_clkin; int /*<<< orphan*/  clk_mux_ins; void* regmap; struct i2c_client* client; } ;
struct i2c_device_id {int dummy; } ;
struct TYPE_16__ {int /*<<< orphan*/  of_node; } ;
struct i2c_client {TYPE_5__ dev; } ;
struct clk_init_data {int num_parents; char const** parent_names; void* name; void* flags; int /*<<< orphan*/ * ops; } ;
typedef  int /*<<< orphan*/  init ;
struct TYPE_15__ {int flags; unsigned int clk_fod_cnt; unsigned int clk_out_cnt; int /*<<< orphan*/  model; } ;
struct TYPE_14__ {unsigned int num; TYPE_8__ hw; struct vc5_driver_data* vc5; } ;
struct TYPE_13__ {unsigned int num; TYPE_8__ hw; struct vc5_driver_data* vc5; } ;

/* Variables and functions */
 void* CLK_SET_RATE_PARENT ; 
 int EINVAL ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (void*) ; 
 int PTR_ERR (void*) ; 
 int VC5_HAS_INTERNAL_XTAL ; 
 int VC5_HAS_PFD_FREQ_DBL ; 
 int /*<<< orphan*/  VC5_MUX_IN_CLKIN ; 
 int /*<<< orphan*/  VC5_MUX_IN_XIN ; 
 char* __clk_get_name (void*) ; 
 void* clk_register_fixed_rate (TYPE_5__*,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  clk_unregister_fixed_rate (void*) ; 
 int /*<<< orphan*/  dev_err (TYPE_5__*,char*,...) ; 
 void* devm_clk_get (TYPE_5__*,char*) ; 
 int devm_clk_hw_register (TYPE_5__*,TYPE_8__*) ; 
 struct vc5_driver_data* devm_kzalloc (TYPE_5__*,int,int /*<<< orphan*/ ) ; 
 void* devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct vc5_driver_data*) ; 
 int /*<<< orphan*/  memset (struct clk_init_data*,int /*<<< orphan*/ ,int) ; 
 int of_clk_add_hw_provider (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct vc5_driver_data*) ; 
 TYPE_4__* of_device_get_match_data (TYPE_5__*) ; 
 void** vc5_clk_out_names ; 
 int /*<<< orphan*/  vc5_clk_out_ops ; 
 void** vc5_dbl_names ; 
 int /*<<< orphan*/  vc5_dbl_ops ; 
 void** vc5_fod_names ; 
 int /*<<< orphan*/  vc5_fod_ops ; 
 unsigned int vc5_map_index_to_output (int /*<<< orphan*/ ,unsigned int) ; 
 void** vc5_mux_names ; 
 int /*<<< orphan*/  vc5_mux_ops ; 
 int /*<<< orphan*/  vc5_of_clk_get ; 
 void** vc5_pfd_names ; 
 int /*<<< orphan*/  vc5_pfd_ops ; 
 void** vc5_pll_names ; 
 int /*<<< orphan*/  vc5_pll_ops ; 
 int /*<<< orphan*/  vc5_regmap_config ; 

__attribute__((used)) static int vc5_probe(struct i2c_client *client,
		     const struct i2c_device_id *id)
{
	struct vc5_driver_data *vc5;
	struct clk_init_data init;
	const char *parent_names[2];
	unsigned int n, idx = 0;
	int ret;

	vc5 = devm_kzalloc(&client->dev, sizeof(*vc5), GFP_KERNEL);
	if (vc5 == NULL)
		return -ENOMEM;

	i2c_set_clientdata(client, vc5);
	vc5->client = client;
	vc5->chip_info = of_device_get_match_data(&client->dev);

	vc5->pin_xin = devm_clk_get(&client->dev, "xin");
	if (PTR_ERR(vc5->pin_xin) == -EPROBE_DEFER)
		return -EPROBE_DEFER;

	vc5->pin_clkin = devm_clk_get(&client->dev, "clkin");
	if (PTR_ERR(vc5->pin_clkin) == -EPROBE_DEFER)
		return -EPROBE_DEFER;

	vc5->regmap = devm_regmap_init_i2c(client, &vc5_regmap_config);
	if (IS_ERR(vc5->regmap)) {
		dev_err(&client->dev, "failed to allocate register map\n");
		return PTR_ERR(vc5->regmap);
	}

	/* Register clock input mux */
	memset(&init, 0, sizeof(init));

	if (!IS_ERR(vc5->pin_xin)) {
		vc5->clk_mux_ins |= VC5_MUX_IN_XIN;
		parent_names[init.num_parents++] = __clk_get_name(vc5->pin_xin);
	} else if (vc5->chip_info->flags & VC5_HAS_INTERNAL_XTAL) {
		vc5->pin_xin = clk_register_fixed_rate(&client->dev,
						       "internal-xtal", NULL,
						       0, 25000000);
		if (IS_ERR(vc5->pin_xin))
			return PTR_ERR(vc5->pin_xin);
		vc5->clk_mux_ins |= VC5_MUX_IN_XIN;
		parent_names[init.num_parents++] = __clk_get_name(vc5->pin_xin);
	}

	if (!IS_ERR(vc5->pin_clkin)) {
		vc5->clk_mux_ins |= VC5_MUX_IN_CLKIN;
		parent_names[init.num_parents++] =
			__clk_get_name(vc5->pin_clkin);
	}

	if (!init.num_parents) {
		dev_err(&client->dev, "no input clock specified!\n");
		return -EINVAL;
	}

	init.name = vc5_mux_names[0];
	init.ops = &vc5_mux_ops;
	init.flags = 0;
	init.parent_names = parent_names;
	vc5->clk_mux.init = &init;
	ret = devm_clk_hw_register(&client->dev, &vc5->clk_mux);
	if (ret) {
		dev_err(&client->dev, "unable to register %s\n", init.name);
		goto err_clk;
	}

	if (vc5->chip_info->flags & VC5_HAS_PFD_FREQ_DBL) {
		/* Register frequency doubler */
		memset(&init, 0, sizeof(init));
		init.name = vc5_dbl_names[0];
		init.ops = &vc5_dbl_ops;
		init.flags = CLK_SET_RATE_PARENT;
		init.parent_names = vc5_mux_names;
		init.num_parents = 1;
		vc5->clk_mul.init = &init;
		ret = devm_clk_hw_register(&client->dev, &vc5->clk_mul);
		if (ret) {
			dev_err(&client->dev, "unable to register %s\n",
				init.name);
			goto err_clk;
		}
	}

	/* Register PFD */
	memset(&init, 0, sizeof(init));
	init.name = vc5_pfd_names[0];
	init.ops = &vc5_pfd_ops;
	init.flags = CLK_SET_RATE_PARENT;
	if (vc5->chip_info->flags & VC5_HAS_PFD_FREQ_DBL)
		init.parent_names = vc5_dbl_names;
	else
		init.parent_names = vc5_mux_names;
	init.num_parents = 1;
	vc5->clk_pfd.init = &init;
	ret = devm_clk_hw_register(&client->dev, &vc5->clk_pfd);
	if (ret) {
		dev_err(&client->dev, "unable to register %s\n", init.name);
		goto err_clk;
	}

	/* Register PLL */
	memset(&init, 0, sizeof(init));
	init.name = vc5_pll_names[0];
	init.ops = &vc5_pll_ops;
	init.flags = CLK_SET_RATE_PARENT;
	init.parent_names = vc5_pfd_names;
	init.num_parents = 1;
	vc5->clk_pll.num = 0;
	vc5->clk_pll.vc5 = vc5;
	vc5->clk_pll.hw.init = &init;
	ret = devm_clk_hw_register(&client->dev, &vc5->clk_pll.hw);
	if (ret) {
		dev_err(&client->dev, "unable to register %s\n", init.name);
		goto err_clk;
	}

	/* Register FODs */
	for (n = 0; n < vc5->chip_info->clk_fod_cnt; n++) {
		idx = vc5_map_index_to_output(vc5->chip_info->model, n);
		memset(&init, 0, sizeof(init));
		init.name = vc5_fod_names[idx];
		init.ops = &vc5_fod_ops;
		init.flags = CLK_SET_RATE_PARENT;
		init.parent_names = vc5_pll_names;
		init.num_parents = 1;
		vc5->clk_fod[n].num = idx;
		vc5->clk_fod[n].vc5 = vc5;
		vc5->clk_fod[n].hw.init = &init;
		ret = devm_clk_hw_register(&client->dev, &vc5->clk_fod[n].hw);
		if (ret) {
			dev_err(&client->dev, "unable to register %s\n",
				init.name);
			goto err_clk;
		}
	}

	/* Register MUX-connected OUT0_I2C_SELB output */
	memset(&init, 0, sizeof(init));
	init.name = vc5_clk_out_names[0];
	init.ops = &vc5_clk_out_ops;
	init.flags = CLK_SET_RATE_PARENT;
	init.parent_names = vc5_mux_names;
	init.num_parents = 1;
	vc5->clk_out[0].num = idx;
	vc5->clk_out[0].vc5 = vc5;
	vc5->clk_out[0].hw.init = &init;
	ret = devm_clk_hw_register(&client->dev, &vc5->clk_out[0].hw);
	if (ret) {
		dev_err(&client->dev, "unable to register %s\n",
			init.name);
		goto err_clk;
	}

	/* Register FOD-connected OUTx outputs */
	for (n = 1; n < vc5->chip_info->clk_out_cnt; n++) {
		idx = vc5_map_index_to_output(vc5->chip_info->model, n - 1);
		parent_names[0] = vc5_fod_names[idx];
		if (n == 1)
			parent_names[1] = vc5_mux_names[0];
		else
			parent_names[1] = vc5_clk_out_names[n - 1];

		memset(&init, 0, sizeof(init));
		init.name = vc5_clk_out_names[idx + 1];
		init.ops = &vc5_clk_out_ops;
		init.flags = CLK_SET_RATE_PARENT;
		init.parent_names = parent_names;
		init.num_parents = 2;
		vc5->clk_out[n].num = idx;
		vc5->clk_out[n].vc5 = vc5;
		vc5->clk_out[n].hw.init = &init;
		ret = devm_clk_hw_register(&client->dev,
					   &vc5->clk_out[n].hw);
		if (ret) {
			dev_err(&client->dev, "unable to register %s\n",
				init.name);
			goto err_clk;
		}
	}

	ret = of_clk_add_hw_provider(client->dev.of_node, vc5_of_clk_get, vc5);
	if (ret) {
		dev_err(&client->dev, "unable to add clk provider\n");
		goto err_clk;
	}

	return 0;

err_clk:
	if (vc5->chip_info->flags & VC5_HAS_INTERNAL_XTAL)
		clk_unregister_fixed_rate(vc5->pin_xin);
	return ret;
}