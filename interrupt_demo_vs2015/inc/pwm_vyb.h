///
/// @file        pwm_vyb.h
/// @copyright   Copyright (c) 2014 Toradex AG
/// $Author: chitresh.gupta $
/// $Rev: 2625 $ 
/// $Date: 2015-01-27 15:01:51 +0100 (Di, 27 Jan 2015) $
/// @brief       Library to support Pulse Width Modulation (PWM) on Vybrid.
/// @test        
/// @target      Colibri VF50, VF61
///
/// _NOTE:_ For Vybrid modules library is supported on WinCE image <b>v1.1Beta1</b> onwards.
///
/// @anchor vybpwm_pins
/// <h2 class ="groupheader">PWM Pin Availability on Colibri VF50/VF61 modules</h2>
/// The following table is valid only for Colibri VF50 and Colibri VF61.\n
/// The default PWM channels as defined on the Colibri Evaluation board are listed
/// in the column "PWM".
///              
/// |   SODIMM   |  GPIO  |  AltFn  |    PWM     | FTM controller |  FTM Channel |
/// | :--------: | :----: | :-----: | :--------: | :------------: | :----------: |
/// |     59     |   22   |     1   | PWM1/PWM_A |        0       |         0    |
/// |     30     |   23   |     1   | PWM3/PWM_C |                |         1    |
/// |     NA     |   NA   |     NA  |     -      |                |         2    |
/// |     24     |   25   |     1   |     -      |                |         3    |
/// |     21     |   26   |     1   |     -      |                |         4    |
/// |     19     |   27   |     1   |     -      |                |         5    |
/// |     94     |   28   |     1   |     -      |                |         6    |
/// |     81     |   29   |     1   |     -      |                |         7    |
/// |     28     |   30   |     1   | PWM2/PWM_B |        1       |         0    |
/// |     67     |   31   |     1   | PWM4/PWM_D |                |         1    |
/// |     NA     |   NA   |     NA  |     -      |        2       |         0    |
/// |     NA     |   NA   |     NA  |     -      |                |         1    |
/// |     106    |   63   |     4   |     -      |        3       |         0    |
/// |     69     |   64   |     4   |     -      |                |         1    |
/// |     99     |   65   |     4   |     -      |                |         2    |
/// |     104    |   66   |     4   |     -      |                |         3    |
/// |     107    |   67   |     4   |     -      |                |         4    |
/// |     127    |   68   |     4   |     -      |                |         5    |
/// |     184    |   69   |     4   |     -      |                |         6    |
/// |     186    |   70   |     4   |     -      |                |         7    |

/// @page    pcfg_pwm      PWM Configuration Options
/// @section scfg_pwm_vyb  VF50/VF61 PWM Configurations
/// @anchor  acfg_pwm_vyb
/// The following table explains the configuration parameters supported by calls of
/// * VybPwm_SetConfigInt()
/// * VybPwm_GetConfigInt()
/// * VybPwm_SetConfigString()
/// * VybPwm_GetConfigString()
/// <table>
/// <tr><th>valueName       </th><th>Type</th><th>Description</th></tr>
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
///                         You can define *io* as uIo structure (include Gpio.h) and pass *io.GenericDefinition*.\n
///                         The @ref vybpwm_pins "Vybrid PWM pins" shows a list of GPIOs with PWM functionality.</td></tr>
/// <tr><td><b>baseFreq</b></td><td>DWORD</td><td> Base clock frequency for the PWM generator in Hz.<p>
///                         This frequency defines the time resolution of the PWM signal (resolution = 1/baseFreq)<br>
///                         Only a small number of discrete frequencies can be configured in the VF50/VF61. Allowed frequencies are:
///                         <ul>
///                         <li>For VF61: 83.3 MHz/n, where n is 1,2,4,8,16,32,64 or 128.</li>
///                         <li>For VF50: 66.0 MHz/n, where n is 1,2,4,8,16,32,64 or 128.</li>
///                         </ul>
///                         If baseFreq is not one of these frequencies, the PwmLib will select the next higher frequency.\n
///                         A PWM period can be configured to be 1 to 65536 cycles of the baseFreq. Therefore the lowest achievable PWM frequency is baseFreq/65536.</td></tr>
/// </table> 
/// 
/// @test        Colibri VF61 and VF50
/// @target      Vybrid
/// 

#ifndef __PWM_VYB_H__
#define __PWM_VYB_H__

#include <windows.h> 
#include "tdxcommon.h"

