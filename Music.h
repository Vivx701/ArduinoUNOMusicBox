#ifndef MUSIC_H
#define MUSIC_H

#include <stddef.h> // For size_t
#include <stdint.h> // For standard integer types
#include "Buzzer.h" // Ensure the Buzzer library is included

// Define the structure for a Tone
typedef struct {
  int note;      // Musical note frequency
  int duration;  // Duration in milliseconds
} Tone;

// Define the structure for MusicNotes
typedef struct {
  const Tone *tones; // Pointer to an array of Tones
  size_t size;       // Number of tones in the array
  int begin;         // Delay before starting playback
  int end;           // Delay after finishing playback
} MusicNotes;



const Tone STARTUP_MUSIC[] = {
  {NOTE_E5, 200}, {NOTE_D5, 200}, {NOTE_B4, 200}, {NOTE_G4, 200}, {NOTE_E4, 400}
};

const MusicNotes STARTUP_MUSIC_NOTES = {
  STARTUP_MUSIC,
  sizeof(STARTUP_MUSIC) / sizeof(Tone),
  10, // Begin delay
  300  // End delay
};

const Tone HAPPY_BIRTHDAY[] = {
  {NOTE_C4, 500}, {NOTE_C4, 500}, {NOTE_D4, 1000}, {NOTE_C4, 1000}, {NOTE_F4, 1000}, {NOTE_E4, 2000},
  {NOTE_C4, 500}, {NOTE_C4, 500}, {NOTE_D4, 1000}, {NOTE_C4, 1000}, {NOTE_G4, 1000}, {NOTE_F4, 2000},
  {NOTE_C4, 500}, {NOTE_C4, 500}, {NOTE_C5, 1000}, {NOTE_A4, 1000}, {NOTE_F4, 1000}, {NOTE_E4, 1000}, {NOTE_D4, 1000},
  {NOTE_AS4, 500}, {NOTE_AS4, 500}, {NOTE_A4, 1000}, {NOTE_F4, 1000}, {NOTE_G4, 1000}, {NOTE_F4, 2000}
};

const MusicNotes HAPPY_BIRTHDAY_NOTES = {
  HAPPY_BIRTHDAY,
  sizeof(HAPPY_BIRTHDAY) / sizeof(Tone),
  0, 
  500  // End delay
};

const Tone TWINKLE_TWINKLE[] = {
  {NOTE_C4, 500}, {NOTE_C4, 500}, {NOTE_G4, 500}, {NOTE_G4, 500}, {NOTE_A4, 500}, {NOTE_A4, 500}, {NOTE_G4, 1000},
  {NOTE_F4, 500}, {NOTE_F4, 500}, {NOTE_E4, 500}, {NOTE_E4, 500}, {NOTE_D4, 500}, {NOTE_D4, 500}, {NOTE_C4, 1000},
  {NOTE_G4, 500}, {NOTE_G4, 500}, {NOTE_F4, 500}, {NOTE_F4, 500}, {NOTE_E4, 500}, {NOTE_E4, 500}, {NOTE_D4, 1000},
  {NOTE_G4, 500}, {NOTE_G4, 500}, {NOTE_F4, 500}, {NOTE_F4, 500}, {NOTE_E4, 500}, {NOTE_E4, 500}, {NOTE_C4, 1000}
};

const MusicNotes TWINKLE_TWINKLE_NOTES = {
  TWINKLE_TWINKLE,
  sizeof(TWINKLE_TWINKLE) / sizeof(Tone),
  10, // Begin delay
  500  // End delay
};

const Tone STAR_WARS[] = {
  {NOTE_A4, 500}, {NOTE_A4, 500}, {NOTE_A4, 500}, {NOTE_F4, 350}, {NOTE_C5, 150},
  {NOTE_A4, 500}, {NOTE_F4, 350}, {NOTE_C5, 150}, {NOTE_A4, 1000},
  {NOTE_E5, 500}, {NOTE_E5, 500}, {NOTE_E5, 500}, {NOTE_F5, 350}, {NOTE_C5, 150},
  {NOTE_GS4, 500}, {NOTE_F4, 350}, {NOTE_C5, 150}, {NOTE_A4, 1000}
};

