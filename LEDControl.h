#ifndef LEDCONTROL_H
#define LEDCONTROL_H

#include <Arduino.h>
#define MAXPATTERN 8
class LEDControl {
public:
    LEDControl(int *singleLEDs, int singleCount, int *rgbPins);
    void setPattern(int patternId);
    void update(); // Call this in `loop()` to execute patterns
    void patternBlinkAll();
    void turnOffSingleLEDs(); // Turn off all single LEDs
    void turnOffRGBLED();     // Turn off RGB LED

private:
    int *singleLEDs;
    int singleCount;
    int rgbPins[3];
    int currentPattern;
    unsigned long lastUpdate;
    int state;
    bool direction;

    void patternChase();
    void patternRGBCycle();
    void patternReverseChase();
    void patternPingPong();
    void patternAlternating();
    void patternMarquee();
    void patternBGColors();
    void setRGBColor(bool red, bool green, bool blue);
};

#endif // LEDCONTROL_H
