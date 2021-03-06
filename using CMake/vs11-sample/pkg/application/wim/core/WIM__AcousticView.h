/* Generated by Together */
#ifndef WIM__ACOUSTICVIEW_H
#define WIM__ACOUSTICVIEW_H
/******************************************************************************
*=====================      Copyright by Continental AG      ==================
*******************************************************************************
* Titel        : WIM__AcousticView.h
*
* Description  : Package private interface of acoustic view class:
*                View class for messages with acoustic output (beep/gong)
*                Private class that manages sound attributes and controls
*                acoustic output for acoustic messages with and without display
*
* Environment  : OSEK, JCP (NEC V850)
*
* Responsible  : A.Wagner, Schleissheimer GmbH
*
* Guidelines   : SMK 3.3  
*
* Template name: OOLite Codefile, Revision 1.0
*
* CASE-Tool    : Together Controlcenter, Version 6.2
*
* Revision List: (Will be filled by PVCS)
* Archive: $Log: WIM__AcousticView.h  $
* Archive: Initial revision for VS11 (Based on 213IC-EL E009.4rel)
*
* Archive: Revision 1.1.2.4 2014/06/06 18:56:46CEST Wagner-EXT, Alexander (uidw3785) 
* Archive: DC MR 40088 : WIM: Extend implementation for break in acoustic HIL signal - WDM 203
* Archive: DC MR 40569 : WIM: Deactivation time of FCW/LCW acoustics takes too long - WDMs 99460, 99457
* Archive: DC MR 40609 : WIM: Correct handling for "kurzzeitige Ruhe" (short rest) - WDMs 99458, 99481, 99485
* Archive: Revision 1.1.2.3 2013/11/22 16:53:02CET Wagner-EXT, Alexander (uidw3785) 
* Archive: DC MR 36779 : BR213EL, E006, Implementation of new WarnDB
* Archive: DC MR 36462 : WIM: Implement new scheduling and state handling for acoustic part
* Archive: Revision 1.1.2.2 2013/03/27 15:52:11CET Immel-EXT, Marc (uid37561) 
* Archive: Initial revision
* Archive: Member added to project /id/dag_PF3/sw/pkg/wim/core/coreGenPF3GC/project.pj
* Archive: Revision 1.9 2012/10/02 12:22:08CEST Immel-EXT, Marc (uid37561) 
* Archive: DC MR 27252 BR222 MY - Use Global Storage for HMI internal variables
* Archive: DC MR 29677 W222, E010/GC, WIM: Possible access violation in fault memory
* Archive: DC MR 29701 W222, E010/GC, WIM: Changes for SBW acoustic handling - �LP 3082 / missing HIL output for NCAP acoustics - WDM 47538
* Archive: Revision 1.8 2012/07/10 08:39:38CEST Gottwalles Dirk (uid37556) (uid37556) 
* Archive: DC MR 27180: W222, E009/GC, WIM: Acoustic stop behavior - WDM43362, WDM43364
* Archive: DC MR 27539: BR222/E7.4/GC: WIM: Update HIL feedback for sound and soundrequests
* Archive: Revision 1.7.1.3 2012/07/10 08:39:38CEST Gottwalles Dirk (uid37556) (uid37556) 
* Archive: DC MR 27179: W222, E007/GC, WIM: Acoustic stop behavior - WDM43362, WDM43364
* Archive: DC MR 26956: BR222/E7.4/GC: WIM: Update HIL feedback for sound and soundrequests
* Archive: Revision 1.7 2012/05/18 10:42:43CEST Gottwalles Dirk (uid37556) (uid37556) 
* Archive: Member moved from WIM__AcousticView.h in project /id/dag_PF3/sw/pkg/wim/core/project.pj[dag_PF3.sw.pkg.wim_COMMON_IC222GC_VarP] to WIM__AcousticView.h in project /id/dag_PF3/sw/pkg/wim/core/coreGenPF3GC/project.pj[dag_PF3.sw.pkg.wim_COMMON_GenPF3GC_VarX].
* Archive: Revision 1.6 2012/05/10 17:21:01CEST Gottwalles Dirk (uid37556) (uid37556) 
* Archive: DC MR 25842: BR222/E7.2/GC: WIM: HIL Fix Loudness Feedback (WDM31515)
* Archive: DC MR 25916: W222, E007/GC, WIM: Changes on display-block by sound only warning - WDM35459
* Archive: DC MR 25913: W222, E007/AC, HIL: Mapping of WIM sound types
* Archive: DC MR 25704: W222, E007/GC, WIM: Fix for corrupted sound - WDM35438
* Archive: Revision 1.5 2012/04/27 12:57:40CEST 07_BH_FA Partnerroom-SSH-9 (uid37556) (uid37556) 
* Archive: DC MR 25131: W222, E007/GC, WIM: Implementation of exceptions
* Archive: DC MR 25823: BR222 E7.2: Implementation of L3 delivery (XML-Files)
* Archive: DC MR 21251: W222, E007/GC, WIM: ComplexFunction of Warning 0x2001A6 Kurvenlicht
* Archive: DC MR 25710: W222, E007/GC, WIM: Inactive handling messages show up after 600ms - WDM35020
* Archive: DC MR 25126: W222, E007/GC, WIM: Behaviour of sync acoustics - WDM35391, 35418, 35392, 35389, 35396, 35421
* Archive: Revision 1.3 2012/04/04 13:42:03CEST 07_BH_FA Partnerroom-SSH-9 (uid37556) (uid37556) 
* Archive: DC MR 24870: W222, E007/GC, WIM: Implement changes from Review ORM2907
* Archive: DC MR 25007: W222, E007/GC, WIM: Displacement of handling messages - WDM20280
* Archive: DC MR 25041: Do not specify message propagation in message description files
* Archive: DC MR 25095: W222, E007/GC, WIM: Improvement of Timer accuracy for display role - WDM 25704
* Archive: DC MR 25034: Reduction of lag times in case of vehicle locked
* Archive: DC MR 25393: W222, E007/GC, WIM: No cancel of interval acoustic - WDM31269, �LP2895
* Archive: Revision 1.2 2011/12/02 10:52:22CET 07_BH_FA Partnerroom-SSH-9 (uid37556) (uid37556) 
* Archive: Revision derived from PVCS revision DC.SW.PAC.WIM_222IC_GC_COMMON_VarP.V01.02.pre05
* 
*    Rev 1.8   Dec 02 2011 14:49:56   SCHL_Dirk.Gottwalles
* DC MR 23223: W222, E007/AC: Warnung Parkbremse 0x2001A8 �LP2607
* DC MR 23256: W222GC:E006 new volume interface
* DC MR 23803: Applications should send global direct messages
* DC MR 22621: BR222/E007/GC: HIL: DisplayColor
* 
*    Rev 1.7   Aug 12 2011 16:39:38   SCHL_Dirk.Gottwalles
* DC MR 22652: W222, E006/AC, SCS: Remove warning management
* DC MR 22655: W222, E006/AC, WIM: Implmentation of complex key handling for warnings
* DC MR 22263: W222, E006/GC, WIM: Remove of unused sound Ids
* DC MR 22549: E006/GC: HIL: Get acoustics status indication for warnings
* DC MR 22686: Implementation of L3 Menu, Warn DB for E006
* DC MR 22733: W222, E006/GC, WIM: Implementation of complex key handling for warnings
* DC MR 21544: E006/GC: HIL: Get TPOL Menu HIL-ID and WIM-HIL-ID
* DC MR 22749: Integration of ARTEMMIS 3.2
* 
*    Rev 1.6   Jul 13 2011 15:34:38   SCHL_Dirk.Gottwalles
* DC MR 22485: BR222, E006 Implementation of xml-files and style guide
* DC MR 22396: BR222: New acoustic for rearseatbeltwarning �LP2571
* DC MR 22456: Permanent Display menu - hybrid (GC)
* DC MR 21811: BR222: WIM: New Keywords/functions �LP2444, Part II
* DC MR 22265: W222, E006/AC, WIM:Change of Timeout behaviour
* DC MR 22261: W222, E006/AC, WIM: New keyword for WarnDB TIMEOUT_NOT_ENG_START, �LP2574
* DC MR 22260: W222, E006/AC, WIM: New keyword for WarnDB TIMEOUT_KL15_NOT_ENG_START, �LP2573
* DC MR 22092: W222, E006/AC, WIM: Door warning state is not correct evaluated for undefined values
* 
*    Rev 1.5   May 13 2011 15:15:24   SCHL_Dirk.Gottwalles
* DC MR 22206: FLG: No more WIM requests necessary
* DC MR 22089: E004/GC, WIM: Configure warnings that keep the IC awake
* DC MR 22090: BR222/GC, WIM: Warning sounds are not played correct if sound subsystem was not active previoulsy
* 
*    Rev 1.4   Dec 03 2010 15:56:40   SCHL_Lars.Gruenewald
* DC MR20903 BR222 WIM cancel dsp synch acustics at warning left the display
* DC MR21188 BR222: WIM Display lag time at multiple wakeupreq.
* DC MR21334 GC-E003: Update of PCMPL and changed Interface
* DC MR21353 HIL& WIM: Acoustics SetBeltWarningLevel2 und Level1, ContinuousWarning
* DC MR21151 HIL: wrong Accoustics Warning
* DC MR21384 BR222: two warnings for seatbeltwarning
* DC MR21318 E003: Startup MR for Traffic sign assistant (TSA)
* DC MR20897 WIM: Implementation of menu FaultMemory
* DC MR21257 Implementation of L3 WarnDB f�r E003
* 
*    Rev 1.3   Nov 19 2010 16:04:04   SCHL_Dirk.Gottwalles
* DC MR21122 BR222: WIM reaction at wakeupreq.
* DC MR21302 BR222/AC: Optimierung Aufruf Checkfunktion WIM
* DC MR20423 W222: WIM new acoustics requirements
* DC MR21177 Implementation of first WarnDB for E003
* DC MR21336 WIM: Using Enumeration Symbols for State/Widget Mapping
* 
*    Rev 1.2   Aug 27 2010 18:49:38   SCHL_Lars.Gruenewald
* DC MR20751  E002/AC, Introduce Warning 120 km/h
* DC MR20742  W222: Startup Modul SBW for E002
* DC MR20810  AC: Warning requests of Fuel Level Gauge (FLG)
* DC MR20835  E002/AC Startup SBC
* DC MR20951  Add property for priority to WIMController
* DC MR20589  BR222: WIM additional functionality for E002
* DC MR20216  �LP2191: new requirements for 0x2000F2
* DC MR20377  Exception entries in EXEA made by WIM
* DC MR20759  Implementation of first WarnDB for E002
* 
*    Rev 1.1   Jun 25 2010 12:22:10   SCHL_Lars.Gr�newald
* DC MR 20566  WIM222: WIM Part2 for E001
* DC MR 20629 Configuration of Display Handler
* DC MR 20639 WIM: Adaption of HMI part for E001.1 
* DC MR 20620 Startup-MR for dynamical area manager (prio)
* DC MR 20661 Br222: WIM: ICOM Reinitialization
* DC MR 20662 Needed patches for WarnDB E001
* DC MR 20560 Implementation of first WarnDB for E001
* DC MR 20490 W222 E001: start up MR SFG
* 
*    Rev 1.0   Jun 11 2010 14:06:14   SCHL_Thomas.Godemann
* Initial revision.
* 
* --------------------------------------------------------------------------
* Date      | Author | Reason     | Change
* --------------------------------------------------------------------------
* 10-06-03    LarGru   MR20481      Initial revision for W222
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

   /**
   * View attributes of message (type acoustic message)
   */
   typedef struct
   {
      /**
      * acoustic type
      * @range  WIM_tenAcousticType
      * @values WIM__nSingleBeep, WIM__nIntervalBeep, 
      *         WIM_nenFrontalCollisionWarning, WIM_nenLateralCollisionWarning,
      *         WIM_nenPriority1Warning, WIM_nenPriority2Warning, WIM_nenContinuousWarning,
      *         WIM_nenAcknowledgement, WIM_nenAttentionAssistWarning, WIM_nenSeatbeltWarningLevel1,
      *         WIM_nenSeatbeltWarningLevel2, WIM_nenRearSeatbeltWarning
      */
      uint8 biAcousticType : 5;

      /**
      * acoustic volume
      * @range  WIM_tenVolumeCtrl
      * @values WIM_nenVolumeNoSound,
      *         WIM_nenVolumeVel,
      *         WIM_nenVolumeMax,
      *         WIM_nenVolumeMin,
      *         WIM_nenVolumeNcap,
      *         WIM_nenVolumeLevel2,
      *         WIM_nenVolumeLevel3,
      *         WIM_nenVolumeLevel4,
      *         WIM_nenVolumeLevel5
      */
      uint8 biVolume : 4;

      /**
      * acoustic is synchroneous with system clock 
      * @range  boolean
      * @values True/False 
      */
      uint8 biSfgSyncAcoustic : 1;

      /**
      * send mute signal to head unit if acoustic active 
      * @range  boolean
      * @values True/False 
      */
      uint8 biMuteHeadUnit : 1;

      /**
      * send volume decrease signal to head unit if acoustic active
      * @range  boolean
      * @values True/False 
      */
      uint8 biDecVolHeadUnit : 1;

      /**
      * unused bits
      */
      uint8 biUnused : 4;

   } WIM__tstViewAttrAcu;

   typedef enum
   {
      WIM__nAcuInactive,               /* warning without acoustic */
      WIM__nActiveDspSync,             /* warning with display synchronous acoustic */
      WIM__nActiveDspAsync,            /* warning with display asynchronous acoustic */
      WIM__nNoOfAcuTypes
   } WIM__tenAcuTypes;

   typedef enum
   {
      WIM__enSingleTone,               /* Single tone that ends after tone output */
      WIM__enIntervalTone,             /* Signle tone with flexible interval, controlled by application */
      WIM__enPeriodicIntervalTone,     /* Interval tone with automatic repition (fixed frequency) */
      WIM__enNoOfToneTypes
   } WIM__tenToneTypes;

   typedef enum
   {
      WIM__nenFreq400,                 /* Frequency 400 ms phase for interval sounds */
      WIM__nenFreq1000,                /* Frequency 1000 ms phase for interval sounds */
      WIM__nenInvalidFreq              /* Frequency invalid */
   } WIM__tenFrequencies;
   