const MusicNotes STAR_WARS_NOTES = {
  STAR_WARS,
  sizeof(STAR_WARS) / sizeof(Tone),
  1, // Begin delay
  700  // End delay
};

const Tone ODE_TO_JOY[] = {
  {NOTE_E4, 500}, {NOTE_E4, 500}, {NOTE_F4, 500}, {NOTE_G4, 500},
  {NOTE_G4, 500}, {NOTE_F4, 500}, {NOTE_E4, 500}, {NOTE_D4, 500},
  {NOTE_C4, 500}, {NOTE_C4, 500}, {NOTE_D4, 500}, {NOTE_E4, 500},
  {NOTE_E4, 750}, {NOTE_D4, 250}, {NOTE_D4, 1000},
  {NOTE_E4, 500}, {NOTE_E4, 500}, {NOTE_F4, 500}, {NOTE_G4, 500},
  {NOTE_G4, 500}, {NOTE_F4, 500}, {NOTE_E4, 500}, {NOTE_D4, 500},
  {NOTE_C4, 500}, {NOTE_C4, 500}, {NOTE_D4, 500}, {NOTE_E4, 500},
  {NOTE_D4, 750}, {NOTE_C4, 250}, {NOTE_C4, 1000}
};

const MusicNotes ODE_TO_JOY_NOTES = {
  ODE_TO_JOY,
  sizeof(ODE_TO_JOY) / sizeof(Tone),
  2, // Begin delay
  500  // End delay
};


const Tone GAME_OF_THRONES_THEME[] = {
  {NOTE_G4, 500}, {NOTE_C5, 500}, {NOTE_DS5, 200}, {NOTE_F5, 200}, {NOTE_G5, 500},
  {NOTE_C5, 500}, {NOTE_DS5, 200}, {NOTE_F5, 200}, {NOTE_G5, 500},
  {NOTE_C5, 300}, {NOTE_DS5, 300}, {NOTE_F5, 300}, {NOTE_D5, 300}, {NOTE_G4, 500},
  {NOTE_C5, 500}, {NOTE_DS5, 500}, {NOTE_F5, 500}, {NOTE_G5, 500}
};

const MusicNotes GAME_OF_THRONES_NOTES = {
  GAME_OF_THRONES_THEME,
  sizeof(GAME_OF_THRONES_THEME) / sizeof(Tone),
  0, // Begin delay
  700  // End delay
};


const Tone TETRIS_THEME[] = {
  {NOTE_E4, 400}, {NOTE_B3, 200}, {NOTE_C4, 200}, {NOTE_D4, 400},
  {NOTE_C4, 200}, {NOTE_B3, 200}, {NOTE_A3, 400}, {NOTE_A3, 200},
  {NOTE_C4, 200}, {NOTE_E4, 400}, {NOTE_D4, 200}, {NOTE_C4, 200},
  {NOTE_B3, 600}, {NOTE_C4, 200}, {NOTE_D4, 400}, {NOTE_E4, 400},
  {NOTE_C4, 400}, {NOTE_A3, 400}, {NOTE_A3, 400}, {NOTE_A3, 400}
};

const MusicNotes TETRIS_THEME_NOTES = {
  TETRIS_THEME,
  sizeof(TETRIS_THEME) / sizeof(Tone),
  10, // Begin delay
  500  // End delay
};

