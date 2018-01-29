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
#define MINUTE 8            // Using digital pin 8 as input for minute button.

int pixel[LED_QUANTITY];   // Array used in function theTime() to light LEDS.
int hour_holder = 0;                  // Variable to check how many times the hour button is pressed.
int minute_holder = 0;                // Variable to check how many times the minute button is pressed.  
int hour_test = 0;

// Variables will change:
int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers


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
  pinMode(HOUR, INPUT);                 // Set pin 7 as an input.
  pinMode(MINUTE, INPUT);               // Set pin 8 as an input.
  
  strip.begin();                        // Start the LED strip.
  strip.setBrightness(BRIGHTNESS);      // Set the brightness of the strip.
  
  colorWipe(strip.Color(0, 0, 0), 50);  // Start all pixels as off.
  strip.show();                         // Push update to strip.

}

void loop() {
  // put your main code here, to run repeatedly:
 
  if(digitalRead(HOUR) == HIGH) {
    hour_test = 1;
    addHour();
    delay(200);
  }
  
  if(digitalRead(MINUTE) == HIGH) {
    hour_test = 2; 
    addMinute();
    //debouncer(hour_test);
    delay(200);
  }

//  Serial.print("Current hour and minute holder: ");
//  Serial.print(hour_holder);
//  Serial.print(", ");
//  Serial.println(minute_holder);
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


// ADD HOUR TO TIME
// --------------------------------------------------------------------
// Adds one hour to the time when the button is pressed
void addHour()  {
  hour_holder = hour_holder + 1;
  if (hour_holder > 23) {
    hour_holder = 0;
  }
}
// --------------------------------------------------------------------

// ADD MINUTE TO TIME
// --------------------------------------------------------------------
// Adds one minute to the time when the button is pressed
void addMinute()  {
  minute_holder = minute_holder + 1;
  if (minute_holder > 59) {
    minute_holder = 0;
    addHour();
  }
}
// --------------------------------------------------------------------

// DEBOUNCER
// -----------------------------
//
//void debouncer(int hour_test) {
//  // read the state of the switch into a local variable:
//  int reading = digitalRead(HOUR);
//
//  // check to see if you just pressed the button
//  // (i.e. the input went from LOW to HIGH), and you've waited long enough
//  // since the last press to ignore any noise:
//
//  // If the switch changed, due to noise or pressing:
//  if (reading != lastButtonState) {
//    // reset the debouncing timer
//    lastDebounceTime = millis();
//  }
//
//  if ((millis() - lastDebounceTime) > debounceDelay) {
//    // whatever the reading is at, it's been there for longer than the debounce
//    // delay, so take it as the actual current state:
//
//    // if the button state has changed:
//    if (reading != buttonState) {
//      buttonState = reading;
//
//      // only toggle the LED if the new button state is HIGH
//      if (buttonState == HIGH) {
//        ledState = !ledState;
//      }
//    }
//  }

//  // set the LED:
//  digitalWrite(ledPin, ledState);
//if(hour_test == 1){
//  addHour();
//} else if (hour_test == 2) {
//  addMinute();
//}
//  // save the reading. Next time through the loop, it'll be the lastButtonState:
//  lastButtonState = reading;
//}

