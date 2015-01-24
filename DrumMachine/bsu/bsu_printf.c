/*
 *  File: BSU/bsu_printf.c
 *  Author: Arlen Planting
 *  Date: October 2010
 *  Environment Tested: Altera Nios II IDE
 * 
 *  Rudimentary printf for minimalist environment
 */


#include <stdarg.h>
#include "BSU\BSU.h"

void bsu_printf(char *fmt, ...)
{
    va_list ap;
    char *p, *sval;
    int ival;
    unsigned long xval;
    int cval;
    char buff[10];
    
    va_start(ap,fmt);
    
    for(p = fmt; *p; p++)
    {
        if (*p != '%')
        {
            bsu_putchar(*p);
            continue;
        }
        switch (*++p)
        {
            case 'c':
                cval = va_arg(ap, int);
                bsu_putchar((char)cval);
                break;
            case 's':
                sval = va_arg(ap, char *);
                bsu_prints(sval);
                break;
            case 'x':
                xval = va_arg(ap, unsigned long);
                itoh(xval,buff);
                bsu_prints(buff);
                break;
            case 'i':
                ival = va_arg(ap, int);
                itoa(ival,buff);
                bsu_prints(buff);
                break;
            default:
                bsu_putchar(*p);
                break;
        }
    }
    
    va_end(ap);
}
