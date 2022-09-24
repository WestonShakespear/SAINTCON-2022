//SAINTCON 2022 Hack in the Box UT Badge Code
//Written by -Weston Shakespear-

// #define DEBUG 1
// #define TEST 1
// #define OUTPUT_TOUCH_STATE 1

#define PIN_UART_TX 0
#define PIN_LED_DOUT 1
#define PIN_TOUCH_A A2
#define PIN_TOUCH_B A3
// #define PIN_TOUCH_C A3

#define NUM_PIXELS 12

#include <tinyNeoPixel.h>
#include <ADCTouch.h>

#if defined(DEBUG)

  #include <SendOnlySoftwareSerial.h>
  SendOnlySoftwareSerial mySerial(PIN_UART_TX);

#endif


tinyNeoPixel pixels = tinyNeoPixel(NUM_PIXELS, PIN_LED_DOUT, NEO_GRB + NEO_KHZ800);

short touchA = 0;
short touchB = 0;

byte threshold = 200;
// byte touchC = 0;


//function definitions
void populateButtonState();

void setup() {
  pixels.begin();

  #if defined(DEBUG)

    mySerial.begin(4800);

  #endif
}

void loop() {

  populateButtonState();

  #if defined(TEST)

  byte colorR = 0;
  byte colorG = 0;
  byte colorB = 40;

  if (touchA == 1) {
    colorG = 40;
  }

  if (touchB == 1) {
    colorR = 40;
  }

  for (int i = 0; i < NUM_PIXELS/3; i++) {
    pixels.setPixelColor(i, pixels.Color(40, colorG, 0));
    pixels.setPixelColor(i+4, pixels.Color(colorR, 40, 0));
    pixels.setPixelColor(i+8, pixels.Color(colorR, colorG, colorB));
    pixels.show();
    delay(40);
  }
  for (int i = 0; i < NUM_PIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.setPixelColor(i+4, pixels.Color(0, 0, 0));
    pixels.setPixelColor(i+8, pixels.Color(0, 0, 0));
    pixels.show();
    delay(20);
  }



  #else

  for (int i = 0; i < NUM_PIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 40));
    pixels.show();
    delay(100);
  }
  for (int i = 0; i < NUM_PIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));

  }
  pixels.show();

  #endif

  #if defined(DEBUG)

    // mySerial.println("hello from debug stuff");

  #endif

}

void populateButtonState() {
  touchA = ADCTouch.read(PIN_TOUCH_A);
  touchB = ADCTouch.read(PIN_TOUCH_B);

  // touchC = ADCTouch.read(PIN_TOUCH_C);

  #if defined(DEBUG)
  #if defined(OUTPUT_TOUCH_STATE) || defined(TEST)

  mySerial.print("A: ");
  mySerial.print(touchA);
  mySerial.print("\t B: ");
  mySerial.println(touchB);
  // mySerial.print("\t C: ");
  // mySerial.println(touchC);

  #endif
  #endif

  if (touchA > threshold) {
    touchA = 1;
  } else {
    touchA = 0;
  }

  if (touchB > threshold) {
    touchB = 1;
  } else {
    touchB = 0;
  }

  #if defined(DEBUG)
  #if defined(OUTPUT_TOUCH_STATE) || defined(TEST)

  mySerial.print("Ab: ");
  mySerial.print(touchA);
  mySerial.print("\t Bb: ");
  mySerial.println(touchB);
  mySerial.println("--------------------\n");
  // mySerial.print("\t C: ");
  // mySerial.println(touchC);

  #endif
  #endif

}