// Define the JINGLE_BELLS melody as a basic array
const Tone JINGLE_BELLS[] = {
  {NOTE_G3, 500 / 2}, {NOTE_E4, 500 / 2}, {NOTE_D4, 500 / 2}, {NOTE_C4, 500 / 2}, {NOTE_G3, 500 * 2},
  {NOTE_G3, 500 / 2}, {NOTE_E4, 500 / 2}, {NOTE_D4, 500 / 2}, {NOTE_C4, 500 / 2}, {NOTE_A4, 500 * 2},
  {NOTE_A4, 500 / 2}, {NOTE_F4, 500 / 2}, {NOTE_E4, 500 / 2}, {NOTE_D4, 500 / 2}, {NOTE_G4, 500},
  {NOTE_G4, 500}, {NOTE_A5, 500 / 2}, {NOTE_G4, 500 / 2}, {NOTE_F4, 500 / 2}, {NOTE_D4, 500 / 2},
  {NOTE_E4, 500 * 2}, {NOTE_G3, 500 / 2}, {NOTE_E4, 500 / 2}, {NOTE_D4, 500 / 2}, {NOTE_C4, 500 / 2},
  {NOTE_G3, 500 * 2}, {NOTE_G3, 500 / 2}, {NOTE_E4, 500 / 2}, {NOTE_D4, 500 / 2}, {NOTE_C4, 500 / 2},
  {NOTE_A4, 500 * 2}, {NOTE_A4, 500 / 2}, {NOTE_F4, 500 / 2}, {NOTE_E4, 500 / 2}, {NOTE_D4, 500 / 2},
  {NOTE_G4, 500 / 2}, {NOTE_G4, 500 / 2}, {NOTE_G4, (500 * 3) / 4}, {NOTE_G4, 500 / 4}, {NOTE_A5, 500 / 2},
  {NOTE_G4, 500 / 2}, {NOTE_F4, 500 / 2}, {NOTE_D4, 500 / 2}, {NOTE_C4, 500 * 2}, {NOTE_E4, 500 / 2},
  {NOTE_E4, 500 / 2}, {NOTE_E4, 500}, {NOTE_E4, 500 / 2}, {NOTE_E4, 500 / 2}, {NOTE_E4, 500},
  {NOTE_E4, 500 / 2}, {NOTE_G4, 500 / 2}, {NOTE_C4, 500 / 2}, {NOTE_D4, 500 / 2}, {NOTE_E4, 500 * 2},
  {NOTE_F4, 500 / 2}, {NOTE_F4, 500 / 2}, {NOTE_F4, 500 / 2}, {NOTE_F4, 500 / 2}, {NOTE_F4, 500 / 2},
  {NOTE_E4, 500 / 2}, {NOTE_E4, 500 / 2}, {NOTE_E4, 500 / 4}, {NOTE_E4, 500 / 4}, {NOTE_E4, 500 / 2},
  {NOTE_D4, 500 / 2}, {NOTE_D4, 500 / 2}, {NOTE_E4, 500 / 2}, {NOTE_D4, 500}, {NOTE_G4, 500},
  {NOTE_E4, 500 / 2}, {NOTE_E4, 500 / 2}, {NOTE_E4, 500}, {NOTE_E4, 500 / 2}, {NOTE_E4, 500 / 2},
  {NOTE_E4, 500}, {NOTE_E4, 500 / 2}, {NOTE_G4, 500 / 2}, {NOTE_C4, 500 / 2}, {NOTE_D4, 500 / 2},
  {NOTE_E4, 500 * 2}, {NOTE_F4, 500 / 2}, {NOTE_F4, 500 / 2}, {NOTE_F4, 500 / 2}, {NOTE_F4, 500 / 2},
  {NOTE_F4, 500 / 2}, {NOTE_E4, 500 / 2}, {NOTE_E4, 500 / 2}, {NOTE_E4, 500 / 4}, {NOTE_E4, 500 / 4},
  {NOTE_G4, 500 / 2}, {NOTE_G4, 500 / 2}, {NOTE_F4, 500 / 2}, {NOTE_D4, 500 / 2}, {NOTE_C4, 500 * 2}
};

// Define a MusicNotes object for JINGLE_BELLS
const MusicNotes JINGLE_BELLS_NOTES = {
  JINGLE_BELLS,                       // Pointer to the array of tones
  sizeof(JINGLE_BELLS) / sizeof(Tone), // Size of the array
  10,                               // Delay before starting playback
  2000                                // Delay after finishing playback
};

