///
/// @file        int.h
/// @copyright   Copyright (c) 2015 Toradex AG
/// $Author: chitresh.gupta $
/// $Rev: 2669 $ 
/// $Date: 2015-02-09 14:34:41 +0100 (Mo, 09 Feb 2015) $
/// @brief       Functions to setup and use Interrupt Service Threads (IST) and 
///              Installable Interrupt Service Routines (ISR).
/// @target      Txx , VFxx
/// @caveats     This library can only be used in user mode. It does not work in kernel mode.

#ifndef _INT_H_
#define _INT_H_

#include "TdxCommon.h"

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus


//******************************************************************************
/// Interrupt initialize function.\n
/// This function can be used in Kernel mode as well as in User mode.
/// @return   Handle to the Interrupt Library.\n
///           NULL indicates a failure.\n
///           In Kernel mode, the function always returns 0xffffffff.
HANDLE Int_Init(void);

//******************************************************************************
/// De Initialize function.Free Loaded Library of coredll.\n
/// This function can be used in Kernel mode as well as in User mode.
/// @param[in]            hInt            Handle to the interrupt library, 
///                                       obtained by calling Int_Init()
/// @retval               TRUE            Success
/// @retval               FALSE           Failure
BOOL Int_Deinit(HANDLE hInt);


//=============================================================================
// Compatible Kernel interrupt function  
//=============================================================================

//******************************************************************************
/// Win CE 5.0/6.0/7.0/2013 compatible version of LoadIntChainHandler()\n
/// This function can be used in Kernel mode as well as in User mode.
/// @param[in]            hInt             Handle to the interrupt library, 
///                                        obtained by calling Int_Init()
/// @param[in]            lpFilename       Pointer to File name
/// @param[in]            lpszFunctionName Function Name String
/// @param[in]            bIRQ             IRQ Number
/// @return               Instance Handle
HANDLE Int_LoadIntChainHandler(HANDLE hInt, LPCWSTR lpFilename, LPCWSTR lpszFunctionName, BYTE bIRQ);

//******************************************************************************
/// Win CE 5.0/6.0/7.0/2013 compatible version of FreeIntChainHandler()
/// This function can be used in Kernel mode as well as in User mode
/// @param[in]            hInt            Handle to the interrupt library, 
///                                       obtained by calling Int_Init()
/// @param[in]            hInstance       Instance Handle
/// @retval               TRUE            Success
/// @retval               FALSE           Failure
BOOL Int_FreeIntChainHandler(HANDLE hInt, HANDLE hInstance);

//******************************************************************************
/// Win CE 5.0/6.0/7.0/2013 compatible version of InterruptInitialize()\n
/// This function can be used in Kernel mode as well as in User mode.
/// @caveat     On Tegra modules, this function requires Windows CE image V0.1beta7 or later.
/// @param[in]            hInt            Handle to the interrupt library, 
///                                       obtained by calling Int_Init()
/// @param[in]            idInt           Interrupt ID
/// @param[in]            hEvent          Event Handle
/// @param[in]            pvData          Pointer to data buffer
/// @param[in]            cbData          Size of data buffer
/// @retval               TRUE            Success
/// @retval               FALSE           Failure
BOOL Int_InterruptInitialize(HANDLE hInt, DWORD idInt, HANDLE hEvent, LPVOID pvData, DWORD cbData);

//******************************************************************************
/// Win CE 5.0/6.0/7.0/2013 compatible version of InterruptDisable()\n
/// This function can be used in Kernel mode as well as in User mode.
/// @param[in]            hInt            Handle to the interrupt library, 
///                                       obtained by calling Int_Init()
/// @param[in]            idInt           Interrupt ID
void Int_InterruptDisable(HANDLE hInt, DWORD idInt);


//******************************************************************************
/// Win CE 5.0/6.0/7.0/2013 compatible version of InterruptDone()\n
/// This function can be used in Kernel mode as well as in User mode.
/// @param[in]            hInt            Handle to the interrupt library, 
///                                       obtained by calling Int_Init()
/// @param[in]            idInt           Interrupt ID
void Int_InterruptDone(HANDLE hInt, DWORD idInt);

