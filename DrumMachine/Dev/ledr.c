/*
 *  File: Dev/ledr.c
 *  Lab: Final
 *  Alex Eklund
 *  Date: December 2010
 *  Environment Tested: Altera Nios II IDE
 * 
 */

#include "system.h"
#include "Inc/pio_regs.h"

static struct PIO_REGS *rleds = (struct PIO_REGS*) LED_RED_BASE;      //pointer rleds assigned to LEDR_BASE

void update_ledr(unsigned int n)
{
    __asm("stwio %0, %1"::"r"(n), "m"(rleds->data));  //update ledrs
}
