/******************************************************************************
*******************************************************************************
** COPYRIGHT:      (c) 1997, Rohde & Schwarz Services Ltd, Fleet, England
** MODULE:         $Header: \ZVAB\SW\RunTime\Rsib\rsib.h   \main\1    22 Nov 2006 10:10:08   anastase $
** ABBREVIATION:   MOD
** COMPILER:       MICROSOFT Visual C++ V1.52/V5.0
** LANGUAGE:       ANSI-C
** AUTHOR:         $Author: anastase $
** ABSTRACT        Interface definition for the RSIB library.
** PREMISES:       None.
** REMARKS:        None.
** HISTORY:        
** REVIEW_DATE:    
*******************************************************************************
*******************************************************************************/

// Check for previous inclusion
#ifndef _RohdeAndSchwarz_RSIB_h
#define _RohdeAndSchwarz_RSIB_h

// Force C compilation
#ifdef __cplusplus
extern "C"
{
#endif

/* INCLUDE FILES **************************************************************/
#include <Windows.h>

/* DEFINES ********************************************************************/

// NI-488 status values
#define IBSTA_ERR   (short)0x8000 // Error bit
#define IBSTA_TIMO  (short)0x4000 // Time limit exceeded
#define IBSTA_CMPL  (short)0x0100 // I/O completed
#define IBSTA_REM   (short)0x0040 // Remote state

// NI-488 error codes for iberr
#define IBERR_DEVICE_REGISTER   (short)1
#define IBERR_CONNECT           (short)2
#define IBERR_NO_DEVICE         (short)3
#define IBERR_MEM               (short)4
#define IBERR_TIMEOUT           (short)5
#define IBERR_BUSY              (short)6
#define IBERR_FILE              (short)7

#define IBERR_UNKNOWN           (short)-1

/* GLOBAL TYPES DECLARATION ***************************************************/
/* GLOBAL CLASSES DECLARATION *************************************************/
/* CLASS **********************************************************************/
/* GLOBAL VARIABLES DECLARATION ***********************************************/
/* GLOBAL CONSTANTS DECLARATION ***********************************************/
/* GLOBAL FUNCTIONS DECLARATION ***********************************************/



//----------------
// Initialisation
//----------------

/* FUNCTION *******************************************************************/
short WINAPI RSDLLibfind( char far* szName,
                          short far* ibsta,
                          short far* iberr,
                          unsigned long far* ibcntl);
/* 
SPECIFICATION:
  Provides a handle with which to access the named instrument.
    This function must be called before any other interface functions are used.
PARAMETERS:
  szName - Name of the instrument.  Either an IP address (e.g. "89.1.1.200") for a
             remote connection or "@local" for the local instrument.
    ibsta  - OUTPUT: Status of the RSIB interface.
    iberr  - OUTPUT: Error code (if the ERR bit is set in the status word)
    ibcntl - Not used.
PRECONDITIONS:
  None.
SIDE_EFFECTS:
  None.
RETURN_VALUES:
  The handle of the instrument object or
    -1 if not found.
EXCEPTIONS:
  None.
*******************************************************************************/


//---------------------
// Write to instrument
//---------------------

/* FUNCTION *******************************************************************/
short WINAPI RSDLLibwrt( short  ud,
                         char far* szWrt,
                         short far* ibsta,
                         short far* iberr,
                         unsigned long far* ibcntl);
/* 
SPECIFICATION:
  Writes a string to the instrument.  String is NULL terminated.
PARAMETERS:
  ud     - Handle of instrument as returned by RSDLLibfind().
  szWrt  - String to write.
  ibsta  - OUTPUT: Status of the RSIB interface.
  iberr  - OUTPUT: Error code (if the ERR bit is set in the status word)
  ibcntl - OUTPUT: Number of bytes written.
PRECONDITIONS:
  None.
SIDE_EFFECTS:
  None.
RETURN_VALUES:
  NI status word (ibsta).
EXCEPTIONS:
  None.
*******************************************************************************/


/* FUNCTION *******************************************************************/
short WINAPI RSDLLilwrt( short  ud,
                         char far* pcWrt,
                         unsigned long  ulCnt,
                         short far* ibsta,
                         short far* iberr,
                         unsigned long far* ibcntl);
/* 
SPECIFICATION:
  Writes the string to the instrument.  String length is given.
PARAMETERS:
  ud     - Handle of instrument as returned by RSDLLibfind().
  pcWrt  - String to write.
  ulCnt  - Number of bytes to write.
  ibsta  - OUTPUT: Status of the RSIB interface.
  iberr  - OUTPUT: Error code (if the ERR bit is set in the status word)
  ibcntl - OUTPUT: Number of bytes written.
PRECONDITIONS:
  None.
SIDE_EFFECTS:
  None.
RETURN_VALUES:
  NI status word (ibsta).
EXCEPTIONS:
  None.
*******************************************************************************/


/* FUNCTION *******************************************************************/
short WINAPI RSDLLibwrtf( short  ud,
                          char far* szFileName,
                          short far* ibsta,
                          short far* iberr,
                          unsigned long far* ibcntl);
/* 
SPECIFICATION:
  Writes the contents of the given file to the instrument.
PARAMETERS:
  ud         - Handle of instrument as returned by RSDLLibfind().
    szFileName - Name of file to open.
    ibsta      - OUTPUT: Status of the RSIB interface.
    iberr      - OUTPUT: Error code (if the ERR bit is set in the status word)
    ibcntl     - OUTPUT: Number of bytes written.
PRECONDITIONS:
  None.
SIDE_EFFECTS:
  None.
RETURN_VALUES:
  NI status word (ibsta).
EXCEPTIONS:
  None.
*******************************************************************************/


//--------------------------
// Read from the instrument
//--------------------------

/* FUNCTION *******************************************************************/
short WINAPI RSDLLibrd( short  ud,
                        char far* pcRd, 
                        short far* ibsta,
                        short far* iberr,
                        unsigned long far* ibcntl);
/* 
SPECIFICATION:
  Reads data from the instrument.
PARAMETERS:
  ud     - Handle of instrument as returned by RSDLLibfind().
    pcRd   - Buffer for storing the read data.
    ibsta  - OUTPUT: Status of the RSIB interface.
    iberr  - OUTPUT: Error code (if the ERR bit is set in the status word)
    ibcntl - OUTPUT: Number of bytes read.
PRECONDITIONS:
  None.
SIDE_EFFECTS:
  None.
RETURN_VALUES:
  0 = Success.
  Anything else indicates an error.
EXCEPTIONS:
  None.
*******************************************************************************/


/* FUNCTION *******************************************************************/
short WINAPI RSDLLilrd( short  ud,
                        char far* pcRd,
                        unsigned long  ulCnt,
                        short far* ibsta,
                        short far* iberr,
                        unsigned long far* ibcntl);
/* 
SPECIFICATION:
  Reads data from the instrument.
PARAMETERS:
  ud     - Handle of instrument as returned by RSDLLibfind().
    pcRd   - Buffer for storing the read data.
    ulCnt  - Max no. of bytes to read.
    ibsta  - OUTPUT: Status of the RSIB interface.
    iberr  - OUTPUT: Error code (if the ERR bit is set in the status word)
    ibcntl - OUTPUT: Number of bytes read.
PRECONDITIONS:
  None.
SIDE_EFFECTS:
  None.
RETURN_VALUES:
  NI status word (ibsta).
EXCEPTIONS:
  None.
*******************************************************************************/


/* FUNCTION *******************************************************************/
short WINAPI RSDLLibrdf( short  ud,
                         char far* szFileName,
                         short far* ibsta,
                         short far* iberr,
                         unsigned long far* ibcntl);
/* 
SPECIFICATION:
  Reads data from the instrument.
PARAMETERS:
  ud         - Handle of instrument as returned by RSDLLibfind().
    szFileName - File in which to store data.
    ibsta      - OUTPUT: Status of the RSIB interface.
    iberr      - OUTPUT: Error code (if the ERR bit is set in the status word)
    ibcntl     - OUTPUT: Number of bytes read.
PRECONDITIONS:
  None.
SIDE_EFFECTS:
  None.
RETURN_VALUES:
  NI status word (ibsta).
EXCEPTIONS:
  None.
*******************************************************************************/


//-----
// SRQ
//-----

/* FUNCTION *******************************************************************/
void WINAPI RSDLLTestSrq( short  ud,
                          short far* result,
                          short far* ibsta,
                          short far* iberr,
                          unsigned long far* ibcntl);
/* 
SPECIFICATION:
  Tests the SRQ (IEC bus) of the instrument and returns the state..
PARAMETERS:
  ud     - Handle of instrument as returned by RSDLLibfind().
    result - Status of SRQ line.
    ibsta  - OUTPUT: Status of the RSIB interface.
    iberr  - OUTPUT: Error code (if the ERR bit is set in the status word)
    ibcntl - Not used.
PRECONDITIONS:
  None.
SIDE_EFFECTS:
  None.
RETURN_VALUES:
  None.
EXCEPTIONS:
  None.
*******************************************************************************/


/* FUNCTION *******************************************************************/
void WINAPI RSDLLWaitSrq( short  ud,
                          short far* result,
                          short far* ibsta,
                          short far* iberr,
                          unsigned long far* ibcntl);
/* 
SPECIFICATION:
  Returns when the SRQ is set (or timeout is reached).
PARAMETERS:
  ud     - Handle of instrument as returned by RSDLLibfind().
  result - Status of SRQ line.
  ibsta  - OUTPUT: Status of the RSIB interface.
  iberr  - OUTPUT: Error code (if the ERR bit is set in the status word)
  ibcntl - Not used.
PRECONDITIONS:
  None.
SIDE_EFFECTS:
  None.
RETURN_VALUES:
  None.
EXCEPTIONS:
  None.
*******************************************************************************/


//------
// Misc
//------

/* FUNCTION *******************************************************************/
short WINAPI RSDLLibrsp( short  ud,
                         char far*  spr,
                         short far* ibsta,
                         short far* iberr,
                         unsigned long far* ibcntl);
/* 
SPECIFICATION:
  Conduct a serial poll.
PARAMETERS:
  ud     - Handle of instrument as returned by RSDLLibfind().
  spr    - OUTPUT: serial poll response byte.
  ibsta  - OUTPUT: Status of the RSIB interface.
  iberr  - OUTPUT: Error code (if the ERR bit is set in the status word)
  ibcntl - Not used.
PRECONDITIONS:
  None.
SIDE_EFFECTS:
  None.
RETURN_VALUES:
  NI status word (ibsta).
EXCEPTIONS:
  None.
*******************************************************************************/

/* FUNCTION *******************************************************************/
void WINAPI RSDLLibtmo( short  ud,
                        short  tmo,
                        short far* ibsta,
                        short far* iberr,
                        unsigned long far* ibcntl);
/* 
SPECIFICATION:
  Sets the timeout for all operations.
PARAMETERS:
  ud     - Handle of instrument as returned by RSDLLibfind().
    tmo    - Timeout in seconds.
    ibsta  - OUTPUT: Status of the RSIB interface.
    iberr  - OUTPUT: Error code (if the ERR bit is set in the status word)
    ibcntl - Not used.
PRECONDITIONS:
  None.
SIDE_EFFECTS:
  None.
RETURN_VALUES:
  NI status word (ibsta).
EXCEPTIONS:
  None.
*******************************************************************************/


/* FUNCTION *******************************************************************/
void WINAPI RSDLLibsre( short  ud,
                        short  v,
                        short far* ibsta,
                        short far* iberr,
                        unsigned long far* ibcntl);
/* 
SPECIFICATION:
  Sets the instrument into remote/local mode.
PARAMETERS:
  ud     - Handle of instrument as returned by RSDLLibfind().
    v      - 0 = Local, 1 = Remote.
    ibsta  - OUTPUT: Status of the RSIB interface.
    iberr  - OUTPUT: Error code (if the ERR bit is set in the status word)
    ibcntl - Not used.
PRECONDITIONS:
  None.
SIDE_EFFECTS:
  None.
RETURN_VALUES:
  None.
EXCEPTIONS:
  None.
*******************************************************************************/


/* FUNCTION *******************************************************************/
short WINAPI RSDLLibclr(           short  ud,
                                   short* ibsta,
                                   short* iberr,
                                   unsigned long* ibcntl);
/* 
SPECIFICATION:
    Sends Selected Device Clear (SDC) message to the instrument.
PARAMETERS:
    ud     - Handle of instrument as returned by RSDLLibfind().
  ibsta  - OUTPUT: Status of the RSIB interface.
  iberr  - OUTPUT: Error code (if the ERR bit is set in the status word)
  ibcntl - Not used.
PRECONDITIONS:
    None.
SIDE_EFFECTS:
    None.
RETURN_VALUES:
    NI status word (ibsta).
EXCEPTIONS:
    None.
*******************************************************************************/


/* FUNCTION *******************************************************************/
void WINAPI RSDLLibloc( short  ud,
                        short far* ibsta,
                        short far* iberr,
                        unsigned long far* ibcntl);
/* 
SPECIFICATION:
  Sets the instrument temporarily into local mode.
PARAMETERS:
  ud     - Handle of instrument as returned by RSDLLibfind().
    ibsta  - OUTPUT: Status of the RSIB interface.
    iberr  - OUTPUT: Error code (if the ERR bit is set in the status word)
    ibcntl - Not used.
PRECONDITIONS:
  None.
SIDE_EFFECTS:
  None.
RETURN_VALUES:
  None.
EXCEPTIONS:
  None.
*******************************************************************************/


/* FUNCTION *******************************************************************/
void WINAPI RSDLLibeot( short  ud,
                        short  v,
                        short far* ibsta,
                        short far* iberr,
                        unsigned long far* ibcntl);
/* 
SPECIFICATION:
  Sets whether strings will be sent to the parser with EOS or not.
PARAMETERS:
  ud     - Handle of instrument as returned by RSDLLibfind().
    v      - 
    ibsta  - OUTPUT: Status of the RSIB interface.
    iberr  - OUTPUT: Error code (if the ERR bit is set in the status word)
    ibcntl - Not used.
PRECONDITIONS:
  None.
SIDE_EFFECTS:
  None.
RETURN_VALUES:
  None.
EXCEPTIONS:
  None.
*******************************************************************************/

/* FUNCTION *******************************************************************/
void WINAPI RSDLLibonl( short  ud,
                        short  v,
                        short far* ibsta,
                        short far* iberr,
                        unsigned long far* ibcntl);
/* 
SPECIFICATION:
    If v is zero, the device is taken offline. 
    If v is non-zero, the device is left operational, or online.
    
    If a device is taken offline, the device descriptor (ud) is no longer valid. 
    You must execute an RSDLLibfind to access the board again.
    
PARAMETERS:
  ud     - Handle of instrument as returned by RSDLLibfind().
    v      - Indicates whether the device is to be taken online or offline.
    ibsta  - OUTPUT: Status of the RSIB interface.
    iberr  - OUTPUT: Error code (if the ERR bit is set in the status word)
    ibcntl - Not used.
PRECONDITIONS:
  None.
SIDE_EFFECTS:
  None.
RETURN_VALUES:
  None.
EXCEPTIONS:
  None.
*******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif // ifndef _RohdeAndSchwarz_RSIB_h

