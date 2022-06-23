///
/// @file        TdxCommon.h
/// @copyright   Copyright (c) 2014 Toradex AG
/// $Author: andy.kiser $
/// $Rev: 2835 $ 
/// $Date: 2015-06-12 11:02:44 +0200 (Fr, 12 Jun 2015) $
/// @brief       Common definitions used in various libraries
/// 
/// @target      all (hardware independent)
///

#ifndef __TDXCOMMON_H__
#define __TDXCOMMON_H__

#include <windows.h>

//=============================================================================
// Library Package Version. This is used as the major and minor revision number
// for each single library.\n
// (The related build number is the individual SVN revision number of a library)
#define LIBPKG_VERMAJ	1
#define LIBPKG_VERMIN   3

//=============================================================================

#ifdef __cplusplus
extern "C" {
#endif

//=============================================================================

/// type definition for a software version (usually shown as `[Major].[Minor].[Build]`
typedef struct
{
    DWORD Major;     ///< Major Version Number
    DWORD Minor;     ///< Minor Version Number
    DWORD Build;     ///< Build Number
} tVersion;

//=============================================================================

/// Used when setting parameters for various Toradex libraries: defines whether
/// the parameter should be stored also in the Registry. When the library finds
/// a parameter in the registry upon initialization, the registry value will be 
/// used as default.
typedef enum 
{
    StoreToRegistry = 0,    ///< Store the value also in the registry. It will be used as new default when the library's Init() function is called.
    StoreVolatile = 1       ///< Store the parameter only temporarily, until the library's DeInit() function is called.
} ParamStorageType;


#ifdef __cplusplus
}
#endif

#endif
