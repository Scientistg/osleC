///
/// @file        CoProc.h
/// @copyright   Copyright (c) 2014 Toradex AG
/// $Author: andy.kiser $
/// $Rev: 2636 $ 
/// $Date: 2015-01-30 13:30:52 +0100 (Fr, 30 Jan 2015) $
/// @brief       Library to provide access to the ARM Coprocessor registers.
/// 
/// @target      Colibri VFxx
///

#ifndef __COPROC_H__
#define __COPROC_H__

#include "tdxcommon.h"

#ifdef __cplusplus
extern "C" {
#endif

//=============================================================================
// Type definitions for global system information
//=============================================================================

/// Enumeration listing the SoC (System-on-a-Chip).\n
/// This was called PROCID in the old lib
typedef enum
{
    Soc_None     = -1,          ///< This special eSoc ID is used internally to mark an invalid value
    Soc_PXA270   = 0x11,        ///< Marvell PXA270 or PXA270M SoC
    Soc_PXA320   = 0x02,        ///< Marvell PXA320 SoC
    Soc_PXA300   = 0x08,        ///< Marvell PXA300 SoC
    Soc_PXA310   = 0x09,        ///< Marvell PXA310 SoC
    Soc_TEGRA2   = 0x411FC09,   ///< Nvidia Tegra 2 (T20) Dual Core SoC
    Soc_TEGRA3   = 0x412FC09,   ///< Nvidia Tegra 3 (T30) Quad Core SoC
    Soc_VF50     = 0x00500000,  ///< Freescale Vybrid VF50 SoC
    Soc_VF61     = 0x00610000,  ///< Freescale Vybrid VF61 SoC
    Soc_IMX6     = 0x200        ///< Freescale i.MX6 CPU. @todo The i.MX6 ID needs to be adjusted to match with the iMX6 BSP!
} eSoc;

/// Enumeration listing the CPU families - a categorization of the processor IDs.\n
/// This was called SoCType in the old libraries.
typedef enum 
{
    SocFamily_None   = -1,   ///< This special eSoc ID is used internally to mark an invalid value
    SocFamily_PXA    = 1,    ///< PXA270, PXA300, PXA310 or PXA320 SoC
    SocFamily_Tegra  = 2,    ///< Nvidia Tegra2 (T20) or Tegra3 T30) SoC
    SocFamily_Vybrid = 3,    ///< Freescale Vybrid VF50 or VF61 SoC
    SocFamily_Imx    = 4     ///< Freescale i.MX6 SoC
} eSocFamily;

/// Enumeration listing the Toradex form factors. \n
/// This was called ModuleFamily in the old libraries.
typedef enum
{
    FormFactor_None     = -1,   ///< This special eSoc ID is used internally to mark an invalid value
    FormFactor_Colibri  = 0,    ///< Toradex Colibri module, 200-pin SODIMM connector
    FormFactor_Apalis   = 1     ///< Toradex Apalis module, 321-pin MXM3 connector
} eFormFactor;

/// @cond no_doxygen
/// Enumeration of all CPU coprocessors
/// Used for Cop_MRC and Cop_MCR functions
typedef enum
{
    p0 = 0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15
} eCop;

/// Enumeration of all coprocessor registers
/// Used for Cop_MRC and Cop_MCR functions
typedef enum
{
    c0 = 0, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15
} eCopReg;

/// @endcond


//=============================================================================
// Low-Level functions
//=============================================================================

//-------------------------------------------------------------------------
/// Read Coprocessor register. This is directly mapped to the ARM assembler instruction\n
/// MRC cpNr,cpOpc,rd,cRn,cRm,cpInfo\n
/// Please note that many coprocessor registers are implemented per-core. Therefore in
/// a multicore system the function may return different values, depending on 
/// the actual core this function is running on.
/// @param[in]  cpNr        the unique number of the required coprocessor p0..p15
/// @param[in]  opcode1     coprocessor opcode1 (should always be 0 for CP15 access)
/// @param[in]  cRn         coprocessor (source) register number c0..c15
/// @param[in]  cRm         coprocessor (source) register number c0..c15
/// @param[in]  opcode2     coprocessor opcode2
/// @return     Value read from the coprocessor register
DWORD Cop_MRC(eCop cpNr, DWORD opcode1, eCopReg cRn, eCopReg cRm, DWORD opcode2);

//-------------------------------------------------------------------------
/// Write Coprocessor register. This is directly mapped to the ARM assembler instruction\n
/// MCR cpNr,cpOpc,rd,cRn,cRm,cpInfo\n
/// Please note that many coprocessor registers are implemented per-core. Therefore in
/// a multicore system the function may affect only the core this function is running on.
/// @param[in]  value       value to write into the coprocessor register
/// @param[in]  cpNr        the unique number of the required coprocessor p0..p15
/// @param[in]  opcode1     coprocessor opcode1 (should always be 0 for CP15 access)
/// @param[in]  cRn         coprocessor (source) register number c0..c15
/// @param[in]  cRm         coprocessor (source) register number c0..c15
/// @param[in]  opcode2     coprocessor opcode2
void Cop_MCR(DWORD value, eCop cpNr, DWORD opcode1, eCopReg cRn, eCopReg cRm, DWORD opcode2);


//=============================================================================
// CPU information
//=============================================================================


//-------------------------------------------------------------------------
/// Read extended CPUID from Coprocessor 15, register c0
/// @return     value read from coprocessor 15 register c0.\n
///             Refer to the ARM documentation for details.
DWORD Cop_GetCpuid();

//-------------------------------------------------------------------------
/// Detect the SoC type this code is running on. (This was called PROCID in the old lib).
/// @return     SoC ID.\n
///             _E.g. PXA270, PXA300, Tegra2, Tegra3, VF50, VF61, ..._
eSoc Cop_GetSoc();


//-------------------------------------------------------------------------
/// Detect the SoC family this code is running on. (This was called CPU_TYPE in the old lib)
/// @return     SoC family\n
///             _E.g. PXA, Tegra, Vybrid, iMX_
eSocFamily Cop_GetSocFamily();


//-------------------------------------------------------------------------
/// Detect the module form factor this code is running on. (This was called ModuleFamily in the old lib)
/// @return     module form factor\n
///             _E.g. Colibri or Apalis_
eFormFactor Cop_GetFormFactor();


//=============================================================================
// General Functions
//=============================================================================

//-------------------------------------------------------------------------
/// Get the revision of this Coproc Lib
/// @param[out]     ver     library version, consisting of major, minor and build version.
void Cop_GetVersion(tVersion *ver);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __COPROC_H__ */
