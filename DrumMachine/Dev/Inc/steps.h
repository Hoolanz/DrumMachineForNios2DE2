/*
 *  File: Dev/Inc/steps.h
 *  Lab: Final
 *  Alex Eklund
 *  Date: December 2010
 *  Environment Tested: Altera Nios II IDE
 * 
 */

#ifndef STEP_H_
#define STEP_H_

struct STEPS
{
    short buffer[16][20000];
    unsigned int sounds[16][8];
};

void steps_init(void);
unsigned int steps_add_sound( unsigned int step, unsigned int current_sound, unsigned int vel );
unsigned int steps_check_samp(unsigned int step);
void steps_amplitude_overflow( unsigned int step, int fail_point, unsigned int current_sound, unsigned int vel );
unsigned int steps_update_current_sound(unsigned int new_current_sound);

unsigned int steps_update_vel(unsigned int new_vel);
unsigned int steps_current_step_sounds(unsigned int step);
void steps_remove_sound(int step, unsigned int current_sound);
unsigned int steps_get_current_sound(void);
void steps_edit_steps(unsigned int steps_to_edit, unsigned int SW1, unsigned int current_sound, unsigned int vel );
unsigned int * steps_get_step_vels_for_sound(int sound);
unsigned int steps_get_sounds_in_step(int step);
short steps_get_sample(int step, int sample);

void steps_store(void);

void steps_load(void);

int steps_shift_divide_by_eight(int temp);

#endif /*STEP_H_*/