//******************************************************************************
/// Win CE 5.0/6.0/7.0/2013 compatible version of CreateStaticMapping()\n
/// This function can be used in Kernel mode as well as in User mode.\n
/// It enables an application to map any physical address to a static 
/// virtual memory address that can then be used in an interrupt service 
/// routine (ISR). An ISR can access only a static mapped virtual address.
/// @param[in]           hInt             Handle to the interrupt library, 
///                                       obtained by calling Int_Init()
/// @param[in]           dwPhysBase       Starting physical address to map. 
///                                       The address passed in must be right-shifted by 8.
/// @param[in]           dwSize           Number of bytes to map, starting from dwPhysBase.
/// @return     If the memory can be mapped, a valid static virtual memory 
///             pointer is returned. The virtual memory address returned is for 
///             an uncached memory region.
LPVOID Int_CreateStaticMapping(HANDLE hInt, DWORD dwPhysBase, DWORD dwSize);

//******************************************************************************
/// Win CE 5.0/6.0/7.0/2013 compatible version of KernelLibIoControl()\n
/// This function can be used in Kernel mode as well as in User mode.
/// @param[in]            hInt            Handle to the interrupt library, 
///                                       obtained by calling Int_Init().\n
///                                       Currently not used in this function.
/// @param[in]            hModule         Module Handle
/// @param[in]            dwIoControlCode IO Control Code
/// @param[in]            lpInBuf         Pointer to Input Buffer
/// @param[in]            nInBufSize      Input Buffer Size in bytes
/// @param[in]            lpOutBuf        Pointer to Output Buffer
/// @param[in]            nOutBufSize     Output Buffer Size
/// @param[out]           lpBytesReturned Number of bytes returned
/// @retval               TRUE            Success
/// @retval               FALSE           Failure
BOOL Int_KernelLibIoControl(HANDLE hInt, HANDLE hModule, DWORD dwIoControlCode, LPVOID lpInBuf, DWORD nInBufSize, LPVOID lpOutBuf, DWORD nOutBufSize, LPDWORD lpBytesReturned);

//******************************************************************************
/// Win CE 5.0/6.0/7.0/2013 compatible version of the GetCurrentProcessId() 
/// function. This implementation works, even if it was build with an SDK 
/// for the wrong WinCE version.
/// @param[in]            hInt            Handle to the interrupt library, 
///                                       obtained by calling Int_Init()
/// @return               Process ID of the current process.
DWORD Int_GetCurrentProcessId(HANDLE hInt);

// The following functions are also defined in KERNEL MODE


//******************************************************************************
/// Get the System Interrupt Number for the specified IRQ
/// @param[in]            hInt            Handle to the interrupt library, 
///                                       obtained by calling Int_Init().\n
///                                       Currently not used in this function.
/// @param[in]            dwIrq           IRQ to translate into a SYSINTR
/// @return               SYSINTR translated from an IRQ.\n
///                       0 indicates a failure.
DWORD Int_RequestSysInterrupt(HANDLE hInt, DWORD dwIrq);


//******************************************************************************
/// Release the specified system interrupt
/// @param[in]            hInt            Handle to the interrupt library, 
///                                       obtained by calling Int_Init().\n
///                                       Currently not used in this function.
/// @param[in]            dwSysIntr       System Interrupt Number
/// @retval               TRUE            Success
/// @retval               FALSE           Failure\n
///                                       Some OS releases always return FALSE here. 
///                                       We will add more details about this issue.
BOOL Int_ReleaseSysIntr(HANDLE hInt, DWORD dwSysIntr);

//******************************************************************************
/// Get the revision of this Interrupt Lib
/// @param[out]     ver     library version, consist of major, minor and build version.
void Int_GetVersion(tVersion *ver);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _INT_H_
