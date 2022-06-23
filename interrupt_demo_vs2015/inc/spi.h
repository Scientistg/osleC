///
/// @file         spi.h
/// @copyright    Copyright (c) 2015 Toradex AG
/// $Author: chitresh.gupta $
/// $Revision: 2660 $
/// $Date: 2015-02-06 13:45:47 +0100 (Fr, 06 Feb 2015) $
/// @brief        Library to support SPI interface on Toradex modules.
/// @target
/// @test tested on:  Colibri Vyb
///
/// _NOTE:_ For Vybrid modules library is supported on WinCE image <b>v1.1Beta1</b> onwards.
///
/// @anchor spi_parameters
/// SPI interface for Colibri VF50/VF61 modules
/// For information on SPI pin availability, supported Baud rates and \n
/// SPI configurations please refer module specific section.
///     - Colibri VF50 / VF61: spi_vyb.h
///     - Colibri T20 / T30, Apalis T30: spi_teg.h
///
/// @page pcfg_spi SPI Configuration Options
/// @tableofcontents
///
/// @section scfg_spi Compatible SPI Configurations
/// @anchor  acfg_spi
/// The following subset of SPI configuration parameters is expected to be 
/// available on any SoC.\n
/// Toradex  recommends to prefer these settings over the SoC specific
/// configurations. This can simplify the porting to any other Toradex hardware.
///
/// @todo: Implement DmaEnable=Auto
/// <table class="libParam" >
///   <tr><th>                            Parameter Name </th><th> Value   </th><th> Description</th></tr>
///   <tr><td class="paramname"          >ioClk          </td><td> DWORD   </td><td> GPIO used as CLK pin in uIo format. </td></tr>
///   <tr><td class="paramname"          >ioMOSI         </td><td> DWORD   </td><td> GPIO used as MOSI pin in uIo format.</td></tr>
///   <tr><td class="paramname"          >ioMISO         </td><td> DWORD   </td><td> GPIO used as MISO pin in uIo format.</td></tr>
///   <tr><td class="paramname"          >ioCS           </td><td> DWORD   </td><td> GPIO used as CS pin in uIo format.  </td></tr>
///   <tr><td class="paramname"          >BitRateHz      </td><td> DWORD   </td><td> SPI signal frequency in Hz. The library will automatically select the next lower available bit rate</td></tr>
///   <tr><td class="paramname"          >SpiMode        </td><td> 0 to 3  </td><td> Clock polarity and active clock edge (SPI Modes 0...3)</td></tr>
///   <tr><td class="paramname"          >BitsPerWord    </td><td> 1 to 31 </td><td> Number of bits that make up one SPI word (frame).<br>Not all values may be supported on all SoC. </td></tr>
///   <tr><td class="paramname" rowspan=3>DmaEnable      </td><td> 0       </td><td> PIO:  Data is transferred from/to the SPI controller in PIO mode.</td></tr>
///   <tr>                                                    <td> 1       </td><td> DMA:  Data is transferred from/to the SPI controller in DMA mode.</td></tr>
///   <tr>                                                    <td> 2       </td><td> Auto: The library decides based on transfer size, whether it is more efficient to use PIO or DMA mode.</td></tr>
///   <tr><td class="paramname" rowspan=2>MasterSlave    </td><td> 0       </td><td> Master: The CPU is operating in SPI Master mode</td></tr>
///   <tr>                                                    <td> 1       </td><td> Slve:   The CPU is operating in SPI Slave mode. SPI Slave mode may not be available on all SoC.</td></tr>
///   <tr><td class="paramname" rowspan=2>PackedMode     </td><td> 0       </td><td> Unpacked: Transmit/Receive data is arranged in memory, so that every SPI word (0..31 bits) occupy a full DWORD (4 bytes).</td></tr>
///   <tr>                                                    <td> 1       </td><td> Packed:   Transmit/Receive data is arranged in memory, so that 8bit SPI words occupy only 1 byte, and 16bit SPI wods occupy only 2 bytes.<br></td></tr>
/// </table>

#ifndef _SPI_H_
#define _SPI_H_

#include "TdxCommon.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    SpiMaster,             ///< Configure as Master Device
    SpiSlave,              ///< Configure as Slave Device
} eSpiMasterSlave;

typedef enum
{
    SpiMode0,              ///< Mode 0 - Polarity (CPOL) 0, Phase (CPHA) 0
    SpiMode1,              ///< Mode 1 - Polarity (CPOL) 0, Phase (CPHA) 1
    SpiMode2,              ///< Mode 2 - Polarity (CPOL) 1, Phase (CPHA) 0
    SpiMode3,              ///< Mode 3 - Polarity (CPOL) 1, Phase (CPHA) 1
} eSpiMode;

//******************************************************************************
/// Initialize HANDLE for the SPI channel\n
/// This function call does not modify any hardware register. Therefore the returned\n
/// handle can be used to make additional configuration, which will become active\n
/// when calling spi_open(). It will allocate memory of spi structure.
/// @param[in]  portName      Selected SPI channel (1 - SPI_CHANNELS_MAX)("SPI1" to "SPI6")
/// @return     Handle to the SPI channel. NULL if the function failed.
HANDLE Spi_Init(const TCHAR *portName);

