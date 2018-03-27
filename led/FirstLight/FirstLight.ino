#include <Adafruit_NeoPixel.h>

  #define PIN 6         // Parameter 1 = number of pixels in strip
                        // Parameter 2 = pin number (most are valid)
                        // Parameter 3 = pixel type flags, add together as needed:
                        // NEO_KHZ800 800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
                        // NEO_KHZ400 400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
                        // NEO_GRB Pixels are wired for GRB bitstream (most NeoPixel products)
                        // NEO_RGB Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, PIN, NEO_GRB + NEO_KHZ800);

 int i = 0;
 byte colors[5] = {0, 0, 0, 0, 0};
 byte lineEnding = 0x0A;
 int bytesRead; //eponse['id']
// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(115200);  // start serial for output
  Serial.println("test");
  strip.begin();
  strip.show();                // initialize all pixels to 'off'
 }

// the loop routine runs over and over again forever;

void loop() {
 if (Serial.available() > 2){
    //store data up until lineEnding (0x0A) in the bytesRead array
    uint8_t bytesRead = Serial.readBytesUntil(lineEnding, (char*)colors, 5);
    Serial.println((uint8_t)colors[0]);
    strip.setPixelColor(((((uint8_t)colors[3]-48)*10)+((uint8_t)colors[4]-48)), strip.Color(((uint8_t)colors[0]-48)*10, ((uint8_t)colors[1]-48)*10, ((uint8_t)colors[2]-48)*10));

    i = 0;
    strip.show();
  }
}
