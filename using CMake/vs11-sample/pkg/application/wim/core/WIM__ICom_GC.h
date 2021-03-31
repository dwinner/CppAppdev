/* Generated by Together */
#ifndef WIM__ICOM_GC
#define WIM__ICOM_GC
/******************************************************************************
*======================= Copyright by Continental Automotive AG ===============
*******************************************************************************
* Titel        : WIM__ICom_GC.h
*
* Description  : Package private interface of icom-class:
*                ICom services GC
*                Private class that manages DPOOL access
*                package WIM
*
* Environment  : OSEK, JCP (NEC )
*
* Responsible  : L.Gruenewald, Schleissheimer GmbH
*
* Guidelines   : SMK 3.3  
*
* Template name: OOLite Codefile, Revision 1.0
*
* CASE-Tool    : Together Controlcenter, Version 6.2
*
* Revision List: (Will be filled by PVCS)
* Archive: $Log: WIM__ICom_GC.h  $
* Archive: Revision 1.3 2014/07/29 18:35:51CEST Wagner-EXT, Alexander (uidw3785) 
* Archive: DC MR 41681 : WIM: Prevent sporadic flicker of GC controlled complex warnings after Kl15ACC
* Archive: Revision 1.2 2013/11/22 17:20:18CET Wagner-EXT, Alexander (uidw3785) 
* Archive: DC MR 36779 : BR213EL, E006, Implementation of new WarnDB
* Archive: DC MR 36462 : WIM: Implement new scheduling and state handling for acoustic part
* Archive: Revision 1.1 2012/06/15 15:49:34CEST Immel-EXT, Marc (uid37561) 
* Archive: Initial revision
* Archive: Member added to project /id/dag_PF3/sw/pkg/wim/adapt/project.pj
* Archive: Revision 1.3 2012/06/15 15:49:34CEST uid37556 
* Archive: DC MR 26087: W205, E009/GC, WIM: Change of Prio1Mute and Lowering times - �LP2873
* Archive: Revision 1.2 2012/05/18 14:48:24CEST Gottwalles Dirk (uid37556) (uid37556) 
* Archive: DC MR 25917: W222, E007/GC, WIM: Changes on display-block by sound only warning - WDM35459
* Archive: DC MR 25905: W205, E008/GC, WIM: Displacement of handling messages - Follow-Up
* Archive: DC MR 25716: W205, E009/GC, WIM: Behaviour of sync acoustics - WDM35391, 35418, 35392, 35389, 35396, 35421
* Archive: DC MR 25711: W205, E009/GC, WIM: Inactive handling messages show up after 600ms - WDM35020
* Archive: DC MR 25705: W205, E009/GC, WIM: Fix for corrupted sound
* Archive: DC MR 25460: BR205 E009: PrioHandler: Changes after code review
* Archive: DC MR 25147: W205, E009/GC, WIM: Priorities for roll handling - WDM35385
* Archive: DC MR 25142: W205, E009/GC, WIM: SBW/WIM Acoustic corrections - WDM21151, WDM34246
* Archive: DC MR 25132: W205, E009/GC, WIM: Implementation of exceptions
* Archive: DC MR 25089: W205, E008/GC, WIM: Improvement of Timer accuracy for display role - WDM 32006
* Archive: Revision 1.1 2011/11/08 13:47:56CET Gottwalles Dirk (uid37556) (uid37556) 
* Archive: Initial revision
* Archive: Member added to project /id/dag_PF3/sw/pkg/wim/adapt/project.pj
* 
*    Rev 1.0   Nov 08 2011 14:34:36   SCHL_Dirk.Gottwalles
* Initial revision.
* 
*
*******************************************************************************/

/******************************************************************************
** Header Files (Only those that are needed in this file)
*******************************************************************************/

/* System Header Files */
#include "cdef.h"

/* Foreign headerfiles */

/* Own headerfiles */

/******************************************************************************
* Definition of exported global data used by Class
* Macros, Enumerations, Types,  Forward declarations
*******************************************************************************/

/******************************************************************************
* CLASS DEFINITION
*******************************************************************************/
#ifdef TOGETHER /* open C++ class */