/******************************************************************************
* CLASS DEFINITION
*******************************************************************************/
#ifdef TOGETHER /* open C++ class */

/**
* View class for messages with acoustic output (beep/gong)
*/
class WIM__AcousticView {
public: 
#endif

/******************************************************************************
*   Class Attributes
*******************************************************************************/

/* System Wide Scope */
#ifdef TOGETHER
public:
#endif
  
/* Package Global Scope */

/*
* memory for frontal, lateral collision warning playing sound
*/
extern WIM_tenMsg WIM__enFrontLatCollWarnPlaying;

/*
* memory for continious playing sound
*/
extern WIM_tenMsg WIM__enContPlayingSound;

/* File Local Scope */
#ifdef TOGETHER
private:
#endif

   /**                                            
   * memory for current playing PCM streams       
   * @range  PCMPL_tenStream
   * @values see PCMPL enumeration
   */                                             
   static PCMPL_tenStream WIM__enStreamId;



/******************************************************************************
*   Class Operations
*******************************************************************************/

/* Package Global Scope */
#ifdef TOGETHER
public:
#endif

   /**
   * The function initializes the acoustic class
   *   @return  void
   *   @param   void
   *   @author  T.Godemann, Schleissheimer GmbH 
   */
   void WIM__vInitAcoustic(void);

