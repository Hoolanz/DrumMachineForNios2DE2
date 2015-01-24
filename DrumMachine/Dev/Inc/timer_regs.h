/*
 *  File: Dev/Inc/timer_regs.h
 *  Author: Arlen Planting
 *  Date: October 2010
 *  Environment Tested: Altera Nios II IDE
 * 
 *  Register definitions for timer devices
 */


#ifndef TIMER_REGS_H_
#define TIMER_REGS_H_

#include "bsu/types.h"

union TIMER_STATUS_REG {
    REGISTER data;
    struct {
        BITS TO     : 1;
        BITS RUN    : 1;
        BITS unused : 30;
    } bits;
};

union TIMER_CONTROL_REG {
    REGISTER data;
    struct {
        BITS ITO    : 1;
        BITS CONT   : 1;
        BITS START  : 1;
        BITS STOP   : 1;
        BITS unused : 28;
    } bits;
};

struct TIMER_REGS {
    REGISTER status;
    REGISTER control;
    REGISTER periodl;
    REGISTER periodh;
    REGISTER snapl;
    REGISTER snaph;
};


#endif /*TIMER_REGS_H_*/
