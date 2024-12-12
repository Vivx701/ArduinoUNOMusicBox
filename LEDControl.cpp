#include "Arduino.h"
#include "LEDControl.h"

LEDControl::LEDControl(int *singleLEDs, int singleCount, int *rgbPins) {
    this->singleLEDs = singleLEDs;
    this->singleCount = singleCount;
    memcpy(this->rgbPins, rgbPins, sizeof(this->rgbPins));

    // Initialize pins as output
    for (int i = 0; i < singleCount; i++) {
        pinMode(singleLEDs[i], OUTPUT);
    }
    for (int i = 0; i < 3; i++) {
        pinMode(rgbPins[i], OUTPUT);
    }

    currentPattern = 0; // Default pattern
    lastUpdate = 0;
    state = 0;
}

void LEDControl::setPattern(int patternId) {
    currentPattern = patternId;
    state = 0; // Reset state for the new pattern
}

void LEDControl::update() {
    unsigned long currentMillis = millis();
    switch (currentPattern) {
        case 0: patternRGBCycle(); break;
        case 1: patternChase(); break;
        case 2: patternReverseChase(); break;
        case 3: patternPingPong(); break;
        case 4: patternAlternating(); break;
        case 5: patternMarquee(); break;
        case 6: patternRGBCycle(); break;
        case 7: patternBGColors(); break;
        default:
            // Default to turning everything off
            for (int i = 0; i < singleCount; i++) {
                digitalWrite(singleLEDs[i], LOW);
            }
            setRGBColor(false, false, false);
            break;
    }
}

void LEDControl::patternBlinkAll() {
    unsigned long interval = 500; // 500ms interval
    if (millis() - lastUpdate >= interval) {
        lastUpdate = millis();
        state = !state; // Toggle state

        for (int i = 0; i < singleCount; i++) {
            digitalWrite(singleLEDs[i], state);
        }
        setRGBColor(state, state, state); // Blink RGB LED
    }
}

void LEDControl::patternChase() {
    turnOffRGBLED();
    unsigned long interval = 200; // 200ms interval
    if (millis() - lastUpdate >= interval) {
        lastUpdate = millis();

        for (int i = 0; i < singleCount; i++) {
            digitalWrite(singleLEDs[i], (i == state) ? HIGH : LOW);
        }

        state = (state + 1) % singleCount; // Move to the next LED
    }
}

void LEDControl::patternRGBCycle() {
    turnOffSingleLEDs();
    turnOffRGBLED();
    unsigned long interval = 500; // 500ms interval
    if (millis() - lastUpdate >= interval) {
        lastUpdate = millis();

        switch (state) {
            case 0:
                setRGBColor(true, false, false); // Red
                break;
            case 1:
                setRGBColor(false, true, false); // Green
                digitalWrite(singleLEDs[2], HIGH);
                break;
            case 2:
                setRGBColor(false, false, true); // Blue
                digitalWrite(singleLEDs[0], HIGH);
                digitalWrite(singleLEDs[1], HIGH);
                digitalWrite(singleLEDs[3], HIGH);
                digitalWrite(singleLEDs[4], HIGH);
                break;
        }

        state = (state + 1) % 3; // Cycle through RGB states
    }
}

void LEDControl::setRGBColor(bool red, bool green, bool blue) {
    digitalWrite(rgbPins[0], red ? HIGH : LOW);
    digitalWrite(rgbPins[1], green ? HIGH : LOW);
    digitalWrite(rgbPins[2], blue ? HIGH : LOW);
}


void LEDControl::patternReverseChase() {

    turnOffRGBLED();
    unsigned long interval = 200; // 200ms interval
    if (millis() - lastUpdate >= interval) {
        lastUpdate = millis();

        for (int i = 0; i < singleCount; i++) {
            digitalWrite(singleLEDs[i], (i == state) ? HIGH : LOW);
        }

        state = (state - 1 + singleCount) % singleCount; // Move to the previous LED
    }
}

void LEDControl::patternPingPong() {
    turnOffRGBLED();
    unsigned long interval = 200; // 200ms interval
    if (millis() - lastUpdate >= interval) {
        lastUpdate = millis();

        for (int i = 0; i < singleCount; i++) {
            digitalWrite(singleLEDs[i], (i == state) ? HIGH : LOW);
        }

        if (direction) {
            state++;
            if (state >= singleCount - 1) direction = false;
        } else {
            state--;
            if (state <= 0) direction = true;
        }
    }
}

void LEDControl::patternAlternating() {
    turnOffRGBLED();
    unsigned long interval = 500; // 500ms interval
    if (millis() - lastUpdate >= interval) {
        lastUpdate = millis();
        state = !state; // Toggle state

        for (int i = 0; i < singleCount; i++) {
            digitalWrite(singleLEDs[i], (i % 2 == state) ? HIGH : LOW);
        }
    }
}

void LEDControl::turnOffSingleLEDs() {
    for (int i = 0; i < singleCount; i++) {
        digitalWrite(singleLEDs[i], LOW);
    }
}

void LEDControl::turnOffRGBLED() {
    setRGBColor(false, false, false);
}

void LEDControl::patternMarquee() {
    turnOffRGBLED();
    unsigned long interval = 200; // 200ms interval
    if (millis() - lastUpdate >= interval) {
        lastUpdate = millis();

        for (int i = 0; i < singleCount; i++) {
            digitalWrite(singleLEDs[i], (i == state) ? HIGH : LOW);
        }

        state = (state + 1) % singleCount; // Move to the next LED
    }
}

void LEDControl::patternBGColors() {
  turnOffSingleLEDs();
  turnOffRGBLED();
  direction = !direction;
  if(direction)
  {
      digitalWrite(singleLEDs[2], HIGH);
      setRGBColor(false, true, false);
  }else{
      digitalWrite(singleLEDs[0], HIGH);
      digitalWrite(singleLEDs[1], HIGH);
      digitalWrite(singleLEDs[3], HIGH);
      digitalWrite(singleLEDs[4], HIGH);
      setRGBColor(false, false, true);
  }

}
