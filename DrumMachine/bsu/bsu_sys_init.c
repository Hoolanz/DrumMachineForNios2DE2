/*
 *  File: BSU/bsu_sys_init.c
 *  Author: Arlen Planting
 *  Date: October 2010
 *  Environment Tested: Altera Nios II IDE
 * 
 *  Module for initializing device drivers
 * 
 * Team 12 Lab Final version
 * December 2010
 * 
 */

#include "system.h"
#include "BSU/bsu.h"

#include "Dev/LCD/lcd.h"
//#include "sysclk.h"
#include "Dev/Inc/timer.h"
//#include "Dev/porta.h"
//#include "Dev/SEG7.h"

void bsu_sys_init( void )
{
    Timer_Init();

    LCD_Init(LCD_16207_0_BASE);
    LCD_Puts("DRUM MACHINE!!!");

    bsu_irq_enable_all(0);
}
