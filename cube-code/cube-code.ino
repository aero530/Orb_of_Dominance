#include <FastLED.h>

/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  This example code is in the public domain.
 */

#define NUM_LEDS 36
#define DATA_PIN 18

CRGB leds[NUM_LEDS];

int colors[][3] = {{255,90,0}, {255,140,0}, {128,0,128}};
unsigned int colorsIndex = 0;

int dimness[] = {0, 32, 64, 128, 192, 220};
unsigned int dimnessIndex = 0;

// Pin 13 has an LED connected on most Arduino boards.
// Pin 11 has the LED on Teensy 2.0
// Pin 6  has the LED on Teensy++ 2.0
// Pin 13 has the LED on Teensy 3.0
// give it a name:
int led = 13;
int button1 = 19;
int button2 = 20;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  
//  Serial.begin(115200);
  
  pinMode(led, OUTPUT);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

// the loop routine runs over and over again forever:
void loop() {
  int button1Val = digitalRead(button1);
  int button2Val = digitalRead(button2);

//  Serial.print("Button values ");
//  Serial.print(button1Val);
//  Serial.print(" ");
//  Serial.println(button2Val);

  if (button1Val == 0) {
    dimnessIndex = dimnessIndex + 1;
    // When you reach the end of dimness make dimnessIndex zero
    if (dimnessIndex > ( sizeof(dimness) / sizeof(dimness[0]) - 1) ) {
      dimnessIndex = 0;
    }
  }

  if (button2Val == 0) {
    colorsIndex = colorsIndex + 1;
    // When you reach the end of dimness make dimnessIndex zero
    if (colorsIndex > ( sizeof(colors) / sizeof(colors[0]) - 1) ) {
      colorsIndex = 0;
    }
  }

//  Serial.print("Dimness index ");
//  Serial.print(dimnessIndex);
//  Serial.print(" value ");
//  Serial.println(dimness[dimnessIndex]);
//
//  Serial.print("Colors index ");
//  Serial.print(colorsIndex);
//  Serial.print(" value ");
//  Serial.print(colors[colorsIndex][0]);
//  Serial.print(",");
//  Serial.print(colors[colorsIndex][1]);
//  Serial.print(",");
//  Serial.print(colors[colorsIndex][2]);
  
  for (int i = 0; i <= NUM_LEDS; i++) {
    // leds[i] = CRGB( 255, 90, 0);
    leds[i] = CRGB(colors[colorsIndex][0], colors[colorsIndex][1], colors[colorsIndex][2]);
    leds[i].fadeLightBy( dimness[dimnessIndex] );
  }
  
  FastLED.show();

  delay(200);
}
