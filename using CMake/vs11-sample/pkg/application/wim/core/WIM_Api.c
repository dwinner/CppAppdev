/* ---> This file is automatically generated by API_Generator.pl! <--- */
/***************************************************************************
*================ Copyright by Continental Automotive GmbH =================
****************************************************************************
*
* Titel        : WIM_Api.c
*
* Description  : EMPTY API BODIES / TOOLBASED GENERATION
*
* Environment  : JCP 2011 / WIN_XP
*
* Responsible  : Christian Opel <ID RD SW GA A>
*
* Guidelines   : SMK 4.3
*
* Template name: OOLite Interface, Revision 1.0
*
* CASE-Tool    : Together, Version 6.1
*
* Revision List: (Will be filled by PVCS)
* Archive: $Log: WIM_Api.c  $
* Archive: Revision 1.1.1.4 2014/06/06 17:02:31CEST Wagner-EXT, Alexander (uidw3785) 
* Archive: DC MR 38112 : WIM: Introduction of "Singleline Acknowledgements" - MR47
* Archive: DC MR 40764 : WIM: Changes after code review for single line acknowledgements -  ORM 7144
* Archive: DC MR 40531 : Single line acknowledgement should cancel a running startup animation
* Archive: Revision 1.1.1.3 2014/02/19 17:03:20CET Wagner-EXT, Alexander (uidw3785) 
* Archive: DC MR 39262 : BR213-GC-EL: Adaptions for refactored Brutus
* Archive: Revision 1.1.1.2 2013/08/14 16:26:32CEST Wagner-EXT, Alexander (uidw3785) 
* Archive: Initial revision
* Archive: Member added to project /id/dag_PF3/sw/pkg/wim/adapt/project.pj
* Archive: Revision 1.2.1.5 2013/01/31 13:53:45CET Chirila Rosa, Adela (uidt6989) 
* Archive: DC MR 30836 W222, E011/GC, WIM: complex display of warnung ConvertibleTop 0x200527 - ALP2745
* Archive: Revision 1.2.1.4 2013/01/14 16:41:26CET Tudoran Florian (uidu2066) (uidu2066) 
* Archive: MR 25690 W205IC-GC TSA: Prevent popup warning from being displayed when FAS menu is active (ALP2802)
* Archive: Revision 1.2.1.3 2012/12/20 13:47:08CET Tudoran Florian (uidu2066) (uidu2066) 
* Archive: MR 30836 W205E011/GC, WIM: complex display of warnung ConvertibleTop 0x200527 - ?LP2745
* Archive: Revision 1.2.1.2 2012/08/14 13:08:17CEST Chirila Rosa Adela (uidt6989) (uidt6989) 
* Archive: DC MR 27253 BR205 - Use Global Storage for HMI internal variables
* Archive: Revision 1.2.1.1 2012/05/16 12:23:44CEST Tudoran Florian (uidu2066) (uidu2066) 
* Archive: update to 205 IC GC, DC.SW.SYS.205IC_GC_Series_E8.01.22.rel
* 
*    Rev 1.1   23 Jan 2012 13:12:12   Florian.Tudoran
* DC MR 24330 W205, E007/GC, WIM: Takeover MR for 23683, 24093, 24088
* 
*    Rev 1.0   19 Oct 2011 12:54:42   Florian.Tudoran
* Initial revision.
* 
*    Rev 1.9   12 Aug 2011 09:31:56   Florian.Tudoran
* DC MR 22733
* 
*    Rev 1.8   Apr 29 2011 13:20:38   Michael-Johannes.Kling
* MR 21860
* 
*    Rev 1.7   Mar 22 2011 09:42:16   Nicolae.Gavrila
* DC MRs:
* 21698
* 21726
* 21737
* 21733
* 21579
* 21757
* 21344
* 21567
* 21801
* 
*    Rev 1.6   Feb 08 2011 11:36:20   Nicolae.Gavrila
* DC MR 21667: E004 API clean-up
* 
*    Rev 1.5   Dec 17 2010 15:01:36   Nicolae.Gavrila
* DC MRs 20859, 20897, 21486
* Overtaking integrator patches
* 
*    Rev 1.4   Dec 03 2010 15:31:44   Nicolae.Gavrila
* DC MRs:
* 21237
* 21208
* 21346
* 20859
* 21290
* 20897
* 21329
* 21345
* 21359
* 
*    Rev 1.3   Aug 30 2010 08:11:30   Nicolae.Gavrila
* DC MR 20926: GC; �LP2191: new requirements for 0x2000F2
* 
*    Rev 1.2   Jul 13 2010 14:25:04   Nicolae.Gavrila
* DC MR 20545: WIM: Extension of HMI Interface for E001.2
* 
*    Rev 1.1   Jun 24 2010 09:10:14   Nicolae.Gavrila
* DC MR 20481 Update
* 
*    Rev 1.0   Jun 11 2010 15:10:22   Nicolae.Gavrila
* Initial revision.
*
****************************************************************************/


