/*
 *  File: Dev/LCD/lcd.h
 *  Lab: Final
 *  Alex Eklund
 *  Date: December 2010
 *  Environment Tested: Altera Nios II IDE
 * 
 */

// include in main function to use LCD

#ifndef LCD_H_
#define LCD_H_


#define LCD_ON  1 
#define LCD_OFF 0   

// initializes LCD
char *	LCD_Init ( unsigned int LCDADDR );

// prints c to current cursor position
void	LCD_PutChar ( unsigned char c );
// returns char at current cursor position
char	LCD_GetChar ( void );

// prints a string beginning with *s
void	LCD_Puts ( char *s );

// sets cursor address to arg addr
void	LCD_SetCursor ( unsigned char addr );

void LCD_update_bpm(unsigned int bpm);
void LCD_update_vel(unsigned int vel);
void LCD_update_current_sound(unsigned int current_sound, unsigned int steps[16]);
void LCD_update_steps(unsigned int steps[16]);
void LCD_update_volume(unsigned int volume);

#endif  // #ifndef LCD_H_
