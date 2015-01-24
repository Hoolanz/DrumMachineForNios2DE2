/*
 *  File: Dev/LCD/lcd_io.h
 *  Lab: Final
 *  Alex Eklund
 *  Date: December 2010
 *  Environment Tested: Altera Nios II IDE
 * 
 */

#ifndef LCD_IO_H_
#define LCD_IO_H_

//initialization rountine
void LCD_IO_init ( unsigned int LCDADDR );
//write an instruction to LCD
void LCD_IO_write_cmd ( unsigned char cmd );
//write data to LCD
void LCD_IO_write_data ( unsigned char data );
//read status of LCD
unsigned char LCD_IO_read_status ( void );
//read data from LCD
unsigned char LCD_IO_read_data ( void );

#endif /*LCD_IO_H_*/
