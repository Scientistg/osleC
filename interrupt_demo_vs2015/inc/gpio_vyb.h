/// @file        gpio_vyb.h
/// @copyright   Copyright (c) 2015 Toradex AG
/// $Author: andy.kiser $
/// $Rev: 2825 $
/// $Date: 2015-06-05 17:33:38 +0200 (Fr, 05 Jun 2015) $
/// @brief       This library allows easy access to the GPIO pins on Vybrid modules.
/// @test        VFxx
/// @target      Colibri VF50, VF61
///
/// _GPIO Toggle rate for VFxx:_
///                    * VF61 - 0.43 us (2.3 MHz)
///                    * VF50 - 0.59 us (1.7 MHz)
///
/// @page    pcfg_gpio     GPIO Configuration Options
/// @section scfg_gpio_vyb VF50/VF61 GPIO Configurations
/// @anchor  acfg_gpio_vyb
/// For a list of compatible parameters, refer to @ref acfg_gpio.
/// <table class="libParam">
///   <tr><th>Parameter Name</th>      <th>Value</th>   <th>Description</th></tr>
///   <tr><td rowspan="3" >altfn</td>  <td>-1</td>      <td>This is the compatible value to define a GPIO. In the SoC datasheet, there is no AltFn with value -1.</td></tr>
///   <tr>                             <td>0</td>       <td>GPIO</td></tr>
///   <tr>                             <td>1 to 7</td>  <td>Alternate Function 1 to 7. The precise meaning depends on the actual IO.</td></tr>
///   <tr><td rowspan="3">dir</td>     <td>in</td>      <td>IO direction is input</td></tr>
///   <tr>                             <td>out</td>     <td>IO direction is output</td></tr>
///   <tr>                             <td>outonly</td> <td>IO direction is output, actual pin level cannot be read back</td></tr>
///   <tr><td rowspan="2">lvl</td>     <td>0</td>       <td>Set IO level to Logic low (if AltFn=GPIO, and Dir=out or outonly)</td></tr>
///   <tr>                             <td>1</td>       <td>Set IO level to Logic high (if AltFn=GPIO, and Dir=out or outonly)</td></tr>
///   <tr><td rowspan="8">pull</td>    <td>none</td>    <td>This is the compatible value to remove all software pullup/down resistors or bus keepers.</td></tr>
///   <tr>                             <td>up</td>      <td>This is the compatible value to configure a software pullup.</td></tr>
///   <tr>                             <td>down</td>    <td>This is the compatible value to configure a software pulldown.</td></tr>
///   <tr>                             <td>up22k</td>   <td>22k pull up</td></tr>
///   <tr>                             <td>up47k</td>   <td>47k pull up </td></tr>
///   <tr>                             <td>up100k</td>  <td>100k pull up. "pull=up" and "pull=up100k" are both identical.</td></tr>
///   <tr>                             <td>down100k</td><td>100k pull down. "pull=down" and "pull=down100k" are both identical.</td></tr>
///   <tr>                             <td>buskeep</td> <td>Instead of a pullup/down resistor, a bus keeper gets enabled</td></tr>
///   <tr><td rowspan="8">strength</td><td>0</td>       <td>Output driver and pull up/down disabled</td></tr>
///   <tr>                             <td>1</td>       <td>150 Ohm output impedance. This is the reset default value.</td></tr>
///   <tr>                             <td>2</td>       <td>75 Ohm output impedance</td></tr>
///   <tr>                             <td>3</td>       <td>50 Ohm output impedance</td></tr>
///   <tr>                             <td>4</td>       <td>37 Ohm output impedance</td></tr>
///   <tr>                             <td>5</td>       <td>30 Ohm output impedance</td></tr>
///   <tr>                             <td>6</td>       <td>25 Ohm output impedance</td></tr>
///   <tr>                             <td>7</td>       <td>20 Ohm output impedance</td></tr>
///   <tr><td rowspan="2">outmode</td> <td>std</td>     <td>Standard output. This is the reset default value</td></tr>
///   <tr>                             <td>od</td>      <td>Open drain </td></tr>
///   <tr><td rowspan="2">inmode</td>  <td>std</td>     <td>Normal input. This is the reset default value.</td></tr>
///   <tr>                             <td>schmitt</td> <td>Schmitt trigger input</td></tr>
///   <tr><td rowspan="2">slew</td>    <td>slow</td>    <td>Slow rising and falling edge. This is the reset default value.</td></tr>
///   <tr>                             <td>fast</td>    <td>Fast rising and falling edge.</td></tr>
///   <tr><td rowspan="3">speed</td>   <td>low</td>     <td>IO bandwidth = 50 MHz (low). This is the reset default value</td></tr>
///   <tr>                             <td>medium</td>  <td>IO bandwidth = 100 MHz (medium)</td></tr>
///   <tr>                             <td>high</td>    <td>IO bandwidth = 200 MHz (high)</td></tr>
///   <tr><td rowspan="6">irqtrig</td> <td>none</td>    <td>IRQ Trigger at GPIO level Low</td></tr>
///   <tr>                             <td>rising</td>  <td>IRQ Trigger at GPIO rising edge</td></tr>
///   <tr>                             <td>falling</td> <td>IRQ Trigger at GPIO falling edge</td></tr>
///   <tr>                             <td>anyedge</td> <td>IRQ Trigger at GPIO rising and falling edge</td></tr>
///   <tr>                             <td>low</td>     <td>IRQ Trigger at GPIO level Low. Same as "none".</td></tr>
///   <tr>                             <td>high</td>    <td>IRQ Trigger at GPIO level High</td></tr>
///   <tr><td>            irq</td>     <td>DWORD</td>   <td>IRQ Number for the GPIO.</td></tr>
/// </table>
/// _NOTE:_ "altfn" configuration is only supported on Vybrid image <b>v1.1Beta1</b> onwards.

