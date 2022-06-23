///
/// @file        KernelCallback.h
/// @copyright   Copyright (c) 2015 Toradex AG
/// @author      $Author: andy.kiser $
/// @version     $Rev: 2635 $ 
/// @date        $Date: 2015-01-30 13:28:31 +0100 (Fr, 30 Jan 2015) $
/// @brief       Provides Kernel Call functions for Applications
/// 
/// @target      All Colibri and Apalis modules
/// 

#ifndef _KERNELCALLBACK_H_
#define _KERNELCALLBACK_H_

#include <windows.h>
#include "tdxcommon.h"

#ifdef __cplusplus
extern "C" {
#endif

/// List of available Kernel Callback functions
/// Each value is an index matching a kernel-function-pointer
typedef enum 
{
    idGetModuleHandle,
    idGetProcAddress,
    idAllocPhysMem,
    idCacheRangeFlush,
    idCacheSync, 
    idCeGetCacheInfo,
    idCeSetMemoryAttributes,
    idCeSetPowerOnEvent,
    idCeVirtualSharedAlloc,
    idCreateStaticMapping,
    idDrWatsonClear,
    idDrWatsonFlush,
    idDrWatsonGetSize,
    idDrWatsonReadData,
    idDrWatsonWriteData,
    idForcePageout,
    idFreeIntChainHandler,
    idFreePhysMem,
    idGetCallerProcess,
    idGetStdioPathW,
    idGetSystemMemoryDivision,
    idInterruptDisable,
    idInterruptDone,
    idInterruptInitialize,
    idInterruptMask,
    idKernelLibIoControl,
    idLoadDriver,
    idLoadIntChainHandler,
    idLockPages,
    idOpenWatchDogTimer,
    idPageOutModule, 
    idProfileCaptureStatus,
    idRefreshWatchDogTimer,
    idSetDbgZone,
    idSetInterruptEvent,
    idSetJITDebuggerPath,
    idSetStdioPathW, 
    idSetSystemMemoryDivision,
    idUnlockPages,
    idVirtualCopy,
    idVirtualCopyEx,
    idVirtualSetAttributes,
    idCloseHandle,
    idLastEntry
} eKFn;


//******************************************************************************
/// Initialises the KernelCallback Library.\n
/// If Kcb_GetFunctionPointer() is not used, it is safe to call Kcb_DoKernelCallBack() without prior call to Kcb_Init()
/// @return  Handle to the KernelCallback Library.\n
///          NULL indicates failure
HANDLE Kcb_Init(void);

//******************************************************************************
/// Deinitialises the Kernel Callback Library
/// @param[in]  hKcb    Handle to the KernelCallback library, obtained in Kcb_Init()
///                     This parameter is currently unused, therefore passing NULL is allowed.
/// @retval     TRUE    Success - this function always returns TRUE
BOOL Kcb_Deinit(HANDLE hKcb);

//******************************************************************************
/// Request a Kernel function pointer. This is used in pArgs[1], when calling Kcb_DoKernelCallBack()
/// @param[in]  hKcb                Handle to the KernelCallback library, obtained in Kcb_Init()
///                                 This parameter is currently unused, therefore passing NULL is allowed.
/// @param[in]  kernelFunction      Enumeration value which defines the Kernel function (see type eKFn)   
/// @return                         Pointer to the Kernel function. This pointer is used to setup 
///                                 a call to Kcb_DoKernelCallBack().
void *Kcb_GetFunctionPointer(HANDLE hKcb, eKFn kernelFunction);

//******************************************************************************
/// Uses IOCTL for various utility function calls.
/// @param[in]            pArgs     Array of arguments, which are used for the callback functions.\n
///                                 pArgs[0] (DWORD) KCID_CALLBACK = 0 ; always use this constant value.\n
///                                 pArgs[1] (DWORD) Pointer to the callback function. Use KFn[i], where i is an element of the eKFn enumeration.
///                                 pArgs[2 to n]    Parameters, which will be passed to the callback function.
/// @param[in]            size      Size of the pArgs array in Bytes.         
/// @retval               TRUE      Callback function succeeded.
/// @retval               FALSE     Error.
DWORD Kcb_DoKernelCallBack(void *pArgs, DWORD size);

//-------------------------------------------------------------------------
/// Get the revision of this KernelCallback lib
/// @param[out]     ver     library version, consisting of major, minor and build version.
void Kcb_GetVersion(tVersion *ver);

#ifdef __cplusplus
}
#endif

#endif // _KERNELLCALLBACK_H_
