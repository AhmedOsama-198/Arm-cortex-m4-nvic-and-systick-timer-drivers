/******************************************************************************
 *
 * Module: timer
 *
 * File Name: systick_timer.h
 *
 * Description: Header file for the ARM Cortex M4 timer driver
 *
 * Author: Ahmed Osama
 *
 *******************************************************************************/


#ifndef SYSTICK_H_
#define SYSTICK_H_



/*******************************************************************************
 *                                Inclusions                                   *
 *******************************************************************************/
#include"tm4c123gh6pm_registers.h"
#include "std_types.h"
/*******************************************************************************
 *                           Preprocessor Definitions                          *
 *******************************************************************************/
#define tick_per_sec 15999999



/* Enable Exceptions ... This Macro enable IRQ interrupts, Programmable Systems Exceptions and Faults by clearing the I-bit in the PRIMASK. */
#define Enable_Exceptions()    __asm(" CPSIE I ")

/* Disable Exceptions ... This Macro disable IRQ interrupts, Programmable Systems Exceptions and Faults by setting the I-bit in the PRIMASK. */
#define Disable_Exceptions()   __asm(" CPSID I ")

/* Enable Faults ... This Macro enable Faults by clearing the F-bit in the FAULTMASK */
#define Enable_Faults()        __asm(" CPSIE F ")

/* Disable Faults ... This Macro disable Faults by setting the F-bit in the FAULTMASK */
#define Disable_Faults()       __asm(" CPSID F ")

/* Go to low power mode while waiting for the next interrupt */
#define Wait_For_Interrupt()   __asm(" WFI ")

/*******************************************************************************
 *                           Data Types Declarations                           *
 *******************************************************************************/
static  void (*SYSTICK_call_back)(void) = NULL_PTR;


/*******************************************************************************
 *                            Functions Prototypes                             *
 *******************************************************************************/

void SysTick_Init(uint16 a_TimeInMilliSeconds);

void SysTick_Handler(void);

void SysTick_SetCallBack(volatile void (*Ptr2Func) (void));

void SysTick_Stop(void);

void SysTick_Start(void);

void SysTick_DeInit(void);

void SysTick_StartBusyWait(uint16 a_TimeInMilliSeconds);



/************************************************************************************
 *                                 End of File                                      *
 ************************************************************************************/





#endif /* SYSTICK_H_ */
