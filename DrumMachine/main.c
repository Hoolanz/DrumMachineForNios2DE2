/*
 *  File: main.c
 *  Lab: Final
 *  Alex Eklund
 *  Date: December 2010
 *  Environment Tested: Altera Nios II IDE
 * 
 */

#include "Dev/Inc/btn.h"
#include "Dev/Inc/control_interface.h"
#include "Dev/Inc/audio_interface.h"

int main(void)
{
    ci_init(); // ci stands for control_interface. functions that begin with this are in control_interface.c
    ai_init(); // ai stands for audio_interface. functions that begin with this are in audio_interface.c
    unsigned int c_sw;

    while(1)
    {
        c_sw = ci_read_switches();

        if(btn_get_key0())
            ai_play_stop_edge();
        if(btn_get_key1())
            switch (c_sw & 1)
            {
                case 0: ci_edit_steps( sound_to_vel );
                    break;
                case 1: ci_edit_steps( remove_sound );
                    break;
            }
        if( btn_get_key2() )
            switch (c_sw)
            {
                case 0: ci_update_current_sound();
                    break;
                case 1: ci_update_vel();
                    break;
                case 2: ci_update_bpm();
                    break;
                case 3: ci_update_volume();
                    break;
            }
        if( btn_get_key3() )
            switch (c_sw)
            {
                case 0: ci_store_beat();
                    break;
                case 1: ci_load_beat();
                    break;
                case 2: ci_clear_beat();
                    break;
            }
    }
    return 0;
}
