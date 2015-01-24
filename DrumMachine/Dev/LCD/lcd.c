/*
 *  File: Dev/LCD/lcd.c
 *  Lab: Final
 *  Alex Eklund
 *  Date: December 2010
 *  Environment Tested: Altera Nios II IDE
 * 
 */

#include "Dev/LCD/lcd.h"
#include "Dev/LCD/lcd_def.h"
#include "Dev/LCD/lcd_io.h"

char * LCD_Init ( unsigned int LCDADDR ) 
{

    LCD_IO_init(LCDADDR);

    LCD_IO_write_cmd( LCD_CMD_FUNC_SET  |  LCD_OPT_FUNC_8BIT     |
					   LCD_OPT_FUNC_TWO_LINE |
                                           LCD_OPT_FUNC_BIGFONT    );

    LCD_IO_write_cmd ( LCD_CMD_CONTROL );

    LCD_IO_write_cmd ( LCD_CMD_CLR );

    LCD_IO_write_cmd ( LCD_CMD_MODE | LCD_OPT_MODE_INC );

    LCD_IO_write_cmd ( LCD_CMD_CONTROL |   LCD_OPT_CONTROL_DISP );

    return LCD_VERSION;
}

void	LCD_PutChar ( unsigned char c ) 
{
	LCD_IO_write_data (c);
}

void	LCD_Puts ( char *s ) 
{
	while (*s)
        LCD_IO_write_data (*s++);
}

void	LCD_SetCursor ( unsigned char add ) 
{
	LCD_IO_write_cmd(LCD_CMD_DDADDR | add);
}




void LCD_update_bpm(unsigned int bpm)
{
    unsigned char d0=0;
    unsigned char d1=0;
    unsigned char d2=0;

    d0 = bpm % 10;
    d2 = bpm / 100;
    d1 = (bpm % 100)/10;

    LCD_SetCursor ( 0x45 );
    LCD_PutChar ( (3 << 4) | d2 );
    LCD_PutChar ( (3 << 4) | d1 );
    LCD_PutChar ( (3 << 4) | d0 );
}

void LCD_update_vel(unsigned int vel)
{
    LCD_SetCursor ( 0x4b );
    LCD_PutChar ( (3 << 4) | vel );
}

void LCD_update_current_sound(unsigned int current_sound, unsigned int steps[16])
{
    LCD_SetCursor ( 0x4f );
    LCD_PutChar ( (3 << 4) | current_sound );
    LCD_update_steps(steps);
}

void LCD_update_steps(unsigned int steps[16])
{
    LCD_SetCursor ( 0 );
    int t;
    for(t=0; t<16; t++)
    {
        LCD_PutChar ( (3 << 4) |  steps[t]);
    }
}

void LCD_update_volume(unsigned int volume)
{
    unsigned char d0=0;
    unsigned char d1=0;

    d0 = volume % 10;
    d1 = (volume % 100)/10;
    LCD_SetCursor ( 0x40 );
    LCD_PutChar ( (3 << 4) | d1 );
    LCD_PutChar ( (3 << 4) | d0 );

}
