/*
 *  File: Dev/Inc/audio_interface.h
 *  Lab: Final
 *  Alex Eklund
 *  Date: December 2010
 *  Environment Tested: Altera Nios II IDE
 * 
 */

#ifndef AUDIO_INTERFACE_H_
#define AUDIO_INTERFACE_H_

#define STEP_LED 1
#define LEDR17 17
#define ticks_per_15_sec 15000
#define no_sounds 0
#define end_of_step_buffer 20000
#define silence 0
#define samples_in_ms 96
#define unity 32
#define unity_shift_divide_num 5

//called at beginning of main
void ai_init(void);

//called in main loop
void ai_play_stop_edge(void);

//called in timer isr
void ai_ms_edge(void);

unsigned int ai_update_ticks_per_step(unsigned int bpm);
short ai_volume_adjust_samp_amp( short sample );
unsigned int ai_volume_change(unsigned int new_vol);

#endif /*AUDIO_INTERFACE_H_*/
