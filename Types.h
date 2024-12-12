
#ifndef TYPES_H
#define TYPES_H
#include <stdint.h>
#include <Arduino.h>

const int8_t SWITCH_PIN = 2;
const int8_t BUZZER_PIN = 11;
// Define pins for single LEDs and RGB LEDs
// Pins for single LEDs
int singleLEDs[] = {3, 4, 5, 6, 7};
// Pins for RGB LED
int rgbPins[] = {8, 9, 10};  // RGB LED pins
#endif