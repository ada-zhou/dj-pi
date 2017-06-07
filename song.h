//
//  song.h
//  
//
//  Created by Harrison Bronfeld on 6/6/17.
//
//

#ifndef song_h
#define song_h

#include "audio.h"

typedef struct {
    int size;
    notes_t notes[];
} songs_t;

void play_song(notes_t notes[], int size);

static songs_t HOT_CROSS_BUNS = {17, {{B4, QTR},
    {A4, QTR},
    {G4, HALF},
    {B4, QTR},
    {A4, QTR},
    {G4, HALF},
    {G4, EIT},
    {G4, EIT},
    {G4, EIT},
    {G4, EIT},
    {A4, EIT},
    {A4, EIT},
    {A4, EIT},
    {A4, EIT},
    {B4, QTR},
    {A4, QTR},
    {G4, HALF}}};

static songs_t TWINKLE_TWINKLE = {42, {{C4, QTR},
    {C4, QTR},
    {G4, QTR},
    {G4, QTR},
    {A4, QTR},
    {A4, QTR},
    {G4, HALF},
    {F4, QTR},
    {F4, QTR},
    {E4, QTR},
    {E4, QTR},
    {D4, QTR},
    {D4, QTR},
    {C4, HALF},
    {G4, QTR},
    {G4, QTR},
    {F4, QTR},
    {F4, QTR},
    {E4, QTR},
    {E4, QTR},
    {D4, HALF},
    {G4, QTR},
    {G4, QTR},
    {F4, QTR},
    {F4, QTR},
    {E4, QTR},
    {E4, QTR},
    {D4, HALF},
    {C4, QTR},
    {C4, QTR},
    {G4, QTR},
    {G4, QTR},
    {A4, QTR},
    {A4, QTR},
    {G4, HALF},
    {F4, QTR},
    {F4, QTR},
    {E4, QTR},
    {E4, QTR},
    {D4, QTR},
    {D4, QTR},
    {C4, HALF}}};

//#ABDE
static songs_t FIREWORKS = {100, {{C3, EIT},
    {C3, EIT},
    {E3, EIT},
    {C3, EIT},
    {C3, QTR},
    {REST, QTR},
    {A3, EIT},
    {B3, EIT},
    {B3, EIT},
    {A3, EIT},
    {A3, HALF},
    {A3, EIT},
    {B3, EIT},
    {B3, EIT},
    {A3, EIT},
    {A3, QTR},
    {REST, EIT},
    {A3, EIT},
    {A3, EIT},
    {A3, EIT},
    {B3, EIT},
    {C3, EIT},
    {C3, QTR},
    {REST, QTR},
    {C3, EIT},
    {E4, EIT},
    {E4, EIT},
    {C3, EIT},
    {C3, QTR},
    {REST, QTR},
    {A3, EIT},
    {B3, EIT},
    {B3, EIT},
    {A3, EIT},
    {A3, HALF},
    {A3, EIT},
    {B3, EIT},
    {B3, EIT},
    {A3, EIT},
    {A3, QTR},
    {A3, EIT},
    {A3, EIT},
    {A3, EIT},
    {A3, EIT},
    {B4, EIT},
    {C4, EIT},
    {C4s, EIT},
    {C4, EIT},
    {REST, EIT},
    {E3, EIT},
    {E3, EIT},
    {A3, EIT},
    {A3, EIT},
    {E3, EIT},
    {E3, QTR},
    {REST, EIT},
    {E3, EIT},
    {E3, EIT},
    {E3, EIT},
    {F3, EIT},
    {A3, QTR},
    {A3, QTR},
    {REST, QTR},
    {E3, EIT},
    {A3, EIT},
    {A3, EIT},
    {E3, EIT},
    {E3, EIT},
    {E3, EIT},
    {F3, EIT},
    {E3, EIT},
    {E3, EIT},
    {C3, EIT},
    {F3, EIT},
    {E3, EIT},
    {E3, HALF},
    {C3, EIT},
    {E3, EIT},
    {E3, EIT},
    {C3, EIT},
    {C3, QTR}}}; //17


    
    
    
    

#endif /* song_h */
