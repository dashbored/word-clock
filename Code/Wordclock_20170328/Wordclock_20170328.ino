/*
 *  WORD CLOCK - 12x12 Wall Clock
 *  by Richard Davy
 *  
 *  A word clock in swedish using an Arduino Uno and 144 WS2812 LEDs 
 *  
 *  For more info about the project, and all files used, see the GitHub:
 *  https://github.com/dashbored/word-clock
 *  
 *  
 *  This code requires the following libraries:
 *
 * - RTClib https://github.com/adafruit/RTClib
 * - Adafruit_GFX https://github.com/adafruit/Adafruit-GFX-Library
 * - Adafruit_NeoPixel https://github.com/adafruit/Adafruit_NeoPixel
 * - Adafruit_NeoMatrix https://github.com/adafruit/Adafruit_NeoMatrix
 *
 *  Acknowledgements:
 *  - Thanks to Andy Doro for his open source code as a baseline.
 *  
 */

#include <Wire.h>
#include <RTClib.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_GFX.h>
#include <gfxfont.h>

RTC_DS3231 rtc;           // Easier command for the Real Time Clock (RTC).

#define LED_PIN 6         // Using digital out pin 6 as the data pin for the LED strip.
#define LED_QUANTITY 143  // Right now only 143, should be 144 (12x12) + four minute LEDs.
#define BRIGHTNESS 50     // Brightness of the LED's, fixed for now, will be dynamic later.

int pixel[LED_QUANTITY];   // Array used in function theTime() to light LEDS.

/*   
 *    %%%%%        FROM ADAFRUIT NEOPIXEL TUTORIAL INSTRUCTIONS        %%%%%
 *   Parameter 1 = number of pixels in strip
 *   Parameter 2 = Arduino pin number (most are valid)
 *   Parameter 3 = pixel type flags, add together as needed:
 *   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
 *   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
 *   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
 *   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2) 
 *   
 */
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_QUANTITY, LED_PIN, NEO_GRB + NEO_KHZ800);



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);                   // Begin Serial Monitor.
  Wire.begin();                         // Begin I2C.
  rtc.begin();                          // Begin Real Time Clock (DS3231).
  pinMode(LED_PIN, OUTPUT);             // Set pin 6 as an output.
  
  strip.begin();                        // Start the LED strip.
  strip.setBrightness(BRIGHTNESS);      // Set the brightness of the strip.
  
  strip.show();                         // Push update to strip.

  colorWipe(strip.Color(0, 0, 0), 50);  // Start all pixels as off.
}

void loop() {
  // put your main code here, to run repeatedly:
  theTime();
}

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}
