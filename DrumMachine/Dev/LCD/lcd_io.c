/*
 *  File: Dev/LCD/lcd_io.c
 *  Lab: Final
 *  Alex Eklund
 *  Date: December 2010
 *  Environment Tested: Altera Nios II IDE
 * 
 */

#include <unistd.h>
#include "Dev/LCD/lcd_io.h"
#include "Dev/LCD/lcd_def.h"

static void LCD_IO_busy_wait ( void );

struct LCD_REGS {
    unsigned int write_cmd;     // RS = 0 write only
    unsigned int read_status;   // RS = 0 read only
    unsigned int write_data;    // RS = 1 write only
    unsigned int read_data;     // RS = 1 read only
};

static struct LCD_REGS *LCD; //pointer for LCD address
   
void LCD_IO_init ( unsigned int LCDADDR )
{
    LCD = (struct LCD_REGS*) (LCDADDR | 0x80000000);  //initialize pointer
    
    usleep(15000);
    LCD->write_cmd = LCD_CMD_FUNC_SET  | LCD_OPT_FUNC_8BIT;

    usleep(4100);    
    LCD->write_cmd = LCD_CMD_FUNC_SET  | LCD_OPT_FUNC_8BIT;

    usleep(100);    
    LCD->write_cmd = LCD_CMD_FUNC_SET  | LCD_OPT_FUNC_8BIT;    
}

void LCD_IO_write_cmd ( unsigned char cmd ) 
{
    LCD_IO_busy_wait();   // wait for LCD
    LCD->write_cmd = cmd; //write cmd
}

void LCD_IO_write_data ( unsigned char data ) 
{
    LCD_IO_busy_wait();     // wait for LCD
    LCD->write_data = data; // write data
}

unsigned char LCD_IO_read_status ( void ) 
{
	return LCD->read_status;
}

unsigned char LCD_IO_read_data ( void ) 
{
	return LCD->read_data;
}

static void LCD_IO_busy_wait ( void )
{
    while(LCD->read_status & LCD_BUSY); //check BF until it is 0
    usleep(1);
}
