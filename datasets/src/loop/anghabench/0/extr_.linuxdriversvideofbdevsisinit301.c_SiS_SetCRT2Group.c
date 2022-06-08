#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct SiS_Private {int SiS_SetFlag; int SiS_SelectCRT2Rate; int SiS_IF_DEF_LVDS; scalar_t__ ChipType; int SiS_VBInfo; int SiS_VBType; int SiS_IF_DEF_CH70xx; scalar_t__ SiS_LCDVDES; scalar_t__ SiS_LCDHDES; int /*<<< orphan*/  SiS_Part1Port; int /*<<< orphan*/  UseCustomMode; } ;

/* Variables and functions */
 int DisableCRT2Display ; 
 int LowModeTests ; 
 int ProgrammingCRT2 ; 
 scalar_t__ SIS_315H ; 
 scalar_t__ SIS_730 ; 
 int SetCRT2ToLCD ; 
 int SetCRT2ToLCDA ; 
 int SetCRT2ToTV ; 
 int SetDOSMode ; 
 int SetInSlaveMode ; 
 int /*<<< orphan*/  SiS_DisableBridge (struct SiS_Private*) ; 
 int /*<<< orphan*/  SiS_DisplayOn (struct SiS_Private*) ; 
 int /*<<< orphan*/  SiS_EnableBridge (struct SiS_Private*) ; 
 int /*<<< orphan*/  SiS_GetCRT2Data (struct SiS_Private*,unsigned short,unsigned short,unsigned short) ; 
 int /*<<< orphan*/  SiS_GetLVDSDesData (struct SiS_Private*,unsigned short,unsigned short,unsigned short) ; 
 unsigned short SiS_GetRatePtr (struct SiS_Private*,unsigned short,unsigned short) ; 
 int /*<<< orphan*/  SiS_LockCRT2 (struct SiS_Private*) ; 
 int /*<<< orphan*/  SiS_ModCRT1CRTC (struct SiS_Private*,unsigned short,unsigned short,unsigned short) ; 
 int /*<<< orphan*/  SiS_SaveCRT2Info (struct SiS_Private*,unsigned short) ; 
 int /*<<< orphan*/  SiS_SearchModeID (struct SiS_Private*,unsigned short*,unsigned short*) ; 
 int /*<<< orphan*/  SiS_SetCH70xxANDOR (struct SiS_Private*,int,int,int) ; 
 int /*<<< orphan*/  SiS_SetCHTVReg (struct SiS_Private*,unsigned short,unsigned short,unsigned short) ; 
 int /*<<< orphan*/  SiS_SetCRT2ECLK (struct SiS_Private*,unsigned short,unsigned short,unsigned short) ; 
 int /*<<< orphan*/  SiS_SetCRT2ModeRegs (struct SiS_Private*,unsigned short,unsigned short) ; 
 int /*<<< orphan*/  SiS_SetCRT2Sync (struct SiS_Private*,unsigned short,unsigned short) ; 
 int /*<<< orphan*/  SiS_SetGroup1 (struct SiS_Private*,unsigned short,unsigned short,unsigned short) ; 
 int /*<<< orphan*/  SiS_SetGroup2 (struct SiS_Private*,unsigned short,unsigned short,unsigned short) ; 
 int /*<<< orphan*/  SiS_SetGroup3 (struct SiS_Private*,unsigned short,unsigned short) ; 
 int /*<<< orphan*/  SiS_SetGroup4 (struct SiS_Private*,unsigned short,unsigned short,unsigned short) ; 
 int /*<<< orphan*/  SiS_SetGroup5 (struct SiS_Private*,unsigned short,unsigned short) ; 
 int /*<<< orphan*/  SiS_SetReg (int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  SiS_SetRegSR11ANDOR (struct SiS_Private*,int,int) ; 
 int /*<<< orphan*/  SiS_UnLockCRT2 (struct SiS_Private*) ; 
 int VB_NoLCD ; 
 int VB_SIS30xBLV ; 
 int VB_SISVB ; 

bool
SiS_SetCRT2Group(struct SiS_Private *SiS_Pr, unsigned short ModeNo)
{
#ifdef CONFIG_FB_SIS_300
   unsigned char  *ROMAddr  = SiS_Pr->VirtualRomBase;
#endif
   unsigned short ModeIdIndex, RefreshRateTableIndex;

   SiS_Pr->SiS_SetFlag |= ProgrammingCRT2;

   if(!SiS_Pr->UseCustomMode) {
      SiS_SearchModeID(SiS_Pr, &ModeNo, &ModeIdIndex);
   } else {
      ModeIdIndex = 0;
   }

   /* Used for shifting CR33 */
   SiS_Pr->SiS_SelectCRT2Rate = 4;

   SiS_UnLockCRT2(SiS_Pr);

   RefreshRateTableIndex = SiS_GetRatePtr(SiS_Pr, ModeNo, ModeIdIndex);

   SiS_SaveCRT2Info(SiS_Pr,ModeNo);

   if(SiS_Pr->SiS_SetFlag & LowModeTests) {
      SiS_DisableBridge(SiS_Pr);
      if((SiS_Pr->SiS_IF_DEF_LVDS == 1) && (SiS_Pr->ChipType == SIS_730)) {
         SiS_SetReg(SiS_Pr->SiS_Part1Port,0x00,0x80);
      }
      SiS_SetCRT2ModeRegs(SiS_Pr, ModeNo, ModeIdIndex);
   }

   if(SiS_Pr->SiS_VBInfo & DisableCRT2Display) {
      SiS_LockCRT2(SiS_Pr);
      SiS_DisplayOn(SiS_Pr);
      return true;
   }

   SiS_GetCRT2Data(SiS_Pr, ModeNo, ModeIdIndex, RefreshRateTableIndex);

   /* Set up Panel Link for LVDS and LCDA */
   SiS_Pr->SiS_LCDHDES = SiS_Pr->SiS_LCDVDES = 0;
   if( (SiS_Pr->SiS_IF_DEF_LVDS == 1) ||
       ((SiS_Pr->SiS_VBType & VB_NoLCD) && (SiS_Pr->SiS_VBInfo & SetCRT2ToLCD)) ||
       ((SiS_Pr->ChipType >= SIS_315H) && (SiS_Pr->SiS_VBType & VB_SIS30xBLV)) ) {
      SiS_GetLVDSDesData(SiS_Pr, ModeNo, ModeIdIndex, RefreshRateTableIndex);
   }

   if(SiS_Pr->SiS_SetFlag & LowModeTests) {
      SiS_SetGroup1(SiS_Pr, ModeNo, ModeIdIndex, RefreshRateTableIndex);
   }

   if(SiS_Pr->SiS_VBType & VB_SISVB) {

      if(SiS_Pr->SiS_SetFlag & LowModeTests) {

	 SiS_SetGroup2(SiS_Pr, ModeNo, ModeIdIndex, RefreshRateTableIndex);
#ifdef CONFIG_FB_SIS_315
	 SiS_SetGroup2_C_ELV(SiS_Pr, ModeNo, ModeIdIndex, RefreshRateTableIndex);
#endif
	 SiS_SetGroup3(SiS_Pr, ModeNo, ModeIdIndex);
	 SiS_SetGroup4(SiS_Pr, ModeNo, ModeIdIndex, RefreshRateTableIndex);
#ifdef CONFIG_FB_SIS_315
	 SiS_SetGroup4_C_ELV(SiS_Pr, ModeNo, ModeIdIndex);
#endif
	 SiS_SetGroup5(SiS_Pr, ModeNo, ModeIdIndex);

	 SiS_SetCRT2Sync(SiS_Pr, ModeNo, RefreshRateTableIndex);

	 /* For 301BDH (Panel link initialization): */
	 if((SiS_Pr->SiS_VBType & VB_NoLCD) && (SiS_Pr->SiS_VBInfo & SetCRT2ToLCD)) {

	    if(!((SiS_Pr->SiS_SetFlag & SetDOSMode) && ((ModeNo == 0x03) || (ModeNo == 0x10)))) {
	       if(SiS_Pr->SiS_VBInfo & SetInSlaveMode) {
		  SiS_ModCRT1CRTC(SiS_Pr, ModeNo, ModeIdIndex, RefreshRateTableIndex);
	       }
            }
	    SiS_SetCRT2ECLK(SiS_Pr, ModeNo, ModeIdIndex, RefreshRateTableIndex);
	 }
      }

   } else {

      SiS_SetCRT2Sync(SiS_Pr, ModeNo, RefreshRateTableIndex);

      SiS_ModCRT1CRTC(SiS_Pr,ModeNo,ModeIdIndex,RefreshRateTableIndex);

      SiS_SetCRT2ECLK(SiS_Pr,ModeNo,ModeIdIndex,RefreshRateTableIndex);

      if(SiS_Pr->SiS_SetFlag & LowModeTests) {
	 if(SiS_Pr->SiS_IF_DEF_CH70xx != 0) {
	    if(SiS_Pr->SiS_VBInfo & (SetCRT2ToLCD | SetCRT2ToLCDA)) {
	       if(SiS_Pr->SiS_IF_DEF_CH70xx == 2) {
#ifdef CONFIG_FB_SIS_315
		  SiS_SetCH701xForLCD(SiS_Pr);
#endif
	       }
	    }
	    if(SiS_Pr->SiS_VBInfo & SetCRT2ToTV) {
	       SiS_SetCHTVReg(SiS_Pr,ModeNo,ModeIdIndex,RefreshRateTableIndex);
	    }
	 }
      }

   }

#ifdef CONFIG_FB_SIS_300
   if(SiS_Pr->ChipType < SIS_315H) {
      if(SiS_Pr->SiS_SetFlag & LowModeTests) {
	 if(SiS_Pr->SiS_UseOEM) {
	    if((SiS_Pr->SiS_UseROM) && (SiS_Pr->SiS_UseOEM == -1)) {
	       if((ROMAddr[0x233] == 0x12) && (ROMAddr[0x234] == 0x34)) {
		  SiS_OEM300Setting(SiS_Pr, ModeNo, ModeIdIndex, RefreshRateTableIndex);
	       }
	    } else {
	       SiS_OEM300Setting(SiS_Pr, ModeNo, ModeIdIndex, RefreshRateTableIndex);
	    }
	 }
	 if(SiS_Pr->SiS_IF_DEF_LVDS == 1) {
	    if((SiS_Pr->SiS_CustomT == CUT_BARCO1366) ||
	       (SiS_Pr->SiS_CustomT == CUT_BARCO1024)) {
	       SetOEMLCDData2(SiS_Pr, ModeNo, ModeIdIndex,RefreshRateTableIndex);
	    }
	    SiS_DisplayOn(SiS_Pr);
         }
      }
   }
#endif

#ifdef CONFIG_FB_SIS_315
   if(SiS_Pr->ChipType >= SIS_315H) {
      if(SiS_Pr->SiS_SetFlag & LowModeTests) {
	 if(SiS_Pr->ChipType < SIS_661) {
	    SiS_FinalizeLCD(SiS_Pr, ModeNo, ModeIdIndex);
	    SiS_OEM310Setting(SiS_Pr, ModeNo, ModeIdIndex, RefreshRateTableIndex);
	 } else {
	    SiS_OEM661Setting(SiS_Pr, ModeNo, ModeIdIndex, RefreshRateTableIndex);
	 }
	 SiS_SetRegOR(SiS_Pr->SiS_Part1Port,0x01,0x40);
      }
   }
#endif

   if(SiS_Pr->SiS_SetFlag & LowModeTests) {
      SiS_EnableBridge(SiS_Pr);
   }

   SiS_DisplayOn(SiS_Pr);

   if(SiS_Pr->SiS_IF_DEF_CH70xx == 1) {
      if(SiS_Pr->SiS_VBInfo & SetCRT2ToTV) {
	 /* Disable LCD panel when using TV */
	 SiS_SetRegSR11ANDOR(SiS_Pr,0xFF,0x0C);
      } else {
	 /* Disable TV when using LCD */
	 SiS_SetCH70xxANDOR(SiS_Pr,0x0e,0x01,0xf8);
      }
   }

   if(SiS_Pr->SiS_SetFlag & LowModeTests) {
      SiS_LockCRT2(SiS_Pr);
   }

   return true;
}