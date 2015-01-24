/*
 *  File: Dev/Inc/audio.h
 *  Lab: Final
 *  Alex Eklund
 *  Date: December 2010
 *  Environment Tested: Altera Nios II IDE
 * 
 */

#ifndef AUDIO_H_
#define AUDIO_H_

void audio_write_sample( short sample );

unsigned int audio_full(void);

void audio_output_samples(void);

#endif /*AUDIO_H_*/
