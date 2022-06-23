#include <windows.h>
#include "gpio.h"
#include "int.h"

#define INTERRUPT_PIN	101									///< constant interrupt pin
#define OUTPUT_PIN		135									///< constant output pin 
#define TIMEOUT			10000								///< constant Time-out in ms.
HANDLE  hIntr			= NULL;								///< Global interrupt handle
HANDLE  hGpio			= NULL;								///< Global Handle to gpio library
int wmain()
{
    
    uIo			interruptPin = COLIBRI_PIN(INTERRUPT_PIN);  ///< Colibri SODIMM pin for interrupt
	uIo			outputPin	= COLIBRI_PIN(OUTPUT_PIN);		///< Colibri SODIMM pin for output Logic
    HANDLE		hEvent		= NULL;							///< Handle to interrupt tread					
    BOOL		returnFlag	= FALSE;
	BOOL		pinLevel	= FALSE;
	DWORD		retVal		= 0;
    DWORD		irq			= 0;							///< Variable for irq number from gpio   
	CHAR		select		= 0;							///< Variable to get choice/option from user
    DWORD		systemInterrupt = 0;						///< Variable to get system inerrupt number
	
    hGpio = Gpio_Init(NULL);									///< Init GPIO handle 
	if (hGpio == NULL)
	{
        printf("ERROR:: GPIO init function");
	}
    returnFlag = Gpio_Open(hGpio);							///< Open GPIO library
	if(returnFlag == FALSE)
	{
		printf("ERROR:: GPIO Open function");
	}
	Gpio_ConfigureAsGpio(hGpio, outputPin);					///< Configure output PIN as GPIO
    Gpio_SetDir(hGpio, outputPin, ioOutput);				///< Set output pin Configured io as output
    Gpio_ConfigureAsGpio(hGpio, interruptPin);				///< Configure interrupt PIN as GPIO
    Gpio_SetDir(hGpio, interruptPin, ioInput);				///< Set interrupt Configured io as input
    interruptPin = Gpio_NormalizeIo(hGpio, interruptPin);	///< Convert IO (ioColibriPin, ioApalis or ioGpio) to ioGpio
	hIntr = Int_Init();										///< Initialize interrupt Library
    if (hIntr == NULL)
	{
        printf("ERROR:: interrupt init function");
	}
    Gpio_SetConfigString(hGpio, interruptPin, NULL, L"irqtrig=rising", StoreVolatile);	///< Set Edge to trigger rising
    Gpio_GetConfigInt(hGpio, interruptPin, L"irq", &irq);								///< Requests interrupt (IRQ) on GPIO number.
    if (!irq)
    {
        printf("\nCannot obtain IRQ for SODDIM Number %d. \nPress enter to exit.", INTERRUPT_PIN);
        getchar();
        return FALSE;
    }
	printf("\nIRQ number for SODIMM %d is: %d", INTERRUPT_PIN, irq);
    hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);										///< Creates event or check for existing event to wait for.
    if (!hEvent) 
    {
        printf("\nEvent cannot be created.");
        getchar();
        return FALSE;
    }
    systemInterrupt = Int_RequestSysInterrupt(hIntr, irq);								///< Gets the system interrupt number for corresponding irq.
    if (!systemInterrupt)
    {
        printf("\nCannot obtain system interrupt number.");
        getchar();
        return FALSE;
    }
    printf("\nSystem Interrupt request: %d", systemInterrupt);
    if (!Int_InterruptInitialize(hIntr, systemInterrupt, hEvent, NULL, 0))				///< Initializes system interrupt.
    {
        printf("\nCannot Initialize interrupt.");
        Int_ReleaseSysIntr(hIntr, systemInterrupt);
        getchar();
        return FALSE;
    }
    CeSetThreadPriority(GetCurrentThread(), 200);
    while (TRUE)
    {
		retVal = WaitForSingleObject(hEvent, TIMEOUT);									///< Waits for Event (Interrupt).
        if (retVal == WAIT_OBJECT_0)
        {
            if (pinLevel == TRUE)
            {
				Gpio_SetLevel(hGpio, outputPin, ioLow);									///< Set output pin(SODIMM 135) to low
				pinLevel = FALSE;
            }
            else 
            {
				Gpio_SetLevel(hGpio, outputPin, ioHigh);								///< Set output pin(SODIMM 135) to high
				pinLevel = TRUE;
            }
            if (MessageBox(NULL, L"Interrupt Event Detected, continue Waiting?", L"Interrupt", MB_YESNO) == IDNO)
			{
				break;
			}
            Int_InterruptDone(hIntr, systemInterrupt);
        }
		else if (retVal == WAIT_TIMEOUT)
		{
			printf("\nTimeout %d ms, No interrupt captured on SODIMM pin %d", TIMEOUT, INTERRUPT_PIN);
			printf("\nContinue waiting - y/n?  ");
			fflush(stdin);
			scanf_s("%c", &select);
			if (select == 'y' || select == 'Y')
			{
				continue;
			}
			else
			{
				break;
			}
		}
		else
		{
			printf("\nWait failure. Error Code = %d", GetLastError());
			break;
		}
    }
    Int_InterruptDisable(hIntr, systemInterrupt);			///< Disables interrupt.
	CloseHandle(hEvent);									///< Closes the event handle.
    if (!Int_ReleaseSysIntr(hIntr, systemInterrupt)) 
    {
        MessageBox(NULL, L"An Error occurred!\nInterrupt was not released correctly", L"ERROR", MB_OK);
        return FALSE;
    }
	Int_Deinit(hIntr);										///< DeInitialize interrupt handle
    Gpio_Close(hGpio);										///< Close  GPIO handle
    Gpio_Deinit(hGpio);										///< DeInitialize GPIO handle
    return TRUE;
}