#ifndef __GPIO_VYB_H__
#define __GPIO_VYB_H__

#include "gpio.h"

#ifdef __cplusplus
extern "C" {
#endif


//******************************************************************************
/// Initialize HANDLE for the GPIO.\n 
/// This function call does not modify any hardware registers.\n  
/// It will load lib and stored GPIO and IOMUX (physical and virtual address)
/// @param[in]  registryPath  Registry path string value.e.g "SOFTWARE\\Toradex\\spi" , "SOFTWARE\\Toradex\\app" 
/// @return     Handle to the GPIO. NULL if the function failed.
HANDLE VybGpio_Init(const TCHAR *registryPath);

//******************************************************************************
/// De-initialize HANDLE for the GPIO.\n 
/// Un-Map memory of gpio.
/// @param[in]    hGpio       HANDLE to GPIO
/// @retval       TRUE        Success
/// @retval       FALSE       Failure
BOOL VybGpio_Deinit(HANDLE hGpio);

//******************************************************************************
/// Apply configuration to the hardware IOs, if it is stored in registry path 
/// @param[in]    hGpio       HANDLE to GPIO
/// @retval       TRUE        Success
/// @retval       FALSE       Failure
BOOL VybGpio_Open(HANDLE hGpio);

//******************************************************************************
/// Close gpio
/// @param[in]    hGpio       HANDLE to GPIO
/// @retval       TRUE        Success
/// @retval       FALSE       Failure
BOOL VybGpio_Close(HANDLE hGpio);

//******************************************************************************
/// Get the Input/Output direction of the specified io
/// @param[in]  hGpio       HANDLE to GPIO
/// @param[in]  io          GPIO or Colibri pin or Apalis pin number
/// @retval     ioInput     Pin is configured as input
/// @retval     ioOutput    Pin is configured as output
tIoDirection VybGpio_GetDir(HANDLE hGpio, uIo io);

//******************************************************************************
/// Set the Input/Output direction of the specified io
/// @param[in]          hGpio           HANDLE to GPIO
/// @param[in]          io              GPIO or Colibri pin or Apalis pin number
/// @param[in]          dirOut          tIoDirection (0: ioInput, 1:ioOutput)  
void VybGpio_SetDir(HANDLE hGpio, uIo io, tIoDirection dirOut);

//******************************************************************************
/// Set Alternative to GPIO of the specified io.\n
/// Only supported on Vybrid image <b>v1.1Beta1</b> onwards.
/// @param[in]          hGpio           HANDLE to GPIO
/// @param[in]          io              GPIO or Colibri pin or Apalis pin number
void VybGpio_ConfigureAsGpio(HANDLE hGpio, uIo io);

//******************************************************************************
/// Get the logic level of the specified io
/// @param[in]          hGpio   HANDLE to GPIO
/// @param[in]          io      GPIO or Colibri pin or Apalis pin number
/// @retval             ioLow   Current pin Level is low
/// @retval             ioHigh  Current pin Level is high
tIoLevel VybGpio_GetLevel(HANDLE hGpio, uIo io);

//******************************************************************************
/// Set the logic level of the specified io
/// @param[in]          hGpio           HANDLE to GPIO
/// @param[in]          io              GPIO or Colibri pin or Apalis pin number
/// @param[in]          val             [0: ioLow  ,1: ioHigh]  
void VybGpio_SetLevel(HANDLE hGpio, uIo io, tIoLevel val);

//******************************************************************************
/// Convert GPIO number from Colibri pin number or Apalis pin number
/// @param[in]    hGpio       HANDLE received from Gpio_Init()
/// @param[in]    io          GPIO or Colibri pin or Apalis pin number in uIo format.
/// @return             The same io, but always represented as a GPIO.\n
///                     If io was passed as a GPIO, the returned value is equal to io.\n
///                     If io was a Colibri or Apalis pin number, it is converted to a GPIO number.
///                     In case there is more than one GPIO on a pin, only the first GPIO is returned.
uIo VybGpio_NormalizeIo(HANDLE hGpio, uIo io);

//******************************************************************************
/// Set one or many configuration parameters for a particular GPIO.\n
/// "altfn" configuration is only supported on Vybrid image <b>v1.1Beta1</b> onwards.
/// @param[in]    hGpio       HANDLE received from Gpio_Init()
/// @param[in]    io          GPIO number or SODIMM pin number or Apalis pin number
/// @param[in]    paramName2  Not used. Always set to NULL.
/// @param[in]    value       String value to be set,e.g "dir=out, lvl=1, pull=up100k"
///                           Refer to the table @ref scfg_gpio_vyb "GPIO Configurations for Colibri VF50/VF61" for details.
/// @param[in]    storageType StoreInRegistry = parameter will also be stored in the registry\n
///                           StoreVolatile   = parameter will only be stored in local variable.
/// @retval       TRUE        Success
/// @retval       FALSE       Failure
BOOL VybGpio_SetConfigString(HANDLE hGpio, uIo io, const TCHAR *paramName2, const TCHAR *value, ParamStorageType storageType);

//******************************************************************************
/// Retrieves the current configuration of a particular GPIO.
/// @param[in]    hGpio       HANDLE received from Gpio_Init()
/// @param[in]    io          GPIO number or SODIMM pin number or Apalis pin number
/// @param[in]    paramName2  Prefix of the configuration option, e.g. "dir", "lvl", or "altfn".\n
///                           Set to NULL, in order to receive a string containing *all* configuration options.\n
///                           Refer to the table @ref scfg_gpio_vyb "GPIO Configurations for Colibri VF50/VF61" for details.
/// @param[out]   pValue      String data obtained
/// @param[in]    maxBytes    Maximum size of string in Bytes
/// @return                   Number of bytes read. 0 indicates an error.
DWORD VybGpio_GetConfigString(HANDLE hGpio, uIo io, const TCHAR *paramName2, TCHAR *pValue, DWORD maxBytes);

//******************************************************************************
/// Retrieves the current configuration of a particular GPIO.
/// @param[in]    hGpio       HANDLE received from Gpio_Init()
/// @param[in]    io          GPIO number or SODIMM pin number or Apalis pin number
/// @param[in]    paramName2  Prefix of the configuration option. Only <b>irq</b> supported at the moment.
/// @param[out]   pValue      DWORD data obtained
/// @return       Number of bytes read. 0 indicates an error.
DWORD VybGpio_GetConfigInt(HANDLE hGpio, uIo io, const TCHAR *paramName2, DWORD *pValue);

//******************************************************************************
/// Get the revision of this gpio_vyb lib
/// @param[out]     ver     library version, consist of major, minor and build version.
void VybGpio_GetVersion(tVersion *ver);


#ifdef __cplusplus
}
#endif


#endif
