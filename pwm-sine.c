#include "memcpy.h"
#include "audio.h"
#include "song.h"
#include "sine.h"

void main() {
    audio_init();
    //play_song(FIREWORKS.notes, FIREWORKS.size);
    //play_song(HOT_CROSS_BUNS.notes, HOT_CROSS_BUNS.size);
    notes_t G = {G3, QTR};
    //notes_t GG = {G3, QTR};
    audio_send_tone(G, 8);

    //while (1) {
    //    audio_send_tone(G, 8);
    //    audio_send_tone(G, 8);
    //}
    
    /*
    double x = sine(4.6);
    printf("Sine of 4.6: %d\n", (int)(x * 1000));
    x = sine(3.14);
    printf("Sine of 3.14: %d\n", (int)(x * 1000));
    x = sine(1.5);
    printf("Sine of 1.5: %d\n", (int)(x * 1000));
    x = sine(0.2);
    printf("Sine of 0.2: %d\n", (int)(x * 100000));
     */
}
