#include <FastLED.h>

int r = 152;
int g = 20;
int b = 10;

#define LED_PIN     5            // data pin for LED light (DIN)
#define NUM_LEDS    60           // the number of LED lights in your strip

CRGB leds[NUM_LEDS];
CRGB led[NUM_LEDS];
int soundSensor = 0;

void setup() {

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  for (int i = NUM_LEDS/2; i >= 0; i--) {
    leds[i] = CRGB (r,g,b);
    leds[NUM_LEDS-i] = CRGB (r,g,b);
    delay(40);
    FastLED.show();
  }
  
  Serial.begin(9600);
  pinMode(A0,INPUT);
}


void loop() {
  
  soundSensor = analogRead(A0);
  soundSensor = soundSensor*2;

  // defining the parameters of sound impact to trigger coloured lights
  if ((soundSensor>=550) && (soundSensor<=600)) { 
   leds[(NUM_LEDS/2)-1]=CRGB (0, 0, 255);
   leds[NUM_LEDS/2]=CRGB (0, 0, 255);
  }
  else if ((soundSensor>=500) && (soundSensor<=550)) {
   leds[(NUM_LEDS/2)-1]=CRGB (153, 153, 0);
   leds[NUM_LEDS/2]=CRGB (153, 153, 0);
  }
  else if ((soundSensor>=450) && (soundSensor<=500)) {
   leds[(NUM_LEDS/2)-1]=CRGB (255, 50, 255);
   leds[NUM_LEDS/2]=CRGB (255, 50, 255);
  }
  else if ((soundSensor>=400) && (soundSensor<=450)) {
   leds[(NUM_LEDS/2)-1]=CRGB (10, 25, 210);
   leds[NUM_LEDS/2]=CRGB (10, 25, 210);
  }
  else if ((soundSensor>=350) && (soundSensor<=400)) {
   leds[(NUM_LEDS/2)-1]=CRGB (50, 50, 150);
   leds[NUM_LEDS/2]=CRGB (50, 50, 150);
  }
  else if ((soundSensor>=300) && (soundSensor<=350)) {
   leds[(NUM_LEDS/2)-1]=CRGB (230, 0, 0);
   leds[NUM_LEDS/2]=CRGB (230, 0, 0);
  }
  else if ((soundSensor>=250) && (soundSensor<=300)) {
    leds[(NUM_LEDS/2)-1]=CRGB (0, 180, 0);
    leds[NUM_LEDS/2]=CRGB (0, 180, 0);
  }
  else if ((soundSensor>=200) && (soundSensor<=250)) {
    leds[(NUM_LEDS/2)-1]=CRGB (1, 0, 1);
    leds[NUM_LEDS/2]=CRGB (1, 0, 1);
  }
  else {
    leds[(NUM_LEDS/2)-1] = CRGB (r, soundSensor-100,b);
    leds[NUM_LEDS/2] = CRGB (r,soundSensor-100,b);
  }
  for (int i = 0; i <= ((NUM_LEDS/2)-2); i++) {
    leds[i] = leds[i+1];
    leds[NUM_LEDS-1-i] = leds[(NUM_LEDS)-i-2];
  }
  
 FastLED.show();
 delay(20);

}
