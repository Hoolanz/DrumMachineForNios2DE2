/*
 *  File: Dev/audio_interface.c
 *  Lab: Final
 *  Alex Eklund
 *  Date: December 2010
 *  Environment Tested: Altera Nios II IDE
 * 
 */

#include "Inc/audio_interface.h"
#include "Inc/steps.h"
#include "Inc/timer.h"
#include "Inc/audio.h"
#include "Inc/ledr.h"
#include "Inc/ledg.h"

static unsigned int play;
static unsigned int volume;
static unsigned int ticks_per_step = 125;
static unsigned int tick_count = 0;
static unsigned int step_counter = 0;
static unsigned int sample_counter = 0;

void ai_init(void)
{
    update_ledr( STEP_LED << LEDR17 );
    update_ledg( steps_get_sounds_in_step(0) );
}

void ai_ms_edge(void)
{
    if(play)
    {
        int i;
        for(i = 0; i < samples_in_ms; i++)
        {
            if(sample_counter < end_of_step_buffer)
                audio_write_sample( ai_volume_adjust_samp_amp( steps_get_sample(step_counter, sample_counter++) ) );
            else
                audio_write_sample( silence );
        }
        tick_count++;
        if(tick_count >= ticks_per_step)
        {
            tick_count = 0;
            sample_counter = 0;
            if (step_counter < 15)
                step_counter++;
            else
                step_counter = 0;
            update_ledr( STEP_LED << ( LEDR17 - step_counter ) );
            update_ledg( steps_get_sounds_in_step(step_counter) );
        }
    }
}

void ai_play_stop_edge(void)
{
    play = ~play;
    if (!play)
    {
        tick_count = 0;
        step_counter = 0;
        sample_counter = 0;
        update_ledr( STEP_LED << LEDR17 );
        update_ledg( no_sounds );
    }
    else
    {
        update_ledg( steps_get_sounds_in_step(step_counter) );
    }
}

unsigned int ai_update_ticks_per_step(unsigned int bpm)
{
    ticks_per_step = ticks_per_15_sec / bpm;
    return bpm;
}

short ai_volume_adjust_samp_amp( short sample )
{
    // put sample into int for greater precision and to avoid overflow during processing
    int temp = sample;

    temp = temp * volume; // multiply sample by volume
    
    temp = temp >> unity_shift_divide_num; // divide sample by unity
    
    /* crude limiter --- if sample went outside of range during 
     * processing as int, give it maxor min value of short */
    if (temp < -32768)
        temp = -32768;
    if (temp > 32767)
        temp = 32767;

    return (short)temp; //caste to short and retutn
}

unsigned int ai_volume_change(unsigned int new_vol)
{
    volume = new_vol;
    return volume;
}
