/******************************************************************************
 *
 * Module: NVIC
 *
 * File Name: NVIC.c
 *
 * Description: Source file for the ARM Cortex M4 NVIC driver
 *
 * Author: Ahmed Osama
 *
 ******************************************************************************/
#include "nvic.h"

/*****************************************************************************
 * Service Name: NVIC_EnableIRQ
 * Sync/Async: Synchronous
 * Reentrancy: Non-reentrant
 * Parameters (in): IRQ_Num - Interrupt request number
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Enables the specified IRQ in the NVIC registers.
 *****************************************************************************/
void NVIC_EnableIRQ(NVIC_IRQType IRQ_Num)
{
    Enable_Exceptions();
    Enable_Faults();
    if (IRQ_Num < 32) {
        NVIC_EN0_REG |= (1 << IRQ_Num); // Enable interrupt in NVIC_EN0
    } else if (IRQ_Num < 64) {
        NVIC_EN1_REG |= (1 << (IRQ_Num - 32)); // Enable interrupt in NVIC_EN1
    } else if (IRQ_Num < 96) {
        NVIC_EN2_REG |= (1 << (IRQ_Num - 64)); // Enable interrupt in NVIC_EN2
    } else if (IRQ_Num < 128) {
        NVIC_EN3_REG |= (1 << (IRQ_Num - 96)); // Enable interrupt in NVIC_EN3
    } else if (IRQ_Num < 160) {
        NVIC_EN4_REG |= (1 << (IRQ_Num - 128)); // Enable interrupt in NVIC_EN4
    }
}

/*****************************************************************************
 * Service Name: NVIC_DisableIRQ
 * Sync/Async: Synchronous
 * Reentrancy: Non-reentrant
 * Parameters (in): IRQ_Num - Interrupt request number
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Disables the specified IRQ in the NVIC registers.
 *****************************************************************************/
void NVIC_DisableIRQ(NVIC_IRQType IRQ_Num)
{
    if (IRQ_Num < 32) {
        NVIC_DIS0_REG |= (1 << IRQ_Num);
    } else if (IRQ_Num < 64) {
        NVIC_DIS1_REG |= (1 << (IRQ_Num - 32));
    } else if (IRQ_Num < 96) {
        NVIC_DIS2_REG |= (1 << (IRQ_Num - 64));
    } else if (IRQ_Num < 128) {
        NVIC_DIS3_REG |= (1 << (IRQ_Num - 96));
    } else if (IRQ_Num < 160) {
        NVIC_DIS4_REG |= (1 << (IRQ_Num - 128));
    }
}

/*****************************************************************************
 * Service Name: NVIC_SetPriorityIRQ
 * Sync/Async: Synchronous
 * Reentrancy: Non-reentrant
 * Parameters (in): IRQ_Num - Interrupt request number
 *                 IRQ_Priority - Priority of the interrupt
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Sets the priority level of a specified IRQ.
 *****************************************************************************/
void NVIC_SetPriorityIRQ(NVIC_IRQType IRQ_Num, NVIC_IRQPriorityType IRQ_Priority)
{
    uint32 reg_num = IRQ_Num / 4;
    uint32 reg_address = (uint32)0xE000E400 + (0x4 * reg_num);
    uint32 loc_in_reg = ((float32)IRQ_Num / 4 - (uint32)(IRQ_Num / 4)) * 100;

    if (loc_in_reg == 0) {
        (*((volatile uint32 *)reg_address)) &= ~(7 << 5);
        (*((volatile uint32 *)reg_address)) |= (IRQ_Priority << 5);
    } else if (loc_in_reg == 25) {
        (*((volatile uint32 *)reg_address)) &= ~(7 << 13);
        (*((volatile uint32 *)reg_address)) |= (IRQ_Priority << 13);
    } else if (loc_in_reg == 50) {
        (*((volatile uint32 *)reg_address)) &= ~(7 << 21);
        (*((volatile uint32 *)reg_address)) |= (IRQ_Priority << 21);
    } else if (loc_in_reg == 75) {
        (*((volatile uint32 *)reg_address)) &= ~(7 << 29);
        (*((volatile uint32 *)reg_address)) |= (IRQ_Priority << 29);
    }
}