const Tone CONTRA_THEME[] = {
  {NOTE_E4, 300}, {NOTE_G4, 300}, {NOTE_C4, 300}, {NOTE_E4, 300},
  {NOTE_G4, 300}, {NOTE_C4, 300}, {NOTE_E4, 150}, {NOTE_F4, 150}, {NOTE_E4, 150},
  {NOTE_D4, 300}, {NOTE_E4, 300}, {NOTE_F4, 300}, {NOTE_E4, 300}, {NOTE_G4, 300},
  {NOTE_C5, 300}, {NOTE_B4, 300}, {NOTE_A4, 300}, {NOTE_G4, 300},
  {NOTE_F4, 150}, {NOTE_E4, 150}, {NOTE_F4, 150}, {NOTE_G4, 150},
  {NOTE_E4, 300}, {NOTE_G4, 300}, {NOTE_C4, 300}, {NOTE_E4, 300},
  {NOTE_G4, 300}, {NOTE_C4, 300}, {NOTE_E4, 150}, {NOTE_F4, 150}, {NOTE_E4, 150},
  {NOTE_D4, 300}, {NOTE_E4, 300}, {NOTE_F4, 300}, {NOTE_E4, 300}, {NOTE_G4, 300},
  {NOTE_C5, 300}, {NOTE_B4, 300}, {NOTE_A4, 300}, {NOTE_G4, 300}
};

const MusicNotes CONTRA_THEME_NOTES = {
  CONTRA_THEME,
  sizeof(CONTRA_THEME) / sizeof(Tone),
  2, // Begin delay
  500  // End delay
};

const Tone SUPER_MARIO[] = {
  {NOTE_E4, 125}, {NOTE_E4, 125}, {0, 125}, {NOTE_E4, 125}, {0, 125},
  {NOTE_C4, 125}, {NOTE_E4, 125}, {NOTE_G4, 250}, {0, 250}, {NOTE_G3, 250}, {0, 250},
  {NOTE_C4, 125}, {0, 125}, {NOTE_G3, 125}, {0, 125}, {NOTE_E3, 125}, {0, 125},
  {NOTE_A3, 125}, {NOTE_B3, 125}, {NOTE_AS3, 125}, {NOTE_A3, 125}, {NOTE_G3, 125},
  {NOTE_E4, 125}, {NOTE_G4, 125}, {NOTE_A4, 125}, {NOTE_F4, 125}, {NOTE_G4, 125},
  {NOTE_E4, 125}, {NOTE_C4, 125}, {NOTE_D4, 125}, {NOTE_B3, 125}
};

const MusicNotes SUPER_MARIO_NOTES = {
  SUPER_MARIO,
  sizeof(SUPER_MARIO) / sizeof(Tone),
  10, // Begin delay
  500  // End delay
};


const Tone PAC_MAN_THEME[] = {
  {NOTE_B4, 200}, {NOTE_B5, 200}, {NOTE_FS5, 200}, {NOTE_DS5, 200}, {NOTE_B5, 200},
  {NOTE_FS5, 200}, {NOTE_DS5, 200}, {NOTE_C5, 200}, {NOTE_C6, 200}, {NOTE_G5, 200},
  {NOTE_E5, 200}, {NOTE_C6, 200}, {NOTE_G5, 200}, {NOTE_E5, 200}, {NOTE_B4, 200},
  {NOTE_B5, 200}, {NOTE_FS5, 200}, {NOTE_DS5, 200}, {NOTE_B5, 200}, {NOTE_FS5, 200},
  {NOTE_DS5, 200}, {NOTE_C5, 200}, {NOTE_C6, 200}, {NOTE_G5, 200}, {NOTE_E5, 200}
};

const MusicNotes PAC_MAN_NOTES = {
  PAC_MAN_THEME,
  sizeof(PAC_MAN_THEME) / sizeof(Tone),
  10, // Begin delay
  300  // End delay
};

