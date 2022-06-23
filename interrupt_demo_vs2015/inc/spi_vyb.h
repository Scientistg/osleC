/// @file         spi_vyb.h
/// @copyright    Copyright (c) 2015 Toradex AG
/// $Author: chitresh.gupta $
/// $Rev: 2645 $
/// $Date: 2015-02-03 13:56:54 +0100 (Di, 03 Feb 2015) $
/// @brief        Library to manage access to the Colibri's SPI ports - Freescale Vybrid specific code.
/// @target       Colibri VF50, VF61
///
/// _NOTE:_ For Vybrid modules library is supported on WinCE image <b>v1.1Beta1</b> onwards.
///
/// @anchor vybspi_pins
/// <h2 class = "groupheader">SPI Pin Availability</h2>
/// SPI functionality is available on the following SODIMM pins of the Colibri VF50 and Colibri VF61.
/// Colibri Standard SPI pins are marked __bold__.
/// | Function    | SPI1    | SPI2         | SPI3    | SPI4    |
/// |-------------|---------|--------------|---------|---------|
/// |      CLK    | 77      | __88__\n  85 | 107     | 100     |
/// |      MOSI   | 73      | __92__\n  59 | 104     |  75     |
/// |      MISO   | 43      | __90__\n  67 |  99     | 188     |
/// |      CS0    | 45      | __86__\n  97 |  69     | 135     |
/// |      CS1    | 65      |   79  \n 129 | 106     | 133     |
/// |      CS2    | 98\n 137|   32  \n  95 |         |         |
/// |      CS3    | 71      |   34  \n  61 |         |         |
/// |      CS4    | 25      |              |         |         |
/// |      CS5    | 27      |              |         |         |
///
/// @anchor vybspi_baud
/// <h2 class="groupheader">Supported Baud rates</h2>
/// The following SPI bit rates can be configured on the Colibri VF50 and Colibri VF61.
/// if another baud rate is passed to the library functions, the next lower bit rate is selected.
/// | Frequency (Hz) | VF61 | VF50 |
/// |----------------|------|------|
/// | 26000          | Y    | Y    |
/// | 100000         | Y    | Y    |
/// | 200000         | Y    | Y    |
/// | 812000         | Y    | Y    |
/// | 1000000        | Y    | Y    |
/// | 2000000        | Y    | Y    |
/// | 3000000        | Y    | Y    |
/// | 4000000        | Y    | Y    |
/// | 5000000        | Y    | Y    |
/// | 6000000        | Y    | Y    |
/// | 7000000        | Y    | Y    |
/// | 8000000        | Y    | Y    |
/// | 9000000        | Y    | Y    |
/// | 10000000       | Y    | -    |
/// | 11000000       | -    | Y    |
/// | 12000000       | Y    | -    |
/// | 13000000       | -    | Y    |
/// | 14000000       | Y    | -    |
/// | 17000000       | Y    | Y    |
/// | 21000000       | Y    | -    |
/// | 22000000       | -    | Y    |
/// | 28000000       | Y    | -    |
/// | 33000000       | -    | Y    |
/// | 42000000       | Y    | -    |

