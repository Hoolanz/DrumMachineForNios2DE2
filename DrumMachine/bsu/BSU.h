/*
 *  File: BSU/bsu.h
 *  Author: Arlen Planting
 *  Date: October 2010
 *  Environment Tested: Altera Nios II IDE
 * 
 *  Common header file for BSU directory
 */

#ifndef BSU_H_
#define BSU_H_

#include "BSU/types.h"

void bsu_printf(char *fmt, ...);
void bsu_prints(char *);
void bsu_putchar(char);
void itoh(unsigned int, char *);
void itoa(unsigned int, char *);

void bsu_irq_enable_all (unsigned int status);
unsigned int bsu_irq_disable_all (void);
void bsu_enable_irq (int irqnbr);
void bsu_disable_irq (int irqnbr);
void bsu_register_irq (int irqnbr, void (*handler)(void));

#endif /*BSU_H_*/
