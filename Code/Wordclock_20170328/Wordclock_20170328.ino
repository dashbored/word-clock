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
#define LED_QUANTITY 144  // Right now only 143, should be 144 (12x12) + four minute LEDs.
#define BRIGHTNESS 99     // Brightness of the LED's, fixed for now, will be dynamic later.
#define HOUR 7            // Using digital pin 7 as input for hour button.
#define MINUTE 8          // Using digital pin 8 as input for minute button.
#define MAX_HOUR 24       // 24 is always 0
#define MAX_MINUTE 60

int pixel[LED_QUANTITY];   // Array used in function theTime() to light LEDS.
int hourAdjust = 0;       // Variable to check how many times the hour button is pressed.
int minuteAdjust = 0;     // Variable to check how many times the minute button is pressed.  


// Variables will change:
int buttonState[13] = {LOW};        // One for every digital pin
unsigned long lastDebounceTime[13] = {0}; // One for every digital pin
unsigned long holdTime[13] = {0}; // One for every digital pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers
unsigned long holdDelay = 500;      // Interval registering for holding the hour/minute button

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
  Serial.begin(9600);                   // Begin Serial Monitor.
  Wire.begin();                         // Begin I2C.
  rtc.begin();                          // Begin Real Time Clock (DS3231).
  pinMode(LED_PIN, OUTPUT);             // Set pin 6 as an output.
  pinMode(HOUR, INPUT);                 // Set pin 7 as an input.
  pinMode(MINUTE, INPUT);               // Set pin 8 as an input.
  
  strip.begin();                        // Start the LED strip.
  strip.setBrightness(BRIGHTNESS);      // Set the brightness of the strip.
  
  colorWipe(strip.Color(0, 0, 0), 50);  // Start all pixels as off.
  strip.show();                         // Push update to strip.

}

void loop() {
  // put your main code here, to run repeatedly:
 
  if(debouncer(HOUR)) {
     Serial.println("add hour");
    addHour();
  }

  if(debouncer(MINUTE)) {
    Serial.println("add minute");
    addMinute();
  }

  if(buttonState[HOUR] && buttonState[MINUTE]) {
    Serial.println("reset");
    reset();
  }


 theTime(hour_holder, minute_holder);
}

// Wipes all LED to specific color, used as initializer.
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

// RESET
// --------------------------------------------------------------------
// Resets the hour_holder and minute_holder
void reset() {
  hourAdjust = MAX_HOUR - rtc.now().hour();
  minuteAdjust = MAX_MINUTE - rtc.now().minute();
}


// ADD HOUR TO TIME
// --------------------------------------------------------------------
// Adds one hour to the time when the button is pressed
void addHour()  {
  hourAdjust = hourAdjust + 1;
  if (hourAdjust > 23) {
    hourAdjust = 0;
  }
}
// --------------------------------------------------------------------

// ADD MINUTE TO TIME
// --------------------------------------------------------------------
// Adds one minute to the time when the button is pressed
void addMinute()  {
  minuteAdjust = minuteAdjust + 1;
  if (minuteAdjust > 59) {
    minuteAdjust = 0;
    addHour();
  }
}
// --------------------------------------------------------------------

// DEBOUNCER
// -----------------------------

bool debouncer(int pin) {
 // read the state of the switch into a local variable:
 int reading = digitalRead(pin);

 // If the switch changed, due to noise or pressing:
 if (reading != buttonState[pin]) {
   // reset the debouncing timer
   buttonState[pin] = reading;
   holdTime[pin] = millis();
   lastDebounceTime[pin] = millis();   
 }

  // only toggle the LED if the new button state is HIGH
  if ((millis() - holdTime[pin]) > holdDelay && buttonState[pin] == HIGH) {
     lastDebounceTime[pin] = millis();
     holdTime[pin] = millis();
    return true;
  }

 return false;
}


