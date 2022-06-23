#ifndef __GPIO_TEG_H__
#define __GPIO_TEG_H__

/*
Definitions of the Tegra GPIO Registers
This file must not be made public without NDA
*/

#include "gpio.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TEGRA_APB_MISC    0x70000000
#define TEGRA_GPIO_BASE   0x6000D000



#if 1
/*Remark need to remove SOC releted macro*/
///
//**************************************
///@name Tegra Specific Defines
//**************************************
///@{
//Converts a Tegra GPIO Name in a GPIONr.
//x is Port Name y is bit nr,
//e.g TEGRA_GPIONUM('b',1) is GPIO B1, this is translated into GPIO #9
#define TEGRA_GPIONUM(x, y) ((((x) - 'a') * 8) + y)

//Define Max length of the Group name
#define TEGRA_MAX_GROUPNAME 6
//Define Max number of GPIOGroups
#define TEGRA_MAX_GROUPNUM 115

#define TEGRA_NOPULL    0x00
#define TEGRA_PULLDOWN  0x01
#define TEGRA_PULLUP    0x02

#define TEGRA_TRISTATE_ENABLED  0x01
#define TEGRA_TRISTATE_DISABLED 0x00
///@}

///Need to optimize interrupt part 
#define GPIO_EDGE_RISING    1
#define EDGE_RISING         1
#define GPIO_EDGE_FALLING   2
#define EDGE_FALLING        2
#define GPIO_EDGE_BOTH      3
#define EDGE_BOTH           3


//////// check?
#define MFP_PULL_SEL         0x8000
#define MFP_PULLUP_EN        0x4000
#define MFP_PULLDOWN_EN      0x2000
#define MFP_SLEEP_SEL        0x0200
#define MFP_SLEEP_DATA       0x0100
#define MFP_SLEEP_OE_N       0x0080
#define MFP_EDGE_CLEAR       0x0040
#define MFP_EDGE_FALL_EN     0x0020
#define MFP_EDGE_RISE_EN     0x0010


#endif
//Index    -> GPIONr
//Value    -> Pin Group Nr.
static const BYTE g_TegraGPIOtoPinGroup[]=
{
//        0      1      2      3      4      5      6      7
/*A*/    12,    17,    59,    59,    59,    59,    25,    27,
/*B*/    20,    20,    88,    80,    26,    26,    26,    26,
/*C*/    17,    87,     8,     8,     1,     1,    86,    23,
/*D*/    53,    56,    12,    55,    54,    16,    14,    14,
/*E*/    45,    44,    43,    42,    41,    40,    39,    38,
/*F*/    37,    36,    94,    93,    92,    91,    90,    89,
/*G*/     3,     3,     3,     3,     3,     3,     3,     3,
/*H*/     4,     4,     4,     4,     6,     6,     6,     6,
/*I*/     3,     3,     5,     2,     2,     3,     2,     3,
/*J*/    22,    83,    22,    34,    33,    62,    61,    20,
/*K*/     3,     3,     3,     3,     3,    77,    76,    20,
/*L*/    13,    13,    13,    13,    13,    13,    13,    13,
/*M*/    103,  102,   101,   100,    99,    98,    49,    50,
/*N*/    60,    60,    60,    60,    82,    84,    35,   108,
/*O*/    10,    11,    11,    11,    11,    10,    10,    10,
/*P*/    58,    58,    58,    58,    57,    57,    57,    57,
/*Q*/    63,    63,    52,    52,    52,    52,    52,    51,
/*R*/    65,    65,    65,    96,    96,    96,    96,    64,
/*S*/    64,    64,    64,    64,    64,    64,    64,    64,
/*T*/    13,    67,    15,    15,    16,    47,    47,     5,
/*U*/    28,    28,    28,    28,    28,    28,    28,    95,
/*V*/     9,     9,     9,     9,    29,    29,    29,    78,
/*W*/    32,    31,    74,    75,   110,   109,    18,    18,
/*X*/    68,    69,    70,    70,    71,    72,    72,    73,
/*Y*/     7,     7,     7,     7,   107,   107,   107,   107,
/*Z*/   107,   107,    85,    79,    81,    48,    66,    66,
/*AA*/   21,    21,    21,    21,    30,    30,    30,    30,
/*BB*/   48,    12,    46,    46,    12,    12
};


