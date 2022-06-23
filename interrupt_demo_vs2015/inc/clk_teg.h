///
/// @file        clk_teg.h
/// @copyright   Copyright (c) 2014 Toradex AG
/// $Author: chitresh.gupta $
/// $Rev: 2669 $ 
/// $Date: 2015-02-09 14:34:41 +0100 (Mo, 09 Feb 2015) $
/// @brief       Library to manage clock settings
/// @target      VFxx

#ifndef _CLK_TEG_H_
#define _CLK_TEG_H_

#include "TdxCommon.h"
#include "clk_teg_internal.h"

#ifdef __cplusplus
extern "C" {
#endif

//******************************************************************************
/// Initialises the library, call before calling any other functions
HANDLE TegClk_Init();

//******************************************************************************
/// Releases the library resources, call when finished with the library
/// @param[in]    hClk        HANDLE of clock lib 
BOOL TegClk_Deinit(HANDLE hClk);

//******************************************************************************
/// Enables / disables clock for a specific peripheral.
/// @param[in]    hClk        HANDLE of clock lib 
/// @param[in]    clockId     Clock ID (refer to ClkLib.h)
/// @param[in]    state       TRUE: Enable clock, FALSE: Disable clock
/// @retval       TRUE: Success, FALSE: Error
BOOL TegClk_EnableClock(HANDLE hClk, DWORD clockId, BOOL state);

//******************************************************************************
/// Sets Clock Speed as close as possible to the provided frequency. Tegra 2 Only
/// @param[in]    hClk              HANDLE of clock lib 
/// @param[in]    clockId           Clock ID (refer to ClkLib.h)
/// @param[in]    targetMinimumFreq Lowest allowed frequency  [Hz]
/// @param[in]    targetMaximumFreq Highest allowed frequency [Hz]
/// @param[in]    optimiseTarget    ClkOptimiseForPower = select the slowest clock source which can be used to generate a frequency in the requested range\n
///                                 ClkOptimizeForPrecision = select the clock source which can generate a clock as close as possible to the average of minFreq and maxFreq
/// @retval       Actual Frequency configured, 0 = function failed
DWORD TegClk_SetClockFrequency(HANDLE hClk, DWORD clockId, DWORD targetMinimumFrequency, DWORD targetMaximumFrequency, tClockOptimise optimiseTarget);

//******************************************************************************
/// Request clock enable status for a specific peripheral
/// @param[in]    hClk        HANDLE of clock lib 
/// @param[in]    clockId     Clock ID (refer to ClkLib.h)
/// @retval       TRUE: Success, FALSE: Error
BOOL TegClk_GetClk(HANDLE hClk, DWORD clockId);

//******************************************************************************
/// Gets the current frequency of the given clock. Tegra 2 Only
/// @param[in]    hClk        HANDLE of clock lib 
/// @param[in]    clockId     Clock ID (refer to ClkLib.h)
/// @retval                Actual Frequency (Hz) configured, 0 = function failed
DWORD TegClk_GetClockFrequency(HANDLE hClk, DWORD clockId);


#ifdef __cplusplus
}
#endif

#endif