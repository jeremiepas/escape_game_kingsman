#include "LPD8806.h"
#include "SPI.h" // Comment out this line if using Trinket or Gemma
#ifdef __AVR_ATtiny85__
 #include <avr/power.h>
#endif

// Number of RGB LEDs in strand:
int nLEDs = 32;

// Chose 2 pins for output; can be any valid output pins:
int dataPin  = 2;
int clockPin = 3;
LPD8806 strip = LPD8806(nLEDs, dataPin, clockPin);

void setup() {
  // put your setup code here, to run once:
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
    clock_prescale_set(clock_div_1); // Enable 16 MHz on Trinket
  #endif

  // Start up the LED strip
  strip.begin();

  // Update the strip, to start they are all 'off'
  strip.show();
}

void loop() {
  // put your main code here, to run repeatedly:
 strip.setPixelColor(1, 40);// White
  //strip.setPixelColor(1, 10);// White

  delay(100);
//  colorChase(strsetPixelColorip.Color(127,   0,   0), 50); // Red
//  delay(100);
//  colorChase(strip.Color(127, 127,   0), 50); // Yellow
//  delay(100);
//  colorChase(strip.Color(  0, 127,   0), 50); // Green
//  delay(100);
//  colorChase(strip.Color(  0, 127, 127), 50); // Cyan
//  delay(100);
//  colorChase(strip.Color(  0,   0, 127), 50); // Blue
//  delay(100);
//  colorChase(strip.Color(127,   0, 127), 50); // Violet
  
}