/****************************************************************************
** Header Files (Only those that are needed in this file)
****************************************************************************/
#include "API_c1.h"
#include "dpool_c1.h"
#include <SDF_c1.h>

/***************************************************************************
* API FUNCTION DEFINITIONS
***************************************************************************/

void API_WIM_vProcessPhoneCallKey ( bool boConfirm, bool boReject, bool boECall, bool boBack ) /* @status Implemented */
{
   DPOOL_txWIM_tstPhoneCallKey stPhoneCallKey;     
   
   stPhoneCallKey.boConfirm = boConfirm;
   stPhoneCallKey.boReject = boReject;
   stPhoneCallKey.boECall = boECall;
   stPhoneCallKey.boBack = boBack;
   
   APIM_boSetData(APIM_nDId_WIM_stPhoneCallKey, &stPhoneCallKey, (uint16) sizeof(stPhoneCallKey));
}

//DC MR 22733
void API_WIM_vSetWarningConfirmed ( uint16 u16WarningId, uint8 u8Key) /* @status Implemented */
   {
      /****************************************************************************************** 
       * Setter for confirmed warning; DPOOL structure: WIM_stKeyEvent{u16WarningID, u8Key}
       * @response  => ONCHANGE
       * @return    => void
        * @param   u16WarningId - The warning ID
		* @param        u8Key - Key
		* @param boPreConfirmed - Pre confirmation status of warning
       ******************************************************************************************/
    DPOOL_txWIM_tstKeyEvent stKeyEvent;
    
    stKeyEvent.u16WarningID = u16WarningId;
    stKeyEvent.u8Key = u8Key;

    APIM_boSetData( APIM_nDId_WIM_stKeyEvent , &stKeyEvent, (uint16)sizeof(stKeyEvent) );
   }
uint32 API_WIM_u32GetAcoustWarning ( void ) /* @status Implemented */ 
{
    /****************************************************************************************** 
     * Get current acoustic warning
     * @response  => ONCHANGE
     * @return    => uint32
      * @param void
     ******************************************************************************************/

    uint32 u32Tmp;
    APIM_boGetData( APIM_nDId_u32AcoustWarningR , &u32Tmp, (uint16)sizeof(u32Tmp) );
    return ( u32Tmp );
}
/* EasyCASE ) */

/* EasyCASE ( 8
   API_FaultMem_u16GetFirstWarnID */
/* EasyCASE F */
uint16 API_WIM_u16FaultMemGetFirstWarnID ( void ) /* @status Implemented */ 
{
    /****************************************************************************************** 
     * Getter for 
     * @response  => ONCHANGE
     * @return    => uint16
      * @param void
     ******************************************************************************************/

    uint32 u32Tmp;
    APIM_boGetData( APIM_nDId_API_FaultMem_boGetFaultMemBorder , &u32Tmp, (uint16)sizeof(u32Tmp) );
    return ( u32Tmp );
}
uint16 API_WIM_u16FaultMemGetCurrentWarnID ( void ) /* @status Implemented */ 
{
    /****************************************************************************************** 
     * Getter for 
     * @response  => ONCHANGE
     * @return    => uint16
      * @param void
     ******************************************************************************************/

    uint32 u32Tmp;
    APIM_boGetData( APIM_nDId_API_FaultMem_boGetFaultMemState , &u32Tmp, (uint16)sizeof(u32Tmp) );
    return ( u32Tmp );
}
uint16 API_WIM_u16FaultMemGetCountOfFaultMemMsgs ( void ) /* @status Implemented */ 
{
    /****************************************************************************************** 
     * Getter for 
     * @response  => ONCHANGE
     * @return    => uint16
      * @param void
     ******************************************************************************************/

	uint32 u32Tmp;
	uint16 u16NoMsgsFaultMem;

    APIM_boGetData( APIM_nDId_API_FaultMem_boGetFaultMemBorder , &u32Tmp, (uint16)sizeof(u32Tmp) );
    u16NoMsgsFaultMem = (uint16)(u32Tmp >> 16);
	return ( u16NoMsgsFaultMem );
   }
