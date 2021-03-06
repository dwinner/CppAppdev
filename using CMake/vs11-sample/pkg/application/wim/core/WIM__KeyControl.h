/* Generated by Together */
#ifndef WIM__KEYCONTROL_H
#define WIM__KEYCONTROL_H
/******************************************************************************
*=====================      Copyright by Continental AG      ==================
*******************************************************************************
* Titel        : WIM__KeyControl.h
*
* Description  : Package private interface of key-control class:
*                The class controlls key-events delivered by KBD module.
*                It provides a global callback function, called for the active
*                display message if a key event occures
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
* Archive: $Log: WIM__KeyControl.h  $
* Archive: Revision 1.1.2.2 2012/05/18 10:42:42CEST Immel-EXT, Marc (uid37561) 
* Archive: Initial revision
* Archive: Member added to project /id/dag_PF3/sw/pkg/wim/core/coreGenPF3GC/project.pj
* Archive: Revision 1.2 2012/05/18 10:42:43CEST uid37556 
* Archive: Member moved from WIM__KeyControl.h in project /id/dag_PF3/sw/pkg/wim/core/project.pj[dag_PF3.sw.pkg.wim_COMMON_IC222GC_VarP] to WIM__KeyControl.h in project /id/dag_PF3/sw/pkg/wim/core/coreGenPF3GC/project.pj[dag_PF3.sw.pkg.wim_COMMON_GenPF3GC_VarX].
* Archive: Revision 1.1 2010/06/04 17:26:56CEST Brueggemann Alexander (uidt3637) (uidt3637) 
* Archive: Initial revision
* Archive: Member added to project /id/dag_PF3/sw/pkg/wim/core/project.pj
* 
*    Rev 1.0   Jun 11 2010 14:06:42   SCHL_Thomas.Godemann
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
* key event control class
*/
class WIM__KeyControl {
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
   * Central key event handler. Function is called for current display master if
   * a key event was detected. Key events may be used to confirm a message or do 
   * some specific handling. How the key has to be evaluated is configured in
   * the central message property table. The enumeration WIM__tenKeyCbType 
   * defines the allowed configurations.
   *   @return  none 
   *   @param   EVHD_tenReceiveEvent enKeyEvent: Message that DpoolData for Key changed
   *   @author  L.Gruenewald, Schleissheimer GmbH 
   */
   void WIM__vDoKeyEvent(EVHD_tenReceiveEvent enKeyEvent);

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
#endif /* WIM__KEYCONTROL_H */
