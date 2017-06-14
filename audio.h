
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

typedef enum {//we have coded in the frequenices of different notes to the hundreths place
    
    B5 = 98777,
    A5s = 93233,
    A5 = 88000,
    G5s = 83061,
    G5 = 78399,
    F5s = 73999,
    F5 = 69846,
    E5 = 65926,
    D5s = 62225,
    D5 = 58733,
    C5s = 55437,
    C5 = 52325,

    B4 = 49388,
    A4s = 46616,
    A4 = 44000,
    G4s = 41530,
    G4 = 39200,
    F4s = 36999,
    F4 = 34923,
    E4 = 32963,
    D4s = 31113,
    D4 = 29366,
    C4s = 27718,
    C4 = 26163,
    
    B3 = 24694,
    A3s = 23308,
    A3 = 22000,
    G3s = 20765,
    G3 = 19600,
    F3s = 18500,
    F3 = 17461,
    E3 = 16481,
    D3s = 15556,
    D3 = 14683,
    C3s = 13859,
    C3 = 13082,
    
    REST = 0,
    
} tones_t;

typedef enum {//we have coded in int constants for different note speeds
    
    WHOLE = 33600,
    HALF = 16800,
    QTR = 8400,
    EIT = 4200,
    SIX = 2100,
    STAC = 40,
    
} times_t;

typedef struct {//a note contains a frequency (tone) and a time (time)
    tones_t tone;
    times_t time;
} notes_t;

void audio_init();
void audio_send_tone(int hz, int volume);
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