   /**
   * The function deinitializes the acoustic class
   *   @return  void
   *   @param   void
   *   @author  D.Gottwalles, Schleissheimer GmbH 
   */
   void WIM__vDeinitAcoustic(void);

   /**
   * The function starts an acoustic message.
   * It controls the type and volume of the acoustic and mutes the head unit
   * if configured by sending specific CAN signals.
   *   @return  TRUE - Acoustic could be started (Acustics is generally intact, callback will give feedback)
   *            FALSE - Acoustics could not be started (callback will not give feedback)
   *   @param   enMsg: Identifier of message
   *   @param   enReplacedMsg: Identifier of replaced message
   *   @author  T.Godemann, Schleissheimer GmbH 
   */
   bool WIM__boStartAcoustic(WIM_tenMsg enMsg, WIM_tenMsg enReplacedMsg);

   /**
   * The function stops a running acoustic message.
   * A mute/volume decrease of the head unit is canceled by sending specific CAN 
   * signals (if a delay is specified, the signals are canceled on timer end).
   *   @return  void
   *   @param   enMsg: Identifier of message
   *   @param   boAbort: stops sound immediately
   *   @author  T.Godemann, Schleissheimer GmbH 
   */
   void WIM__vStopAcoustic(WIM_tenMsg enMsg, bool boAbort);

