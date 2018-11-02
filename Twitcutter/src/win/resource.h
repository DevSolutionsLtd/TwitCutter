// resource.h

#ifndef _RESOURCE_H_INCLUDED_
#define _RESOURCE_H_INCLUDED_

#include <winres.h>

// Resources
#define IDR_APPMENU       101
#define IDC_MAIN_EDIT     102
  // These values define individual
  // dialog box resources.
#define IDD_ABOUT         103
#define IDD_ADDFILE       104

// Icons
#define IDI_APPICON       201

// Menu commands
  // File menu
#define ID_FILE_NEW       1001
#define ID_FILE_OPEN      1002
#define ID_FILE_SAVE      1003
#define ID_FILE_SAVEAS    1004
#define ID_FILE_EXIT      1009
  
  // Edit menu
#define ID_EDIT_CUT       2001
#define ID_EDIT_COPY      2002
#define ID_EDIT_PASTE     2003
#define ID_EDIT_FIND      2004
#define ID_EDIT_REPLACE   2005

// Connect menu
#define ID_CONNECT_POST   3001

  // View menu
#define ID_VIEW           4001

  // Tools menu
#define ID_TOOLS_OPTIONS  5001

  // Help menu
#define ID_HELP_ABOUT     6001

// Command macros
#define IDBROWSE             901 // TODO: Place or displace!
#endif // !_RESOURCE_H_INCLUDED_