//GroupNr To Group Name
//Index    -> Group Number
//Value    -> Group Name.
static char g_TegraPinGrouptoGroupName[TEGRA_MAX_GROUPNUM+2][TEGRA_MAX_GROUPNAME]=
{
    "--",
    "RM",
    "ATA",
    "ATC",
    "ATD",
    "ATB",
    "ATE",
    "UDA",
    "UAD",
    "UAC",
    "UAB",
    "UAA",
    "DTE",
    "DTD",
    "DTC",
    "DTB",
    "DTA",
    "UCB",
    "UCA",
    "OWC",
    "GMC",
    "GMA",
    "GMD",
    "GMB",
    "DDC",
    "SDD",
    "SDC",
    "SDB",
    "GPU",
    "GPV",
    "GME",
    "LM1",
    "LM0",
    "LVS",
    "LHS",
    "LDC",
    "LD9",
    "LD8",
    "LD7",
    "LD6",
    "LD5",
    "LD4",
    "LD3",
    "LD2",
    "LD1",
    "LD0",
    "DTF",
    "PTA",
    "PMC",
    "LDI",
    "LPP",
    "KBCE",
    "KBCF",
    "SLXK",
    "SLXD",
    "SLXC",
    "SLXA",
    "DAP4",
    "DAP3",
    "DAP2",
    "DAP1",
    "IRRX",
    "IRTX",
    "KBCC",
    "KBCB",
    "KBCA",
    "I2CP",
    "CSUS",
    "SPIA",
    "SPIB",
    "SPIC",
    "SPID",
    "SPIE",
    "SPIF",
    "SPIG",
    "SPIH",
    "SPDI",
    "SPDO",
    "LVP0",
    "LSC1",
    "LSC0",
    "LSCK",
    "LCSN",
    "LSPI",
    "LSDA",
    "LSDI",
    "LPW2",
    "LPW1",
    "LPW0",
    "LD15",
    "LD14",
    "LD13",
    "LD12",
    "LD11",
    "LD10",
    "GPU7",
    "KBCD",
    "CRTP",
    "LHP0",
    "LVP1",
    "LHP2",
    "LHP1",
    "LD17",
    "LD16",
    "DAC3",
    "DAC2",
    "DAC1",
    "SDIO1",
    "HDINT",
    "CDEV2",
    "CDEV1",
    "DAP4M",
    "DAP3M",
    "DAP2M",
    "DAP1M",
    ""
};


//Index        -> Pin Group Number
//FistValue    -> Register Offset e.g 1 -> Register B
//Second Value -> Bit offset in register
static BYTE g_TegraPinGroupMuxRegisterOffset[TEGRA_MAX_GROUPNUM][2]=
{
    {-1, -1},
    {0, 14},
    {0, 24},
    {0, 22},
    {0, 20},
    {0, 16},
    {0, 12},
    {0,  8},
    {0,  6},
    {0,  4},
    {0,  2},
    {0,  0},
    {1, 30},
    {1, 28},
    {1, 26},
    {1, 22},
    {1, 20},
    {1, 18},
    {1, 16},
    {1,  8},
    {1,  2},
    {1,  0},
    {2, 30},
    {2, 28},
    {2,  0},
    {3, 14},
    {3, 12},
    {3, 10},
    {3,  4},
    {3,  2},
    {3,  0},
    {4, 28},
    {4, 26},
    {4, 24},
    {4, 22},
    {4, 14},
    {5, 18},
    {5, 16},
    {5, 14},
    {5, 12},
    {5, 10},
    {5,  8},
    {5,  6},
    {5,  4},
    {5,  2},
    {5,  0},
    {6, 30},
    {6, 22},
    {6, 18},
    {6, 16},
    {6, 14},
    {0, 28},
    {0, 26},
    {1, 14},
    {1, 12},
    {1, 10},
    {1,  6},
    {2, 26},
    {2, 24},
    {2, 22},
    {2, 20},
    {2, 18},
    {2, 16},
    {2, 14},
    {2, 12},
    {2, 10},
    {2,  8},
    {2,  6},
    {3, 30},
    {3, 28},
    {3, 26},
    {3, 24},
    {3, 22},
    {3, 20},
    {3, 18},
    {3, 16},
    {3,  8},
    {3, 6},
    {4, 30},
    {4, 20},
    {4, 18},
    {4, 16},
    {4, 12},
    {4, 10},
    {4,  8},
    {4,  6},
    {4,  4},
    {4,  2},
    {4,  0},
    {5, 30},
    {5, 28},
    {5, 26},
    {5, 24},
    {5, 22},
    {5, 20},
    {6, 28},
    {6, 26},
    {6, 20},
    {6, 10},
    {6,  8},
    {6,  6},
    {6,  4},
    {6,  2},
    {6,  0},
    {7, 16},
    {7, 14},
    {7, 12},
    {0, 30},
    {1,  4},
    {2,  4},
    {2,  2},
    {7, 21},
    {7, 20},
    {7, 19},
    {7, 18}
};

