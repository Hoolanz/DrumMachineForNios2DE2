/*
 *  File: Dev/Inc/btn.h
 *  Lab: Final
 *  Alex Eklund
 *  Date: December 2010
 *  Environment Tested: Altera Nios II IDE
 * 
 */

#ifndef BTN_H_
#define BTN_H_


/* The following functions each return a one if
 * the button in question has been pushed
 */
unsigned int btn_get_key0(void);
unsigned int btn_get_key1(void);
unsigned int btn_get_key2(void);
unsigned int btn_get_key3(void);

#endif /*BTN_H_*/