/// @page pcfg_spi        SPI Configuration Options
/// @section scfg_spi_vyb VF50/VF61 SPI Configurations 
/// @anchor  acfg_spi_vyb
/// The following table explains the configuration parameters supported by calls of \n
/// * VybSpi_SetConfigInt()
/// * VybSpi_GetConfigInt()
/// * VybSpi_GetConfigString()
/// * VybSpi_SetConfigString()
///
/// @todo: remove CsMode. This is defined through ioCS
/// @todo: rename isSlave to MasterSlave
/// @todo: rename DmaEnable 
/// @todo: does SPI operate in packed or unpacked mode?
/// @todo: Implement DmaEnable=Auto
/// <table class="libParam" >
///   <tr><th>                  Parameter Name        </th><th> Value   </th><th> Description</th></tr>
///   <tr><td class="paramname"          >ioClk       </td><td> DWORD   </td><td> GPIO used as CLK pin in uIo format. <br>@ref vybspi_pins "Vybrid SPI pins".</td></tr>
///   <tr><td class="paramname"          >ioMOSI      </td><td> DWORD   </td><td> GPIO used as MOSI pin in uIo format.<br>@ref vybspi_pins "Vybrid SPI pins".</td></tr>
///   <tr><td class="paramname"          >ioMISO      </td><td> DWORD   </td><td> GPIO used as MISO pin in uIo format.<br>@ref vybspi_pins "Vybrid SPI pins".</td></tr>
///   <tr><td class="paramname"          >ioCS        </td><td> DWORD   </td><td> GPIO used as CS pin in uIo format.  <br>@ref vybspi_pins "Vybrid SPI pins".</td></tr>
///   <tr><td class="paramname"          >BitRateHz   </td><td> DWORD   </td><td> SPI signal frequency in Hz.<br>@ref vybspi_baud "List of supported bit rates"</td></tr>
///   <tr><td class="paramname"          >SpiMode     </td><td> 0 to 3  </td><td> Clock polarity and active clock edge (SPI Modes 0...3)</td></tr>
///   <tr><td class="paramname"          >BitsPerWord </td><td> 8 or 16 </td><td> Number of bits that make up one SPI word (frame)</td></tr>
///   <tr><td class="paramname" rowspan=3>DmaEnable   </td><td> 0       </td><td> PIO:  Data is transferred from/to the SPI controller in PIO mode.</td></tr>
///   <tr>                                                 <td> 1       </td><td> DMA:  (Not supported yet)</td></tr>
///   <tr>                                                 <td> 2       </td><td> Auto: The library decides based on transfer size, whether it is more efficient to use PIO or DMA mode.(Not supported yet)</td></tr>
///   <tr><td class="paramname" rowspan=2>MasterSlave </td><td> 0       </td><td> Master: The CPU is operating in SPI Master mode</td></tr>
///   <tr>                                                 <td> 1       </td><td> Slave:  (Not supported yet)</td></tr>
///   <tr><td class="paramname" rowspan=2>PackedMode  </td><td> 0       </td><td> Unpacked: (Not supported yet)</td></tr>
///   <tr>                                                 <td> 1       </td><td> Packed:   (Not supported yet)</td></tr>
/// </table>
///

#ifndef _SPI_VYB_H_
#define _SPI_VYB_H_

#include <windows.h>
#include "TdxCommon.h"