//Index            -> Pin Group Number
//FistValue        -> Register Offset e.g 1 -> Register B
//Second Value    -> Bit offset in register
static BYTE g_TegraPinGroupPullUpDownRegisterOffset[TEGRA_MAX_GROUPNUM][2]=
{
/*NoGroup*/   {-1, -1},
/* RM */      {1, 0},
/* ATA */     {0, 0},
/* ATC */     {0, 4},
/* ATD */     {0, 6},
/* ATB */     {0, 2},
/* ATE */     {0, 8},
/* UDA */     {4, 16},
/* UAD */     {3, 6},
/* UAC */     {3, 4},
/* UAB */     {3, 2},
/* UAA */     {3, 0},
/* DTE */     {0, 26},
/* DTD */     {0, 24},
/* DTC */     {0, 22},
/* DTB */     {0, 20},
/* DTA */     {0, 18},
/* UCB */     {3, 10},
/* UCA */     {3, 8},
/* OWC */     {4, 30},
/* GMC */     {4, 24},
/* GMA */     {4, 20},
/* GMD */     {4, 26},
/* GMB */     {4, 22},
/* DDC */     {4, 28},
/* SDD */     {3, 30},
/* SDC */     {3, 28},
/* SDB */     {3, 30},
/* GPU */     {1, 20},
/* GPV */     {0, 30},
/* GME */     {2, 24},
/* LM1 */     {3, 22},
/* LM0 */     {3, 22},
/* LVS */     {3, 22},
/* LHS */     {3, 22},
/* LDC */     {3, 20},
/* LD9 */     {3, 12},
/* LD8 */     {3, 12},
/* LD7 */     {3, 12},
/* LD6 */     {3, 12},
/* LD5 */     {3, 12},
/* LD4 */     {3, 12},
/* LD3 */     {3, 12},
/* LD2 */     {3, 12},
/* LD1 */     {3, 12},
/* LD0 */     {3, 12},
/* DTF */     {0, 28},
/* PTA */     {1, 4},
/* PMC */     {4, 6},
/* LDI */     {3, 18},
/* LPP */     {3, 18},
/* KBCE */    {4, 2},
/* KBCF */    {4, 0},
/* SLXK */    {1, 30},
/* SLXD */    {1, 28},
/* SLXC */    {1, 26},
/* SLXA */    {1, 22},
/* DAP4 */    {0, 16},
/* DAP3 */    {0, 14},
/* DAP2 */    {0, 12},
/* DAP1 */    {0, 10},
/* IRRX */    {2, 22},
/* IRTX */    {2, 20},
/* KBCC */    {1, 12},
/* KBCB */    {1, 10},
/* KBCA */    {1,  8},
/* I2CP */    {1,  2},
/* CSUS */    {3, 24},
/* SPIA */    {2,  4},
/* SPIB */    {2,  6},
/* SPIC */    {2,  8},
/* SPID */    {2, 10},
/* SPIE */    {2, 12},
/* SPIF */    {2, 14},
/* SPIG */    {2, 16},
/* SPIH */    {2, 18},
/* SPDI */    {1, 16},
/* SPDO */    {1, 18},
/* LVP0 */    {3, 22},
/* LSC1 */    {3, 20},
/* LSC0 */    {3, 22},
/* LSCK */    {3, 20},
/* LCSN */    {3, 20},
/* LSPI */    {3, 22},
/* LSDA */    {3, 20},
/* LSDI */    {3, 20},
/* LPW2 */    {3, 20},
/* LPW1 */    {3, 20},
/* LPW0 */    {3, 20},
/* LD15 */    {3, 12},
/* LD14 */    {3, 12},
/* LD13 */    {3, 12},
/* LD12 */    {3, 12},
/* LD11 */    {3, 12},
/* LD10 */    {3, 12},
/* GPU7 */    {1,  6},
/* KBCD */    {1, 14},
/* CRTP */    {1, 24},
/* LHP0 */    {3, 16},
/* LVP1 */    {3, 16},
/* LHP2 */    {3, 14},
/* LHP1 */    {3, 14},
/* LD17 */    {3, 12},
/* LD16 */    {3, 12},
/* DAC3 */    {-1, -1},
/* DAC2 */    {-1, -1},
/* DAC1 */    {-1, -1},
/* SDIO1 */   {4, 18},
/* HDINT */   {-1,-1},
/* CDEV2 */   {2,  2},
/* CDEV1 */   {2,  0},
/* DAP4M */   {-1,-1},
/* DAP3M */   {-1,-1},
/* DAP2M */   {-1,-1},
/* DAP1M */   {-1,-1}
};