   /**
   * Function restarts a currently playing sound.
   *   @param   enMsg: Identifier of message
   *   @author  D.Gottwalles, Schleissheimer GmbH 
   */
   void WIM__vRestartAcoustic(WIM_tenMsg enMsg);

   /**
   * Function returns the sound id of a message
   *   @param   enMsg: Identifier of message
   *   @param   RSST_tenSoundID: id of sound
   *   @param   pu8HilVolume: return parameter for resulting volume for HIL
   *   @return  Volume that must be used to play sound
   *   @author  T.Godemann, Schleissheimer GmbH 
   */
   uint8 WIM__u8GetVolume(WIM_tenMsg enMsg, RSST_tenSoundID enSoundId, uint8* pu8HilVolume);

   /**
   * Function returns the sound id of a message
   *   @return  RSST_tenSoundID: id of sound
   *   @param   enMsg: Identifier of message
   *   @author  T.Godemann, Schleissheimer GmbH 
   */
   RSST_tenSoundID WIM__enGetSoundId(WIM_tenMsg enMsg);

   /**
   * The function delivers the acoustic frequency. The frequency can be a beep
   * (200/200) or a gong (800/200).
   *   @return  uint16: frequency (SFG) or WIM__nInvalidFreq on error
   *   @param   enMsg: Identifier of message
   *   @author  T.Godemann, Schleissheimer GmbH 
   */
   uint16 WIM__u16GetAcuFrequency(WIM_tenMsg enMsg);

