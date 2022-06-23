///
/// @file         i2c.h
/// @copyright    Copyright (c) 2015 Toradex AG
/// $Author: andy.kiser $
/// $Revision: 2817 $
/// $Date: 2015-05-28 11:37:42 +0200 (Do, 28 Mai 2015) $
/// @brief        Library to support I2C interface on Toradex modules.
/// @test         Colibri VF61 and VF50
/// @target       Colibri T30, T20, VFxx.
///
///
/// @anchor i2c_parameters
/// I2C interface for Colibri VF50/VF61 modules
/// For information on I2C pin availability and supported\n
/// I2C configurations please refer module specific section.
///     - Colibri VF50 / VF61: i2c_vyb.h
///     - Colibri T20 / T30, Apalis T30: i2c_teg.h
///
/// @page pcfg_i2c I2C Configuration Options
/// @tableofcontents
///
/// @section scfg_i2c Compatible I2C Configurations
/// @anchor  acfg_i2c
/// The following subset of I2C configuration parameters is expected to be
/// available on any SoC.\n
/// Toradex  recommends to prefer these settings over the SoC specific
/// configurations. This can simplify the porting to any other Toradex hardware.
///
/// <table class="libParam" >
///   <tr><th>                            Parameter Name                                             </th><th> Value   </th><th> Description</th></tr>
///   <tr><td class="paramname"          >ioScl<sup><a href="#fn1">1</a></sup>             </td><td> DWORD   </td><td> GPIO used as I2C SCL pin in uIo format.</td></tr>
///   <tr><td class="paramname"          >ioSda<sup><a href="#fn1">1</a></sup>             </td><td> DWORD   </td><td> GPIO used as I2C SDA pin in uIo format.</td></tr>
///   <tr><td class="paramname" rowspan=2>BitRateHz<sup><a href="#fn2">2</a></sup>         </td><td> 400000  </td><td> I2C Speed of 400kHz/400kbps.</td></tr>
///   <tr>                                                                                      <td> 100000  </td><td> I2C Speed of 100kHz/100kbps.</td></tr>
///   <tr><td class="paramname"          >Timeout<sup><a href="#fn2">2</a></sup>           </td><td> DWORD   </td><td> I2C timeout in ms. Will be valid for all future Read/Write.</td></tr>
///   <tr><td class="paramname"          >SlaveAddr<sup><a href="#fn2">2</a></sup>         </td><td> DWORD   </td><td> Address of the slave device to communicate.<br> Will be valid for all future Read/Write.</td></tr>
///   <tr><td class="paramname" rowspan=2>SlaveAddrSize<sup><a href="#fn2">2</a></sup>     </td><td> 7       </td><td> 7 bit slave address.</td></tr>
///   <tr>                                                                                      <td> 10      </td><td> 10 bit slave address. Only some SoCs support 10 bit slave addresses.</td></tr>
///   <tr><td class="paramname"          >RegisterAddr<sup><a href="#fn2">2</a></sup>      </td><td> DWORD   </td><td> Address of the slave device register to Read/Write.<br> Will be valid for all future Read/Write. The least significant byte is transmitted first</td></tr>
///   <tr><td class="paramname" rowspan=3>RegisterAddrSize<sup><a href="#fn2">2</a></sup>  </td><td> 0       </td><td> Do not send any register address before the data.</td></tr>
///   <tr>                                                                                      <td> 8       </td><td> 8 bit register address.</td></tr>
///   <tr>                                                                                      <td> 16      </td><td> 16 bit register address.</td></tr>
/// </table>
/// <sup id="fn1">1. Set these parameters <b>before</b> calling I2c_Open()</sup><br>
/// <sup id="fn1">2. Set these parameters <b>after</b> calling I2c_Open()</sup>

#ifndef _I2C_H_
#define _I2C_H_

#include "TdxCommon.h"

