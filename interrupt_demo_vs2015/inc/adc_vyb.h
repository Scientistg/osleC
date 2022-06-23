///
/// @file        adc_vyb.h
/// @copyright   Copyright (c) 2015 Toradex AG
/// $Author: chitresh.gupta $
/// $Rev: 2692 $ 
/// $Date: 2015-03-18 05:30:44 +0100 (Mi, 18 Mrz 2015) $
/// @brief       Library to support ADC on Toradex modules
/// @test        Colibri VF61 and VF50
/// @target      Colibri T30, T20, VFxx.
///
/// @anchor vybadc_pins
/// <h2 class ="groupheader">ADC Pin Availability on Colibri VF50/VF61 modules</h2>
/// The following table is valid only for Colibri VF50 and Colibri VF61.\n
/// The Compatible ADC channels as defined on the Colibri Evaluation board are listed
/// in the column "ADC".
///              
/// |   SODIMM   |  GPIO  |  AltFn  |  ADC(Analog input) | ADC controller |  ADC Channel |
/// | :--------: | :----: | :-----: | :----------------: | :------------: | :----------: |
/// |    *16     |   8    |     2   |          -         |        0       |         0    |
/// |    *14     |   9    |     2   |          -         |        0       |         1    |
/// |     59     |   22   |     2   |          -         |        0       |         2    |
/// |     30     |   23   |     2   |          -         |        0       |         3    |
/// |     21     |   26   |     3   |          -         |        0       |         4    |
/// |     95     |   103  |     6   |          -         |        0       |         5    |
/// |     NA     |   59   |     6   |          -         |        0       |         6    |
/// |     NA     |   60   |     6   |          -         |        0       |         7    |
/// |     8      |   -    |     -   |       ADC1 (0)     |        0       |         8    |
/// |     4      |   -    |     -   |       ADC3 (2)     |        0       |         9    |
/// |    *18     |   6    |     3   |          -         |        1       |         0    |
/// |     134    |   7    |     3   |          -         |        1       |         1    |
/// |    *20     |   24   |     2   |          -         |        1       |         2    |
/// |    *24     |   25   |     2   |          -         |        1       |         3    |
/// |     19     |   27   |     3   |          -         |        1       |         4    |
/// |    *22     |   104  |     6   |          -         |        1       |         5    |
/// |     NA     |   61   |     6   |          -         |        1       |         6    |
/// |     NA     |   62   |     6   |          -         |        1       |         7    |
/// |     6      |   -    |     -   |       ADC2 (1)     |        1       |         8    |
/// |     2      |   -    |     -   |       ADC4 (3)     |        1       |         9    |
///
/// *These pins are used for other functionality. Please refer Module datasheet for detail information.

/// @page    pcfg_adc     ADC Configuration Options
/// @section scfg_adc_vyb VF50/VF61 ADC Configurations
/// @anchor acfg_adc_vyb
/// For a list of compatible parameters, refer to @ref acfg_adc "Compatible ADC Configurations".
/// <table class="libParam" >
///   <tr><th>                              Parameter Name </th><th> Value   </th><th> Description</th></tr>
///   <tr><td class="paramname"            >ioAdc          </td><td> DWORD   </td><td> GPIO used as ADC pin in uIo format.<br>The @ref vybadc_pins "Vybrid ADC pins" shows a list of GPIOs with ADC functionality.</td></tr>
///   <tr><td class="paramname"            >BitResolution  </td><td> 1 to 32 </td><td> Defines the ADC resolution in Bits.<br>All resolution from 1 to 32 bits are accepted and the best available resolution (8, 10 and 12) is selected.</td></tr>
///   <tr><td class="paramname"            >AvgSamples     </td><td> 1 to 64 </td><td> Defines the number of ADC conversion which will be performed for a single averaged result.<br>All values from 1 to 64 are accepted and the best available number of samples (4, 8, 16 and 32) is selected.</td></tr>
/// </table>
///

#ifndef __ADC_VYB_H__
#define __ADC_VYB_H__

#include <windows.h> 
#include "TdxCommon.h"

#ifdef __cplusplus
extern "C" {
#endif

//******************************************************************************
/// Initialize HANDLE for the ADC channel.\n
/// This function call does not modify any hardware registers. Therefore the
/// returned handle can be used to make additional configuration settings, which
/// will become active when calling VybAdc_Open().
/// @param[in]    portName    ADC channel name. Can be one of these: <ul><li>L"ADC1"</li><li>L"ADC2"</li><li>L"ADC3"</li><li>L"ADC4"</li></ul>
/// @retval       Handle to the ADC port. NULL if the function failed.
HANDLE VybAdc_Init(const TCHAR *portName);

//******************************************************************************
/// Finally close the HANDLE. The port must be closed before.
/// @param[in]    hPort       HANDLE to ADC channel
/// @retval       TRUE        Success
/// @retval       FALSE       Failure
BOOL VybAdc_Deinit(HANDLE hPort);

//******************************************************************************
/// Apply configuration to the hardware, If it is stored in registry path.
/// @param[in]    hPort       HANDLE to ADC channel
/// @retval       TRUE        Success
/// @retval       FALSE       Failure
BOOL VybAdc_Open(HANDLE hPort);

//******************************************************************************
/// Close ADC
/// @param[in]    hPort       HANDLE to ADC channel
/// @retval       TRUE        Success
/// @retval       FALSE       Failure
BOOL VybAdc_Close(HANDLE hPort);

//******************************************************************************
/// Read ADC channel
/// @param[in]    hPort       HANDLE to ADC channel
/// @param[out]   microVolts  ADC value in Micro Volts.
/// @param[in]    maxBytes    Ignored, the implementation always assumes 4.
/// @return       Number of Bytes received. 0 means failure.
DWORD VybAdc_Read(HANDLE hPort, DWORD *microVolts, DWORD maxBytes);

//******************************************************************************
/// Retrieves a DWORD configuration parameter.
/// @param[in]    hPort       HANDLE to ADC channel
/// @param[in]    paramName   Parameter value to retrieve\n
///                           Refer to the @ref scfg_adc_vyb for a list of supported parameters.
/// @param[out]   pValue      Data obtained
/// @return                   Number of bytes read. 0 if paramName not found.
DWORD VybAdc_GetConfigInt(HANDLE hPort, const TCHAR *paramName, DWORD *pValue);

//******************************************************************************
/// Set a DWORD configuration parameter.
/// @param[in]    hPort       HANDLE to ADC channel
/// @param[in]    paramName   Parameter value to configure.\n
///                           Refer to the @ref scfg_adc_vyb for a list of supported parameters.
/// @param[in]    value       Data to be set
/// @param[in]    storageType StoreInRegistry = parameter will also be stored in the registry\n
///                           StoreVolatile   = parameter will only be stored in local variable.
/// @retval       TRUE        Success
/// @retval       FALSE       Failure
BOOL VybAdc_SetConfigInt(HANDLE hPort, const TCHAR *paramName, DWORD value, ParamStorageType storageType);

//******************************************************************************
/// Get the revision of this Adc_vyb library
/// @param[out]    ver        library version, consisting of major, minor and build version
void VybAdc_GetVersion(tVersion *ver);

#ifdef __cplusplus
}
#endif

#endif