///
/// @file        MapMem.h
/// @copyright   Copyright (c) 2013 Toradex AG
/// $Author: chitresh.gupta $
/// $Rev: 2661 $ 
/// $Date: 2015-02-06 13:51:13 +0100 (Fr, 06 Feb 2015) $
/// @brief       Library to support Mapping of physical to virtual addresses
/// 
/// @target      Colibri VFxx
/// 

#ifndef _MAPREG_H_
#define _MAPREG_H_

#include "TdxCommon.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PAGE_SIZE     4096   ///< Memory Page size. Physical memory is allocated in blocks of 4kB

///@cond no_doxygen
/// Common Windows API functions from pkfuncs.h, which are not defined in Visual Studio SDK header files.
LPVOID AllocPhysMem       (DWORD cbSize, DWORD fdwProtect, DWORD dwAlignmentMask, DWORD dwFlags, PULONG pPhysicalAddress);
BOOL FreePhysMem          (LPVOID lpvAddress);
BOOL VirtualCopy          (LPVOID lpvDest, LPVOID lpvSrc, DWORD cbSize, DWORD fdwProtect);
BOOL VirtualSetAttributes (LPVOID lpvAddress, DWORD cbSize, DWORD dwNewFlags, DWORD dwMask, LPDWORD lpdwOldFlags);
LPVOID CreateStaticMapping(DWORD dwPhysBase, DWORD dwSize);
///@endcond

//******************************************************************************
/// Initializes the MapReg Library
/// @return     HANDLE used for various functions in the MapReg Library.\n
///             NULL indicates an error.
HANDLE Map_Init();

//******************************************************************************
/// Deinitialises the MapReg Library
/// @retval  TRUE   Success 
/// @retval  FALSE  Failure
BOOL Map_Deinit(HANDLE hMap);
//******************************************************************************
/// Compatible version of VirtualCopy()
/// @param[in]          lpvDest             Destination Virtual Address
/// @param[in]          lpvSrc              Source Virtual Address
/// @param[in]          cbSize              Number of bytes to copy 
/// @param[in]          fdwProtect          Specifies the protection desired
/// @retval             TRUE  Success
/// @retval             FALSE Failure
BOOL Map_VirtualCopy(LPVOID lpvDest, LPVOID lpvSrc, DWORD cbSize, DWORD fdwProtect);

//******************************************************************************
/// Compatible version of VirtualSetAttributes()\n
/// Change the per-page attributes for a range of virtual memory
/// @param[in]          lpvAddress          Virtual Starting Address
/// @param[in]          cbSize              Number of bytes 
/// @param[in]          dwNewFlags          The new flags values
/// @param[in]          dwMask              Mask the bits to be changed
/// @param[out]         lpdwOldFlags        If not NULL, returns the original value of the first page entry
/// @retval             TRUE  Success
/// @retval             FALSE Failure
BOOL Map_VirtualSetAttributes(LPVOID lpvAddress, DWORD cbSize, DWORD dwNewFlags, DWORD dwMask, LPDWORD lpdwOldFlags);

//******************************************************************************
/// Compatible version of LockPages()\n
/// Locks into memory the specified region of the virtual address space
/// @param[in]          lpvAddress          Virtual Starting Address
/// @param[in]          cbSize              Number of bytes to lock
/// @param[in]          pPFNs               Array of physical frame numbers
/// @param[in]          fOptions            Option Flags
/// @retval             TRUE  Success
/// @retval             FALSE Failure
BOOL Map_LockPages(LPVOID lpvAddress, DWORD cbSize, PDWORD pPFNs, int fOptions);

//******************************************************************************
/// Setup a virtual-to-physical memory mapping 
/// @param[in]            pa                Physical address, start of region to map
/// @param[in]            size              Size to map in bytes.
/// @return               Virtual address pointing to the virtual equivalent of pa.
void *Map_MapMemory(DWORD pa, DWORD size);

//******************************************************************************
/// Remove one virtual-to-physical mapping.
/// @param[in]          pRegs:      Pointer to virtual address
void Map_UnMapMemory(volatile void *pRegs);

//******************************************************************************
/// Compatible version of AllocPhysMem()
/// @param[in]            hMap             Handle to the MapReg Library, obtained by Map_Init()
/// @param[in]            cbSize              Number of bytes to allocate
/// @param[in]            fdwProtect          Specifies the protection desired
/// @param[in]            dwAlignmentMask     Bit mask that describes the byte alignment needed.\n
///                                           If it is set to 0 (zero), the default system alignment is used.\n 
///                                           If it is set to any other value, the kernel will try to fulfill
///                                           the memory request based on the alignment request.\n
///                                           The dwAlignmentMask parameter is AND with a physical address to 
///                                           determine if the memory is aligned correctly for the request.
/// @param[in]            dwFlags             Reserved, set to 0
/// @param[in]            pPhysicalAddress    Physical address
/// @retval               0                   Error
/// @retval               >0                  Virtual address
LPVOID Map_AllocPhysMem(HANDLE hMap, DWORD cbSize, DWORD fdwProtect, DWORD dwAlignmentMask, DWORD dwFlags, PULONG pPhysicalAddress);

//******************************************************************************
/// Compatible version of FreePhysMem()
/// @param[in]          lpvAddress          Virtual Address
/// @retval             TRUE  Success
/// @retval             FALSE Failure
BOOL Map_FreePhysMem(LPVOID lpvAddress);

//******************************************************************************
/// Get Virtual Address of cached or non cached address from Physical Address
/// @param[in]            pa                  Physical Address
/// @param[in]            cached              TRUE: Cached, FALSE: Not cached
/// @return               Virtual Address
void* Map_OALPAtoVA(UINT32 pa, BOOL cached);

//******************************************************************************
/// Get the revision of this MapReg Lib
/// @param[out]     ver     library version, consist of major, minor and build version.
void Map_GetVersion(tVersion *ver);

#ifdef __cplusplus
}
#endif

#endif //_MAPREG_H_
