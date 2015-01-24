/*
 *  File: BSU/bsu_irq.c
 *  Author: Arlen Planting
 *  Date: October 2010
 *  Environment Tested: Altera Nios II IDE
 * 
 *  irq registration API
 */

#include "system.h"
#define putbits(w, size, offset, bits) (w & ~((( 1 << size) - 1) << offset)) | (bits << offset)

void * ISR_TABLE[32];

static unsigned int ienashad = 0; //shadow variable for ienable

//# **********************************************************
//# function: void bsu_irq_enable_all (unsigned int status);
//# 
//# **********************************************************
void bsu_irq_enable_all (unsigned int status)
{
    ienashad = ienashad | status;  //update ienashad
    __asm("wrctl ienable,%0" : : "r"(ienashad) );   // write to ienable
    __asm("wrctl status,%0" : : "r"(1) );
}


//# **********************************************************
//# function: unsigned int bsu_irq_disable_all (void);
//# 
//# **********************************************************
unsigned int bsu_irq_disable_all (void)
{
    unsigned int temp = ienashad;   //save ienashad to return
    ienashad = 0;                   //clear ienable and shadow
    __asm("wrctl ienable,r0" : : ); //
    __asm("wrctl status,%0" : : "r"(0) );
    return temp;
}

//# **********************************************************
//# function: void bsu_irq_enable (unsigned int irqnbr);
//# 
//# **********************************************************
void bsu_irq_enable (unsigned int irqnbr)
{
    //use putbits to set specified irq without changing others
    ienashad = putbits(ienashad, 1, irqnbr, 1);
    __asm("wrctl ienable,%0" : : "r"(ienashad) );
}

//# **********************************************************
//# function: void bsu_irq_disable (unsigned int irqnbr);
//# 
//# **********************************************************
void bsu_irq_disable (unsigned int irqnbr)
{
    //use putbits to clear specified irq without changing others
    ienashad = putbits(ienashad, 1, irqnbr, 0);
    __asm("wrctl ienable,%0" : : "r"(ienashad) );
}


//# **********************************************************
//# function: void bsu_irq_register (int irqnbr, void (*handler)(void));
//# 
//# **********************************************************
void bsu_register_irq(int irqnbr, void (*handler)(void))
{
    ISR_TABLE[irqnbr] = handler; //put isr address in array
    bsu_irq_enable (irqnbr);     //set irq
}
