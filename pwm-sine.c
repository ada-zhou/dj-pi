#include "memcpy.h"
#include "audio.h"
#include "song.h"

void main() {
    audio_init();
    play_song(FIREWORKS.notes, FIREWORKS.size);
    //play_song(HOT_CROSS_BUNS.notes, HOT_CROSS_BUNS.size);

}