/* EasyCASE ) */
/* EasyCASE ( 11
   API_FaultMem_u16GetCurrIndexFaultMemMsg */
/* EasyCASE F */
uint16 API_WIM_u16FaultMemGetCurrIndexFaultMemMsg ( void ) /* @status Implemented */ 
{
    /****************************************************************************************** 
     * Getter for 
     * @response  => ONCHANGE
     * @return    => uint16
      * @param void
     ******************************************************************************************/

    uint32 u32Tmp;
	uint16 u16MsgIndex;
    APIM_boGetData( APIM_nDId_API_FaultMem_boGetFaultMemState , &u32Tmp, (uint16)sizeof(u32Tmp) );
    u16MsgIndex = (uint16)(u32Tmp >> 16);
	return ( u16MsgIndex );
}
bool API_WIM_boFaultMemGetArrowVisibility ( uint8 u8Arrow ) /* @status Implemented */ 
{
    /****************************************************************************************** 
     * Getter for 
     * @response  => ONCHANGE
     * @return    => bool
      * @param	 enArrow - 
     ******************************************************************************************/

    bool boTmp = False;
    uint32 u32Border;
    uint32 u32State;
   uint16 u16NoMsgsFaultMem;
   uint16 u16MsgIndex;
    APIM_boGetData( APIM_nDId_API_FaultMem_boGetFaultMemState , &u32State, (uint16)sizeof(u32State) );
    APIM_boGetData( APIM_nDId_API_FaultMem_boGetFaultMemBorder , &u32Border, (uint16)sizeof(u32Border) );
   u16NoMsgsFaultMem = (uint16)(u32Border >> 16);
   u16MsgIndex = (uint16)(u32State >> 16);
   if (u8Arrow == 0) /* DOWN */
   {
      boTmp = SDF_enGetVariant() != SDF_enVariantLowLine && SDF_enGetVariant() != SDF_enVariantMidLine
         ? u16MsgIndex < u16NoMsgsFaultMem
         : u16NoMsgsFaultMem > 1;
   }

   if (u8Arrow == 1) /* UP */
   {
      boTmp = (SDF_enGetVariant() != SDF_enVariantLowLine && SDF_enGetVariant() != SDF_enVariantMidLine
         ? u16MsgIndex
         : u16NoMsgsFaultMem) > 1;
   }

   return boTmp;
}
void API_WIM_vFaultMemSetEventReset ( uint8 u8ResetTag ) /* @status Implemented */ 
{
    /****************************************************************************************** 
     * Setter for 
     * @response  => ONCHANGE
     * @return    => void
      * @param	 u8ResetTag - 
     ******************************************************************************************/
   APIM_boSetData( APIM_nDId_API_FaultMem_vSetEventReset , &u8ResetTag, (uint16)sizeof(u8ResetTag) );
}
void API_WIM_vFaultMemSetEventPrevNext ( uint8 u8NavTag ) /* @status Implemented */ 
{
    /****************************************************************************************** 
     * Setter for 
     * @response  => ONCHANGE
     * @return    => void
      * @param	 u8NavTag - 
     ******************************************************************************************/
   APIM_boSetData( APIM_nDId_API_FaultMem_vSetEventPrevNext , &u8NavTag, (uint16)sizeof(u8NavTag) );
}
void API_WIM_vSetDisplayedWarning ( uint16 u16WarningIDNew, uint16 u16WarningIDOld ) /* @status Implemented */ 
   {
      /****************************************************************************************** 
       * Setter for displayed warning; DPOOL structure: WIM_stHmiFeedback{u16WarningIDOld, u16WarningIDNew}
       * @response  => ONCHANGE
       * @return    => void
	   * @param        u16WarningIDNew - The new warning ID
	   * @param        u16WarningIDOld - The old warning ID
       ******************************************************************************************/
       DPOOL_txWIM_tstHmiFeedback stHmiFeedback;
	   stHmiFeedback.u16WarningIDNew = u16WarningIDNew;
	   stHmiFeedback.u16WarningIDOld = u16WarningIDOld;
    APIM_boSetData( APIM_nDId_WIM_stHmiFeedback , &stHmiFeedback, (uint16)sizeof(stHmiFeedback) );
}
void API_WIM_vSetCanceledWarning ( uint16 u16WarningID ) /* @status Implemented */
   {
   /* EasyCASE < */
   /****************************************************************************************** 
   * Setter for displayed warning; DPOOL structure: WIM_stHmiFeedback{u16WarningIDOld, u16WarningIDNew}
   * @response  => ONCHANGE
   * @return    => void
        * @param        u16WarningID - Canceled Warning ID
   ******************************************************************************************/
   APIM_boSetData ( APIM_nDId_WIM_u16CanceledWarning, &u16WarningID, (uint16) sizeof ( u16WarningID ) );
   /* EasyCASE > */
   }
