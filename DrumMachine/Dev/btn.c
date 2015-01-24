/*
 *  File: Dev/btn.c
 *  Lab: Final
 *  Alex Eklund
 *  Date: December 2010
 *  Environment Tested: Altera Nios II IDE
 * 
 */

#include "system.h"
#include "Inc/pio_regs.h"

static struct PIO_REGS *btn = (struct PIO_REGS*) (BUTTON_PIO_BASE);  //pointer btn assigned to BUTTON_BASE

union bn{
    unsigned int read;  // to load btn data to
    struct              // bitfield to get specific bit
    {
    unsigned int key0 : 1;
    unsigned int key1 : 1; 
    unsigned int key2 : 1;
    unsigned int key3 : 1;
    } bf;
};

static union bn edgec;
static union bn data;
/*
unsigned int btn_get_key0(void)
{    
    __asm("ldwio %0, %1":"=r"(data.read):"m"(btn->data));          //read data 
    
    data.bf.key0 = data.bf.key0 ^ 1;
    
    return data.bf.key0; 
}

unsigned int btn_get_key1(void)
{    
    __asm("ldwio %0, %1":"=r"(data.read):"m"(btn->data));          //read data 
    
    data.bf.key1 = data.bf.key1 ^ 1;
    
    return data.bf.key1;  
 
}

unsigned int btn_get_key2(void)
{    

    __asm("ldwio %0, %1":"=r"(data.read):"m"(btn->data));          //read data
    
    data.bf.key2 = data.bf.key2 ^ 1;	//invert button data
    
    return data.bf.key2;     //return 1

}

unsigned int btn_get_key3(void)
{    
    __asm("ldwio %0, %1":"=r"(data.read):"m"(btn->data));          //read data 
    
    data.bf.key3 = data.bf.key3 ^ 1;
    
    return data.bf.key3; 

}
*/

unsigned int btn_get_key0(void)
{    
    __asm("ldwio %0, %1":"=r"(edgec.read):"m"(btn->edgecapture));  //read edgecapture
    __asm("ldwio %0, %1":"=r"(data.read):"m"(btn->data));          //read data
    
    data.bf.key0 = data.bf.key0 ^ 1;    //invert button data

    //if edgecapture was set on rising edge
    if(edgec.bf.key0 && data.bf.key0)
    {   
        __asm("stwio %0, %1"::"r"(0), "m"(btn->edgecapture));   //clear edgecapture
        return data.bf.key0;     //return 1
    }

    return 0;  
}

unsigned int btn_get_key1(void)
{    
    __asm("ldwio %0, %1":"=r"(edgec.read):"m"(btn->edgecapture));  //read edgecapture
    __asm("ldwio %0, %1":"=r"(data.read):"m"(btn->data));          //read data
    
    data.bf.key1 = data.bf.key1 ^ 1;    //invert button data

    //if edgecapture was set on rising edge
    if(edgec.bf.key1 && data.bf.key1)
    {   
        __asm("stwio %0, %1"::"r"(0), "m"(btn->edgecapture));   //clear edgecapture
        return data.bf.key1;     //return 1
    }

    return 0;  
}

unsigned int btn_get_key2(void)
{    
    __asm("ldwio %0, %1":"=r"(edgec.read):"m"(btn->edgecapture));  //read edgecapture
    __asm("ldwio %0, %1":"=r"(data.read):"m"(btn->data));          //read data
    
    data.bf.key2 = data.bf.key2 ^ 1;    //invert button data

    //if edgecapture was set on rising edge
    if(edgec.bf.key2 && data.bf.key2)
    {   
        __asm("stwio %0, %1"::"r"(0), "m"(btn->edgecapture));   //clear edgecapture
        return data.bf.key2;     //return 1
    }

    return 0;  
}

unsigned int btn_get_key3(void)
{    
    __asm("ldwio %0, %1":"=r"(edgec.read):"m"(btn->edgecapture));  //read edgecapture
    __asm("ldwio %0, %1":"=r"(data.read):"m"(btn->data));          //read data
    
    data.bf.key3 = data.bf.key3 ^ 1;    //invert button data

    //if edgecapture was set on rising edge
    if(edgec.bf.key3 && data.bf.key3)
    {   
        __asm("stwio %0, %1"::"r"(0), "m"(btn->edgecapture));   //clear edgecapture
        return data.bf.key3;     //return 1
    }

    return 0;  
}
