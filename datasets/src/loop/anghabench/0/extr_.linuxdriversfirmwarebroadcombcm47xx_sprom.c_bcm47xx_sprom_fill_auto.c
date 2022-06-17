#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct ssb_sprom {int dummy; } ;
struct TYPE_8__ {int /*<<< orphan*/  a3; int /*<<< orphan*/  a2; int /*<<< orphan*/  a1; int /*<<< orphan*/  a0; } ;
struct TYPE_6__ {int /*<<< orphan*/  antswlut; int /*<<< orphan*/  tr_iso; int /*<<< orphan*/  pdet_range; int /*<<< orphan*/  extpa_gain; int /*<<< orphan*/  tssipos; } ;
struct TYPE_5__ {int /*<<< orphan*/  antswlut; int /*<<< orphan*/  tr_iso; int /*<<< orphan*/  pdet_range; int /*<<< orphan*/  extpa_gain; int /*<<< orphan*/  tssipos; } ;
struct TYPE_7__ {TYPE_2__ ghz5; TYPE_1__ ghz2; } ;

/* Variables and functions */
 int /*<<< orphan*/  ENTRY (int,int /*<<< orphan*/ ,char const*,char*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  ant_available_a ; 
 int /*<<< orphan*/  ant_available_bg ; 
 TYPE_4__ antenna_gain ; 
 int /*<<< orphan*/  antswitch ; 
 int /*<<< orphan*/  board_num ; 
 int /*<<< orphan*/  board_rev ; 
 int /*<<< orphan*/  board_type ; 
 int /*<<< orphan*/  boardflags ; 
 int /*<<< orphan*/  boardflags2 ; 
 int /*<<< orphan*/  boardflags3 ; 
 int /*<<< orphan*/  boardflags_lo ; 
 int /*<<< orphan*/  bw40po ; 
 int /*<<< orphan*/  bwduppo ; 
 int /*<<< orphan*/  bxa2g ; 
 int /*<<< orphan*/  bxa5g ; 
 int /*<<< orphan*/  cck2gpo ; 
 int /*<<< orphan*/  cckbw202gpo ; 
 int /*<<< orphan*/  cckbw20ul2gpo ; 
 int /*<<< orphan*/  cddpo ; 
 int /*<<< orphan*/  country_code ; 
 int /*<<< orphan*/  dev_id ; 
 int /*<<< orphan*/  elna2g ; 
 int /*<<< orphan*/  elna5g ; 
 TYPE_3__ fem ; 
 int /*<<< orphan*/  freqoffset_corr ; 
 int /*<<< orphan*/  gpio0 ; 
 int /*<<< orphan*/  gpio1 ; 
 int /*<<< orphan*/  gpio2 ; 
 int /*<<< orphan*/  gpio3 ; 
 int /*<<< orphan*/  hw_iqcal_en ; 
 int /*<<< orphan*/  iqcal_swp_dis ; 
 int /*<<< orphan*/  itssi_a ; 
 int /*<<< orphan*/  itssi_bg ; 
 int /*<<< orphan*/  legofdm40duppo ; 
 int /*<<< orphan*/  legofdmbw202gpo ; 
 int /*<<< orphan*/  legofdmbw205ghpo ; 
 int /*<<< orphan*/  legofdmbw205glpo ; 
 int /*<<< orphan*/  legofdmbw205gmpo ; 
 int /*<<< orphan*/  legofdmbw20ul2gpo ; 
 int /*<<< orphan*/  legofdmbw20ul5ghpo ; 
 int /*<<< orphan*/  legofdmbw20ul5glpo ; 
 int /*<<< orphan*/  legofdmbw20ul5gmpo ; 
 int /*<<< orphan*/  maxpwr_a ; 
 int /*<<< orphan*/  maxpwr_ah ; 
 int /*<<< orphan*/  maxpwr_al ; 
 int /*<<< orphan*/  maxpwr_bg ; 
 int /*<<< orphan*/ * mcs2gpo ; 
 int /*<<< orphan*/  mcs32po ; 
 int /*<<< orphan*/ * mcs5ghpo ; 
 int /*<<< orphan*/ * mcs5glpo ; 
 int /*<<< orphan*/ * mcs5gpo ; 
 int /*<<< orphan*/  mcsbw202gpo ; 
 int /*<<< orphan*/  mcsbw205ghpo ; 
 int /*<<< orphan*/  mcsbw205glpo ; 
 int /*<<< orphan*/  mcsbw205gmpo ; 
 int /*<<< orphan*/  mcsbw20ul2gpo ; 
 int /*<<< orphan*/  mcsbw20ul5ghpo ; 
 int /*<<< orphan*/  mcsbw20ul5glpo ; 
 int /*<<< orphan*/  mcsbw20ul5gmpo ; 
 int /*<<< orphan*/  mcsbw402gpo ; 
 int /*<<< orphan*/  mcsbw405ghpo ; 
 int /*<<< orphan*/  mcsbw405glpo ; 
 int /*<<< orphan*/  mcsbw405gmpo ; 
 int /*<<< orphan*/  measpower ; 
 int /*<<< orphan*/  measpower1 ; 
 int /*<<< orphan*/  measpower2 ; 
 int /*<<< orphan*/ * noiselvl2ga ; 
 int /*<<< orphan*/ * noiselvl5gha ; 
 int /*<<< orphan*/ * noiselvl5gla ; 
 int /*<<< orphan*/ * noiselvl5gma ; 
 int /*<<< orphan*/ * noiselvl5gua ; 
 int /*<<< orphan*/  ofdm2gpo ; 
 int /*<<< orphan*/  ofdm5ghpo ; 
 int /*<<< orphan*/  ofdm5glpo ; 
 int /*<<< orphan*/  ofdm5gpo ; 
 int /*<<< orphan*/  opo ; 
 int /*<<< orphan*/  pa0b0 ; 
 int /*<<< orphan*/  pa0b1 ; 
 int /*<<< orphan*/  pa0b2 ; 
 int /*<<< orphan*/  pa1b0 ; 
 int /*<<< orphan*/  pa1b1 ; 
 int /*<<< orphan*/  pa1b2 ; 
 int /*<<< orphan*/  pa1hib0 ; 
 int /*<<< orphan*/  pa1hib1 ; 
 int /*<<< orphan*/  pa1hib2 ; 
 int /*<<< orphan*/  pa1lob0 ; 
 int /*<<< orphan*/  pa1lob1 ; 
 int /*<<< orphan*/  pa1lob2 ; 
 int /*<<< orphan*/  pcieingress_war ; 
 int /*<<< orphan*/  phycal_tempdelta ; 
 int /*<<< orphan*/  rawtempsense ; 
 int /*<<< orphan*/  regrev ; 
 int /*<<< orphan*/  rssisav2g ; 
 int /*<<< orphan*/  rssisav5g ; 
 int /*<<< orphan*/  rssismc2g ; 
 int /*<<< orphan*/  rssismc5g ; 
 int /*<<< orphan*/  rssismf2g ; 
 int /*<<< orphan*/  rssismf5g ; 
 int /*<<< orphan*/  rxchain ; 
 int /*<<< orphan*/ * rxgainerr2ga ; 
 int /*<<< orphan*/ * rxgainerr5gha ; 
 int /*<<< orphan*/ * rxgainerr5gla ; 
 int /*<<< orphan*/ * rxgainerr5gma ; 
 int /*<<< orphan*/ * rxgainerr5gua ; 
 int /*<<< orphan*/  rxpo2g ; 
 int /*<<< orphan*/  rxpo5g ; 
 int /*<<< orphan*/  s8 ; 
 int /*<<< orphan*/  sar2g ; 
 int /*<<< orphan*/  sar5g ; 
 int /*<<< orphan*/  stbcpo ; 
 int /*<<< orphan*/  tempcorrx ; 
 int /*<<< orphan*/  tempoffset ; 
 int /*<<< orphan*/  temps_hysteresis ; 
 int /*<<< orphan*/  temps_period ; 
 int /*<<< orphan*/  tempsense_option ; 
 int /*<<< orphan*/  tempsense_slope ; 
 int /*<<< orphan*/  tempthresh ; 
 int /*<<< orphan*/  tri2g ; 
 int /*<<< orphan*/  tri5g ; 
 int /*<<< orphan*/  tri5gh ; 
 int /*<<< orphan*/  tri5gl ; 
 int /*<<< orphan*/  txchain ; 
 int /*<<< orphan*/ * txpid2g ; 
 int /*<<< orphan*/ * txpid5g ; 
 int /*<<< orphan*/ * txpid5gh ; 
 int /*<<< orphan*/ * txpid5gl ; 
 int /*<<< orphan*/  u16 ; 
 int /*<<< orphan*/  u32 ; 
 int /*<<< orphan*/  u8 ; 

__attribute__((used)) static void bcm47xx_sprom_fill_auto(struct ssb_sprom *sprom,
				    const char *prefix, bool fallback)
{
	const char *pre = prefix;
	bool fb = fallback;

	/* Broadcom extracts it for rev 8+ but it was found on 2 and 4 too */
	ENTRY(0xfffffffe, u16, pre, "devid", dev_id, 0, fallback);

	ENTRY(0xfffffffe, u16, pre, "boardrev", board_rev, 0, true);
	ENTRY(0xfffffffe, u32, pre, "boardflags", boardflags, 0, fb);
	ENTRY(0xfffffff0, u32, pre, "boardflags2", boardflags2, 0, fb);
	ENTRY(0xfffff800, u32, pre, "boardflags3", boardflags3, 0, fb);
	ENTRY(0x00000002, u16, pre, "boardflags", boardflags_lo, 0, fb);
	ENTRY(0xfffffffc, u16, pre, "boardtype", board_type, 0, true);
	ENTRY(0xfffffffe, u16, pre, "boardnum", board_num, 0, fb);
	ENTRY(0x00000002, u8, pre, "cc", country_code, 0, fb);
	ENTRY(0xfffffff8, u8, pre, "regrev", regrev, 0, fb);

	ENTRY(0xfffffffe, u8, pre, "ledbh0", gpio0, 0xff, fb);
	ENTRY(0xfffffffe, u8, pre, "ledbh1", gpio1, 0xff, fb);
	ENTRY(0xfffffffe, u8, pre, "ledbh2", gpio2, 0xff, fb);
	ENTRY(0xfffffffe, u8, pre, "ledbh3", gpio3, 0xff, fb);

	ENTRY(0x0000070e, u16, pre, "pa0b0", pa0b0, 0, fb);
	ENTRY(0x0000070e, u16, pre, "pa0b1", pa0b1, 0, fb);
	ENTRY(0x0000070e, u16, pre, "pa0b2", pa0b2, 0, fb);
	ENTRY(0x0000070e, u8, pre, "pa0itssit", itssi_bg, 0, fb);
	ENTRY(0x0000070e, u8, pre, "pa0maxpwr", maxpwr_bg, 0, fb);

	ENTRY(0x0000070c, u8, pre, "opo", opo, 0, fb);
	ENTRY(0xfffffffe, u8, pre, "aa2g", ant_available_bg, 0, fb);
	ENTRY(0xfffffffe, u8, pre, "aa5g", ant_available_a, 0, fb);
	ENTRY(0x000007fe, s8, pre, "ag0", antenna_gain.a0, 0, fb);
	ENTRY(0x000007fe, s8, pre, "ag1", antenna_gain.a1, 0, fb);
	ENTRY(0x000007f0, s8, pre, "ag2", antenna_gain.a2, 0, fb);
	ENTRY(0x000007f0, s8, pre, "ag3", antenna_gain.a3, 0, fb);

	ENTRY(0x0000070e, u16, pre, "pa1b0", pa1b0, 0, fb);
	ENTRY(0x0000070e, u16, pre, "pa1b1", pa1b1, 0, fb);
	ENTRY(0x0000070e, u16, pre, "pa1b2", pa1b2, 0, fb);
	ENTRY(0x0000070c, u16, pre, "pa1lob0", pa1lob0, 0, fb);
	ENTRY(0x0000070c, u16, pre, "pa1lob1", pa1lob1, 0, fb);
	ENTRY(0x0000070c, u16, pre, "pa1lob2", pa1lob2, 0, fb);
	ENTRY(0x0000070c, u16, pre, "pa1hib0", pa1hib0, 0, fb);
	ENTRY(0x0000070c, u16, pre, "pa1hib1", pa1hib1, 0, fb);
	ENTRY(0x0000070c, u16, pre, "pa1hib2", pa1hib2, 0, fb);
	ENTRY(0x0000070e, u8, pre, "pa1itssit", itssi_a, 0, fb);
	ENTRY(0x0000070e, u8, pre, "pa1maxpwr", maxpwr_a, 0, fb);
	ENTRY(0x0000070c, u8, pre, "pa1lomaxpwr", maxpwr_al, 0, fb);
	ENTRY(0x0000070c, u8, pre, "pa1himaxpwr", maxpwr_ah, 0, fb);

	ENTRY(0x00000708, u8, pre, "bxa2g", bxa2g, 0, fb);
	ENTRY(0x00000708, u8, pre, "rssisav2g", rssisav2g, 0, fb);
	ENTRY(0x00000708, u8, pre, "rssismc2g", rssismc2g, 0, fb);
	ENTRY(0x00000708, u8, pre, "rssismf2g", rssismf2g, 0, fb);
	ENTRY(0x00000708, u8, pre, "bxa5g", bxa5g, 0, fb);
	ENTRY(0x00000708, u8, pre, "rssisav5g", rssisav5g, 0, fb);
	ENTRY(0x00000708, u8, pre, "rssismc5g", rssismc5g, 0, fb);
	ENTRY(0x00000708, u8, pre, "rssismf5g", rssismf5g, 0, fb);
	ENTRY(0x00000708, u8, pre, "tri2g", tri2g, 0, fb);
	ENTRY(0x00000708, u8, pre, "tri5g", tri5g, 0, fb);
	ENTRY(0x00000708, u8, pre, "tri5gl", tri5gl, 0, fb);
	ENTRY(0x00000708, u8, pre, "tri5gh", tri5gh, 0, fb);
	ENTRY(0x00000708, s8, pre, "rxpo2g", rxpo2g, 0, fb);
	ENTRY(0x00000708, s8, pre, "rxpo5g", rxpo5g, 0, fb);
	ENTRY(0xfffffff0, u8, pre, "txchain", txchain, 0xf, fb);
	ENTRY(0xfffffff0, u8, pre, "rxchain", rxchain, 0xf, fb);
	ENTRY(0xfffffff0, u8, pre, "antswitch", antswitch, 0xff, fb);
	ENTRY(0x00000700, u8, pre, "tssipos2g", fem.ghz2.tssipos, 0, fb);
	ENTRY(0x00000700, u8, pre, "extpagain2g", fem.ghz2.extpa_gain, 0, fb);
	ENTRY(0x00000700, u8, pre, "pdetrange2g", fem.ghz2.pdet_range, 0, fb);
	ENTRY(0x00000700, u8, pre, "triso2g", fem.ghz2.tr_iso, 0, fb);
	ENTRY(0x00000700, u8, pre, "antswctl2g", fem.ghz2.antswlut, 0, fb);
	ENTRY(0x00000700, u8, pre, "tssipos5g", fem.ghz5.tssipos, 0, fb);
	ENTRY(0x00000700, u8, pre, "extpagain5g", fem.ghz5.extpa_gain, 0, fb);
	ENTRY(0x00000700, u8, pre, "pdetrange5g", fem.ghz5.pdet_range, 0, fb);
	ENTRY(0x00000700, u8, pre, "triso5g", fem.ghz5.tr_iso, 0, fb);
	ENTRY(0x00000700, u8, pre, "antswctl5g", fem.ghz5.antswlut, 0, fb);
	ENTRY(0x000000f0, u8, pre, "txpid2ga0", txpid2g[0], 0, fb);
	ENTRY(0x000000f0, u8, pre, "txpid2ga1", txpid2g[1], 0, fb);
	ENTRY(0x000000f0, u8, pre, "txpid2ga2", txpid2g[2], 0, fb);
	ENTRY(0x000000f0, u8, pre, "txpid2ga3", txpid2g[3], 0, fb);
	ENTRY(0x000000f0, u8, pre, "txpid5ga0", txpid5g[0], 0, fb);
	ENTRY(0x000000f0, u8, pre, "txpid5ga1", txpid5g[1], 0, fb);
	ENTRY(0x000000f0, u8, pre, "txpid5ga2", txpid5g[2], 0, fb);
	ENTRY(0x000000f0, u8, pre, "txpid5ga3", txpid5g[3], 0, fb);
	ENTRY(0x000000f0, u8, pre, "txpid5gla0", txpid5gl[0], 0, fb);
	ENTRY(0x000000f0, u8, pre, "txpid5gla1", txpid5gl[1], 0, fb);
	ENTRY(0x000000f0, u8, pre, "txpid5gla2", txpid5gl[2], 0, fb);
	ENTRY(0x000000f0, u8, pre, "txpid5gla3", txpid5gl[3], 0, fb);
	ENTRY(0x000000f0, u8, pre, "txpid5gha0", txpid5gh[0], 0, fb);
	ENTRY(0x000000f0, u8, pre, "txpid5gha1", txpid5gh[1], 0, fb);
	ENTRY(0x000000f0, u8, pre, "txpid5gha2", txpid5gh[2], 0, fb);
	ENTRY(0x000000f0, u8, pre, "txpid5gha3", txpid5gh[3], 0, fb);

	ENTRY(0xffffff00, u8, pre, "tempthresh", tempthresh, 0, fb);
	ENTRY(0xffffff00, u8, pre, "tempoffset", tempoffset, 0, fb);
	ENTRY(0xffffff00, u16, pre, "rawtempsense", rawtempsense, 0, fb);
	ENTRY(0xffffff00, u8, pre, "measpower", measpower, 0, fb);
	ENTRY(0xffffff00, u8, pre, "tempsense_slope", tempsense_slope, 0, fb);
	ENTRY(0xffffff00, u8, pre, "tempcorrx", tempcorrx, 0, fb);
	ENTRY(0xffffff00, u8, pre, "tempsense_option", tempsense_option, 0, fb);
	ENTRY(0x00000700, u8, pre, "freqoffset_corr", freqoffset_corr, 0, fb);
	ENTRY(0x00000700, u8, pre, "iqcal_swp_dis", iqcal_swp_dis, 0, fb);
	ENTRY(0x00000700, u8, pre, "hw_iqcal_en", hw_iqcal_en, 0, fb);
	ENTRY(0x00000700, u8, pre, "elna2g", elna2g, 0, fb);
	ENTRY(0x00000700, u8, pre, "elna5g", elna5g, 0, fb);
	ENTRY(0xffffff00, u8, pre, "phycal_tempdelta", phycal_tempdelta, 0, fb);
	ENTRY(0xffffff00, u8, pre, "temps_period", temps_period, 0, fb);
	ENTRY(0xffffff00, u8, pre, "temps_hysteresis", temps_hysteresis, 0, fb);
	ENTRY(0xffffff00, u8, pre, "measpower1", measpower1, 0, fb);
	ENTRY(0xffffff00, u8, pre, "measpower2", measpower2, 0, fb);

	ENTRY(0x000001f0, u16, pre, "cck2gpo", cck2gpo, 0, fb);
	ENTRY(0x000001f0, u32, pre, "ofdm2gpo", ofdm2gpo, 0, fb);
	ENTRY(0x000001f0, u32, pre, "ofdm5gpo", ofdm5gpo, 0, fb);
	ENTRY(0x000001f0, u32, pre, "ofdm5glpo", ofdm5glpo, 0, fb);
	ENTRY(0x000001f0, u32, pre, "ofdm5ghpo", ofdm5ghpo, 0, fb);
	ENTRY(0x000001f0, u16, pre, "mcs2gpo0", mcs2gpo[0], 0, fb);
	ENTRY(0x000001f0, u16, pre, "mcs2gpo1", mcs2gpo[1], 0, fb);
	ENTRY(0x000001f0, u16, pre, "mcs2gpo2", mcs2gpo[2], 0, fb);
	ENTRY(0x000001f0, u16, pre, "mcs2gpo3", mcs2gpo[3], 0, fb);
	ENTRY(0x000001f0, u16, pre, "mcs2gpo4", mcs2gpo[4], 0, fb);
	ENTRY(0x000001f0, u16, pre, "mcs2gpo5", mcs2gpo[5], 0, fb);
	ENTRY(0x000001f0, u16, pre, "mcs2gpo6", mcs2gpo[6], 0, fb);
	ENTRY(0x000001f0, u16, pre, "mcs2gpo7", mcs2gpo[7], 0, fb);
	ENTRY(0x000001f0, u16, pre, "mcs5gpo0", mcs5gpo[0], 0, fb);
	ENTRY(0x000001f0, u16, pre, "mcs5gpo1", mcs5gpo[1], 0, fb);
	ENTRY(0x000001f0, u16, pre, "mcs5gpo2", mcs5gpo[2], 0, fb);
	ENTRY(0x000001f0, u16, pre, "mcs5gpo3", mcs5gpo[3], 0, fb);
	ENTRY(0x000001f0, u16, pre, "mcs5gpo4", mcs5gpo[4], 0, fb);
	ENTRY(0x000001f0, u16, pre, "mcs5gpo5", mcs5gpo[5], 0, fb);
	ENTRY(0x000001f0, u16, pre, "mcs5gpo6", mcs5gpo[6], 0, fb);
	ENTRY(0x000001f0, u16, pre, "mcs5gpo7", mcs5gpo[7], 0, fb);
	ENTRY(0x000001f0, u16, pre, "mcs5glpo0", mcs5glpo[0], 0, fb);
	ENTRY(0x000001f0, u16, pre, "mcs5glpo1", mcs5glpo[1], 0, fb);
	ENTRY(0x000001f0, u16, pre, "mcs5glpo2", mcs5glpo[2], 0, fb);
	ENTRY(0x000001f0, u16, pre, "mcs5glpo3", mcs5glpo[3], 0, fb);
	ENTRY(0x000001f0, u16, pre, "mcs5glpo4", mcs5glpo[4], 0, fb);
	ENTRY(0x000001f0, u16, pre, "mcs5glpo5", mcs5glpo[5], 0, fb);
	ENTRY(0x000001f0, u16, pre, "mcs5glpo6", mcs5glpo[6], 0, fb);
	ENTRY(0x000001f0, u16, pre, "mcs5glpo7", mcs5glpo[7], 0, fb);
	ENTRY(0x000001f0, u16, pre, "mcs5ghpo0", mcs5ghpo[0], 0, fb);
	ENTRY(0x000001f0, u16, pre, "mcs5ghpo1", mcs5ghpo[1], 0, fb);
	ENTRY(0x000001f0, u16, pre, "mcs5ghpo2", mcs5ghpo[2], 0, fb);
	ENTRY(0x000001f0, u16, pre, "mcs5ghpo3", mcs5ghpo[3], 0, fb);
	ENTRY(0x000001f0, u16, pre, "mcs5ghpo4", mcs5ghpo[4], 0, fb);
	ENTRY(0x000001f0, u16, pre, "mcs5ghpo5", mcs5ghpo[5], 0, fb);
	ENTRY(0x000001f0, u16, pre, "mcs5ghpo6", mcs5ghpo[6], 0, fb);
	ENTRY(0x000001f0, u16, pre, "mcs5ghpo7", mcs5ghpo[7], 0, fb);
	ENTRY(0x000001f0, u16, pre, "cddpo", cddpo, 0, fb);
	ENTRY(0x000001f0, u16, pre, "stbcpo", stbcpo, 0, fb);
	ENTRY(0x000001f0, u16, pre, "bw40po", bw40po, 0, fb);
	ENTRY(0x000001f0, u16, pre, "bwduppo", bwduppo, 0, fb);

	ENTRY(0xfffffe00, u16, pre, "cckbw202gpo", cckbw202gpo, 0, fb);
	ENTRY(0xfffffe00, u16, pre, "cckbw20ul2gpo", cckbw20ul2gpo, 0, fb);
	ENTRY(0x00000600, u32, pre, "legofdmbw202gpo", legofdmbw202gpo, 0, fb);
	ENTRY(0x00000600, u32, pre, "legofdmbw20ul2gpo", legofdmbw20ul2gpo, 0, fb);
	ENTRY(0x00000600, u32, pre, "legofdmbw205glpo", legofdmbw205glpo, 0, fb);
	ENTRY(0x00000600, u32, pre, "legofdmbw20ul5glpo", legofdmbw20ul5glpo, 0, fb);
	ENTRY(0x00000600, u32, pre, "legofdmbw205gmpo", legofdmbw205gmpo, 0, fb);
	ENTRY(0x00000600, u32, pre, "legofdmbw20ul5gmpo", legofdmbw20ul5gmpo, 0, fb);
	ENTRY(0x00000600, u32, pre, "legofdmbw205ghpo", legofdmbw205ghpo, 0, fb);
	ENTRY(0x00000600, u32, pre, "legofdmbw20ul5ghpo", legofdmbw20ul5ghpo, 0, fb);
	ENTRY(0xfffffe00, u32, pre, "mcsbw202gpo", mcsbw202gpo, 0, fb);
	ENTRY(0x00000600, u32, pre, "mcsbw20ul2gpo", mcsbw20ul2gpo, 0, fb);
	ENTRY(0xfffffe00, u32, pre, "mcsbw402gpo", mcsbw402gpo, 0, fb);
	ENTRY(0xfffffe00, u32, pre, "mcsbw205glpo", mcsbw205glpo, 0, fb);
	ENTRY(0x00000600, u32, pre, "mcsbw20ul5glpo", mcsbw20ul5glpo, 0, fb);
	ENTRY(0xfffffe00, u32, pre, "mcsbw405glpo", mcsbw405glpo, 0, fb);
	ENTRY(0xfffffe00, u32, pre, "mcsbw205gmpo", mcsbw205gmpo, 0, fb);
	ENTRY(0x00000600, u32, pre, "mcsbw20ul5gmpo", mcsbw20ul5gmpo, 0, fb);
	ENTRY(0xfffffe00, u32, pre, "mcsbw405gmpo", mcsbw405gmpo, 0, fb);
	ENTRY(0xfffffe00, u32, pre, "mcsbw205ghpo", mcsbw205ghpo, 0, fb);
	ENTRY(0x00000600, u32, pre, "mcsbw20ul5ghpo", mcsbw20ul5ghpo, 0, fb);
	ENTRY(0xfffffe00, u32, pre, "mcsbw405ghpo", mcsbw405ghpo, 0, fb);
	ENTRY(0x00000600, u16, pre, "mcs32po", mcs32po, 0, fb);
	ENTRY(0x00000600, u16, pre, "legofdm40duppo", legofdm40duppo, 0, fb);
	ENTRY(0x00000700, u8, pre, "pcieingress_war", pcieingress_war, 0, fb);

	/* TODO: rev 11 support */
	ENTRY(0x00000700, u8, pre, "rxgainerr2ga0", rxgainerr2ga[0], 0, fb);
	ENTRY(0x00000700, u8, pre, "rxgainerr2ga1", rxgainerr2ga[1], 0, fb);
	ENTRY(0x00000700, u8, pre, "rxgainerr2ga2", rxgainerr2ga[2], 0, fb);
	ENTRY(0x00000700, u8, pre, "rxgainerr5gla0", rxgainerr5gla[0], 0, fb);
	ENTRY(0x00000700, u8, pre, "rxgainerr5gla1", rxgainerr5gla[1], 0, fb);
	ENTRY(0x00000700, u8, pre, "rxgainerr5gla2", rxgainerr5gla[2], 0, fb);
	ENTRY(0x00000700, u8, pre, "rxgainerr5gma0", rxgainerr5gma[0], 0, fb);
	ENTRY(0x00000700, u8, pre, "rxgainerr5gma1", rxgainerr5gma[1], 0, fb);
	ENTRY(0x00000700, u8, pre, "rxgainerr5gma2", rxgainerr5gma[2], 0, fb);
	ENTRY(0x00000700, u8, pre, "rxgainerr5gha0", rxgainerr5gha[0], 0, fb);
	ENTRY(0x00000700, u8, pre, "rxgainerr5gha1", rxgainerr5gha[1], 0, fb);
	ENTRY(0x00000700, u8, pre, "rxgainerr5gha2", rxgainerr5gha[2], 0, fb);
	ENTRY(0x00000700, u8, pre, "rxgainerr5gua0", rxgainerr5gua[0], 0, fb);
	ENTRY(0x00000700, u8, pre, "rxgainerr5gua1", rxgainerr5gua[1], 0, fb);
	ENTRY(0x00000700, u8, pre, "rxgainerr5gua2", rxgainerr5gua[2], 0, fb);

	ENTRY(0xfffffe00, u8, pre, "sar2g", sar2g, 0, fb);
	ENTRY(0xfffffe00, u8, pre, "sar5g", sar5g, 0, fb);

	/* TODO: rev 11 support */
	ENTRY(0x00000700, u8, pre, "noiselvl2ga0", noiselvl2ga[0], 0, fb);
	ENTRY(0x00000700, u8, pre, "noiselvl2ga1", noiselvl2ga[1], 0, fb);
	ENTRY(0x00000700, u8, pre, "noiselvl2ga2", noiselvl2ga[2], 0, fb);
	ENTRY(0x00000700, u8, pre, "noiselvl5gla0", noiselvl5gla[0], 0, fb);
	ENTRY(0x00000700, u8, pre, "noiselvl5gla1", noiselvl5gla[1], 0, fb);
	ENTRY(0x00000700, u8, pre, "noiselvl5gla2", noiselvl5gla[2], 0, fb);
	ENTRY(0x00000700, u8, pre, "noiselvl5gma0", noiselvl5gma[0], 0, fb);
	ENTRY(0x00000700, u8, pre, "noiselvl5gma1", noiselvl5gma[1], 0, fb);
	ENTRY(0x00000700, u8, pre, "noiselvl5gma2", noiselvl5gma[2], 0, fb);
	ENTRY(0x00000700, u8, pre, "noiselvl5gha0", noiselvl5gha[0], 0, fb);
	ENTRY(0x00000700, u8, pre, "noiselvl5gha1", noiselvl5gha[1], 0, fb);
	ENTRY(0x00000700, u8, pre, "noiselvl5gha2", noiselvl5gha[2], 0, fb);
	ENTRY(0x00000700, u8, pre, "noiselvl5gua0", noiselvl5gua[0], 0, fb);
	ENTRY(0x00000700, u8, pre, "noiselvl5gua1", noiselvl5gua[1], 0, fb);
	ENTRY(0x00000700, u8, pre, "noiselvl5gua2", noiselvl5gua[2], 0, fb);
}