#include "memcpy.h"
#include "audio.h"
#include "song.h"

void main() {
    audio_init();
    //play_song(FIREWORKS.notes, FIREWORKS.size);
    //play_song(HOT_CROSS_BUNS.notes, HOT_CROSS_BUNS.size);
    while (1) {
    	play_song(TWINKLE_TWINKLE.notes, TWINKLE_TWINKLE.size);
    }
    


}