//Index        -> Pin Group Number
//FistValue    -> Register Offset e.g 1 -> Register B
//Second Value -> Bit offset in register
static BYTE g_TegraPinGroupTristateRegisterOffset[TEGRA_MAX_GROUPNUM][2]=
{
/*NoGroup*/   {-1, -1},
/* RM */      {0,  25},
/* ATA */     {0,   0},
/* ATC */     {0,   2},
/* ATD */     {0,   3},
/* ATB */     {0,   1},
/* ATE */     {1,  25},
/* UDA */     {3,  13},
/* UAD */     {1,  21},
/* UAC */     {1,  20},
/* UAB */     {1,  19},
/* UAA */     {1,  18},
/* DTE */     {0,  15},
/* DTD */     {0,  14},
/* DTC */     {0,  13},
/* DTB */     {0,  12},
/* DTA */     {0,  11},
/* UCB */     {1,  23},
/* UCA */     {1,  22},
/* OWC */     {0,  31},
/* GMC */     {0,  29},
/* GMA */     {0,  28},
/* GMD */     {1,  30},
/* GMB */     {1,  29},
/* DDC */     {1,  31},
/* SDD */     {1,   2},
/* SDC */     {1,   1},
/* SDB */     {3,  15},
/* GPU */     {0,  16},
/* GPV */     {0,  17},
/* GME */     {1,   0},
/* LM1 */     {2,  25},
/* LM0 */     {2,  24},
/* LVS */     {2,  26},
/* LHS */     {3,   7},
/* LDC */     {2,  30},
/* LD9 */     {2,   9},
/* LD8 */     {2,   8},
/* LD7 */     {2,   7},
/* LD6 */     {2,   6},
/* LD5 */     {2,   5},
/* LD4 */     {2,   4},
/* LD3 */     {2,   3},
/* LD2 */     {2,   2},
/* LD1 */     {2,   1},
/* LD0 */     {2,   0},
/* DTF */     {3,  12},
/* PTA */     {0,  24},
/* PMC */     {0,  23},
/* LDI */     {3,   6},
/* LPP */     {3,   8},
/* KBCE */    {0,  26},
/* KBCF */    {0,  27},
/* SLXK */    {1,   7},
/* SLXD */    {1,   6},
/* SLXC */    {1,   5},
/* SLXA */    {1,   3},
/* DAP4 */    {0,  10},
/* DAP3 */    {0,   9},
/* DAP2 */    {0,   8},
/* DAP1 */    {0,   7},
/* IRRX */    {0,  20},
/* IRTX */    {0,  19},
/* KBCC */    {1,  26},
/* KBCB */    {0,  21},
/* KBCA */    {0,  22},
/* I2CP */    {0,  18},
/* CSUS */    {0,   6},
/* SPIA */    {1,  10},
/* SPIB */    {1,  11},
/* SPIC */    {1,  12},
/* SPID */    {1,  13},
/* SPIE */    {1,  14},
/* SPIF */    {1,  15},
/* SPIG */    {1,  16},
/* SPIH */    {1,  17},
/* SPDI */    {1,   8},
/* SPDO */    {1,   9},
/* LVP0 */    {2,  21},
/* LSC1 */    {2,  28},
/* LSC0 */    {2,  27},
/* LSCK */    {2,  29},
/* LCSN */    {2,  31},
/* LSPI */    {3,   0},
/* LSDA */    {3,   1},
/* LSDI */    {3,   2},
/* LPW2 */    {3,   5},
/* LPW1 */    {3,   4},
/* LPW0 */    {3,   3},
/* LD15 */    {2,  15},
/* LD14 */    {2,  14},
/* LD13 */    {2,  13},
/* LD12 */    {2,  12},
/* LD11 */    {2,  11},
/* LD10 */    {2,  10},
/* GPU7 */    {3,  11},
/* KBCD */    {3,  10},
/* CRTP */    {3,  14},
/* LHP0 */    {2,  18},
/* LVP1 */    {2,  22},
/* LHP2 */    {2,  20},
/* LHP1 */    {2,  19},
/* LD17 */    {2,  17},
/* LD16 */    {2,  16},
/* DAC3 */    {-1, -1},
/* DAC2 */    {-1, -1},
/* DAC1 */    {-1, -1},
/* SDIO1 */   {0,  30},
/* HDINT */   {2,  23},
/* CDEV2 */   {0,   5},
/* CDEV1 */   {0,   4},
/* DAP4M */   {-1, -1},
/* DAP3M */   {-1, -1},
/* DAP2M */   {-1,- 1},
/* DAP1M */   {-1, -1}
};

