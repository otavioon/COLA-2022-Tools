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
typedef  size_t u8 ;
typedef  int u32 ;
struct TYPE_2__ {scalar_t__ dynamic_txhighpower_lvl; } ;
struct rtl_phy {int** mcs_offset; int pwrgroup_cnt; int /*<<< orphan*/  current_chan_bw; } ;
struct rtl_priv {TYPE_1__ dm; struct rtl_phy phy; } ;
struct rtl_efuse {int eeprom_regulatory; int** pwrgroup_ht40; int** pwrgroup_ht20; } ;
struct ieee80211_hw {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  FPHY ; 
 int /*<<< orphan*/  HT_CHANNEL_WIDTH_20_40 ; 
 int /*<<< orphan*/  PHY_TXPWR ; 
 int /*<<< orphan*/  RTPRINT (struct rtl_priv*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,char,int) ; 
 scalar_t__ TXHIGHPWRLEVEL_BT1 ; 
 scalar_t__ TXHIGHPWRLEVEL_BT2 ; 
 struct rtl_efuse* rtl_efuse (struct rtl_priv*) ; 
 struct rtl_priv* rtl_priv (struct ieee80211_hw*) ; 

__attribute__((used)) static void _rtl92c_get_txpower_writeval_by_regulatory(struct ieee80211_hw *hw,
						       u8 channel, u8 index,
						       u32 *powerBase0,
						       u32 *powerBase1,
						       u32 *p_outwriteval)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct rtl_phy *rtlphy = &(rtlpriv->phy);
	struct rtl_efuse *rtlefuse = rtl_efuse(rtl_priv(hw));
	u8 i, chnlgroup = 0, pwr_diff_limit[4];
	u32 writeVal, customer_limit, rf;

	for (rf = 0; rf < 2; rf++) {
		switch (rtlefuse->eeprom_regulatory) {
		case 0:
			chnlgroup = 0;

			writeVal = rtlphy->mcs_offset[chnlgroup][index +
			    (rf ? 8 : 0)]
			    + ((index < 2) ? powerBase0[rf] : powerBase1[rf]);

			RTPRINT(rtlpriv, FPHY, PHY_TXPWR,
				"RTK better performance, writeVal(%c) = 0x%x\n",
				rf == 0 ? 'A' : 'B', writeVal);
			break;
		case 1:
			if (rtlphy->current_chan_bw == HT_CHANNEL_WIDTH_20_40) {
				writeVal = ((index < 2) ? powerBase0[rf] :
					    powerBase1[rf]);

				RTPRINT(rtlpriv, FPHY, PHY_TXPWR,
					"Realtek regulatory, 40MHz, writeVal(%c) = 0x%x\n",
					rf == 0 ? 'A' : 'B', writeVal);
			} else {
				if (rtlphy->pwrgroup_cnt == 1)
					chnlgroup = 0;
				if (rtlphy->pwrgroup_cnt >= 3) {
					if (channel <= 3)
						chnlgroup = 0;
					else if (channel >= 4 && channel <= 9)
						chnlgroup = 1;
					else if (channel > 9)
						chnlgroup = 2;
					if (rtlphy->pwrgroup_cnt == 4)
						chnlgroup++;
				}

				writeVal = rtlphy->mcs_offset[chnlgroup]
				    [index + (rf ? 8 : 0)] + ((index < 2) ?
							      powerBase0[rf] :
							      powerBase1[rf]);

				RTPRINT(rtlpriv, FPHY, PHY_TXPWR,
					"Realtek regulatory, 20MHz, writeVal(%c) = 0x%x\n",
					rf == 0 ? 'A' : 'B', writeVal);
			}
			break;
		case 2:
			writeVal =
			    ((index < 2) ? powerBase0[rf] : powerBase1[rf]);

			RTPRINT(rtlpriv, FPHY, PHY_TXPWR,
				"Better regulatory, writeVal(%c) = 0x%x\n",
				rf == 0 ? 'A' : 'B', writeVal);
			break;
		case 3:
			chnlgroup = 0;

			if (rtlphy->current_chan_bw == HT_CHANNEL_WIDTH_20_40) {
				RTPRINT(rtlpriv, FPHY, PHY_TXPWR,
					"customer's limit, 40MHz rf(%c) = 0x%x\n",
					rf == 0 ? 'A' : 'B',
					rtlefuse->pwrgroup_ht40[rf][channel -
								    1]);
			} else {
				RTPRINT(rtlpriv, FPHY, PHY_TXPWR,
					"customer's limit, 20MHz rf(%c) = 0x%x\n",
					rf == 0 ? 'A' : 'B',
					rtlefuse->pwrgroup_ht20[rf][channel -
								    1]);
			}
			for (i = 0; i < 4; i++) {
				pwr_diff_limit[i] = (u8) ((rtlphy->mcs_offset
					  [chnlgroup][index +
					  (rf ? 8 : 0)] & (0x7f << (i * 8))) >>
					  (i * 8));

				if (rtlphy->current_chan_bw ==
				    HT_CHANNEL_WIDTH_20_40) {
					if (pwr_diff_limit[i] >
					    rtlefuse->
					    pwrgroup_ht40[rf][channel - 1])
						pwr_diff_limit[i] =
						    rtlefuse->pwrgroup_ht40[rf]
						    [channel - 1];
				} else {
					if (pwr_diff_limit[i] >
					    rtlefuse->
					    pwrgroup_ht20[rf][channel - 1])
						pwr_diff_limit[i] =
						    rtlefuse->pwrgroup_ht20[rf]
						    [channel - 1];
				}
			}

			customer_limit = (pwr_diff_limit[3] << 24) |
			    (pwr_diff_limit[2] << 16) |
			    (pwr_diff_limit[1] << 8) | (pwr_diff_limit[0]);

			RTPRINT(rtlpriv, FPHY, PHY_TXPWR,
				"Customer's limit rf(%c) = 0x%x\n",
				rf == 0 ? 'A' : 'B', customer_limit);

			writeVal = customer_limit +
			    ((index < 2) ? powerBase0[rf] : powerBase1[rf]);

			RTPRINT(rtlpriv, FPHY, PHY_TXPWR,
				"Customer, writeVal rf(%c)= 0x%x\n",
				rf == 0 ? 'A' : 'B', writeVal);
			break;
		default:
			chnlgroup = 0;
			writeVal = rtlphy->mcs_offset[chnlgroup]
			    [index + (rf ? 8 : 0)]
			    + ((index < 2) ? powerBase0[rf] : powerBase1[rf]);

			RTPRINT(rtlpriv, FPHY, PHY_TXPWR,
				"RTK better performance, writeVal rf(%c) = 0x%x\n",
				rf == 0 ? 'A' : 'B', writeVal);
			break;
		}

		if (rtlpriv->dm.dynamic_txhighpower_lvl == TXHIGHPWRLEVEL_BT1)
			writeVal = writeVal - 0x06060606;
		else if (rtlpriv->dm.dynamic_txhighpower_lvl ==
			 TXHIGHPWRLEVEL_BT2)
			writeVal = writeVal - 0x0c0c0c0c;
		*(p_outwriteval + rf) = writeVal;
	}
}