const Tone DONKEY_KONG_THEME[] = {
  {NOTE_C4, 300}, {NOTE_E4, 300}, {NOTE_G4, 300}, {NOTE_C5, 300}, {NOTE_G4, 300},
  {NOTE_E4, 300}, {NOTE_C4, 300}, {NOTE_C4, 300}, {NOTE_E4, 300}, {NOTE_G4, 300},
  {NOTE_C5, 300}, {NOTE_G4, 300}, {NOTE_E4, 300}, {NOTE_C4, 300}, {NOTE_G3, 300},
  {NOTE_B3, 300}, {NOTE_D4, 300}, {NOTE_G4, 300}, {NOTE_B3, 300}, {NOTE_G3, 300}
};

const MusicNotes DONKEY_KONG_NOTES = {
  DONKEY_KONG_THEME,
  sizeof(DONKEY_KONG_THEME) / sizeof(Tone),
  0, // Begin delay
  500  // End delay
};


const Tone SILENT_NIGHT[] = {
  {NOTE_G4, 400}, {NOTE_A4, 400}, {NOTE_G4, 400}, {NOTE_E4, 400},
  {NOTE_G4, 400}, {NOTE_A4, 400}, {NOTE_G4, 400}, {NOTE_E4, 800},
  {NOTE_D4, 400}, {NOTE_G4, 400}, {NOTE_B4, 400}, {NOTE_C5, 400},
  {NOTE_B4, 400}, {NOTE_G4, 400}, {NOTE_A4, 400}, {NOTE_G4, 800}
};

const MusicNotes SILENT_NIGHT_NOTES = {
  SILENT_NIGHT,
  sizeof(SILENT_NIGHT) / sizeof(Tone),
  10, // Begin delay
  500  // End delay
};

const Tone RUDOLPH[] = {
  {NOTE_G4, 300}, {NOTE_A4, 300}, {NOTE_G4, 300}, {NOTE_E4, 600},
  {NOTE_G4, 300}, {NOTE_A4, 300}, {NOTE_G4, 300}, {NOTE_E4, 600},
  {NOTE_C5, 300}, {NOTE_C5, 300}, {NOTE_B4, 300}, {NOTE_A4, 300}, {NOTE_G4, 600},
  {NOTE_A4, 300}, {NOTE_B4, 300}, {NOTE_A4, 300}, {NOTE_F4, 600}
};

const MusicNotes RUDOLPH_NOTES = {
  RUDOLPH,
  sizeof(RUDOLPH) / sizeof(Tone),
  1, // Begin delay
  500  // End delay
};

const Tone YANKEE_DOODLE[] = {
  {NOTE_C4, 300}, {NOTE_C4, 300}, {NOTE_D4, 300}, {NOTE_E4, 300}, {NOTE_C4, 300}, {NOTE_E4, 300}, {NOTE_D4, 300},
  {NOTE_E4, 600}, {NOTE_G4, 300}, {NOTE_E4, 300}, {NOTE_C4, 300}, {NOTE_C4, 300}, {NOTE_D4, 300}, {NOTE_E4, 300},
  {NOTE_C4, 300}, {NOTE_D4, 300}, {NOTE_C4, 300}
};

const MusicNotes YANKEE_DOODLE_NOTES = {
  YANKEE_DOODLE,
  sizeof(YANKEE_DOODLE) / sizeof(Tone),
  10, // Begin delay
  500  // End delay
};


// Array of pointers to MusicNotes for all melodies
const MusicNotes* melodies[] = {
    &HAPPY_BIRTHDAY_NOTES,
    &TWINKLE_TWINKLE_NOTES,
    &STAR_WARS_NOTES,
    &ODE_TO_JOY_NOTES,
    &GAME_OF_THRONES_NOTES,
    &TETRIS_THEME_NOTES,
    &JINGLE_BELLS_NOTES,
    &CONTRA_THEME_NOTES,
    &PAC_MAN_NOTES,
    &DONKEY_KONG_NOTES,
    &SILENT_NIGHT_NOTES,
    &RUDOLPH_NOTES,
    &YANKEE_DOODLE_NOTES
};

// Number of melodies
const size_t melodyCount = sizeof(melodies) / sizeof(melodies[0]);

#endif // MUSIC_H