// On Tegra3 PinMux, PullUp/Down and Tristate bits are all in one per pin register
// So we only need a GPIO->PinmuxReg table
#define A2I(address) (address/4) // Address2Index Macro
static BYTE g_Tegra3GpioToPinMuxRegisterOffset[]=
{
/*                0             1               2             3               4              5             6              7 */
/*A*/    A2I(0x31c),    A2I(0x17c),    A2I(0x358),    A2I(0x364),    A2I(0x35c),    A2I(0x360),    A2I(0x390),    A2I(0x394),
/*B*/    A2I(0x234),    A2I(0x238),    A2I(0x090),    A2I(0x094),    A2I(0x3a4),    A2I(0x3a0),    A2I(0x39c),    A2I(0x398),
/*C*/    A2I(0x180),    A2I(0x070),    A2I(0x168),    A2I(0x164),    A2I(0x1a4),    A2I(0x1a0),    A2I(0x074),    A2I(0x1c0),
/*D*/    A2I(0x3ac),    A2I(0x3a8),    A2I(0x10c),    A2I(0x3b0),    A2I(0x3b4),    A2I(0x128),    A2I(0x15c),    A2I(0x160),
/*E*/    A2I(0x0a4),    A2I(0x0a8),    A2I(0x0ac),    A2I(0x0b0),    A2I(0x0b4),    A2I(0x0b8),    A2I(0x0bc),    A2I(0x0c0),
/*F*/    A2I(0x0c4),    A2I(0x0c8),    A2I(0x0cc),    A2I(0x0d0),    A2I(0x0d4),    A2I(0x0d8),    A2I(0x0dc),    A2I(0x0e0),
/*G*/    A2I(0x1f0),    A2I(0x1f4),    A2I(0x1f8),    A2I(0x1fc),    A2I(0x200),    A2I(0x204),    A2I(0x208),    A2I(0x20c),
/*H*/    A2I(0x210),    A2I(0x214),    A2I(0x218),    A2I(0x21c),    A2I(0x220),    A2I(0x224),    A2I(0x228),    A2I(0x22c),
/*I*/    A2I(0x240),    A2I(0x244),    A2I(0x248),    A2I(0x1e8),    A2I(0x24c),    A2I(0x1c4),    A2I(0x1ec),    A2I(0x1c8),
/*J*/    A2I(0x1d4),    A2I(0x098),    A2I(0x1d8),    A2I(0x09c),    A2I(0x0a0),    A2I(0x170),    A2I(0x16c),    A2I(0x230),
/*K*/    A2I(0x1cc),    A2I(0x1d0),    A2I(0x1e4),    A2I(0x1dc),    A2I(0x1e0),    A2I(0x354),    A2I(0x350),    A2I(0x23c),
/*L*/    A2I(0x12c),    A2I(0x130),    A2I(0x134),    A2I(0x138),    A2I(0x13c),    A2I(0x140),    A2I(0x144),    A2I(0x148),
/*M*/    A2I(0x0e4),    A2I(0x0e8),    A2I(0x0ec),    A2I(0x0f0),    A2I(0x0f4),    A2I(0x0f8),    A2I(0x0fc),    A2I(0x100),
/*N*/    A2I(0x338),    A2I(0x33c),    A2I(0x340),    A2I(0x344),    A2I(0x084),    A2I(0x07c),    A2I(0x088),    A2I(0x110),
/*O*/    A2I(0x01c),    A2I(0x000),    A2I(0x004),    A2I(0x008),    A2I(0x00c),    A2I(0x010),    A2I(0x014),    A2I(0x018),
/*P*/    A2I(0x030),    A2I(0x034),    A2I(0x038),    A2I(0x03c),    A2I(0x1a8),    A2I(0x1ac),    A2I(0x1b0),    A2I(0x1b4),
/*Q*/    A2I(0x2fc),    A2I(0x300),    A2I(0x304),    A2I(0x308),    A2I(0x30c),    A2I(0x310),    A2I(0x314),    A2I(0x318),
/*R*/    A2I(0x2bc),    A2I(0x2c0),    A2I(0x2c4),    A2I(0x2c8),    A2I(0x2cc),    A2I(0x2d0),    A2I(0x2d4),    A2I(0x2d8),
/*S*/    A2I(0x2dc),    A2I(0x2e0),    A2I(0x2e4),    A2I(0x2e8),    A2I(0x2ec),    A2I(0x2f0),    A2I(0x2f4),    A2I(0x2f8),
/*T*/    A2I(0x154),    A2I(0x158),    A2I(0x14c),    A2I(0x150),    A2I(0x124),    A2I(0x250),    A2I(0x254),    A2I(0x25c),
/*U*/    A2I(0x184),    A2I(0x188),    A2I(0x18c),    A2I(0x190),    A2I(0x194),    A2I(0x198),    A2I(0x19c),    A2I(0x2b0),
/*V*/    A2I(0x040),    A2I(0x044),    A2I(0x060),    A2I(0x064),    A2I(0x114),    A2I(0x118),    A2I(0x11c),    A2I(0x120),
/*W*/    A2I(0x104),    A2I(0x108),    A2I(0x388),    A2I(0x38c),    A2I(0x34c),    A2I(0x068),    A2I(0x174),    A2I(0x178),
/*X*/    A2I(0x368),    A2I(0x36c),    A2I(0x374),    A2I(0x370),    A2I(0x378),    A2I(0x37c),    A2I(0x380),    A2I(0x384),
/*Y*/    A2I(0x020),    A2I(0x024),    A2I(0x028),    A2I(0x02c),    A2I(0x050),    A2I(0x054),    A2I(0x058),    A2I(0x05c),
/*Z*/    A2I(0x048),    A2I(0x04c),    A2I(0x078),    A2I(0x080),    A2I(0x08c),    A2I(0x320),    A2I(0x2b4),    A2I(0x2b8),
/*AA*/   A2I(0x260),    A2I(0x264),    A2I(0x268),    A2I(0x26c),    A2I(0x270),    A2I(0x274),    A2I(0x278),    A2I(0x27c),
/*BB*/   A2I(0x28c),    A2I(0x290),    A2I(0x294),    A2I(0x298),    A2I(0x29c),    A2I(0x2a0),    A2I(0x2a4),    A2I(0x2a8),
/*CC*/   A2I(0x284),    A2I(0x288),    A2I(0x2ac),    A2I(0x280),    A2I(0x258),    A2I(0x06c),    A2I(0x3d8),    A2I(0x3dc),
/*DD*/   A2I(0x3b8),    A2I(0x3bc),    A2I(0x3c0),    A2I(0x3c4),    A2I(0x3c8),    A2I(0x3cc),    A2I(0x3d0),    A2I(0x3d4),
/*EE*/   A2I(0x1b8),    A2I(0x1bc),    A2I(0x348),    A2I(0x3e0)
};

