/*
 *  File: Dev/sw.c
 *  Lab: Final
 *  Alex Eklund
 *  Date: December 2010
 *  Environment Tested: Altera Nios II IDE
 * 
 */

#include "system.h"
#include "Inc/pio_regs.h"
#include "Inc/sw.h"

static struct PIO_REGS *sw = (struct PIO_REGS*) (SWITCH_PIO_BASE);   //pointer sw assinged to SWITCH_BASE

unsigned int temp;

void sw_get(union switches * newsw)
{
    // the switches 17-14 are wired backwards
    //here, we fix them after populating the switch union
    __asm("ldwio %0, %1":"=r"(newsw->word):"m"(sw->data));
    temp = newsw->fix.b14;
    newsw->fix.b14 = newsw->fix.b17;
    newsw->fix.b17 = temp;
    temp = newsw->fix.b15;
    newsw->fix.b15 = newsw->fix.b16;
    newsw->fix.b16 = temp;
}
