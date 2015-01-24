/*
 *  File: Dev/control_interface.c
 *  Lab: Final
 *  Alex Eklund
 *  Date: December 2010
 *  Environment Tested: Altera Nios II IDE
 * 
 */


#define control_sw_mask 0x3
#define check_lsb_mask 0x00000001

#include "Inc/sw.h"
#include "LCD/lcd.h"
#include "Inc/steps.h"
#include "Inc/audio_interface.h"

union switches sw;
static unsigned int current_sound = 0;
static unsigned int vel = 3;

// initialize audio buffer, lcd
void ci_init(void)
{
    steps_init();
    LCD_update_volume( ai_volume_change(32) );
    LCD_update_bpm(120);
    LCD_update_vel( vel );
    LCD_update_current_sound( 0, steps_get_step_vels_for_sound( current_sound) );
}

//read switches
unsigned int ci_read_switches(void)
{
    sw_get(&sw);
    return (sw.word & control_sw_mask);
}

// update the volume
void ci_update_volume(void)
{
    LCD_update_volume( ai_volume_change( sw.vol.b17_12 ) );
}

// update the speed
void ci_update_bpm(void)
{
    if(sw.bpm.b17_10) // to avoid divide by zero, ignore request for speed change to 0
    {
        LCD_update_bpm( ai_update_ticks_per_step( sw.bpm.b17_10 ) );
    }
}

//update the velocity at which sounds are edited edited 
void ci_update_vel(void)
{
    vel = sw.vel_and_sounds.b17_15;
    LCD_update_vel( vel );
}

//update which sound is to be edited 
void ci_update_current_sound(void)
{
    current_sound = sw.vel_and_sounds.b17_15;
    LCD_update_current_sound( current_sound, steps_get_step_vels_for_sound( current_sound ) );
}

void ci_edit_steps( unsigned int SW1 )
{
    unsigned int steps_to_edit = sw.steps.steps;
    int t;
    for(t=15; t>=0; t--) //run through steps
    {
        if(steps_to_edit & check_lsb_mask)//check step's switch
        {
            LCD_SetCursor ( t ); //set lcd cursor (no really??)
            if(!SW1) //if switch one is 0
            {
                if( steps_add_sound(t, current_sound, vel) ) // add sound to step
                    LCD_PutChar ( (3 << 4) | vel ); // update lcd
            }
            else // else
            {
                steps_remove_sound(t, current_sound); // remove
                LCD_PutChar ( (3 << 4) | 0 );   // update lcd
            }
        }
        steps_to_edit = steps_to_edit >> 1; // shift switch vals to check next step
    }
}

// stores beat
void ci_store_beat(void)
{
    steps_store(); // stores beat
}

// loads beat
void ci_load_beat(void)
{
    steps_load(); // loads beat
    LCD_update_current_sound( current_sound, steps_get_step_vels_for_sound( current_sound) );
}

//clears beat
void ci_clear_beat(void)
{
    steps_init(); //clears beat
    LCD_update_current_sound( current_sound, steps_get_step_vels_for_sound( current_sound) );
}
