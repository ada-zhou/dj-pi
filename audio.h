
#ifndef AUDIO_H_INCLUDED
#define AUDIO_H_INCLUDED

/* Hardware abstraction functions for bare metal pulse-width
 * modulation (PWM) audio on the Raspberry Pi.
 *
 * NOTE: To use this library, you must first call timer_init().
 * Audio initialization requires timers for busy waiting.
 *
 * Author: Philip Levis <pal@cs.stanford.edu>
 * Date: September 10 2014
 */

typedef enum {
    WAVE_SQUARE,
    WAVE_SINE,
    WAVE_SAW,
    WAVE_TRIANGLE
} wave_type_t;

typedef enum {
    
    B5 = 988,
    A5s = 932,
    A5 = 880,
    G5s = 831,
    G5 = 784,
    F5s = 698,
    F5 = 698,
    E5 = 659,
    D5s = 587,
    D5 = 587,
    C5s = 554,
    C5 = 523,

    B4 = 494,
    A4s = 466,
    A4 = 440,
    G4s = 415,
    G4 = 392,
    F4s = 370,
    F4 = 349,
    E4 = 330,
    D4s = 311,
    D4 = 294,
    C4s = 277,
    C4 = 262,
    
    B3 = 247,
    A3s = 233,
    A3 = 220,
    G3s = 208,
    G3 = 196,
    F3s = 185,
    F3 = 175,
    E3 = 165,
    D3s = 156,
    D3 = 147,
    C3s = 139,
    C3 = 262,//131,
    
    REST = 0,
    
} tones_t;

typedef enum {
    
    WHOLE = 4000000 * 5,
    HALF = 2000000 * 5,
    QTR = 1000000 * 5,
    EIT = 500000 * 5,
    
    /*
    WHOLE = 40000,
    HALF = 20000,
    QTR = 10000,
    EIT = 5000,
    */
    
} times_t;

typedef struct {
    tones_t tone;
    times_t time;
} notes_t;

void audio_init();
void audio_send_1kHz();
void audio_send_tone(wave_type_t type, unsigned int hz);
unsigned int audio_max_tone_hz();
unsigned int audio_min_tone_hz();

#endif

/*
 * Copyright (c) 2014 Stanford University.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the
 *   distribution.
 * - Neither the name of the Stanford University nor the names of
 *   its contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL STANFORD
 * UNIVERSITY OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */
