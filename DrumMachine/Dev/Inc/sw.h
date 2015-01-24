/*
 *  File: Dev/Inc/sw.h
 *  Lab: Final
 *  Alex Eklund
 *  Date: December 2010
 *  Environment Tested: Altera Nios II IDE
 * 
 */

#ifndef SW_H_
#define SW_H_

/*#define store_save_mask 0xf
#define shift_vel 3
#define mask_vel 0x7
#define shift_vel 3
#define mask_vel 0x7*/

union switches
{
    unsigned int word;
    struct
    {
        unsigned int b0 : 1;
        unsigned int b1 : 1;
        unsigned int steps : 16;
    } steps;
    struct
    {
        unsigned int b3_0 : 4;
        unsigned int fill : 10;
        unsigned int b14 : 1;
        unsigned int b15 : 1;
        unsigned int b16 : 1;
        unsigned int b17 : 1;
    } fix;
    struct
    {
        unsigned int fill : 15;
        unsigned int b17_15 : 3;
    } vel_and_sounds;
    struct
    {
        unsigned int fill11_0 : 12;
        unsigned int b17_12 : 6;
    } vol;
    struct
    {
        unsigned int fill9_0 : 10;
        unsigned int b17_10 : 8;
    } bpm;
};

void sw_get(union switches * newsw);

#endif /*SWITCHES_H_*/
