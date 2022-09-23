#define PIN_A A1

#include <SoftwareSerial.h>
#include <ADCTouch.h>

int ref0;

SoftwareSerial mySerial(1, 0); // RX, TX

void setup()
{



  // set the data rate for the SoftwareSerial port
  mySerial.begin(4800);
  mySerial.println("Hello, world?");
}

void loop() // run over and over
{
  int value0 = ADCTouch.read(PIN_A);
  int value1 = ADCTouch.read(A2);
  int value2 = ADCTouch.read(A3);

  mySerial.print(value0);
  mySerial.print("\t");
  mySerial.print(value1);
  mySerial.print('\t');
  mySerial.println(value2);

  delay(100);
}
