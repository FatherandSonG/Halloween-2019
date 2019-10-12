#include "FastLED.h"
#define NUM_LEDS 24
CRGB leds[NUM_LEDS];
void setup() { FastLED.addLeds<NEOPIXEL, 2>(leds, NUM_LEDS); }
void loop() {
  leds[0,2,4,6,8,10] = CRGB::Red; FastLED.show(); delay(30);
  leds[0,2,4,6,8,10] = CRGB::Black; FastLED.show(); delay(30);
}
