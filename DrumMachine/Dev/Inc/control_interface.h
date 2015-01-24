/*
 *  File: Dev/Inc/control_interface.h
 *  Lab: Final
 *  Alex Eklund
 *  Date: December 2010
 *  Environment Tested: Altera Nios II IDE
 * 
 */

#ifndef CONTROL_INTERFACE_H_
#define CONTROL_INTERFACE_H_

#define sound_to_vel 0
#define remove_sound 1

unsigned int ci_read_switches(void);

void ci_update_volume(void);

void ci_update_bpm(void);

void ci_update_vel(void);

void ci_update_current_sound(void);

void ci_init(void);

void ci_edit_steps( unsigned int SW1 );

void ci_store_beat(void);
void ci_load_beat(void);
void ci_clear_beat(void);

#endif /*CONTROL_INTERFACE_H_*/