/* EasyCASE ) */

void API_WIM_vSetSuppressedWarning ( uint16 u16WarningId ) /* @status Implemented */
{
	/****************************************************************************************** 
       * Setter for supressed warning
       * @response  => NONE
       * @return    => void
	   * @param        uint16 u16WarningId => Id of the supressed warning
       ******************************************************************************************/
	APIM_boSetData ( APIM_nDId_WIM_u16SuppressedWarning, &u16WarningId, (uint16)sizeof(u16WarningId) );
}

/* vSetDisplayedSlack */
void API_WIM_vSetDisplayedSlack ( uint16 u16WarningIDNew, uint16 u16WarningIDOld ) /* @status Implemented */
{
	/****************************************************************************************** 
   * Setter for displayed slack; DPOOL structure: WIM_stHmiFeedbackSlack{u16WarningIDOld, u16WarningIDNew}
   * @response  => ONCHANGE
   * @return    => void
   * @param        u16WarningIDNew - The new slack ID
   * @param        u16WarningIDOld - The old slack ID
	******************************************************************************************/
   DPOOL_txWIM_tstHmiFeedback stHmiFeedbackSlack;
   stHmiFeedbackSlack.u16WarningIDNew = u16WarningIDNew;
   stHmiFeedbackSlack.u16WarningIDOld = u16WarningIDOld;
   APIM_boSetData( APIM_nDId_WIM_stHmiFeedbackSlack , &stHmiFeedbackSlack, (uint16)sizeof(stHmiFeedbackSlack) );
}
   
/* vSetCanceledSlack */
void API_WIM_vSetCanceledSlack ( uint16 u16WarningID ) /* @status Implemented */
{
	 /****************************************************************************************** 
    * Setter for displayed slack; DPOOL structure: WIM_stHmiFeedbackSlack{u16SlackIDOld, u16SlackIDNew}
    * @response  => ONCHANGE
    * @return    => void
    * @param        u16WarningID - Canceled Slack ID
    ******************************************************************************************/
	 APIM_boSetData ( APIM_nDId_WIM_u16CanceledSlack, &u16WarningID, (uint16) sizeof ( u16WarningID ) );
}

/* vSetDisplayOn */
void API_WIM_vSetDisplayOn ( bool boDisplayOn ) /* @status Implemented */
{
	 /****************************************************************************************** 
    * Setter for display ON/OFF state
    * @response  => NONE
    * @return    => void
    * @param        boDisplayOn - Indicated weither display is on
    ******************************************************************************************/
	 APIM_boSetData ( APIM_nDId_WIM_boDisplayOn, &boDisplayOn, (uint16) sizeof ( boDisplayOn ) );
}
/* --- EOF --- */
