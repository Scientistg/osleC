///
/// @file         i2c_vyb.h
/// @copyright    Copyright (c) 2015 Toradex AG
/// $Author: andy.kiser $
/// $Revision: 2817 $
/// $Date: 2015-05-28 11:37:42 +0200 (Do, 28 Mai 2015) $
/// @brief        Library to support i2c interface on Toradex modules.
/// @test         Colibri VF61 and VF50
/// @target       Colibri VFxx.
///
/// @anchor vybi2c_pins
/// <h2 class = "groupheader">I2C Pin Availability</h2>
/// I2C functionality is available on the following SODIMM pins of the Colibri VF50 and Colibri VF61.
/// Colibri Standard I2C pins are marked __bold__.
/// |   Function  |        I2C1        |      I2C2     | I2C3 | I2C4 |
/// |-------------|--------------------|---------------|------|------|
/// |      SCL    | __196__\n 102\n 74 | 63\n 134\n 78 | 104  | 37   |
/// |      SDA    | __194__\n 50       | 55\n 72       | 107  | 29   |

/// @page pcfg_i2c        I2C Configuration Options
/// @section scfg_i2c_vyb VF50/VF61 I2C Configurations
/// @anchor  acfg_i2c_vyb
/// The following table explains the configuration parameters supported by calls of \n
/// * VybI2c_SetConfigInt()
/// * VybI2c_GetConfigInt()
///
/// <table class="libParam" >
///   <tr><th>                            Parameter Name                                             </th><th> Value   </th><th> Description</th></tr>
///   <tr><td class="paramname"          >ioScl<sup><a href="#fn1">1</a></sup>             </td><td> DWORD   </td><td> GPIO used as I2C SCL pin in uIo format.</td></tr>
///   <tr><td class="paramname"          >ioSda<sup><a href="#fn1">1</a></sup>             </td><td> DWORD   </td><td> GPIO used as I2C SDA pin in uIo format.</td></tr>
///   <tr><td class="paramname" rowspan=2>BitRateHz<sup><a href="#fn2">2</a></sup>         </td><td> 400000  </td><td> I2C Speed of 400kHz/400kbps.</td></tr>
///   <tr>                                                                                      <td> 100000  </td><td> I2C Speed of 100kHz/100kbps.</td></tr>
///   <tr><td class="paramname"          >Timeout<sup><a href="#fn2">2</a></sup>           </td><td> 1 to 2000 </td><td> I2C timeout in ms. Will be valid for all future Read/Write.</td></tr>
///   <tr><td class="paramname"          >SlaveAddr<sup><a href="#fn2">2</a></sup>         </td><td> DWORD   </td><td> Address of the slave device to communicate.<br> Will be valid for all future Read/Write.</td></tr>
///   <tr><td class="paramname"          >SlaveAddrSize<sup><a href="#fn2">2</a></sup>     </td><td> 7         </td><td> 7 Bit Slave address.</td></tr>
///   <tr><td class="paramname"          >RegisterAddr<sup><a href="#fn2">2</a></sup>      </td><td> DWORD   </td><td> Address of the slave device register to Read/Write.<br> Will be valid for all future Read/Write. The least significant byte is transmitted first</td></tr>
///   <tr><td class="paramname" rowspan=3>RegisterAddrSize<sup><a href="#fn2">2</a></sup>  </td><td> 0       </td><td> Do not send any register address before the data.</td></tr>
///   <tr>                                                                                      <td> 8       </td><td> 8 bit register address.</td></tr>
///   <tr>                                                                                      <td> 16      </td><td> 16 bit register address.</td></tr>
/// </table>
/// <sup id="fn1">1. Set these parameters <b>before</b> calling I2c_Open()</sup><br>
/// <sup id="fn1">2. Set these parameters <b>after</b> calling I2c_Open()</sup>

#ifndef _I2C_VYB_H_
#define _I2C_VYB_H_

#include "TdxCommon.h"

