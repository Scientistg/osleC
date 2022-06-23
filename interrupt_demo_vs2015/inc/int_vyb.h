///
/// @file        Int_Vyb.h
/// @copyright   Copyright (c) 2015 Toradex AG
/// $Author: andy.kiser $
/// $Rev: 2650 $ 
/// $Date: 2015-02-04 11:11:26 +0100 (Mi, 04 Feb 2015) $
/// @brief       IRQ Number of Vybrid peripherals. Gpio IRQ numbers are not 
///              not defined here, but throug the Gpio_GetIrq() function
///              in the GPIO Library.
/// 
/// @target      Colibri VFxx

#ifndef _INT_VYB_H_
#define _INT_VYB_H_

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

#define IRQ_BASE        16

/// IRQ numbers for VF50 and VF61
/// 
/// | IRQ       | Interrupt source           |
/// | :-------- | :------------------------- |
/// | 0 - 145   | Various Vybrid Peripherals |
/// | 146 - 153 | Timer0 - Timer7            |
/// | 154 - 255 | GPIOs. See Gpio_GetIrq()   |
/// \n
/// The constants defining each IRQ number of the VF50/VF61 SoCs are:
typedef enum {
  IRQ_SGI0                     = 16-IRQ_BASE ,              ///< Software Generated Interrupt
  IRQ_SGI1                     = 17-IRQ_BASE ,              ///< Software Generated Interrupt
  IRQ_SGI2                     = 18-IRQ_BASE ,              ///< Software Generated Interrupt
  IRQ_SGI3                     = 19-IRQ_BASE ,              ///< Software Generated Interrupt
  IRQ_SGI4                     = 20-IRQ_BASE ,              ///< Software Generated Interrupt
  IRQ_SGI5                     = 21-IRQ_BASE ,              ///< Software Generated Interrupt
  IRQ_SGI6                     = 22-IRQ_BASE ,              ///< Software Generated Interrupt
  IRQ_SGI7                     = 23-IRQ_BASE ,              ///< Software Generated Interrupt
  IRQ_SGI8                     = 24-IRQ_BASE ,              ///< Software Generated Interrupt
  IRQ_SGI9                     = 25-IRQ_BASE ,              ///< Software Generated Interrupt
  IRQ_SGI10                    = 26-IRQ_BASE ,              ///< Software Generated Interrupt
  IRQ_SGI11                    = 27-IRQ_BASE ,              ///< Software Generated Interrupt
  IRQ_SGI12                    = 28-IRQ_BASE ,              ///< Software Generated Interrupt
  IRQ_SGI13                    = 29-IRQ_BASE ,              ///< Software Generated Interrupt
  IRQ_SGI14                    = 30-IRQ_BASE ,              ///< Software Generated Interrupt
  IRQ_SGI15                    = 31-IRQ_BASE ,              ///< Software Generated Interrupt
  IRQ_PPI0                     = 32-IRQ_BASE ,              ///< Private Peripheral Interrupt
  IRQ_PPI1                     = 33-IRQ_BASE ,              ///< Private Peripheral Interrupt
  IRQ_PPI2                     = 34-IRQ_BASE ,              ///< Private Peripheral Interrupt
  IRQ_PPI3                     = 35-IRQ_BASE ,              ///< Private Peripheral Interrupt
  IRQ_PPI4                     = 36-IRQ_BASE ,              ///< Private Peripheral Interrupt
  IRQ_PPI5                     = 37-IRQ_BASE ,              ///< Private Peripheral Interrupt
  IRQ_PPI6                     = 38-IRQ_BASE ,              ///< Private Peripheral Interrupt
  IRQ_PPI7                     = 39-IRQ_BASE ,              ///< Private Peripheral Interrupt
  IRQ_PPI8                     = 40-IRQ_BASE ,              ///< Private Peripheral Interrupt
  IRQ_PPI9                     = 41-IRQ_BASE ,              ///< Private Peripheral Interrupt
  IRQ_PPI10                    = 42-IRQ_BASE ,              ///< Private Peripheral Interrupt
  IRQ_GlobalTimer              = 43-IRQ_BASE ,              ///< Private Peripheral Interrupt
  IRQ_PPI12                    = 44-IRQ_BASE ,              ///< Private Peripheral Interrupt
  IRQ_CoreTimer                = 45-IRQ_BASE ,              ///< Private Peripheral Interrupt
  IRQ_CoreWatchdog             = 46-IRQ_BASE ,              ///< Private Peripheral Interrupt
  IRQ_PPI15                    = 47-IRQ_BASE ,              ///< Private Peripheral Interrupt
  IRQ_CPU_to_CPU_int0          = 48-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_CPU_to_CPU_int1          = 49-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_CPU_to_CPU_int2          = 50-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_CPU_to_CPU_int3          = 51-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_Directed_CA5_int0        = 52-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_Directed_CA5_int1        = 53-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_Directed_CA5_int2        = 54-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_Directed_CA5_int3        = 55-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_DMA0_Transfer_Complete   = 56-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_DMA0_Error               = 57-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_DMA1_Transfer_Complete   = 58-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_DMA1_Error               = 59-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_Reserved44               = 60-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_Reserved45               = 61-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_MSCM_ECC0                = 62-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_MSCM_ECC1                = 63-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_CSU_Alarm                = 64-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_Reserved49               = 65-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_MSCM_ACTZS               = 66-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_Reserved51               = 67-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_WDOG_A5                  = 68-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_WDOG_M4                  = 69-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_WDOG_SNVS                = 70-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_CP1_Boot_Fail            = 71-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_QuadSPI0                 = 72-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_QuadSPI1                 = 73-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_DRAM                     = 74-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_SDHC0                    = 75-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_SDHC1                    = 76-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_Reserved61               = 77-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_DCU0                     = 78-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_DCU1                     = 79-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_VIU                      = 80-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_Reserved65               = 81-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_GC355                    = 82-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_RLE                      = 83-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_LCD                      = 84-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_Reserved69               = 85-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_Reserved70               = 86-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_PIT                      = 87-IRQ_BASE ,              ///< PIT timer interrupt (Shared Peripheral Interrupt)
  IRQ_LPTimer0                 = 88-IRQ_BASE ,              ///< LPTimer interrupt (Shared Peripheral Interrupt)
  IRQ_Reserved73               = 89-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_FlexTimer0               = 90-IRQ_BASE ,              ///< FTM0 fault-IRQ_BASE , overflow and channels interrupt (Shared Peripheral Interrupt)
  IRQ_FlexTimer1               = 91-IRQ_BASE ,              ///< FTM1 fault-IRQ_BASE , overflow and channels interrupt (Shared Peripheral Interrupt)
  IRQ_FlexTimer2               = 92-IRQ_BASE ,              ///< FTM2 fault-IRQ_BASE , overflow and channels interrupt (Shared Peripheral Interrupt)
  IRQ_FlexTimer3               = 93-IRQ_BASE ,              ///< FTM3 fault-IRQ_BASE , overflow and channels interrupt (Shared Peripheral Interrupt)
  IRQ_Reserved78               = 94-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_Reserved79               = 95-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_Reserved80               = 96-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_Reserved81               = 97-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_USBPHY0                  = 98-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_USBPHY1                  = 99-IRQ_BASE ,              ///< Shared Peripheral Interrupt
  IRQ_Reserved84               = 100-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_ADC0                     = 101-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_ADC1                     = 102-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_DAC0                     = 103-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_DAC1                     = 104-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_Reserved89               = 105-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_FlexCAN0                 = 106-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_FlexCAN1                 = 107-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_MLB                      = 108-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_UART0                    = 109-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_UART1                    = 110-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_UART2                    = 111-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_UART3                    = 112-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_UART4                    = 113-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_UART5                    = 114-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_DSPI0                    = 115-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_DSPI1                    = 116-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_DSPI2                    = 117-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_DSPI3                    = 118-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_I2C0                     = 119-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_I2C1                     = 120-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_I2C2                     = 121-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_I2C3                     = 122-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_USB0                     = 123-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_USB1                     = 124-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_Reserved109              = 125-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_ENET_MAC0                = 126-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_ENET_MAC1                = 127-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_ENET_1588_Timer0         = 128-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_ENET_1588_Timer1         = 129-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_ENET_Switch              = 130-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_NFC                      = 131-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_SAI0                     = 132-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_SAI1                     = 133-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_SAI2                     = 134-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_SAI3                     = 135-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_ESAI_BIFIFO              = 136-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_SPDIF                    = 137-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_ASRC                     = 138-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_CMU                      = 139-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_WKPU0                    = 140-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_WKPU1                    = 141-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_CCM0                     = 142-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_CCM1                     = 143-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_SRC                      = 144-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_PDB                      = 145-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_EWM                      = 146-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_Reserved131              = 147-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_SNVS_Consolidated        = 148-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_SNVS_Security            = 149-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_CAAM                     = 150-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_Reserved135              = 151-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_Reserved136              = 152-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_Reserved137              = 153-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_Reserved138              = 154-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_PORT0                    = 155-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_PORT1                    = 156-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_PORT2                    = 157-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_PORT3                    = 158-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_PORT4                    = 159-IRQ_BASE ,             ///< Shared Peripheral Interrupt
  IRQ_Spurious1022             = 160-IRQ_BASE ,             ///< Special Interrupt
  IRQ_Spurious1023             = 161-IRQ_BASE ,             ///< Special Interrupt
  IRQ_HW_MAX                   = 162-IRQ_BASE ,             ///< Special Interrupt
} IRQInterruptIndex;

#define TIMER_IRQ_BASE  IRQ_HW_MAX
#define TIMER_IRQ_MAX   (TIMER_IRQ_BASE+8)

/// IRQs number for a timer (timerNr must be between 0 and 7.
#define TIMER_IRQ(timerNr)    (TIMER_IRQ_BASE + timerNr)

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _INT_VYB_H_