#ifdef __cplusplus
extern "C" {
#endif



// Function declaration 

//******************************************************************************
/// Initialize HANDLE for the SPI channel\n
/// This function call does not modify any hardware register. Therefore the returned\n
/// handle can be used to make additional configuration, which will become active\n
/// when calling spi_open(). It will allocate memory of spi structure.
/// @param[in]  portName      Selected SPI channel (1 - SPI_CHANNELS_MAX)("SPI1" to "SPI4")
/// @return     Handle to the SPI port. NULL if the function failed.
HANDLE VybSpi_Init(const TCHAR  *portName);

//******************************************************************************
/// Unmap SPI registry and SPI structure. Free the handle. 
/// @param[in]  hPort           pointer of SPI structure 
/// @retval     TRUE            Success
/// @retval     FALSE           Failure
BOOL VybSpi_Deinit(HANDLE hPort);

//******************************************************************************
/// SPI unit Configure clock, GPIO and initialize SPI.
/// @param[in]  hPort           HANDLE to SPI channel
/// @retval     TRUE            Success
/// @retval     FALSE           Failure
BOOL VybSpi_Open(HANDLE hPort);

//******************************************************************************
/// Disable clock, close interrupt and de-initialize spi. 
/// @param[in]  hPort       HANDLE to SPI channel
/// @retval     TRUE        Success
/// @retval     FALSE       Failure
BOOL VybSpi_Close(HANDLE hPort);

//******************************************************************************
/// Reads and Writes data from/to SPI in polling mode - unpacked interface.\n
/// Function returns when numberOfFrames have been received. 
/// @param[in]  hPort           pointer of SPI structure 
/// @param[out] rxBuffer        Pointer to the receive buffer
/// @param[in]  txBuffer        Pointer to the transmit buffer
/// @param[in]  numberOfFrames  number of frames to receive / transmit
/// @retval                     Number of frames received
DWORD VybSpi_ReadWrite(HANDLE hPort, DWORD *rxBuffer, DWORD *txBuffer, DWORD numberOfFrames);

//******************************************************************************
/// Reads data from SPI  
/// @param[in]  hPort            pointer of SPI structure 
/// @param[out] buffer           Pointer to the receive buffer
/// @param[in]  numberOfFrames   Number of frames to receive
/// @retval                      Number  of received frames
DWORD VybSpi_Read(HANDLE hPort, DWORD *buffer, DWORD numberOfFrames);

//******************************************************************************
/// Writes data to SPI 
/// @param[in]  hPort           pointer of SPI structure 
/// @param[in]  buffer          Pointer to the write buffer
/// @param[in]  numberOfFrames  Number of frames to write
/// @retval                     Number  of write frames
DWORD VybSpi_Write(HANDLE hPort, DWORD *buffer, DWORD numberOfFrames);

//******************************************************************************
/// Retrieves a string configuration parameter\n
/// There is no String parameter for the Vybrid SPI library, so this function is not used.
/// @param[in]    hPort       HANDLE to SPI channel
/// @param[in]    paramName   Parameter value to retrieve\n
///                           Refer to @ref scfg_spi_vyb for a list of supported parameters.
/// @param[out]   pValue      String data obtained
/// @param[in]    maxBytes    Maximum size of string in Bytes
/// @return                   Number of bytes read. 0 if paramName not found.  
DWORD VybSpi_GetConfigString(HANDLE hPort, const TCHAR *paramName, TCHAR *pValue, DWORD maxBytes);

//******************************************************************************
/// Set a string configuration parameter\n
/// There is no String parameter for the Vybrid SPI library, so this function is not used.
/// @param[in]    hPort       HANDLE to SPI channel
/// @param[in]    paramName   Parameter value to configure\n
///                           Refer to @ref scfg_spi_vyb for a list of supported parameters.
/// @param[in]    value       String value to be set
/// @param[in]    storageType StoreInRegistry = parameter will also be stored in the registry\n
///                           StoreVolatile   = parameter will only be stored in local variable.
/// @retval       TRUE        Success
/// @retval       FALSE       Failure
BOOL VybSpi_SetConfigString(HANDLE hPort, const TCHAR *paramName, const TCHAR *value, ParamStorageType storageType);

//******************************************************************************
/// Retrieves a DWORD configuration parameter\n
/// @param[in]    hPort       HANDLE to SPI channel
/// @param[in]    paramName   Parameter value to retrieve\n
///                           Refer to @ref scfg_spi_vyb for a list of supported parameters.
/// @param[out]   pValue      String data obtained
/// @return                   Number of bytes read. 0 if paramName not found.         
DWORD VybSpi_GetConfigInt(HANDLE hPort, const TCHAR *paramName, DWORD *pValue);

//******************************************************************************
/// Set a DWORD configuration parameter.\n
/// @param[in]    hPort       HANDLE to SPI channel
/// @param[in]    paramName   Parameter value to configure\n
///                           Refer to @ref scfg_spi_vyb for a list of supported parameters.
/// @param[in]    value       Data to be set
/// @param[in]    storageType StoreInRegistry = parameter will also be stored in the registry\n
///                           StoreVolatile   = parameter will only be stored in local variable.
/// @retval       TRUE        Success
/// @retval       FALSE       Failure
BOOL VybSpi_SetConfigInt(HANDLE hPort, const TCHAR *paramName, DWORD value, ParamStorageType storageType);

//******************************************************************************
/// Get the revision of this spi_vyb library
/// @param[out]     ver     library version, consist of major, minor and build version
void VybSpi_GetVersion(tVersion *ver);


#ifdef __cplusplus
}
#endif

#endif //_SPI_VYB_H_