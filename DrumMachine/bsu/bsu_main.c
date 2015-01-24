/*
 *  File: BSU/bsu_main.c
 *  Author: Arlen Planting
 *  Date: October 2010
 *  Environment Tested: Altera Nios II IDE
 * 
 * This module is called from crt0.S (supplied by Altera)
 * The entry point is alt_main and is reduced to minimal components
 * for educational purposes
 */
 
#include <string.h>
#include <stdlib.h>
#include "BSU/bsu.h"
#include "system.h"

void bsu_sys_init( void );
extern int main (int, char **, char **);

int    alt_argc = 0;
char** alt_argv = {NULL};
char** alt_envp = {NULL};

unsigned int JTAG_UART_ADDR = ALT_STDOUT_BASE;

void alt_main (void)
{
    bsu_sys_init();

    exit (main (alt_argc, alt_argv, alt_envp));
}

