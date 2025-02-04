/******************************************************************************
 *
 * Module: NVIC
 *
 * File Name: NVIC.h
 *
 * Description: Header file for the ARM Cortex M4 NVIC driver
 *
 * Author: Ahmed Osama
 *
 *******************************************************************************/

#ifndef NVIC_H_
#define NVIC_H_

/*******************************************************************************
 *                                Inclusions                                   *
 *******************************************************************************/
#include"tm4c123gh6pm_registers.h"
#include "std_types.h"
/*******************************************************************************
 *                           Preprocessor Definitions                          *
 *******************************************************************************/

#define MEM_FAULT_PRIORITY_MASK              0x000000E0
#define MEM_FAULT_PRIORITY_BITS_POS          5

#define BUS_FAULT_PRIORITY_MASK              0x0000E000
#define BUS_FAULT_PRIORITY_BITS_POS          13

#define USAGE_FAULT_PRIORITY_MASK            0x00E00000
#define USAGE_FAULT_PRIORITY_BITS_POS        21

#define SVC_PRIORITY_MASK                    0xE0000000
#define SVC_PRIORITY_BITS_POS                29

#define DEBUG_MONITOR_PRIORITY_MASK          0x000000E0
#define DEBUG_MONITOR_PRIORITY_BITS_POS      5

#define PENDSV_PRIORITY_MASK                 0x00E00000
#define PENDSV_PRIORITY_BITS_POS             21

#define SYSTICK_PRIORITY_MASK                0xE0000000
#define SYSTICK_PRIORITY_BITS_POS            29

#define MEM_FAULT_ENABLE_MASK                0x00010000
#define BUS_FAULT_ENABLE_MASK                0x00020000
#define USAGE_FAULT_ENABLE_MASK              0x00040000

/* Enable Exceptions ... This Macro enable IRQ interrupts, Programmable Systems Exceptions and Faults by clearing the I-bit in the PRIMASK. */
#define Enable_Exceptions()    __asm(" CPSIE I ")

/* Disable Exceptions ... This Macro disable IRQ interrupts, Programmable Systems Exceptions and Faults by setting the I-bit in the PRIMASK. */
#define Disable_Exceptions()   __asm(" CPSID I ")

/* Enable Faults ... This Macro enable Faults by clearing the F-bit in the FAULTMASK */
#define Enable_Faults()        __asm(" CPSIE F ")

/* Disable Faults ... This Macro disable Faults by setting the F-bit in the FAULTMASK */
#define Disable_Faults()       __asm(" CPSID F ")



/*******************************************************************************
 *                           Data Types Declarations                           *
 *******************************************************************************/
