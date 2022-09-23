#include <tinyNeoPixel.h>

#define PIN            1
#define NUMPIXELS      14


tinyNeoPixel pixels = tinyNeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500;

void setup() {
  pixels.begin();

}

void loop() {

  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0));
  }
   pixels.show();
   delay(100);
   for(int i=0;i<NUMPIXELS;i++){
     pixels.setPixelColor(i, pixels.Color(0,0,0));
   }
    pixels.show();
    delay(100);
}
