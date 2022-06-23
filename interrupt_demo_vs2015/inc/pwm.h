///
/// @file        pwm.h
/// @copyright   Copyright (c) 2014 Toradex AG
/// $Author: chitresh.gupta $
/// $Rev: 2625 $ 
/// $Date: 2015-01-27 15:01:51 +0100 (Di, 27 Jan 2015) $
/// @brief       Library to support Pulse Width Modulation (PWM)
///
/// _NOTE:_ For Vybrid modules library is supported on WinCE image <b>v1.1Beta1</b> onwards.
///
/// @page pcfg_pwm PWM Configuration Options
/// @tableofcontents
///
/// @section scfg_pwm Compatible PWM Configurations
/// @anchor acfg_pwm
/// The following table explains the configuration parameters supported by calls of
/// * Pwm_SetConfigInt()
/// * Pwm_GetConfigInt()
/// * Pwm_SetConfigString()
/// * Pwm_GetConfigString()
/// <table>
/// <tr><th>valueName       </th><th>Type</th><th>Description</th><th>Supported Hardware</th></tr>
/// <tr><td><b>  io     </b></td><td></td>DWORD<td> GPIO or Pin number.<br>
///                         The higher 16bit contain the type of the value:
///                         <ul>
///                         <li>0x0010 = GPIO</li>
///                         <li>0x0020 = Colibri SODIMM Pin</li>
///                         </ul>
///                         The lower 16bit contain the Gpio number or pin number.<p>
///                         Examples:
///                         <ul>
///                         <li>0x0010003b defines SODIMM pin 59</li>
///                         <li>0x00200016 defines GPIO 22</li>
///                         </ul>
///                         For the Colibri VF50/VF61, these two definitions describe the same hardware pin.<p>
///                         You can define *io* as uIo structure (include Gpio.h) and pass *io.GenericDefinition*.</td>
///                         <td>Colibri VF50<br>Colibri VF61</td></tr>
/// <tr><td><b>baseFreq</b></td><td>DWORD</td><td> Base clock frequency for the PWM generator in Hz.<p>
///                         This frequency defines the time resolution of the PWM signal (resolution = 1/baseFreq)<br>
///                         
///                         If the requested baseFreq is not one of the available frequencies, the PwmLib will select the next higher available frequency.</td>
///                         <td>Colibri VF50<br>Colibri VF61</td></tr>
/// </table> 
/// 
/// @test        Colibri VF61 and VF50
/// @target      Vybrid
/// 

#ifndef __PWM_H__
#define __PWM_H__

#include <windows.h> 
#include "tdxcommon.h"

#ifdef __cplusplus
extern "C" {
#endif

//******************************************************************************
/// Initialize HANDLE for the PWM channel. 
/// This function call does not modify any hardware registers. Therefore the 
/// returned handle can be used to make additional configuration settings, which 
/// will become active when calling Pwm_Open()
/// @param[in]  portName    PWM channel name. Can be one of these: <ul><li>L"PWM1"</li><li>L"PWM2"</li><li>L"PWM3"</li><li>L"PWM4"</li></ul>
/// @return     Handle to the PWM port. NULL if the function failed.
HANDLE Pwm_Init(const TCHAR *portName);

//******************************************************************************
/// Finally close the HANDLE. The port must be closed before.
/// @param[in]    hPort       HANDLE to PWM channel
/// @retval       TRUE        Success
/// @retval       FALSE       Failure
BOOL Pwm_Deinit(HANDLE hPort);

//******************************************************************************
/// Apply configuration to the hardware registers and IOs
/// @param[in]    hPort       HANDLE to PWM channel
/// @retval       TRUE        Success
/// @retval       FALSE       Failure
BOOL Pwm_Open(HANDLE hPort);

//******************************************************************************
/// Close the PWM port
/// @param[in]    hPort       HANDLE to PWM channel
/// @retval       TRUE        Success
/// @retval       FALSE       Failure
BOOL Pwm_Close(HANDLE hPort);

//******************************************************************************
/// Retrieves a string configuration parameter
/// @param[in]    hPort       HANDLE to PWM channel
/// @param[in]    paramName   Parameter value to retrieve\n
///                           Refer to the @ref scfg_pwm for a list of supported parameters.
/// @param[out]   pValue      String data obtained
/// @param[in]    maxBytes    Maximum size of string in Bytes
/// @return                   Number of bytes read. 0 if paramName not found.
DWORD Pwm_GetConfigString( HANDLE hPort, const TCHAR *paramName, TCHAR *pValue, DWORD maxBytes);

//******************************************************************************
/// Set a string configuration parameter 
/// @param[in]    hPort       HANDLE to PWM channel
/// @param[in]    paramName   Parameter value to configure\n
///                           Refer to the @ref scfg_pwm for a list of supported parameters.
/// @param[in]    value       String value to be set
/// @param[in]    storageType StoreInRegistry = parameter will also be stored in the registry\n
///                           StoreVolatile   = parameter will only be stored in local variable.
/// @retval       TRUE        Success
/// @retval       FALSE       Failure
BOOL Pwm_SetConfigString(HANDLE hPort, const TCHAR *paramName, const TCHAR *value, ParamStorageType storageType);

//******************************************************************************
/// Retrieves a DWORD configuration parameter\n
/// @param[in]    hPort       HANDLE to PWM channel
/// @param[in]    paramName   Parameter value to retrieve\n
///                           Refer to the @ref scfg_pwm for a list of supported parameters.
/// @param[out]   pValue      String data obtained
/// @return                   Number of bytes read. 0 if paramName not found.
DWORD Pwm_GetConfigInt(HANDLE hPort, const TCHAR *paramName, DWORD *pValue);

//******************************************************************************
/// Set a DWORD configuration parameter.\n
/// @param[in]    hPort       HANDLE to PWM channel
/// @param[in]    paramName   Parameter value to configure\n
///                           Refer to the @ref scfg_pwm for a list of supported parameters.
/// @param[in]    value       Data to be set
/// @param[in]    storageType StoreInRegistry = parameter will also be stored in the registry\n
///                           StoreVolatile   = parameter will only be stored in local variable.
/// @retval       TRUE        Success
/// @retval       FALSE       Failure
BOOL Pwm_SetConfigInt(HANDLE hPort, const TCHAR *paramName, DWORD value, ParamStorageType storageType);

//******************************************************************************
/// Assigns frequency and duty cycle in PWM Controller. There are only discrete
/// values possible for frequency and duty cycle, so the requested value may not
/// be reached accurately.
/// @param[in]    hPort       HANDLE to PWM channel
/// @param[in]    freq        PWM frequency in Hz\n
/// @param[in]    duty        16 bit duty cycle (0 = 0% ... 65536 = 100%)
/// @retval       TRUE        Success
/// @retval       FALSE       Failure
BOOL Pwm_SetPwm(HANDLE hPort, DWORD freq, DWORD duty);

//******************************************************************************
/// Get the revision of this pwm library
/// @param[out]     ver     library version, consist of major, minor and build version
void Pwm_GetVersion(tVersion *ver);


#ifdef __cplusplus
}
#endif

#endif