//******************************************************************************
/// Convert specific Tegra GPIO number from SODIMM pin number or Apalis pin number
/// @param[in]          io  GPIO number or SODIMM pin number or Apalis pin number             
/// @retval             io  GPIO number
/// @Remark             Refer uIo structure 
uIo TegGpio_NormalizeIo(uIo io);

//******************************************************************************
/// Initialize Tegra GPIO lib. Allocate the memory map of GPIO.
/// @retval             None 
void TegGpio_Init(void);

//******************************************************************************
/// De Initialize GPIO lib. Un Map memory of GPIO and if used load library ,free 
/// the library.
/// @retval             None 
void TegGpio_DeInit(void);

//******************************************************************************
/// Specific Tegra Get the Input/Output direction of the specified SODIMM Pin or GPIO number or Apalis pin Number
/// @param[in]  io  GPIO number or SODIMM pin number or Apalis pin number                        
/// @retval             GPIO Direction (0: ioInput, 1: ioOutput) 
tIoDirection TegGpio_GetDir(uIo io);

//******************************************************************************
/// Specific Tegra Set the Input/Output direction of the specified SODIMM Pin Number or GPIO number or Apalis pin number
/// @param[in]          io              GPIO number or SODIMM pin number or Apalis pin number
/// @param[in]          dirOut          tIoDirection (0: ioInput, 1:ioOutput)  
void TegGpio_SetDir(uIo io, tIoDirection dirOut);

