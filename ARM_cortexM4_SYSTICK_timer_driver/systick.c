/******************************************************************************
 *
 * Module: timer
 *
 * File Name: systick_timer.c
 *
 * Description: Header file for the ARM Cortex M4 timer driver
 *
 * Author: Ahmed Osama
 *
 ******************************************************************************/

#include "SysTick.h"
#include "common_macros.h"

/*****************************************************************************
 * Service Name: SysTick_Init
 * Sync/Async: Synchronous
 * Reentrancy: Non-reentrant
 * Parameters (in): a_TimeInMilliSeconds - Time period in milliseconds
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Initializes the SysTick timer with the given time period.
 *****************************************************************************/
void SysTick_Init(uint16 a_TimeInMilliSeconds) {
    Enable_Exceptions();
    Enable_Faults();
    SYSTICK_CTRL_REG &= ~0x7;  // Clear SysTick control register
    SYSTICK_CURRENT_REG = 0;  // Clear current register
    SYSTICK_RELOAD_REG = ((a_TimeInMilliSeconds -1)* tick_per_sec) / 1000;
    SYSTICK_CTRL_REG |= 0x7;  // Enable SysTick timer, interrupt, and system clock
}

/*****************************************************************************
 * Service Name: SysTick_Handler
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: SysTick interrupt handler to execute the callback function.
 *****************************************************************************/
void SysTick_Handler(void) {
    // Execute the callback if available
    if (SYSTICK_call_back != NULL_PTR) {
        (*SYSTICK_call_back)();
    }
}

/*****************************************************************************
 * Service Name: SysTick_SetCallBack
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Ptr2Func - Pointer to the callback function
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Sets the callback function for the SysTick timer.
 *****************************************************************************/
void SysTick_SetCallBack(volatile void (*Ptr2Func) (void))
{
    SYSTICK_call_back = Ptr2Func ;
}

/*****************************************************************************
 * Service Name: SysTick_Stop
 * Sync/Async: Synchronous
 * Reentrancy: Non-reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Stops the SysTick timer.
 *****************************************************************************/
void SysTick_Stop(void)
{
    SYSTICK_CTRL_REG&=~(1<<0);   // Disable SysTick
}

/*****************************************************************************
 * Service Name: SysTick_Start
 * Sync/Async: Synchronous
 * Reentrancy: Non-reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Starts the SysTick timer.
 *****************************************************************************/
void SysTick_Start(void)
{
    SYSTICK_CTRL_REG|=(1<<0);   // Enable SysTick
}

/*****************************************************************************
 * Service Name: SysTick_DeInit
 * Sync/Async: Synchronous
 * Reentrancy: Non-reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Deinitializes the SysTick timer and clears its registers.
 *****************************************************************************/
void SysTick_DeInit(void)
{
    SYSTICK_CTRL_REG&=0x8;   // Clear SysTick CTRL register
    SYSTICK_RELOAD_REG=0;
    SYSTICK_CURRENT_REG=0;
}

/*****************************************************************************
 * Service Name: SysTick_StartBusyWait
 * Sync/Async: Synchronous
 * Reentrancy: Non-reentrant
 * Parameters (in): a_TimeInMilliSeconds - Time period in milliseconds
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Starts the SysTick timer in busy-wait mode for the specified time.
 *****************************************************************************/
void SysTick_StartBusyWait(uint16 a_TimeInMilliSeconds)
{
    SYSTICK_CTRL_REG&=~(1<<1);  // Disable interrupt
    SYSTICK_CTRL_REG|=((1<<0)|(1<<2));  // Enable SysTick and system clock
    SYSTICK_RELOAD_REG=a_TimeInMilliSeconds * 15999;
    SYSTICK_CURRENT_REG=0;
    while(!(SYSTICK_CTRL_REG&(1<<16)));  // Wait for the COUNTFLAG
}
