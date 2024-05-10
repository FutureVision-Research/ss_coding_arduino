/***************************************************
This sketch uses the Adafruit MCP3008 library to read the 1st channel of a
MCP3008 10bit A/D covertor IC

By default the library will use the Arduino Uno SPI pins

Pin 13 SCK
Pin 12 COPI (formerly MOSI)
Pin 11 CIPO (formerly MISO)
Pin 10 CS

But you can use software SPI by specifing four other digital pins:
(SCK, COPI, CIPO, CS);
For example: adc.begin(13, 11, 12, 10);
****************************************************/
// If you use the Arduino desktop IDE, you will need to load the Adafruit MCP3008 library before compiling (the web editor loads it automatically)
#include <Adafruit_MCP3008.h> //load the MCP3008 library

Adafruit_MCP3008 adc; //Use the MCP3008 library to create an object called adc

int value, brightness;
int ledPin = 3;

void setup() {
  Serial.begin(9600); //Starts serial communication
  //while (!Serial);
  adc.begin(); //starts the analog to digital object
}

void loop() {
  value = adc.readADC(0); // Reads the value of the first A/D input on the MCP3008 and assigns the value to "value"
  Serial.println(value); // Outputs the value to the serial port
  brightness = map(value,0,1023,0,255); // Converts the A/D value of 0-1023 to the analogWrite value of 0-255
  brightness = constrain(brightness,0,255); // Ensures the value is between 0 and 255
  analogWrite(ledPin, brightness); //drives the LED at the proper PWM value
  delay(50); //Wait 50 milliseconds
}
