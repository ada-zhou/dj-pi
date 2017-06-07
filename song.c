//
//  song.c
//  
//
//  Created by Harrison Bronfeld on 6/6/17.
//
//

#include "song.h"
#include "audio.h"
#include "printf.h"


void play_song(notes_t notes[], int size){
    for (int i = 0; i < size; i++){
        audio_send_tone(notes[i], 16);
    }
}