#ifdef __cplusplus
extern "C" {
#endif

/// Returned by I2c_Read() and I2c_Write() to indicate that the function failed.
#define I2C_RW_FAILURE  ((DWORD)-1)


//******************************************************************************
/// Initialize HANDLE for the I2C channel\n
/// This function call does not modify any hardware register. Therefore the returned\n
/// handle can be used to make additional configuration, which will become active\n
/// when calling i2c_open().
/// This is an expensive operation - it includes dynamic loading of a driver DLL.
/// @param[in]  portName        Selected I2C channel ("I2C1" to "I2C4")
/// @return     Handle to the I2C channel. NULL if the function failed.
HANDLE I2c_Init(const TCHAR *portName);

//******************************************************************************
/// Finally close the HANDLE. The port must be closed before.
/// @param[in]  hPort           HANDLE to I2C channel
/// @retval     TRUE            Success
/// @retval     FALSE           Failure
BOOL I2c_Deinit(HANDLE hPort);

//******************************************************************************
/// Apply configuration to the hardware.
/// @param[in]  hPort           HANDLE to I2C channel
/// @retval     TRUE            Success
/// @retval     FALSE           Failure
BOOL I2c_Open(HANDLE hPort);

//******************************************************************************
/// Close I2C
/// @param[in]  hPort           HANDLE to I2C channel
/// @retval     TRUE            Success
/// @retval     FALSE           Failure
BOOL I2c_Close(HANDLE hPort);

//******************************************************************************
/// Reads data from I2C.\n
/// Before calling this function, the slave address and other parameters must
/// be setup by calling I2c_SetConfigInt()
/// @param[in]  hPort           HANDLE to I2C channel
/// @param[out] pbuf            Pointer to the receive buffer
/// @param[in]  numberOfBytes   Number of Bytes to receive
/// @return                     Number of received Bytes, -1 (I2C_RW_FAILURE) indicates failure
DWORD I2c_Read(HANDLE hPort, DWORD *pbuf, DWORD numberOfBytes);

//******************************************************************************
/// Writes data to I2C\n
/// Before calling this function, the slave address and other parameters must
/// be setup by calling I2c_SetConfigInt()
/// @param[in]  hPort           HANDLE to I2C channel
/// @param[in]  pbuf            Pointer to the write buffer
/// @param[in]  numberOfBytes   Number of Bytes to write
/// @return                     Number of Bytes written, -1 (I2C_RW_FAILURE) indicates failure
DWORD I2c_Write(HANDLE hPort, DWORD *pbuf, DWORD numberOfBytes);

//******************************************************************************
/// Set a DWORD configuration parameter.\n
/// @param[in]   hPort          HANDLE to I2C channel
/// @param [in]  paramName      Parameter value to configure.\n
///                             Refer to @ref scfg_i2c for details.
/// @param [in]  value          Data to be set
/// @param[in]   storageType    StoreInRegistry = parameter will also be stored in the registry\n
///                             StoreVolatile   = parameter will only be stored in local variable.
/// @retval      TRUE           Success
/// @retval      FALSE          Failure
BOOL I2c_SetConfigInt(HANDLE hPort, const TCHAR *paramName, DWORD value, ParamStorageType storageType);

//******************************************************************************
/// Retrieves a DWORD configuration parameter.
/// @param[in]    hPort         HANDLE to I2C channel
/// @param[in]    paramName     Parameter value to retrieve.\n
///                             Refer to @ref scfg_i2c for details.
/// @param[out]   pValue        Data obtained
/// @return                     Number of bytes read. 0 if paramName not found.
DWORD I2c_GetConfigInt(HANDLE hPort, const TCHAR *paramName, DWORD *pValue);

//******************************************************************************
/// Get the revision of this I2C library
/// @param[out]   ver           library version, consisting of major, minor and build version
void I2c_GetVersion(tVersion *ver);

#ifdef __cplusplus
}
#endif

#endif //_I2C_H_
