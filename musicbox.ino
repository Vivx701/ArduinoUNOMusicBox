#include "Types.h"
#include "Music.h"
#include "LEDControl.h"
#include <Arduino.h>


Buzzer buzzer(11, LED_BUILTIN);
// Create LEDControl instance
LEDControl ledControl(singleLEDs, 5, rgbPins);
volatile bool button_pressed = false;
int8_t music_index = 0;
unsigned long lastDebounceTime = 0; // Timestamp of the last button press
const unsigned long debounceDelay = 500; // 50ms debounce time
void playMusic(const MusicNotes &music)
{
  buzzer.begin(music.begin); // Start with the initial delay
  for (size_t i = 0; i < music.size; ++i)
  {
    const Tone &tone = music.tones[i];
    Serial.print("Playing =  ");
    Serial.print(music_index);
    Serial.println("");
    buzzer.sound(tone.note, tone.duration);
    ledControl.update();
    if(button_pressed)
    {
      music_index = (music_index+1)%melodyCount;
      button_pressed = false;
      break;
    }
  }
  buzzer.end(music.end); // End with the final delay
}

void playMelodyByIndex(size_t index) {
    if (index < melodyCount) {
        playMusic(*melodies[index]); // Play the melody at the specified index
    } else {
        Serial.println("Invalid melody index!");
    }
}

void playRandomMelody() {
    size_t randomIndex = random(0, melodyCount); // Generate a random index
    playMusic(*melodies[randomIndex]); // Play the melody at the random index
}

void button_press()
{
  unsigned long currentTime = millis();
  if (currentTime - lastDebounceTime > debounceDelay && !button_pressed) {
    button_pressed = true;
    lastDebounceTime = currentTime;
  }
}

void setup() {
    ledControl.patternBlinkAll();
    playMusic(STARTUP_MUSIC_NOTES);
    attachInterrupt(digitalPinToInterrupt(SWITCH_PIN), button_press, FALLING);
    Serial.begin(9600);    
}



void loop() {
    //Switch patterns every 10 seconds
    static unsigned long lastSwitch = 0;
    if (millis() - lastSwitch > 10000) {
        static int patternId = 0;
        lastSwitch = millis();
        patternId = (patternId + 1) % MAXPATTERN; // Cycle through patterns
        ledControl.setPattern(patternId);
        //playMelodyByIndex(patternId);
    }
    // ledControl.update();
    // //delay(2000);
    playMelodyByIndex(music_index);
}
