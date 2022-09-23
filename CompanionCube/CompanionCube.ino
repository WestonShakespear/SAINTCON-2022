//SAINTCON 2022 Hack in the Box UT Badge Code
//Written by -Weston Shakespear-

#define DEBUG 1

#define PIN_UART_TX 0
#define PIN_LED_DOUT 1
#define PIN_TOUCH_A A1
#define PIN_TOUCH_B A2
#define PIN_TOUCH_C A3

#define NUM_PIXELS 12

#include <tinyNeoPixel.h>

#if defined(DEBUG)

  #include <SendOnlySoftwareSerial.h>
  SendOnlySoftwareSerial mySerial(0);

#endif


tinyNeoPixel pixels = tinyNeoPixel(NUM_PIXELS, PIN_LED_DOUT, NEO_GRB + NEO_KHZ800);


void setup() {
  pixels.begin();

  #if defined(DEBUG)

    mySerial.begin(4800);

  #endif
}

void loop() {
  for (int i = 0; i < NUM_PIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 40));
    pixels.show();
    delay(100);
  }
  for (int i = 0; i < NUM_PIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));

  }
  pixels.show();

  #if defined(DEBUG)

    mySerial.println("hello from debug stuff");
    
  #endif

}