   /**
   * Function returns True, if an acoustic output needs to be synchronized with
   * a running system frequency.
   *   @return  True: sync. necessary, False: no sync. required
   *   @param   enMsg: Identifier of message
   *   @author  T.Godemann, Schleissheimer GmbH 
   */
   bool WIM__boSyncAcoustic(WIM_tenMsg enMsg);

   /**
   * Function returns True, if an acoustic is limited in time
   *   @return  True: limited, False: permanent
   *   @param   enMsg: Identifier of message
   *   @author  T.Godemann, Schleissheimer GmbH 
   */
   WIM__tenToneTypes WIM__enGetToneType(WIM_tenMsg enMsg);
    
   /**
   * Called by Scheduler to switch HU Request signals
   *   @return  void
   *   @param   enMsg: Identifier of message, boOn: switch True=On/False=Off
   *   @author  T.Godemann, Schleissheimer GmbH 
   */
   void WIM__vSwitchHUCanSignals(WIM_tenMsg enMsg, bool boOn);

   /**
   * Writes the current sound request status to DPOOL for usage by HIL
   *   @return  void
   *   @param   enSoundOutputReq: Current acoustic requested
   *   @author  D. Gottwalles, Schleissheimer GmbH 
   */
   void WIM__vSoundOutputReqHIL(WIM_tenAcousticType enSoundOutputReq);

   /**
   * Retruns the current playing sound, this output coresponds with 
   * the speaker output.
   *   @return  WIM_tenMsg
   *   @author  D. Gottwalles, Schleissheimer GmbH 
   */
   WIM_tenMsg WIM_enGetPlayingSound(void);

   /**
   * Timer function for acoustic HIL signals that show only peaks.
   *   @return  none
   *   @author  D. Gottwalles, Schleissheimer GmbH 
   */
   void WIM__vAcousticHilTimer(WIM__tenTimer enTimer, WIM__txCorrTag xCorrTag);

   /**
   * Callback function for elapsed HilBreakTimer
   *   @return  void
   *   @param   none
   *   @author  Martin Wenske, Schleissheimer GmbH 
   */
   void WIM__vHilBreakTimerElapsed(void);

   /**
   * Restart interval acoustics
   *   @return  void
   *   @param   xCorrTag: Correlation tag (message Id)
   *   @author  A.Wagner, Schleissheimer GmbH 
   */
   void WIM__vIntervalTimerElapsedCallback(WIM__txCorrTag xCorrTag);

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
#endif /* WIM__ACOUSTICVIEW_H */
