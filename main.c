#include "memcpy.h"
#include "audio.h"
#include "song.h"
#include "sine.h"
#include "turntable.h"
#include "peripherals.h"



void main() {
    audio_init();
    peripherals_init();
    
    turntable_run(SCALE.notes, SCALE.size, HOT_CROSS_BUNS.notes, HOT_CROSS_BUNS.size);
}