/**
* ICom services class
*/
class WIM__IComGC {
public: 
#endif

/******************************************************************************
*   Class Attributes
*******************************************************************************/

/* System Wide Scope */
#ifdef TOGETHER
public:
#endif


/* File Local Scope */
#ifdef TOGETHER
private:
#endif


/******************************************************************************
*   Class Operations
*******************************************************************************/

/* Package Global Scope */
#ifdef TOGETHER
public:
#endif

/**
* Initialise ICom internal components.
*   @return  void
*   @param   void
*   @author  L.Gruenewald, Schleissheimer GmbH 
*/
void WIM__vIComInit_GC(void);


/******************************************************************************
* PACKAGE LOCAL FUNCTIONS - SERVICES - Receive ICom Function
*******************************************************************************/
/**
* This function is called by Interface function on reception of an Event
* which is processed by WIM__ICom
*   @return  void
*   @param   EVHD_tenReceiveEvent enEvent, contains the received Event.
*   @author  L.Gruenewald, Schleissheimer GmbH 
*/
void WIM__vDoDpoolEventsByICom_GC(EVHD_tenReceiveEvent enEvent);

/******************************************************************************
* PACKAGE LOCAL FUNCTIONS - CONTAINER - Send ICom Data
*******************************************************************************/
/**
*   Helper function to trigger DspChangeCont on AC over ICom
*   @return  void
*   @param   u32HilID
*   @author  L.Gruenewald, Schleissheimer GmbH 
*/
void WIM__vIComDspChangeContainer(uint32 u32HilId);

/**
*   Helper function to trigger StateChangeCont on AC over ICom
*   @return  void
*   @param   u32HilID, enNotify
*   @author  L.Gruenewald, Schleissheimer GmbH 
*/
void WIM__vIComNotifyHandler(uint32 u32HilId, WIM_tenDisplayEvent enNotify);

/**
*   Helper function to trigger ManuQuitContainer on AC over ICom
*   @return  void
*   @param   u32HilID
*   @param   enDispEvt
*   @author  L.Gruenewald, Schleissheimer GmbH 
*/
void WIM__vIComManuQuitContainer(uint32 u32HilId, WIM_tenDisplayEvent enDispEvt);

/**
*   Helper function to trigger PreConfirmationContainer on AC over ICom
*   @return  void
*   @param   u32HilID
*   @author  D.Gottwalles, Schleissheimer GmbH 
*/
void WIM__vIComPreConfirmationContainer(uint32 u32HilId);

/******************************************************************************
* PACKAGE LOCAL FUNCTIONS - Int/Ext Condition Replacements - Send ICom Data
*******************************************************************************/

/**                                                                                                     
* This is replacement function on GC and send Information by ICom on AC
*   @return  void                                                                                       
*   @param   u8Function: function, event belongs to                                                     
*   @param   u8Index: index of subfunction                                                              
*   @param   WIM__tenEventIntern enEvt: Register/Retrigger/Delete                                       
*   @author  L.Gruenewald, Schleissheimer GmbH                                                            
*/                                                                                                      
void WIM__vHandleExtCondition_GC(WIM_tenExtEvtFunction enFunction, uint8 u8Index, WIM__tenEventIntern enEvt);

/**
* This is replacement function on GC and send Information by ICom on AC 
*   @return  void
*   @param   u32HilId: HIL ID of the related message
*   @param   WIM__tenEventIntern enEvt: WIM__nRegister, WIM__nRetrigger, WIM__nDelete
*   @author  T.Godemann, Schleissheimer GmbH 
*/
void WIM__vHandleIntCondition_GC(uint32 u32HilId, WIM__tenEventIntern enEvt);

/******************************************************************************
* PACKAGE LOCAL FUNCTIONS - FaultMemFlag
*******************************************************************************/
/**
* helper function: set/clear fault memory flag on Automotive Controller
*   @return  void
*   @param   WIM_tenMsg: Message identifier
*   @param   bool boSet: True set flag, False clear flag
*   @author  L.Gruenewald, Schleissheimer GmbH 
*/
void WIM__vSetFaultMemFlagICom(WIM_tenMsg enMsg, bool boSet);


/******************************************************************************
* PACKAGE LOCAL FUNCTIONS - CAN HeadUnit Replacements - Send ICom Data
*******************************************************************************/
/**
* Replacement for RequestControl Function!!! Forwoard data by ICom.
* The function sets the internal request 
* A mute/volume decrease of the head unit is canceled by sending specific CAN 
* signals (if a delay is specified, the signals are canceled on timer end).
*   @return  void
*   @param   boOn: True = set request, False = clear request
*   @author  T.Godemann, Schleissheimer GmbH 
*/
void WIM__vSetVolDecRequest_GC(WIM__tenAcuTypes enAcuType, bool boOn);

/**
* Replacement for RequestControl Function!!! Forwoard data by ICom.
* The function sets the internal request 
* A mute/volume decrease of the head unit is canceled by sending specific CAN 
* signals (if a delay is specified, the signals are canceled on timer end).
*   @return  void
*   @param   boOn: True = set request, False = clear request
*   @author  L.Gruenewald, Schleissheimer GmbH 
*/
void WIM__vSetMuteRequest_GC(WIM__tenAcuTypes enAcuType, bool boOn);

/******************************************************************************
* PACKAGE LOCAL FUNCTIONS - RestoreReset Handshake - Send ICom Data
*******************************************************************************/
/**
* Replacement for RequestControl Function!!! 
* Warning states handled by RequestControl has to be restored.
*   @return  void
*   @param   void
*   @author  L.Gruenewald, Schleissheimer GmbH 
*/
void WIM__vStartRestoreWarningsRequestControl_GC(void);

/**
* Notification for check complex GC functions done.
*   @return  void
*   @param   void
*   @author  M. Immel, Schleissheimer GmbH 
*/
void WIM__vCheckComplexWarningsRequestControl(void);

/**
* Replacement for RequestControl Function!!! 
* Warning states handled by RequestControl has to be reset.
*   @return  void
*   @param   void
*   @author  L.Gruenewald, Schleissheimer GmbH 
*/
void WIM__vStartResetWarningsRequestControl_GC(void);

/**
* Timer callback function.
* Called if one of the handshake mechanism relevant timers has elapsed.
* - WIM__nTimerTmOutRestore Timeout for RestoreWarnings mechanism
* - WIM__nTimerTmOutReset   Timeout for ResetAllWarnings mechanism
*   @return  void
*   @param   enTimer: Timer identifier, xCorrTag: Correlation tag (e.g. message Id)
*   @author  L.Gruenewald, Schleissheimer GmbH 
*/
void WIM__vResetRestoreTimer(WIM__tenTimer enTimer, WIM__txCorrTag xCorrTag);

/**
* This function retrieves the HIL-Id of the current displayed message if any.
*   @return  True: message present (HIL valid), False: no message (HIL invalid)
*   @param   pointer to uint32, contains HIL on output
*   @author  T.Godemann, Schleissheimer GmbH 
*/
bool WIM__boGetDisplayMaster(uint32* pu32HilId);

/* File Local Scope */
#ifdef TOGETHER
private:
#endif

#ifdef TOGETHER /* close the C++ class */
};
#endif
/********************
**  CLASS END
*********************/
#endif /* WIM__ICOM_GC */