typedef enum {
    GPIO_PORT_A=0,                    // GPIO Port A
    GPIO_PORT_B,                        // GPIO Port B
    GPIO_PORT_C,                        // GPIO Port C
    GPIO_PORT_D,                        // GPIO Port D
    GPIO_PORT_E,                        // GPIO Port E
    UART0_RXTX,                         // UART0 Rx and Tx
    UART1_RXTX,                         // UART1 Rx and Tx
    SSI0_RXTX,                          // SSI0 Rx and Tx
    I2C0_MASTER_SLAVE,                  // I2C0 Master and Slave
    PWM_FAULT,                          // PWM Fault
    PWM_GENERATOR_0,                    // PWM Generator 0
    PWM_GENERATOR_1,                    // PWM Generator 1
    PWM_GENERATOR_2,                    // PWM Generator 2
    QUADRATURE_ENCODER_0,               // Quadrature Encoder 0
    ADC_SEQUENCE_0,                     // ADC Sequence 0
    ADC_SEQUENCE_1,                     // ADC Sequence 1
    ADC_SEQUENCE_2,                     // ADC Sequence 2
    ADC_SEQUENCE_3,                     // ADC Sequence 3
    WATCHDOG_TIMER,                     // Watchdog timer
    TIMER_0_SUBTIMER_A,                 // Timer 0 subtimer A
    TIMER_0_SUBTIMER_B,                 // Timer 0 subtimer B
    TIMER_1_SUBTIMER_A,                 // Timer 1 subtimer A
    TIMER_1_SUBTIMER_B,                 // Timer 1 subtimer B
    TIMER_2_SUBTIMER_A,                 // Timer 2 subtimer A
    TIMER_2_SUBTIMER_B,                 // Timer 2 subtimer B
    ANALOG_COMPARATOR_0,                // Analog Comparator 0
    ANALOG_COMPARATOR_1,                // Analog Comparator 1
    ANALOG_COMPARATOR_2,                // Analog Comparator 2
    SYSTEM_CONTROL,                     // System Control (PLL, OSC, BO)
    FLASH_CONTROL,                      // FLASH Control
    GPIO_PORT_F,                        // GPIO Port F
    GPIO_PORT_G,                        // GPIO Port G
    GPIO_PORT_H,                        // GPIO Port H
    UART2_RXTX,                         // UART2 Rx and Tx
    SSI1_RXTX,                          // SSI1 Rx and Tx
    TIMER_3_SUBTIMER_A,                 // Timer 3 subtimer A
    TIMER_3_SUBTIMER_B,                 // Timer 3 subtimer B
    I2C1_MASTER_SLAVE,                  // I2C1 Master and Slave
    QUADRATURE_ENCODER_1,               // Quadrature Encoder 1
    CAN0,                               // CAN0
    CAN1,                               // CAN1
    HIBERNATE,                          // Hibernate
    USB0,                               // USB0
    PWM_GENERATOR_3,                    // PWM Generator 3
    UDMA_SOFTWARE_TRANSFER,             // uDMA Software Transfer
    UDMA_ERROR,                         // uDMA Error
    ADC1_SEQUENCE_0,                    // ADC1 Sequence 0
    ADC1_SEQUENCE_1,                    // ADC1 Sequence 1
    ADC1_SEQUENCE_2,                    // ADC1 Sequence 2
    ADC1_SEQUENCE_3,                    // ADC1 Sequence 3
    GPIO_PORT_J,                        // GPIO Port J
    GPIO_PORT_K,                        // GPIO Port K
    GPIO_PORT_L,                        // GPIO Port L
    SSI2_RXTX,                          // SSI2 Rx and Tx
    SSI3_RXTX,                          // SSI3 Rx and Tx
    UART3_RXTX,                         // UART3 Rx and Tx
    UART4_RXTX,                         // UART4 Rx and Tx
    UART5_RXTX,                         // UART5 Rx and Tx
    UART6_RXTX,                         // UART6 Rx and Tx
    UART7_RXTX,                         // UART7 Rx and Tx
    I2C2_MASTER_SLAVE,                  // I2C2 Master and Slave
    I2C3_MASTER_SLAVE,                  // I2C3 Master and Slave
    TIMER_4_SUBTIMER_A,                 // Timer 4 subtimer A
    TIMER_4_SUBTIMER_B,                 // Timer 4 subtimer B
    I2C4_MASTER_SLAVE,                  // I2C4 Master and Slave
    I2C5_MASTER_SLAVE,                  // I2C5 Master and Slave
    GPIO_PORT_M,                        // GPIO Port M
    GPIO_PORT_N,                        // GPIO Port N
    QUADRATURE_ENCODER_2,               // Quadrature Encoder 2
    GPIO_PORT_P,                        // GPIO Port P (Summary or P0)
    GPIO_PORT_Q,                        // GPIO Port Q (Summary or Q0)
    GPIO_PORT_R,                        // GPIO Port R
    GPIO_PORT_S,                        // GPIO Port S
    PWM_1_GENERATOR_0,                  // PWM 1 Generator 0
    PWM_1_GENERATOR_1,                  // PWM 1 Generator 1
    PWM_1_GENERATOR_2,                  // PWM 1 Generator 2
    PWM_1_GENERATOR_3,                  // PWM 1 Generator 3
    PWM_1_FAULT                         // PWM 1 Fault
} NVIC_IRQType;

typedef enum
{
    EXCEPTION_RESET_TYPE,
    EXCEPTION_NMI_TYPE,
    EXCEPTION_HARD_FAULT_TYPE,
    EXCEPTION_MEM_FAULT_TYPE,
    EXCEPTION_BUS_FAULT_TYPE,
    EXCEPTION_USAGE_FAULT_TYPE,
    EXCEPTION_SVC_TYPE,
    EXCEPTION_DEBUG_MONITOR_TYPE,
    EXCEPTION_PEND_SV_TYPE,
    EXCEPTION_SYSTICK_TYPE
}NVIC_ExceptionType;

typedef enum {
    Priority_exception_0,
    Priority_exception_1,
    Priority_exception_2,
    Priority_exception_3,
    Priority_exception_4,
    Priority_exception_5,
    Priority_exception_6,
    Priority_exception_7,
} NVIC_ExceptionPriorityType;

typedef enum {
    Priority_0,
    Priority_1,
    Priority_2,
    Priority_3,
    Priority_4,
    Priority_5,
    Priority_6,
    Priority_7,
} NVIC_IRQPriorityType;
/*******************************************************************************
 *                            Functions Prototypes                             *
 *******************************************************************************/
// Enables a specific IRQ by number
void NVIC_EnableIRQ(NVIC_IRQType IRQ_Num);

// Disables a specific IRQ by number
void NVIC_DisableIRQ(NVIC_IRQType IRQ_Num);

// Sets the priority of a specific IRQ
void NVIC_SetPriorityIRQ(NVIC_IRQType IRQ_Num, NVIC_IRQPriorityType IRQ_Priority);


// Enables a specific ARM system or fault exception
void NVIC_EnableException(NVIC_ExceptionType Exception_Num);

// Disables a specific ARM system or fault exception
void NVIC_DisableException(NVIC_ExceptionType Exception_Num);

// Sets the priority value for a specific ARM system or fault exception
void NVIC_SetPriorityException(NVIC_ExceptionType Exception_Num, NVIC_ExceptionPriorityType Exception_Priority);




/************************************************************************************
 *                                 End of File                                      *
 ************************************************************************************/

#endif /* NVIC_H_ */
