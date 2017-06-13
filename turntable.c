//
//  turntable.c
//  
//
//  Created by Cui  Zhou on 6/13/17.
//
//

#include "turntable.h"
#include "audio.h"
#include "peripherals.h"
#include "song.h"
#include "gpio.h"



#define SPEED_ONE 1
#define SPEED_TWO 2

#define PLAY_PAUSE_ONE 0
#define PLAY_PAUSE_TWO 0





void turntable_run (notes_t track_one[], int size_one, notes_t track_two[], int size_two){
    int track_one_status = 0;
    int track_two_status = 0;
    
    int one_note = 0;
    int two_note = 0;
    
    int one_pos = 0;
    int two_pos = 0;
    
    while (1) {
        /*
        int volume = getVolume();
        int crossfade = getFade();
        int speed_one = getSpeed(SPEED_ONE);
        int speed_two = getSpeed(SPEED_TWO);
        track_one_status = getButtonState(PLAY_PAUSE_ONE);
        track_two_status = getButtonState(PLAY_PAUSE_TWO);
         */
        
        int volume = 1;
        int crossfade = 0;
        int speed_one = 5;
        int speed_two = 5;
        track_one_status = 1;
        track_two_status = 1;
        
        int play_note = 0;
        
        if (track_one_status){
            //printf("Note from track: %d\n", track_one[4].tone);
            play_note = track_one[one_note].tone * crossfade;
            one_pos += 1 * speed_one;
            if (one_pos > track_one[one_note].time) {
                one_note++;
                one_note = one_note % size_one;
                one_pos = 0;
            }
        }
        if (track_two_status){
            //printf("Note from track: %d\n", track_one[4].tone);
            play_note += track_two[two_note].tone * (100 - crossfade);
            two_pos += 1 * speed_two;
            if (two_pos > track_two[two_note].time) {
                two_note++;
                two_note = two_note % size_two;
                two_pos = 0;
            }
        }
        //printf("Note before calling audio: %d\n", play_note);
        audio_send_tone(play_note / 100, volume);
        
    }
}
