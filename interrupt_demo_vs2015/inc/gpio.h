///
/// @file        gpio.h
/// @copyright   Copyright (c) 2015 Toradex AG
/// $Author: andy.kiser $
/// $Rev: 2825 $
/// $Date: 2015-06-05 17:33:38 +0200 (Fr, 05 Jun 2015) $
/// @brief       This library allows easy access to the GPIO pins.
/// @target      Txx , VFxx
///
/// @todo Review the tables and description. Need to add detail descriptions.
///
/// @anchor io
/// <h2 class ="groupheader">IO parameter table for Gpio library</h2>
///
/// The following table explains the uIo structure supported by calls of
/// Gpio_GetDir(), Gpio_SetDir(), Gpio_GetLevel(), Gpio_SetLevel(),
/// Gpio_GetEdgeDetect(), Gpio_SetEdgeDetect(), Gpio_ConfigureAsGpio(), Gpio_NormalizeIo().\n
///
/// @todo We can remove this information and table if not require to Highlight it gain as already present in structure description.\n
/// IO is a uIo structure consisting of one of the following tIoType.
///
/// <table class="alternate_color">
///   <tr>
///     <th>tIoType</th>            <th>Description</th>
///   </tr>
///   <tr>
///     <td>ioApalisPin</td>        <td>Specify an MXM3 pin of an Apalis module</td>
///   </tr>
///   <tr>
///     <td>ioColibriPin</td>       <td>Specify an SODIMM pin of a Colibri module</td>
///   </tr>
///   <tr>
///     <td>ioGpio</td>             <td>Specify a GPIO</td>
///   </tr>
///   <tr>
///     <td>ioColibriExtension</td> <td>Specify a pin on the Colibri FFC Extension connector</td>
///   </tr>
/// </table>
///
///
/// The table below explains about the registry value entry for the IO, when storage type "StoreToRegistry"\n
/// is selected in Gpio_GetConfigString() and Gpio_SetConfigString() functions.
/// <table class="alternate_color">
///   <tr>
///     <th>GPIO/Module family pin</th>       <th>Registry value prefix</th>
///   </tr>
///   <tr>
///     <td>Colibri SODIMM pin</td>           <td>colibriPin_<Number></td>
///   </tr>
///   <tr>
///     <td>Apalis MXM3 pin</td>              <td>apalisPin_<Number></td>
///   </tr>
///   <tr>
///     <td>GPIO</td>                         <td>gpio_<Number></td>
///   </tr>
/// </table>
///
/// Eg:
///  - For Colibri SODIMM pin:  colibriPin_123 \n
///  - For Apalis MXM3 pin   :  apalisPin_123  \n
///  - For SoC GPIO number   :  gpio_123


