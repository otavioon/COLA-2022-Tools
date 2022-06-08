#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  size_t u8 ;
typedef  int u16 ;
struct rtl_phy {int**** tx_power_by_rate_offset; } ;
struct rtl_priv {struct rtl_phy phy; } ;
struct ieee80211_hw {int dummy; } ;

/* Variables and functions */
 size_t BAND_ON_2_4G ; 
 size_t BAND_ON_5G ; 
 int /*<<< orphan*/  CCK ; 
 int /*<<< orphan*/  HT_MCS0_MCS7 ; 
 int /*<<< orphan*/  HT_MCS8_MCS15 ; 
 int /*<<< orphan*/  OFDM ; 
 size_t RF90_PATH_A ; 
 size_t RF90_PATH_B ; 
 size_t RF_1TX ; 
 size_t RF_2TX ; 
 int /*<<< orphan*/  VHT_1SSMCS0_1SSMCS9 ; 
 int /*<<< orphan*/  VHT_2SSMCS0_2SSMCS9 ; 
 int /*<<< orphan*/  _rtl8821ae_phy_set_txpower_by_rate_base (struct ieee80211_hw*,size_t,size_t,int /*<<< orphan*/ ,size_t,size_t) ; 
 struct rtl_priv* rtl_priv (struct ieee80211_hw*) ; 

__attribute__((used)) static void _rtl8821ae_phy_store_txpower_by_rate_base(struct ieee80211_hw *hw)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct rtl_phy *rtlphy = &rtlpriv->phy;
	u16 rawValue = 0;
	u8 base = 0, path = 0;

	for (path = RF90_PATH_A; path <= RF90_PATH_B; ++path) {
		rawValue = (u16)(rtlphy->tx_power_by_rate_offset[BAND_ON_2_4G][path][RF_1TX][0] >> 24) & 0xFF;
		base = (rawValue >> 4) * 10 + (rawValue & 0xF);
		_rtl8821ae_phy_set_txpower_by_rate_base(hw, BAND_ON_2_4G, path, CCK, RF_1TX, base);

		rawValue = (u16)(rtlphy->tx_power_by_rate_offset[BAND_ON_2_4G][path][RF_1TX][2] >> 24) & 0xFF;
		base = (rawValue >> 4) * 10 + (rawValue & 0xF);
		_rtl8821ae_phy_set_txpower_by_rate_base(hw, BAND_ON_2_4G, path, OFDM, RF_1TX, base);

		rawValue = (u16)(rtlphy->tx_power_by_rate_offset[BAND_ON_2_4G][path][RF_1TX][4] >> 24) & 0xFF;
		base = (rawValue >> 4) * 10 + (rawValue & 0xF);
		_rtl8821ae_phy_set_txpower_by_rate_base(hw, BAND_ON_2_4G, path, HT_MCS0_MCS7, RF_1TX, base);

		rawValue = (u16)(rtlphy->tx_power_by_rate_offset[BAND_ON_2_4G][path][RF_2TX][6] >> 24) & 0xFF;
		base = (rawValue >> 4) * 10 + (rawValue & 0xF);
		_rtl8821ae_phy_set_txpower_by_rate_base(hw, BAND_ON_2_4G, path, HT_MCS8_MCS15, RF_2TX, base);

		rawValue = (u16)(rtlphy->tx_power_by_rate_offset[BAND_ON_2_4G][path][RF_1TX][8] >> 24) & 0xFF;
		base = (rawValue >> 4) * 10 + (rawValue & 0xF);
		_rtl8821ae_phy_set_txpower_by_rate_base(hw, BAND_ON_2_4G, path, VHT_1SSMCS0_1SSMCS9, RF_1TX, base);

		rawValue = (u16)(rtlphy->tx_power_by_rate_offset[BAND_ON_2_4G][path][RF_2TX][11] >> 8) & 0xFF;
		base = (rawValue >> 4) * 10 + (rawValue & 0xF);
		_rtl8821ae_phy_set_txpower_by_rate_base(hw, BAND_ON_2_4G, path, VHT_2SSMCS0_2SSMCS9, RF_2TX, base);

		rawValue = (u16)(rtlphy->tx_power_by_rate_offset[BAND_ON_5G][path][RF_1TX][2] >> 24) & 0xFF;
		base = (rawValue >> 4) * 10 + (rawValue & 0xF);
		_rtl8821ae_phy_set_txpower_by_rate_base(hw, BAND_ON_5G, path, OFDM, RF_1TX, base);

		rawValue = (u16)(rtlphy->tx_power_by_rate_offset[BAND_ON_5G][path][RF_1TX][4] >> 24) & 0xFF;
		base = (rawValue >> 4) * 10 + (rawValue & 0xF);
		_rtl8821ae_phy_set_txpower_by_rate_base(hw, BAND_ON_5G, path, HT_MCS0_MCS7, RF_1TX, base);

		rawValue = (u16)(rtlphy->tx_power_by_rate_offset[BAND_ON_5G][path][RF_2TX][6] >> 24) & 0xFF;
		base = (rawValue >> 4) * 10 + (rawValue & 0xF);
		_rtl8821ae_phy_set_txpower_by_rate_base(hw, BAND_ON_5G, path, HT_MCS8_MCS15, RF_2TX, base);

		rawValue = (u16)(rtlphy->tx_power_by_rate_offset[BAND_ON_5G][path][RF_1TX][8] >> 24) & 0xFF;
		base = (rawValue >> 4) * 10 + (rawValue & 0xF);
		_rtl8821ae_phy_set_txpower_by_rate_base(hw, BAND_ON_5G, path, VHT_1SSMCS0_1SSMCS9, RF_1TX, base);

		rawValue = (u16)(rtlphy->tx_power_by_rate_offset[BAND_ON_5G][path][RF_2TX][11] >> 8) & 0xFF;
		base = (rawValue >> 4) * 10 + (rawValue & 0xF);
		_rtl8821ae_phy_set_txpower_by_rate_base(hw, BAND_ON_5G, path, VHT_2SSMCS0_2SSMCS9, RF_2TX, base);
	}
}