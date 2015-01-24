/*
 *  File: Dev/timer.c
 *  Lab: Final
 *  Alex Eklund
 *  Date: December 2010
 *  Environment Tested: Altera Nios II IDE
 * 
 */

#include "system.h"
#include "bsu/BSU.h"
#include "Dev/Inc/timer_regs.h"
#include "bsu/types.h"

#include "Dev/Inc/audio_interface.h"

static struct TIMER_REGS *time = (struct TIMER_REGS *) (TIMER_0_BASE | 0x80000000); // create pointer to TIMER_BASE

extern void * ISR_TABLE[32];

void Timer_ISR_Handler (void)
{
    ai_ms_edge();
    time->status = 0;
}

void Timer_Init (void)
{
	bsu_register_irq(TIMER_0_IRQ, Timer_ISR_Handler);
    time->control = 7;
}