/// @page pcfg_gpio Gpio Configuration Options
/// @tableofcontents
///
/// @section scfg_gpio Compatible GPIO Configurations
/// @anchor  acfg_gpio
/// The following subset of GPIO configuration parameters is expected to be 
/// available on all IOs of any SoC.\n
/// Toradex  recommends to prefer these settings over the SoC specific
/// configurations. This can simplify the porting to any other Toradex hardware.
///
/// <table class="libParam" >
///   <tr><th>Parameter Name</th>                         <th>Value</th>   <th>Description</th></tr>
///   <tr><td class="paramname" rowspan="2">altfn</td>    <td>-1</td>      <td>This is the compatible value to define a GPIO. In the SoC datasheet, there is no AltFn with value -1.</td></tr>
///   <tr>                                                <td>0 to 7</td>  <td>Alternate Function 1 to 7. The precise meaning depends on the SoC and the actual IO.</td></tr>
///   <tr><td class="paramname" rowspan="2">dir</td>      <td>in</td>      <td>IO direction is input</td></tr>
///   <tr>                                                <td>out</td>     <td>IO direction is output</td></tr>
///   <tr><td class="paramname" rowspan="2">lvl</td>      <td>0</td>       <td>Set IO level to Logic low (if AltFn=GPIO, and Dir=out or outonly)</td></tr>
///   <tr>                                                <td>1</td>       <td>Set IO level to Logic high (if AltFn=GPIO, and Dir=out or outonly)</td></tr>
///   <tr><td class="paramname" rowspan="3">pull</td>     <td>none</td>    <td>This is the compatible value to remove all software pullup/down resistors or bus keepers.</td></tr>
///   <tr>                                                <td>up</td>      <td>This is the compatible value to configure a software pullup.</td></tr>
///   <tr>                                                <td>down</td>    <td>This is the compatible value to configure a software pulldown.</td></tr>
///   <tr><td class="paramname" rowspan="2">outmode</td>  <td>std</td>     <td>This is the compatible value to output mode is standard.</td></tr>
///   <tr>                                                <td>od</td>      <td>This is the compatible value to output mode is output drain.</td></tr>
///   <tr><td class="paramname" rowspan="2">inmode</td>   <td>std</td>     <td>This is the compatible value to input mode is standard.</td></tr>
///   <tr>                                                <td>schmitt</td> <td>This is the compatible value to input mode is input trigger schmitt.</td></tr>
///   <tr><td class="paramname" rowspan="3">speed</td>    <td>low</td>     <td>This is the compatible value to configure a software low speed.</td></tr>
///   <tr>                                                <td>medium</td>  <td>This is the compatible value to configure a software medium speed.</td></tr>
///   <tr>                                                <td>high</td>    <td>This is the compatible value to configure a software high speed.</td></tr>
///   <tr><td class="paramname">            strength</td> <td>0 to 7</td>  <td>Drive strength. The exact meaning depends on the SoC.<br>0 is the weakest value (highest impedance).<br>7 is the strongest value (lowest impedance). </td></tr>
///   <tr><td class="paramname" rowspan="4">irqtrig</td>  <td>none</td>    <td>Default IRQ Trigger. The exact meaning depends on the SoC.</td></tr>
///   <tr>                                                <td>rising</td>  <td>This is the compatible value to IRQ Trigger at GPIO rising edge.</td></tr>
///   <tr>                                                <td>falling</td> <td>This is the compatible value to IRQ Trigger at GPIO falling edge.</td></tr>
///   <tr>                                                <td>anyedge</td> <td>This is the compatible value to IRQ Trigger at GPIO rising and falling edge.</td></tr>
///   <tr><td class="paramname">            irq</td>      <td>DWORD</td>   <td>This is the compatible value to IRQ Number for the GPIO.</td></tr>
/// </table>
/// _NOTE:_ "altfn" configuration is only supported on image <b>v1.1Beta1</b> onwards, for Vybrid modules.

#ifndef __GPIO_H__
#define __GPIO_H__

#include <windows.h>
#include "TdxCommon.h"

