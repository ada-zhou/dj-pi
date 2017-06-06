#include "audio.h"

void main() {
  audio_init();
  notes_t GQTR = {G, QTR};
  notes_t BQTR = {B, QTR};
  notes_t AQTR = {A, QTR};
  notes_t GHALF = {G, HALF};
  notes_t BHALF = {B, HALF};
  notes_t AHALF = {A, HALF};
  notes_t GEIT = {G, EIT};
  notes_t BEIT = {B, EIT};
  notes_t AEIT = {A, EIT};

  


  audio_send_tone(WAVE_SINE, BQTR);
  audio_send_tone(WAVE_SINE, AQTR);
  audio_send_tone(WAVE_SINE, GHALF);

  audio_send_tone(WAVE_SINE, BQTR);
  audio_send_tone(WAVE_SINE, AQTR);
  audio_send_tone(WAVE_SINE, GHALF);

  audio_send_tone(WAVE_SINE, GEIT);
  audio_send_tone(WAVE_SINE, GEIT);
  audio_send_tone(WAVE_SINE, GEIT);
  audio_send_tone(WAVE_SINE, GEIT);

  audio_send_tone(WAVE_SINE, AEIT);
  audio_send_tone(WAVE_SINE, AEIT);
  audio_send_tone(WAVE_SINE, AEIT);
  audio_send_tone(WAVE_SINE, AEIT);
  
  audio_send_tone(WAVE_SINE, BQTR);
  audio_send_tone(WAVE_SINE, AQTR);
  audio_send_tone(WAVE_SINE, GHALF);
}
