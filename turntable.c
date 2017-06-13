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


#define VOLUME 0
#define SPEED_ONE 1
#define SPEED_TWO 2
#define CROSS_FADE 3

#define PLAY_BUTT_ONE GPIO_PIN20
#define PLAY_BUTT_TWO GPIO_PIN21
#define ESC_BUTT GPIO_PIN16

//static int status = 1;



void turntable_run (notes_t track_one[], int size_one, notes_t track_two[], int size_two){
    int track_one_status = 1;
    int track_two_status = 1;
    
    int one_note = 0;
    int two_note = 0;
    
    int one_pos = 0;
    int two_pos = 0;
    
    int one_pressed = 50;
    int two_pressed = 50;
    
    int counter = 0;
    
    int volume = 0;
    int crossfade = 0;
    int speed_one = 0;
    int speed_two = 0;
    
    while (1) {
        
        /*
         if (!gpio_read(ESC_BUTT)) {
         
         }
         */
        
        
        
        if (counter == 100){
            int read = mcp3008_read(VOLUME);
            
            if (read < 171) {
                volume = 1;
            } else if (read < 341) {
                volume = 2;
            } else if (read < 512) {
                volume = 4;
            } else if (read < 683) {
                volume = 8;
            } else if (read < 853) {
                volume = 16;
            } else {
                volume = 32;
            }
            counter = 0;
        }
        
        if (counter == 25){
            if (track_one_status == 0) {
                crossfade = 0;
            } else if (track_two_status == 0) {
                crossfade = 1024;
            } else {
                crossfade = (mcp3008_read(CROSS_FADE));
            }
        }
        
        if (counter == 50){
            int read_speed_one = mcp3008_read(SPEED_ONE);
            if (read_speed_one < 103) {
                speed_one = 1;
            } else if (read_speed_one < 205) {
                speed_one = 2;
            } else if (read_speed_one < 308) {
                speed_one = 3;
            } else if (read_speed_one < 410) {
                speed_one = 4;
            } else if (read_speed_one < 512) {
                speed_one = 5;
            } else if (read_speed_one < 615) {
                speed_one = 6;
            } else if (read_speed_one < 717) {
                speed_one = 7;
            } else if (read_speed_one < 819) {
                speed_one = 8;
            } else if (read_speed_one < 922) {
                speed_one = 9;
            } else {
                speed_one = 10;
            }
        }
        
        if (counter == 75){
            int read_speed_two = mcp3008_read(SPEED_TWO);
            if (read_speed_two < 103) {
                speed_two = 1;
            } else if (read_speed_two < 205) {
                speed_two = 2;
            } else if (read_speed_two < 308) {
                speed_two = 3;
            } else if (read_speed_two < 410) {
                speed_two = 4;
            } else if (read_speed_two < 512) {
                speed_two = 5;
            } else if (read_speed_two < 615) {
                speed_two = 6;
            } else if (read_speed_two < 717) {
                speed_two = 7;
            } else if (read_speed_two < 819) {
                speed_two = 8;
            } else if (read_speed_two < 922) {
                speed_two = 9;
            } else {
                speed_two = 10;
            }
        }
        
        counter ++;
        
        
        
        /**
         if (!gpio_read(PLAY_BUTT_ONE) ) {
         track_one_status = !track_one_status;
         }
         if (!gpio_read(PLAY_BUTT_TWO) ) {
         
         track_two_status = !track_two_status;
         }
         
         
         if (one_pressed < 0){
         if (!gpio_read(PLAY_BUTT_ONE) ) {
         track_one_status = !track_one_status;
         one_pressed = 50;
         }
         } else {
         one_pressed--;
         }
         if (two_pressed < 0) {
         if (!gpio_read(PLAY_BUTT_TWO) ) {
         track_two_status = !track_two_status;
         two_pressed = 50;
         }
         } else {
         two_pressed--;
         }
         
         **/
        
        /*
         printf("Volume: %d ", volume);
         printf("Crossfade: %d ", crossfade);
         printf("Speed One: %d ", speed_one);
         printf("Speed Two: %d ", speed_two);
         printf("Track One: %d ", track_one_status);
         printf("Track Two: %d \n", track_two_status);
         
         
         */
        /**
        volume = 1;
        crossfade = 1024;
        speed_one = 1;
        speed_two = 1;
        track_one_status = 1;
        track_two_status = 1;
        **/
        
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
            play_note += track_two[two_note].tone * (1024 - crossfade);
            two_pos += 1 * speed_two;
            if (two_pos > track_two[two_note].time) {
                two_note++;
                two_note = two_note % size_two;
                two_pos = 0;
            }
        }
        //printf("Note before calling audio: %d\n", play_note);
        audio_send_tone(play_note / 1024, volume);
        
        
        
    }
    
}
