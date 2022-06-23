///
/// @file        adc.h
/// @copyright   Copyright (c) 2015 Toradex AG
/// $Author: chitresh.gupta $
/// $Rev: 2692 $ 
/// $Date: 2015-03-18 05:30:44 +0100 (Mi, 18 Mrz 2015) $
/// @brief       Library to support ADC on Toradex modules
/// @test        Colibri VF61 and VF50
/// @target      Colibri T30, T20, VFxx.
///

/// @page pcfg_adc ADC Configuration Options
/// @tableofcontents
///
/// @section scfg_adc Compatible ADC Configurations
/// @anchor acfg_adc
/// The following table explains the configuration parameters supported by calls of
/// * Adc_SetConfigInt()
/// * Adc_GetConfigInt()
///
/// <table class="libParam" >
///   <tr><th>                            Parameter Name </th><th> Value   </th><th> Description</th></tr>
///   <tr><td class="paramname"          >ioAdc          </td><td> DWORD   </td><td> GPIO used as ADC pin in uIo format.</td></tr>
///   <tr><td class="paramname"          >BitResolution  </td><td> 1 to 32 </td><td> Defines the ADC resolution in Bits.<br>All resolution from 1 to 32 bits are accepted and rounded to the supported values by the SoC.</td></tr>
///   <tr><td class="paramname"          >AvgSamples     </td><td> 1 to 64 </td><td> Defines the number of ADC conversion which will be performed for a single averaged result.<br>All values from 1 to 64 are accepted and rounded to the supported values by the SoC.</td></tr>
/// </table>
///

#ifndef __ADC_H__
#define __ADC_H__

#include <windows.h> 
#include "TdxCommon.h"

#ifdef __cplusplus
extern "C" {
#endif

//******************************************************************************
/// Initialize HANDLE for the ADC channel.\n 
/// This function call does not modify any hardware registers. Therefore the 
/// returned handle can be used to make additional configuration settings, which 
/// will become active when calling Adc_Open().
/// @param[in]    portName    ADC channel name. Can be one of these: <ul><li>L"ADC1"</li><li>L"ADC2"</li><li>L"ADC3"</li><li>L"ADC4"</li></ul>
/// @retval       Handle to the ADC port. NULL if the function failed.
HANDLE Adc_Init(const TCHAR *portName);

//******************************************************************************
/// De-initialize HANDLE for the ADC.
/// @param[in]    hPort       HANDLE to ADC channel
/// @retval       TRUE        Success
/// @retval       FALSE       Failure
BOOL Adc_Deinit(HANDLE hPort);

//******************************************************************************
/// Apply configuration to the hardware, If it is stored in registry path.
/// @param[in]    hPort       HANDLE to ADC channel
/// @retval       TRUE        Success
/// @retval       FALSE       Failure
BOOL Adc_Open(HANDLE hPort);

//******************************************************************************
/// Close ADC
/// @param[in]    hPort       HANDLE to ADC channel
/// @retval       TRUE        Success
/// @retval       FALSE       Failure
BOOL Adc_Close(HANDLE hPort);

//******************************************************************************
/// Read ADC channel
/// @param[in]    hPort       HANDLE to ADC channel
/// @param[out]   microVolts  ADC value in Micro Volts. 
/// @param[in]    maxBytes    Ignored, the implementation always assumes 4.
/// @return       Number of Bytes received. 0 means failure.
DWORD Adc_Read(HANDLE hPort, DWORD *microVolts, DWORD maxBytes);

//******************************************************************************
/// Retrieves a DWORD configuration parameter.
/// @param[in]    hPort       HANDLE to ADC channel
/// @param[in]    paramName   Parameter value to retrieve\n
///                           Refer to the @ref scfg_adc for a list of supported parameters.
/// @param[out]   pValue      Data obtained
/// @return                   Number of bytes read. 0 if paramName not found.
DWORD Adc_GetConfigInt(HANDLE hPort, const TCHAR *paramName, DWORD *pValue);

//******************************************************************************
/// Set a DWORD configuration parameter.
/// @param[in]    hPort       HANDLE to ADC channel
/// @param[in]    paramName   Parameter value to configure.\n
///                           Refer to the @ref scfg_adc for a list of supported parameters.
/// @param[in]    value       Data to be set
/// @param[in]    storageType StoreInRegistry = parameter will also be stored in the registry\n
///                           StoreVolatile   = parameter will only be stored in local variable.
/// @retval       TRUE        Success
/// @retval       FALSE       Failure
BOOL Adc_SetConfigInt(HANDLE hPort, const TCHAR *paramName, DWORD value, ParamStorageType storageType);

//******************************************************************************
/// Get the revision of this Adc library
/// @param[out]    ver        library version, consisting of major, minor and build version
void Adc_GetVersion(tVersion *ver);

#ifdef __cplusplus
}
#endif

#endif