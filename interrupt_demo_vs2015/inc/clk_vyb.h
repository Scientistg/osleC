///
/// @file        clk_vyb.h
/// @copyright   Copyright (c) 2014 Toradex AG
/// $Author: chitresh.gupta $
/// $Rev: 2669 $ 
/// $Date: 2015-02-09 14:34:41 +0100 (Mo, 09 Feb 2015) $
/// @brief       Library to manage clock settings
/// @target      Colibri VFxx

#ifndef _CLK_VYB_H_
#define _CLK_VYB_H_

#include "TdxCommon.h"

#ifdef __cplusplus
extern "C" {
#endif

/// Vybrid Clock ID refer in vybrid reference manual CCGR Mapping Table
typedef enum
{
    clkFlexCan0         =   0,
    clkDmaChMux0        =   4,
    clkDmaChMux1        =   5,
    clkUart0            =   7,
    clkUart1            =   8,
    clkUart2            =   9,
    clkUart3            =  10,
    clkSpi0             =  12,
    clkSpi1             =  13,
    clkSai0             =  15,
    clkSai1             =  16,
    clkSai2             =  17,
    clkSai3             =  18,
    clkCrc              =  19,
    clkUsbc0            =  20,
    clkPdb              =  22,
    clkPit              =  23,
    clkFtm0             =  24,
    clkFtm1             =  25,
    clkAdc0             =  27,
    clkTcon0            =  29,
    clkWdogA5           =  30,
    clkWdogM4           =  31,
    clkLptmr            =  32,
    clkRle              =  34,
    clkQuadSpi0         =  36,
    clkIomuxCntr        =  40,
    clkPortAMuxCtrl     =  41,
    clkPortBMuxCtrl     =  42,
    clkPortCMuxCtrl     =  43,
    clkPortDMuxCtrl     =  44,
    clkPortEMuxCtrl     =  45,
    clkAnadig           =  48,
    clkScscm            =  50,
    clkDcu0             =  56,
    clkAsrc             =  64,
    clkSpdif            =  65,
    clkEsai             =  66,
    clkExternalWdog     =  69,
    clkI2c0             =  70,
    clkI2c1             =  71,
    clkWkup             =  74,
    clkCcm              =  75,
    clkGpc              =  76,
    clkVREG_DIG         =  77,
    clkCmu              =  79,
    clkDmaChMux2        =  97,
    clkDmaChMux3        =  98,
    clkOtpCtrl          = 101,
    clkUart4            = 105,
    clkUart5            = 106,
    clkSpi2             = 108,
    clkSpi3             = 109,
    clkDdrmc            = 110,
    clkSdhc0            = 113,
    clkSdhc1            = 114,
    clkUsbc1            = 116,
    clkFtm2             = 120,
    clkFtm3             = 121,
    clkAdc1             = 123,
    clkTcon1            = 125,
    clkSegmwntLcd       = 126,
    clkQuadSpi1         = 132,
    clkVideoAdc         = 135,
    clkVideoDecoder     = 136,
    clkViu3             = 137,
    clkDac0             = 140,
    clkDac1             = 141,
    clkEMac0            = 144,
    clkEMac1            = 145,
    clkFlexCan1         = 148,
    clkDcu1             = 152,
    clkNandFlashControl = 160,
    clkI2c2             = 166,
    clkI2c3             = 167,
    clkEthernetL2Switch = 168,
    clkClockEnd         = 180
} tVybClkId;

//******************************************************************************
/// Initialize HANDLE for the vybrid clock lib.\n
/// Allocate memory map and update to the handle.\n
/// This function does not modify any hardware registers.\n
/// @param[in]  registryPath  Registry path string value.e.g "SOFTWARE\\Toradex\\spi" , "SOFTWARE\\Toradex\\app"\n
///             Reserved for future use. Currently we don't need it.\n
///             NULL = do not use registry.
/// @return     Handle to the Clock Library. NULL if the function failed.
HANDLE VybClk_Init(const TCHAR *registryPath);

//******************************************************************************
/// Deinit HANDLE for the vybrid clock lib.\n 
/// Free the allocated memory.
/// @param[in]    hClk            HANDLE of clock lib
/// @retval       TRUE            Success
/// @retval       FALSE           Failure
BOOL VybClk_Deinit(HANDLE hClk);

//******************************************************************************
/// Enable / disable clock for a specific peripheral
/// @param[in]    hClk            HANDLE of clock lib
/// @param[in]    clockId         Clock ID (refer to enum tVybClkId)
/// @param[in]    enable          TRUE to enable clock \nFALSE to disable clock
/// @retval       TRUE            Success
/// @retval       FALSE           Failure
BOOL VybClk_EnableClock(HANDLE hClk, tVybClkId clockId, BOOL enable);

//******************************************************************************
/// Request clock enable status for a specific peripheral.
/// @param[in]    hClk            HANDLE of clock lib 
/// @param[in]    clockId         Clock ID (refer to enum tVybClkId)
/// @retval       TRUE            The clock is currently enabled
/// @retval       FALSE           The clock is currently disabled
BOOL VybClk_ClockEnabled(HANDLE hClk, tVybClkId clockId);

//******************************************************************************
/// Get the revision of this Clock lib
/// @param[out]     ver     library version, consist of major, minor and build version.
void VybClk_GetVersion(tVersion *ver);



#ifdef __cplusplus
}
#endif

#endif