//******************************************************************************
/// Unmap SPI registry and SPI structure. Free the handle.
/// @param[in]  hPort           HANDLE to SPI channel
/// @retval     TRUE            Success
/// @retval     FALSE           Failure
BOOL Spi_Deinit(HANDLE hPort);

//******************************************************************************
/// SPI unit Configure clock, GPIO and initialize SPI.
/// @param[in]  hPort           HANDLE to SPI channel
/// @retval     TRUE            Success
/// @retval     FALSE           Failure
BOOL Spi_Open(HANDLE hPort);

//******************************************************************************
/// Disable clock, close interrupt and deintilize SPI.
/// @param[in]  hPort       HANDLE to SPI channel
/// @retval     TRUE        Success
/// @retval     FALSE       Failure
BOOL Spi_Close(HANDLE hPort);

//******************************************************************************
/// Reads data from SPI
/// @param[in]  hPort           HANDLE to SPI channel
/// @param[out] pbuf            Pointer to the receive buffer
/// @param[in]  numberOfFrames  Number of frames to receive
/// @return     Number of received frames
DWORD Spi_Read(HANDLE hPort, DWORD *pbuf, DWORD numberOfFrames);

//******************************************************************************
/// Writes data to SPI
/// @param[in]  hPort           HANDLE to SPI channel
/// @param[in]  pbuf            Pointer to the write buffer
/// @param[in]  numberOfFrames  Number of frames to write
/// @return     Number of write frames
DWORD Spi_Write(HANDLE hPort, DWORD *pbuf, DWORD numberOfFrames);

//******************************************************************************
/// Writes data and Reads data from SPI
/// @param[in]  hPort           HANDLE to SPI channel
/// @param[out] rxBuffer        Pointer to the receive buffer.
/// @param[in]  txBuffer        Pointer to the transmit buffer.
/// @param[in]  numberOfFrames  Number of frames to receive
/// @return     Number of transmitted frames
DWORD Spi_ReadWrite(HANDLE hPort, DWORD *rxBuffer, DWORD *txBuffer, DWORD numberOfFrames);

//******************************************************************************
/// Stores data in the string field of an registry key
/// @param[in]  hPort           HANDLE to SPI channel
/// @param[in]  paramName       Pointer to a string containing the name of the string field to set
///                             Refer to @ref scfg_spi for details.
/// @param[in]  value           String value to be set
/// @param[in]  storageType     StoreInRegistry = parameter will also be stored in the registry\n
///                             StoreVolatile   = parameter will only be stored in local variable.
/// @retval     TRUE            Success
/// @retval     FALSE           Failure
BOOL Spi_SetConfigString(HANDLE hPort, const TCHAR *paramName, const TCHAR *value, ParamStorageType storageType);

//******************************************************************************
/// Set a DWORD configuration parameter.\n
/// @param[in]   hPort          HANDLE to SPI channel
/// @param [in]  paramName      Pointer to a string containing the name of the string field to set.\n
///                             Refer to @ref scfg_spi for details.
/// @param [in]  value          Data to be set
/// @param[in]   storageType    StoreInRegistry = parameter will also be stored in the registry\n
///                             StoreVolatile   = parameter will only be stored in local variable.
/// @retval      TRUE           Success
/// @retval      FALSE          Failure
BOOL Spi_SetConfigInt(HANDLE hPort, const TCHAR *paramName, DWORD value, ParamStorageType storageType);

//******************************************************************************
/// Retrieves the type and string data for a specified value name associated with registry key.
/// @param[in]   hPort          HANDLE to SPI channel
/// @param[in]  paramName       Pointer to a string containing the name of the string field to get.
///                             Refer to @ref scfg_spi for details.
/// @param[out] value           Pointer to a buffer that receives the value's string data
/// @param[in]   maxBytes       Maximum size of string in Bytes
/// @return      Number of bytes read. 0 if paramName not found.
DWORD Spi_GetConfigString(HANDLE hPort, const TCHAR *paramName, TCHAR *value, DWORD maxBytes);

//******************************************************************************
/// Retrieves the type and data for a specified value name associated with registry key.
/// @param[in]    hPort         HANDLE to SPI channel
/// @param[in]    paramName     Pointer to a string containing the name of the string field to get.
///                             Refer to @ref scfg_spi for details.
/// @param[out]   pValue        String data obtained
/// @return       Number of bytes read. 0 if paramName not found.
DWORD Spi_GetConfigInt(HANDLE hPort, const TCHAR *paramName, DWORD *pValue);

//******************************************************************************
/// Get the revision of this SPI library
/// @param[out]     ver     library version, consist of major, minor and build version
void Spi_GetVersion(tVersion *ver);

#ifdef __cplusplus
}
#endif

#endif //_SPI_H_
