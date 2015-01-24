/*
 *  File: Dev/steps.c
 *  Lab: Final
 *  Alex Eklund
 *  Date: December 2010
 *  Environment Tested: Altera Nios II IDE
 * 
 */

#include "Inc/steps.h"
#include "Drum_sounds/drum_sounds.h"

struct STEPS steps;
struct STEPS store;

void steps_init(void)
{
    int t, r, i;
    for(t=0; t<16; t++)
    {
        for(r = 0; r < 20000; r++)
            steps.buffer[t][r] = 0;
        for(i = 0; i < 8; i++) 
            steps.sounds[t][i] = 0;
    }
}

unsigned int steps_add_sound( unsigned int step, unsigned int current_sound, unsigned int vel )
{
    int sample, oldsample, t;
    if (steps.sounds[step][current_sound] == vel) return 0;
    for(t = 0; (t < drum_sounds_length(current_sound) && t < 20000); t++)
    {
        sample = (int) drum_sounds_get_sample(current_sound, t);
        if( steps.sounds[step][current_sound] )
        {
            oldsample = sample * steps.sounds[step][current_sound];
            oldsample = steps_shift_divide_by_eight(oldsample);
            steps.buffer[step][t] -= (short) oldsample;
        }
        sample = sample * vel;
        sample = steps_shift_divide_by_eight(sample);
        if( ( ( steps.buffer[step][t] + sample ) <= 32767 ) && ( ( steps.buffer[step][t] + sample ) >= -32768 ) )
            steps.buffer[step][t] += (short) sample;
        else // overflow case
        {
            steps.buffer[step][t] += (short) oldsample;
            steps_amplitude_overflow(step, t, current_sound, vel);
            return 0;
        }
    }
    steps.sounds[step][current_sound] = vel;
    return 1;
}

void steps_amplitude_overflow( unsigned int step, int fail_point, unsigned int current_sound, unsigned int vel )
{
    int sample, oldsample, t;
    for(t = 0; t < fail_point; t++)
    {
        sample = (int) drum_sounds_get_sample(current_sound, t);
        oldsample = sample * steps.sounds[step][current_sound];
        oldsample = steps_shift_divide_by_eight(oldsample);
        sample = steps_shift_divide_by_eight(sample * vel);
        steps.buffer[step][t] -= (short)(sample);
        steps.buffer[step][t] += (short)(oldsample);
    }
}

void steps_remove_sound(int step, unsigned int current_sound)
{
    int oldsample, t;
    if (steps.sounds[step][current_sound] == 0) return;
    for(t = 0; (t < drum_sounds_length(current_sound) && t < 20000); t++)
    {
        oldsample = (int) drum_sounds_get_sample(current_sound, t);
        oldsample = oldsample * steps.sounds[step][current_sound];
        oldsample = steps_shift_divide_by_eight(oldsample);
        steps.buffer[step][t] -= (signed short)oldsample;
    }
    steps.sounds[step][current_sound] = 0;
}

unsigned int s[16];
unsigned int * steps_get_step_vels_for_sound(int sound)
{
    int i;
    for(i = 0; i < 16; i++)
        s[i] = steps.sounds[i][sound];
    return s;
}

unsigned int steps_get_sounds_in_step(int step)
{
    unsigned int sounds = 0;
    int i;
    for(i = 0; i < 8; i++)
        if (steps.sounds[step][i])
            sounds = sounds | (1 << i);
    return sounds;
}

short steps_get_sample(int step_counter, int sample_counter)
{
    return steps.buffer[step_counter][sample_counter];
}

void steps_store(void)
{
    store = steps;
}

void steps_load(void)
{
    steps = store;
}

int steps_shift_divide_by_eight(int temp)
{
    if(temp < 0) // if sample is negative
    {
        temp = (~temp) + 1;
        temp = temp >> 3;
        temp = (~temp) + 1;
    }
        else
            temp = temp >> 3;
    return temp;
}