//******************************************************************************
/// specific tegra Get the Alternative Function setting of the specified SODIMM Pin Number or GPIO number or Apalis pin number
/// @param[in]    io    GPIO number or SODIMM pin number or Apalis pin number            
/// @retval             Alternative Function Setting Number              
///
/// Remarks:            tIoAltFn check this return emum value 
tIoAltFn TegGpio_GetAltFn(uIo io);

//******************************************************************************
/// Specific Tegra Set the Alternative Function setting of the specified SODIMM Pin Number or GPIO number or Apalis pin number
/// @param[in]          io              GPIO number or SODIMM pin number or Apalis pin number
/// @param[in]          altFn:          Alternative Function Setting, (tIoAltFn)use -1 to configure as GPIO.
/// @param[in]          dirOut:         GPIO Direction [False: ioInput, True: ioOutput]
void TegGpio_SetAltFn(uIo io, tIoAltFn altFn, tIoDirection dirOut);

//******************************************************************************
/// Get the logic level of the specified SODIMM Pin Number or GPIO number or Apalis pin number
/// @param[in]          io              GPIO number or SODIMM pin number or Apalis pin number
/// @retval             ioLow           Pin level is low
/// @retval             ioHigh          Pin level is high
tIoLevel TegGpio_GetLevel(uIo io);

//******************************************************************************
/// Set the logic level of the specified SODIMM Pin Number or GPIO number or Apalis pin number
/// @param[in]          io              GPIO number or SODIMM pin number or Apalis pin number
/// @param[in]          val             [0: ioLow  ,1: ioHigh]  
void TegGpio_SetLevel(uIo io, tIoLevel val);

//******************************************************************************
/// Get the GPIO Edge detect
/// @param[in]          io  GPIO number or SODIMM pin number or Apalis pin number             
/// @retval             [EDGE_RISING(1): rising edge, EDGE_FALLING(2): falling edge]
DWORD TegGpio_GetEdgeDetect(uIo io);

//******************************************************************************
/// Set the GPIO Pin Edge Detect - deprecated, Please use SetGPIOIrqEdge() in IntLib.
/// @deprecated Please use SetGPIOIrqEdge() in IntLib.
/// @param[in]          io              GPIO number or SODIMM pin number or Apalis pin number
/// @param[in]          edge            [EDGE_RISING(1): rising edge, EDGE_FALLING(2): falling edge] 
void TegGpio_SetEdgeDetect(uIo io, DWORD edge);

DWORD TegGpio_GetAltFnForGpio(uIo io);
BOOL TegGpio_GetPinGroupName(uIo io, char *groupName);
DWORD TegGpio_GetPullStatePinGroup(uIo io);
BOOL TegGpio_SetPullStatePinGroup(uIo io, DWORD pullState);
BOOL TegGpio_SetTristatePinGroup(uIo io, BOOL tristate);
DWORD TegGpio_GetTristatePinGroup(uIo io);

#ifdef __cplusplus
}
#endif


#endif // __GPIO_TEG_H__