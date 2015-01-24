/*
 *  File: Dev/ledg.c
 *  Lab: Final
 *  Alex Eklund
 *  Date: December 2010
 *  Environment Tested: Altera Nios II IDE
 * 
 */

#include "system.h"
#include "Inc/pio_regs.h"

static struct PIO_REGS *gleds = (struct PIO_REGS*) LED_GREEN_BASE;

void update_ledg(unsigned int sounds)
{
    __asm("stwio %0, %1"::"r"(sounds), "m"(gleds->data));
}
