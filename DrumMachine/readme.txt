/*
 *  File: readme.txt
 *  Lab: Final
 *  Alex Eklund
 *  Date: December 2010
 *  Environment Tested: Altera Nios II IDE
 * 
 */
 
 The folders/files you need to drop in are:
 /bsu
 /Dev
 /Drum_sounds
 main.c
 
 All functions begin with the name of the file they are in except:
	control_interface functions begin with ci_
	audio_interface functions begin with ai_ 


INSTRUCTIONS	
	
You make a beat by choosing a sound to edit:
Sound numbers
0 Kick
1 snare
2 Clap
3 Robo1
4 Robo2
5 open hihat
6 Closed hihat
7 Cowbell
Use switches 17-15 to pick the sound,
and then set switches 1-0 to 0 and press KEY2.

Then you choose which steps to add that sound to 
with switches 17 thru 2.
After doing this, set switch 0 to 0 and press KEY1

Here is a full list of the commands:

KEY0 - Play/Stop

KEY1 -  
	SW1 == 0 - add current sound to steps indicated by SW17_SWSW2
    SW1 == 1 - remove current sound from steps indicated by SW17_SWSW2

KEY2 -  
	SW1_SW0 == 0 - update current_sound to SW17_SW15
    SW1_SW0 == 1 - update vel to SW17_SW15
    SW1_SW0 == 2 - update speed to SW17_SW10
    SW1_SW0 == 3 - update volume to SW17_SW12


KEY3 -  
	SW1_SW0 == 0 - store_beat
    SW1_SW0 == 1 - load_beat
    SW1_SW0 == 2 - clear_beat


Here is what the numbers on the lcd mean:
LCD map
__________________
|0000000000000000|
|44   333   2   1|
------------------
0  --- 0 to 7 for each digit --- Current velocity of step (left most
digit is first step
1  --- 0 to 7    --- current sound to edit
2  --- 0 to 7    --- current velocity to edit to
3  --- 0 to 63   --- Volume
4  --- 0 to 255  --- speed in beats per minute