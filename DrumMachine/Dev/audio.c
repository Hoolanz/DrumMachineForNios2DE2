/*
 *  File: Dev/audio.c
 *  Lab: Final
 *  Alex Eklund
 *  Date: December 2010
 *  Environment Tested: Altera Nios II IDE
 * 
 */

#include "system.h"

void * audio = (void *) AUDIO_0_BASE;

void audio_write_sample( short sample )
{
    __builtin_stwio (audio, sample);
}
