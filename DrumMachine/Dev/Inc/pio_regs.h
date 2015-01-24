/*
 *  File: Dev/Inc/pio_regs.h
 *  Lab: Final
 *  Alex Eklund
 *  Date: December 2010
 *  Environment Tested: Altera Nios II IDE
 * 
 */

#ifndef PIO_REGS_H_
#define PIO_REGS_H_

struct PIO_REGS {
	unsigned int data; // data register
	unsigned int direction; // direction register
	unsigned int intmask; // interrupt mask register
	unsigned int edgecapture; // edge capture register
};

#endif /*PIO_REGS_H_*/
