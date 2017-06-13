#include "memcpy.h"
#include "audio.h"
#include "song.h"
#include "sine.h"

void main() {
    audio_init();
    
    /*
     printf("Rounded 4.84: %d\n", round_int(4.84));
     printf("Rounded 4.50: %d\n", round_int(4.50));
     printf("Rounded 4.02: %d\n", round_int(4.02));
     printf("Rounded 4.500001: %d\n", round_int(4.500001));
     printf("Rounded 11.84: %d\n", round_int(11.84));
     printf("Rounded 100.50: %d\n", round_int(100.50));
     printf("Rounded 2.02: %d\n", round_int(2.02));
     */
    
    //play_song(TWINKLE_TWINKLE.notes, TWINKLE_TWINKLE.size);
    //play_song(HOT_CROSS_BUNS.notes, HOT_CROSS_BUNS.size);
    notes_t C = {C4, QTR};
    notes_t E = {E4, QTR};
    notes_t G = {G4, QTR};
    notes_t CEG = {32775, WHOLE};
    /**
     for (int i = 0; i < 1025; i ++){
     double val = 64.0 * sine( (double)i * 6.28318530718 / 1024.0) + 64.0;
     printf("%d,\n", (int)(val));
     }
     **/
    while(1){
        audio_send_tone(C, 8);
        audio_send_tone(E, 8);
        audio_send_tone(G, 8);
        audio_send_tone(CEG, 8);
    }
    
    
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