#ifdef __cplusplus
extern "C" {
#endif


//******************************************************************************
/// Initialize HANDLE for the PWM channel. 
/// This function call does not modify any hardware registers. Therefore the 
/// returned handle can be used to make additional configuration settings, which 
/// will become active when calling VybPwm_Open()
/// @param[in]  portName    PWM channel name. Can be one of these: <ul><li>L"PWM1"</li><li>L"PWM2"</li><li>L"PWM3"</li><li>L"PWM4"</li></ul>
/// @return     Handle to the FTM channel. NULL if the function failed.
HANDLE VybPwm_Init(const TCHAR *portName);

//******************************************************************************
/// Finally close the HANDLE. The port must be closed before.
/// @param[in]    hPort       HANDLE to PWM channel
/// @retval       TRUE        Success
/// @retval       FALSE       Failure
BOOL VybPwm_Deinit(HANDLE hPort);

//******************************************************************************
/// Apply configuration to the hardware registers and IOs
/// @param[in]    hPort       HANDLE to PWM channel
/// @retval       TRUE        Success
/// @retval       FALSE       Failure
BOOL VybPwm_Open(HANDLE hPort);

//******************************************************************************
/// Close the PWM port
/// @param[in]    hPort       HANDLE to PWM channel
/// @retval       TRUE        Success
/// @retval       FALSE       Failure
BOOL VybPwm_Close(HANDLE hPort);

//******************************************************************************
/// Retrieves a string configuration parameter\n
/// There is no String parameter for the Vybrid PWM library, so this function is not used.
/// @param[in]    hPort       HANDLE to PWM channel
/// @param[in]    paramName   Parameter value to retrieve\n
///                           Refer to the @ref scfg_pwm_vyb for a list of supported parameters.
/// @param[out]   pValue      String data obtained
/// @param[in]    maxBytes    Maximum size of string in Bytes
/// @return                   Number of bytes read. 0 if paramName not found.
DWORD VybPwm_GetConfigString(HANDLE hPort, const TCHAR *paramName, TCHAR *pValue, DWORD maxBytes);

//******************************************************************************
/// Set a string configuration parameter 
/// There is no String parameter for the Vybrid PWM library, so this function is not used.
/// @param[in]    hPort       HANDLE to PWM channel
/// @param[in]    paramName   Parameter value to configure\n
///                           Refer to the @ref scfg_pwm_vyb for a list of supported parameters.
/// @param[in]    value       String value to be set
/// @param[in]    storageType StoreInRegistry = parameter will also be stored in the registry\n
///                           StoreVolatile   = parameter will only be stored in local variable.
/// @retval       TRUE        Success
/// @retval       FALSE       Failure
BOOL VybPwm_SetConfigString(HANDLE hPort, const TCHAR *paramName, const TCHAR *value, ParamStorageType storageType);

//******************************************************************************
/// Retrieves a DWORD configuration parameter\n
/// @param[in]    hPort       HANDLE to PWM channel
/// @param[in]    paramName   Parameter value to retrieve\n
///                           Refer to the @ref scfg_pwm_vyb for a list of supported parameters.
/// @param[out]   pValue      String data obtained
/// @return                   Number of bytes read. 0 if paramName not found.
DWORD VybPwm_GetConfigInt( HANDLE hPort, const TCHAR *paramName, DWORD *pValue);

//******************************************************************************
/// Set a DWORD configuration parameter.\n
/// @param[in]    hPort       HANDLE to PWM channel
/// @param[in]    paramName   Parameter value to configure\n
///                           Refer to the @ref scfg_pwm_vyb for a list of supported parameters.
/// @param[in]    value       Data to be set
/// @param[in]    storageType StoreInRegistry = parameter will also be stored in the registry\n
///                           StoreVolatile   = parameter will only be stored in local variable.
/// @retval       TRUE        Success
/// @retval       FALSE       Failure
BOOL VybPwm_SetConfigInt(HANDLE hPort, const TCHAR *paramName, DWORD value, ParamStorageType storageType);

//******************************************************************************
/// Assigns frequency and duty cycle in PWM Controller. There are only discrete
/// values possible for frequency and duty cycle, so the requested value may not
/// be reached accurately.\n
/// Also note that PWM channels inside the same FTM controller always run at the
/// same frequency! Refer to the @ref vybpwm_pins "table in the file header" for 
/// the relation of pin and FTM controller.
/// @param[in]    hPort       HANDLE to PWM channel
/// @param[in]    freq        PWM frequency in Hz\n
///                           Attention! PWMA and PWMC always run at the same frequency\n
///                           Attention! PWMB and PWMD always run at the same frequency
/// @param[in]    duty        16 bit duty cycle (0 = 0% ... 65536 = 100%)
/// @retval       TRUE        Success
/// @retval       FALSE       Failure
BOOL VybPwm_SetPwm(HANDLE hPort, DWORD freq, DWORD duty);

//******************************************************************************
/// Get the revision of this pwm_vyb library
/// @param[out]     ver     library version, consist of major, minor and build version
void VybPwm_GetVersion(tVersion *ver);

#ifdef __cplusplus
}
#endif

#endif //__PWM_VYB_H__