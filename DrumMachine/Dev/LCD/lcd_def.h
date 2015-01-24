/*
 *  File: Dev/LCD/lcd_def.h
 *  Lab: Final
 *  Alex Eklund
 *  Date: December 2010
 *  Environment Tested: Altera Nios II IDE
 * 
 */

#ifndef LCD_DEF_H_
#define LCD_DEF_H_

#define LCD_VERSION "LCD Driver F2010 Team 12 v0.1"

/* Commands which can be written to the COMMAND register */

#define LCD_CMD_CLR             0x01
#define LCD_CMD_HOME            0x02
#define LCD_CMD_MODE            0x04
#define LCD_CMD_CONTROL         0x08
#define LCD_CMD_SHIFT           0x10
#define LCD_CMD_FUNC_SET        0x20
#define LCD_CMD_CGADDR          0x40
#define LCD_CMD_DDADDR          0x80

//  Function Set options
#define LCD_OPT_FUNC_8BIT       0x10
#define LCD_OPT_FUNC_TWO_LINE   0x08
#define LCD_OPT_FUNC_BIGFONT    0x04

//  options MODE
#define LCD_OPT_MODE_INC        0x02
#define LCD_OPT_MODE_SHIFT      0x01

//  Control options
#define LCD_OPT_CONTROL_DISP    0x04
#define LCD_OPT_CONTROL_CURSOR  0x02
#define LCD_OPT_CONTROL_BLINK   0x01

// options SHIFT
#define LCD_OPT_CURSOR_LEFT     0x00
#define LCD_OPT_CURSOR_RIGHT    0x04
#define LCD_OPT_SHIFT_LEFT      0x08
#define LCD_OPT_SHIFT_RIGHT     0x0c

#define LCD_BUSY		        0x80
#define LCD_LINE1               0x00
#define LCD_LINE2               0x40

#endif /*LCD_DEF_H_*/