#ifdef __cplusplus
extern "C" {
#endif

/// define possible options to specify an IO pin
typedef enum
{
    ioNone              =     -1,  ///< specify that this Io is unused and ignored
    ioReserved          = 0x0000,  ///< do not use this undefined usage type (could be GPIO, SODIMM, ...)
    ioGpio              = 0x0010,  ///< specify a GPIO
    ioColibriPin        = 0x0020,  ///< specify an SODIMM pin of a Colibri module
    ioColibriExtension  = 0x0021,  ///< specify a pin on the Colibri FFC Extension connector
    ioApalisPin         = 0x0030   ///< specify an MXM3 pin of an Apalis module
} tIoType;

/// Define one IO on one Toradex module
/// The struct below can also be seen as a 32bit DWORD
/// (The compiler requires different Field names (`Type`, `Number`) for the unnamed struct, than for the named structs (`Tp`, `Nr`).
/// | Bits              |  Description                                                                                                                                               |
/// |-------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------|
/// | 31..16            | `Type` or `Tp`<br> Constant to describe the mapping used for bits 15..0, e.g. `ioGpio`, `ioColibriPin`.<br> Refer to the documentation of the enum tIoType |
/// | 15..0             | `Number` or `Nr`<br> The actual GPIO or SODIMM / MXM3 pin number.                                                                                          |
typedef union
{
    struct {unsigned Number :16;                        ///< generic definition of the fields
            tIoType  Type   :16;};                      ///< (access as io.Type and io.Number)

    struct {unsigned Nr     :16;
            tIoType  Tp     :16; } Gpio;                ///< use this struct when Type = ioGpio

    struct {unsigned Nr     :16;
            tIoType  Tp     :16; } ColibriPin;          ///< use this struct when Type = ioColibriPin

    struct {unsigned Nr     :16;
            tIoType  Tp     :16; } ColibriExtensionPin; ///< use this struct when Type = ioColibriExtensionPin

    struct {unsigned Nr     :16;
            tIoType  Tp     :16; } ApalisPin;           ///< use this struct when Type = ioApalisPin

    unsigned GenericDefinition :32;                     ///< the full specification of a GPIO or a Pin
} uIo;

/// Short form for the static initialization of a SoC-specific Gpio number
/// @code{.c}
///     uIo io = GPIO(123);
///     // this is identical to the following code:
///     uIo io;
///     io.Type = ioGpio;
///     io.Number = 123;
/// @endcode
#define GPIO(a)                   {a, ioGpio}

/// Short form for the static initialization of a Colibri SODIMM pin number
/// @code{.c}
///     uIo io = COLIBRI_PIN(123);
///     // this is identical to the following code:
///     uIo io;
///     io.Type = ioColibriPin;
///     io.Number = 123;
/// @endcode
#define COLIBRI_PIN(a)            {a, ioColibriPin}

/// Short form for the static initialization of a Colibri PXAxxx extension connector pin number
/// @code{.c}
///     uIo io = COLIBRI_EXTENSION_PIN(12);
///     // this is identical to the following code:
///     uIo io;
///     io.Type = ioColibriExtension;
///     io.Number = 12;
/// @endcode
#define COLIBRI_EXTENSION_PIN(a)  {a, ioColibriExtension}

/// Short form for the static initialization of an Apalis MXM3 pin number
/// @code{.c}
///     uIo io = APALIS_PIN(123);
///     // this is identical to the following code:
///     uIo io;
///     io.Type = ioApalisPin;
///     io.Number = 123;
/// @endcode
#define APALIS_PIN(a)             {a, ioApalisPin}

/// Short form for the initialization of a SoC-specific Gpio number by program code.
/// @code{.c}
///     uIo io;
///     io.GenericDefinition = IOGPIO(123);
/// @endcode
#define IOGPIO(a)               ((ioGpio << 16) + a)

/// Short form for the initialization of a SoC-specific Gpio number by program code.
/// @code{.c}
///     uIo io;
///     io.GenericDefinition = IOCOLIBRIPIN(123);
/// @endcode
#define IOCOLIBRIPIN(a)        ((ioColibriPin << 16) + a)

/// Short form for the initialization of a Colibri SODIMM pin number by program code.
/// @code{.c}
///     uIo io;
///     io.GenericDefinition = IOCOLIBRIEXTENSION(12);
/// @endcode
#define IOCOLIBRIEXTENSION(a)   ((ioColibriExtension << 16) + a)

/// Short form for the initialization of a Apalis MXM3 pin number by program code.
/// @code{.c}
///     uIo io;
///     io.GenericDefinition = IOAPALISPIN(123);
/// @endcode
#define IOAPALISPIN(a)          ((ioApalisPin << 16) + a)

/// Struct to store two IOs.
/// This is used to describe a multiplexed pin, i.e. two GPIOs shorted to one module pin.
typedef struct
{
    uIo Primary;    ///< For signals that have two SoC GPIOs shorted together, this field describes the primary IO.
                    ///< There is no fixed rule which IO is the primary or secondary, it is just a Toradex definition.\n
                    ///< For regular IOs, this is the only valid entry of the tTwoIo structure.
    uIo Secondary;  ///< For signals that have two SoC GPIOs shorted together, this field describes the secondary IO.\n
                    ///< For regular IOs, this field is invalid.
} tTwoIo;

/// Alternative function is used in mux and gpio configuration
typedef enum
{
    ioAltFn0 = 0,    ///< AltFn0 (exact function depends on particular SoC and GPIO)
    ioAltFn1,        ///< AltFn1 (exact function depends on particular SoC and GPIO)
    ioAltFn2,        ///< AltFn2 (exact function depends on particular SoC and GPIO)
    ioAltFn3,        ///< AltFn3 (exact function depends on particular SoC and GPIO)
    ioAltFn4,        ///< AltFn4 (exact function depends on particular SoC and GPIO)
    ioAltFn5,        ///< AltFn5 (exact function depends on particular SoC and GPIO)
    ioAltFn6,        ///< AltFn6 (exact function depends on particular SoC and GPIO)
    ioAltFn7,        ///< AltFn7 (exact function depends on particular SoC and GPIO)
    ioAltFnGpio = -1 ///< Generic definition for the GPIO AltFn, compatible on all modules
} tIoAltFn;

/// Gpio level configuration values
typedef enum
{
    ioLow  = 0,     ///< logic low level 
    ioHigh = 1      ///< logic high level
}tIoLevel;

/// Gpio direction configuration values
typedef enum
{
    ioInput  = 0,   ///< direction: input
    ioOutput = 1    ///< direction: output
}tIoDirection;



//******************************************************************************
/// @name Gpio Specific Functions
//******************************************************************************
///@{

//******************************************************************************
/// Initialize HANDLE for the GPIO.\n
/// This function call does not modify any hardware registers.\n
/// It stores gpio allocated memory map and registry path to handler.
/// @param[in]  registryPath  Registry path string value.e.g SOFTWARE\\Toradex\\spi , SOFTWARE\\Toradex\\app
/// @return     Handle to the GPIO. NULL if the function failed.
HANDLE Gpio_Init(const TCHAR *registryPath);

//******************************************************************************
/// De-initialize HANDLE for the GPIO.\n
/// Un-Map memory of gpio.
/// @param[in]    hGpio       HANDLE to GPIO
/// @retval       TRUE        Success
/// @retval       FALSE       Failure
BOOL Gpio_Deinit(HANDLE hGpio);

//******************************************************************************
/// Apply configuration to the hardware IOs, If it is stored in registry path
/// @param[in]    hGpio       HANDLE to the GPIO library
/// @retval       TRUE        Success
/// @retval       FALSE       Failure
BOOL Gpio_Open(HANDLE hGpio);

//******************************************************************************
/// Close gpio
/// @param[in]    hGpio       HANDLE to GPIO
/// @retval       TRUE        Success
/// @retval       FALSE       Failure
BOOL Gpio_Close(HANDLE hGpio);

//******************************************************************************
/// Get the Input/Output direction of the specified io
/// @param[in]    hGpio         HANDLE to GPIO
/// @param[in]    io            GPIO or Colibri pin or Apalis pin number
/// @retval       ioInput       Pin is configured as input
/// @retval       ioOutput      Pin is configured as output
tIoDirection Gpio_GetDir(HANDLE hGpio, uIo io);

//******************************************************************************
/// Set the Input/Output direction of the specified io
/// @param[in]    hGpio      HANDLE to GPIO
/// @param[in]    io         GPIO or Colibri pin or Apalis pin number
/// @param[in]    dirOut     tIoDirection (0: ioInput, 1: ioOutput)
void Gpio_SetDir(HANDLE hGpio, uIo io, tIoDirection dirOut);

//******************************************************************************
/// Get the logic level of the specified io
/// @param[in]     hGpio      HANDLE to GPIO
/// @param[in]     io         GPIO or Colibri pin or Apalis pin number
/// @retval        ioLow      Current pin Level is low
/// @retval        ioHigh     Current pin Level is high
tIoLevel Gpio_GetLevel(HANDLE hGpio, uIo io);

//******************************************************************************
/// Set the logic level of the specified io
/// @param[in]          hGpio           HANDLE to GPIO
/// @param[in]          io              GPIO or Colibri pin or Apalis pin number
/// @param[in]          val             [0: Logic Low   >0: Logic High]
void Gpio_SetLevel(HANDLE hGpio, uIo io, tIoLevel val);

//******************************************************************************
/// Set Alternative to GPIO of the specified io.\n
/// Only supported on image <b>v1.1Beta1</b> onwards, for Vybrid modules.
/// @param[in]          hGpio           HANDLE to GPIO
/// @param[in]          io              GPIO or Colibri pin or Apalis pin number
void Gpio_ConfigureAsGpio(HANDLE hGpio, uIo io);

//******************************************************************************
/// Convert GPIO number from Colibri pin number or Apalis pin number
/// @param[in]          io               GPIO or Colibri pin or Apalis pin number in uIo format.
/// @return             The same io, but always represented as a GPIO.\n
///                     If io was passed as a GPIO, the returned value is equal to io.\n
///                     If io was a Colibri or Apalis pin number, it is converted to a GPIO number.
///                     In case there is more than one GPIO on a pin, only the first GPIO is returned.
uIo Gpio_NormalizeIo(HANDLE hGpio, uIo io);

//******************************************************************************
/// Set one or many configuration parameters for a particular GPIO.\n
/// "altfn" configuration is only supported on image <b>v1.1Beta1</b> onwards, for Vybrid modules.
/// @param[in]    hGpio       HANDLE received from Gpio_Init()
/// @param[in]    io          GPIO number or SODIMM pin number or Apalis pin number
/// @param[in]    paramName2  Not used. Always set to NULL.
/// @param[in]    value       String value to be set,e.g "dir=out, lvl=1, pull=up100k"
/// @param[in]    storageType StoreInRegistry = parameter will also be stored in the registry\n
///                           StoreVolatile   = parameter will only be stored in local variable.
/// @retval       TRUE        Success
/// @retval       FALSE       Failure
BOOL Gpio_SetConfigString(HANDLE hGpio, uIo io, const TCHAR *paramName2, const TCHAR *value, ParamStorageType storageType);

//******************************************************************************
/// Retrieves the current configuration of a particular GPIO.
/// @param[in]    hGpio       HANDLE received from Gpio_Init()
/// @param[in]    io          GPIO number or SODIMM pin number or Apalis pin number
/// @param[in]    paramName2  Prefix of the configuration option, e.g. "dir" or "lvl", or "altfn".\n
///                           Set to NULL, in order to receive a string containing *all* configuration options.\n
///                           Refer to the @ref scfg_gpio for details.
/// @param[out]   pValue      String data obtained
/// @param[in]    maxBytes    Maximum size of string in Bytes
/// @return       Number of bytes read. 0 indicates an error.
DWORD Gpio_GetConfigString(HANDLE hGpio, uIo io, const TCHAR *paramName2, TCHAR *pValue, DWORD maxBytes);

//******************************************************************************
/// Retrieves the current configuration of a particular GPIO.
/// @param[in]    hGpio       HANDLE received from Gpio_Init()
/// @param[in]    io          GPIO number or SODIMM pin number or Apalis pin number
/// @param[in]    paramName2  Prefix of the configuration option. Only "irq" supported at the moment.
/// @param[out]   pValue      DWORD data obtained
/// @return       Number of bytes read. 0 indicates an error.
DWORD Gpio_GetConfigInt(HANDLE hGpio, uIo io, const TCHAR *paramName2, DWORD *pValue);

//******************************************************************************
/// Get the revision of this Gpio library
/// @param[out]     ver     library version, consist of major, minor and build version.
void Gpio_GetVersion(tVersion *ver);


#ifdef __cplusplus
}
#endif

#endif