/*****************************************************************************
 * Service Name: NVIC_EnableException
 * Sync/Async: Synchronous
 * Reentrancy: Non-reentrant
 * Parameters (in): Exception_Num - Type of exception to enable
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Enables a specific system or fault exception.
 *****************************************************************************/
void NVIC_EnableException(NVIC_ExceptionType Exception_Num)
{
    switch (Exception_Num) {
    case EXCEPTION_MEM_FAULT_TYPE:
        NVIC_SYSTEM_SYSHNDCTRL |= (1 << 16);
        break;
    case EXCEPTION_BUS_FAULT_TYPE:
        NVIC_SYSTEM_SYSHNDCTRL |= (1 << 17);
        break;
    case EXCEPTION_USAGE_FAULT_TYPE:
        NVIC_SYSTEM_SYSHNDCTRL |= (1 << 18);
        break;
    case EXCEPTION_DEBUG_MONITOR_TYPE:
        NVIC_SYSTEM_SYSHNDCTRL |= (1 << 8);
        break;
    case EXCEPTION_SYSTICK_TYPE:
        SYSTICK_CTRL_REG |= (1 << 1);
        break;
    default:
        break;
    }
}

/*****************************************************************************
 * Service Name: NVIC_DisableException
 * Sync/Async: Synchronous
 * Reentrancy: Non-reentrant
 * Parameters (in): Exception_Num - Type of exception to disable
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Disables a specific system or fault exception.
 *****************************************************************************/
void NVIC_DisableException(NVIC_ExceptionType Exception_Num)
{
    switch (Exception_Num) {
    case EXCEPTION_MEM_FAULT_TYPE:
        NVIC_SYSTEM_SYSHNDCTRL &= ~(1 << 16);
        break;
    case EXCEPTION_BUS_FAULT_TYPE:
        NVIC_SYSTEM_SYSHNDCTRL &= ~(1 << 17);
        break;
    case EXCEPTION_USAGE_FAULT_TYPE:
        NVIC_SYSTEM_SYSHNDCTRL &= ~(1 << 18);
        break;
    case EXCEPTION_DEBUG_MONITOR_TYPE:
        NVIC_SYSTEM_SYSHNDCTRL &= ~(1 << 8);
        break;
    case EXCEPTION_SYSTICK_TYPE:
        SYSTICK_CTRL_REG &= ~(1 << 1);
        break;
    default:
        break;
    }
}

/*****************************************************************************
 * Service Name: NVIC_SetPriorityException
 * Sync/Async: Synchronous
 * Reentrancy: Non-reentrant
 * Parameters (in): Exception_Num - Type of exception
 *                 Exception_Priority - Priority to set
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Sets the priority level of a specified system or fault exception.
 *****************************************************************************/
void NVIC_SetPriorityException(NVIC_ExceptionType Exception_Num, NVIC_ExceptionPriorityType Exception_Priority)
{
    switch (Exception_Num) {
    case EXCEPTION_MEM_FAULT_TYPE:
        NVIC_SYSTEM_PRI1_REG &= ~MEM_FAULT_PRIORITY_MASK;
        NVIC_SYSTEM_PRI1_REG |= (Exception_Priority << MEM_FAULT_PRIORITY_BITS_POS);
        break;
    case EXCEPTION_BUS_FAULT_TYPE:
        NVIC_SYSTEM_PRI1_REG &= ~BUS_FAULT_PRIORITY_MASK;
        NVIC_SYSTEM_PRI1_REG |= (Exception_Priority << BUS_FAULT_PRIORITY_BITS_POS);
        break;
    case EXCEPTION_USAGE_FAULT_TYPE:
        NVIC_SYSTEM_PRI1_REG &= ~USAGE_FAULT_PRIORITY_MASK;
        NVIC_SYSTEM_PRI1_REG |= (Exception_Priority << USAGE_FAULT_PRIORITY_BITS_POS);
        break;
    case EXCEPTION_SYSTICK_TYPE:
        NVIC_SYSTEM_PRI3_REG &= ~SYSTICK_PRIORITY_MASK;
        NVIC_SYSTEM_PRI3_REG |= (Exception_Priority << SYSTICK_PRIORITY_BITS_POS);
        break;
    default:
        break;
    }
}