#ifdef __cplusplus
extern "C" {
#endif

//******************************************************************************
/// Initialize HANDLE for the I2C channel\n
/// This function call does not modify any hardware register. Therefore the returned\n
/// handle can be used to make additional configuration, which will become active\n
/// when calling i2c_open().
/// This is an expensive operation - it includes dynamic loading of a driver DLL.
/// @param[in]  portName        I2C channel name. Can be one of these: <ul><li>L"I2C1"</li><li>L"I2C2"</li><li>L"I2C3"</li><li>L"I2C4"</li></ul>
/// @return                     Handle to the I2C port. NULL if the function failed.
HANDLE VybI2c_Init(const TCHAR *portName);

//******************************************************************************
/// Finally close the HANDLE. The port must be closed before.
/// @param[in]  hPort           HANDLE to I2C channel
/// @retval     TRUE            Success
/// @retval     FALSE           Failure
BOOL VybI2c_Deinit(HANDLE hPort);

//******************************************************************************
/// Apply configuration to the hardware, and load the appropriate I2C driver.
/// The I2C driver's port name is identical to the portName used in the library.
/// @param[in]  hPort           HANDLE to I2C channel
/// @retval     TRUE            Success
/// @retval     FALSE           Failure
BOOL VybI2c_Open(HANDLE hPort);

//******************************************************************************
/// Close I2C
/// @param[in]  hPort           HANDLE to I2C channel
/// @retval     TRUE            Success
/// @retval     FALSE           Failure
BOOL VybI2c_Close(HANDLE hPort);

//******************************************************************************
/// Reads data from I2C\n
/// Before calling this function, the slave address and other parameters must
/// be setup by calling VybI2c_SetConfigInt()
/// @param[in]  hPort           HANDLE to I2C channel
/// @param[out] pbuf            Pointer to the receive buffer
/// @param[in]  numberOfBytes   Number of Bytes to receive
/// @return                     Number of received Bytes, -1 (I2C_RW_FAILURE) indicates failure
DWORD VybI2c_Read(HANDLE hPort, DWORD *pbuf, DWORD numberOfBytes);

//******************************************************************************
/// Writes data to I2C\n
/// Before calling this function, the slave address and other parameters must
/// be setup by calling VybI2c_SetConfigInt()
/// @param[in]  hPort           HANDLE to I2C channel
/// @param[in]  pbuf            Pointer to the write buffer
/// @param[in]  numberOfBytes   Number of Bytes to write
/// @return                     Number of Bytes written, -1 (I2C_RW_FAILURE) indicates failure
DWORD VybI2c_Write(HANDLE hPort, DWORD *pbuf, DWORD numberOfBytes);

//******************************************************************************
/// Set a DWORD configuration parameter.\n
/// @param[in]   hPort          HANDLE to I2C channel
/// @param [in]  paramName      Parameter value to configure.\n
///                             Refer to @ref scfg_i2c_vyb for details.
/// @param [in]  value          Data to be set
/// @param[in]   storageType    StoreInRegistry = parameter will also be stored in the registry\n
///                             StoreVolatile   = parameter will only be stored in local variable.
/// @retval      TRUE           Success
/// @retval      FALSE          Failure
BOOL VybI2c_SetConfigInt(HANDLE hPort, const TCHAR *paramName, DWORD value, ParamStorageType storageType);

//******************************************************************************
/// Retrieves a DWORD configuration parameter.
/// @param[in]    hPort         HANDLE to I2C channel
/// @param[in]    paramName     Parameter value to retrieve.\n
///                             Refer to @ref scfg_i2c_vyb for details.
/// @param[out]   pValue        Data obtained
/// @return                     Number of bytes read. 0 if paramName not found.
DWORD VybI2c_GetConfigInt(HANDLE hPort, const TCHAR *paramName, DWORD *pValue);

//******************************************************************************
/// Get the revision of this I2C library
/// @param[out]   ver           library version, consisting of major, minor and build version
void VybI2c_GetVersion(tVersion *ver);

#ifdef __cplusplus
}
#endif

#endif //_I2C_VYB_H_
