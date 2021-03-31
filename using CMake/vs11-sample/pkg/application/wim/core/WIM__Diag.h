/* Generated by Together */
#ifndef WIM__DIAG_H
#define WIM__DIAG_H
/******************************************************************************
*=====================      Copyright by Continental AG      ==================
*******************************************************************************
* Titel        : WIM__Diag.h
*
* Description  : This file implements the diagnostic interface of WIM. 
*
* Environment  : OSEK, JCP (NEC V850)
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
* Archive: $Log: WIM__Diag.h  $
* Archive: Revision 1.1.2.3 2013/08/16 13:28:38CEST Wagner-EXT, Alexander (uidw3785) 
* Archive: DC MR 33822 : IC213EL-GC WIM: display synchroneous periodic tone not stopped with display off: WDM62157
* Archive: DC MR 33932 : IC213EL GC WIM: Initial sound requests for warnings does not work if sound system is not ready
* Archive: DC MR 33999 : BR213GC-EL, E005, WIM, CWMDL: API split - ORM5621
* Archive: DC MR 34028 : BR213EL, E005, StyleGuide Validation and implementation
* Archive: DC MR 34202 : BR213IC-GC-EL, WIM: Missing HIL output for seat belt warning acoustics - Folow-Up 33655
* Archive: DC MR 34326 : BR213-GC-EL/E005.1, WIM: Display is on for 2 minutes even when warning has disappeared
* Archive: DC MR 34547 : BR213-EL, E005.1/GC,WIM: Removal of QAC warning
* Archive: DC MR 34706 : BR213-GC-EL, E005.1: Chance DOCG implementation in WIM and TPOL
* Archive: DC MR 34781 : BR213-GC-EL, E005.1, WIM: Inconsistent display output in Fault Memory
* Archive: Revision 1.1.2.2 2012/05/18 10:42:42CEST Immel-EXT, Marc (uid37561) 
* Archive: Initial revision
* Archive: Member added to project /id/dag_PF3/sw/pkg/wim/core/coreGenPF3GC/project.pj
* Archive: Revision 1.2 2012/05/18 10:42:43CEST uid37556 
* Archive: Member moved from WIM__Diag.h in project /id/dag_PF3/sw/pkg/wim/core/project.pj[dag_PF3.sw.pkg.wim_COMMON_IC222GC_VarP] to WIM__Diag.h in project /id/dag_PF3/sw/pkg/wim/core/coreGenPF3GC/project.pj[dag_PF3.sw.pkg.wim_COMMON_GenPF3GC_VarX].
* Archive: Revision 1.1 2010/11/18 15:13:22CET Brueggemann Alexander (uidt3637) (uidt3637) 
* Archive: Initial revision
* Archive: Member added to project /id/dag_PF3/sw/pkg/wim/core/project.pj
* 
*    Rev 1.2   Nov 19 2010 16:04:12   SCHL_Dirk.Gottwalles
* DC MR21122 BR222: WIM reaction at wakeupreq.
* DC MR21302 BR222/AC: Optimierung Aufruf Checkfunktion WIM
* DC MR20423 W222: WIM new acoustics requirements
* DC MR21177 Implementation of first WarnDB for E003
* DC MR21336 WIM: Using Enumeration Symbols for State/Widget Mapping
* 
*    Rev 1.1   Sep 17 2010 20:58:06   SCHL_Lars.Gruenewald
* DC MR21004 Startup MR for Module DOCG (Display Documentation Target Application)
* DC MR20908 E002/AC, Startup HIL
* 
*    Rev 1.0   Jun 11 2010 14:06:30   SCHL_Thomas.Godemann
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

/******************************************************************************
* CLASS DEFINITION
*******************************************************************************/
#ifdef TOGETHER /* open C++ class */

/**
* View class for messages with complex output
*/
class WIM__Diag {
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

   /**
   * Flag, indicates whether diagostic mode is active or not
   * @range  boolean
   * @values True: diagnostic mode active, False inactive
   */

#ifdef QAC_Analysis
#pragma PRQA_MESSAGES_OFF 2300
#endif /* QAC_Analysis */
   extern bool WIM__boDiagMode;
#ifdef QAC_Analysis
#pragma PRQA_MESSAGES_ON 2300
#endif /* QAC_Analysis */
   
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
   * Activate diagnostic mode. In this mode messages can be activated via the 
   * diagnostic interface (special commands). Diag mode can not be entered,
   * if any WIM configured message is active
   *   @return  void
   *   @param   none 
   *   @author  T.Godemann, Schleissheimer GmbH 
   */
   void WIM__vStartDiagMode(void);

   /**
   * Deactivate diagnostic mode. The function is called at the end of the 
   * diagnostic session or if any warning is activated the "regular" way.
   * All warnings are restored to their "real" state if diagnostic mode ends.
   *   @return  void
   *   @param   none 
   *   @author  T.Godemann, Schleissheimer GmbH 
   */
   void WIM__vEndDiagMode(void);

   /**
   * Function activates/deactivates a message in diagnostic mode
   *   @return  DLIB_tenReturn
   *   @param   boActivate: True > Register, False > Delete message 
   *   @author  T.Godemann, Schleissheimer GmbH 
   */
   DLIB_tenReturn WIM__enDiagWarnRequest(bool boActivate, WIM_tenMsg enMsg);

   /**
   * Function activates/deactivates a message in diagnostic mode
   *   @return  ---
   *   @param   enMsg: Message to register 
   *   @author  L.Gruenewald, Schleissheimer GmbH 
   */
   void WIM__vDiagRemoteCtrlSetWarning(WIM_tenMsg enMsg);

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
#endif /* WIM__DIAG_H */
