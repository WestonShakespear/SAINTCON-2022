#include <SendOnlySoftwareSerial.h>

SendOnlySoftwareSerial mySerial(0);  // Tx pin

void setup()
{
  mySerial.begin(4800);
}

int i;

void loop()
{
  mySerial.print ("test: ");
  mySerial.println (i++);
  delay (100);
}
