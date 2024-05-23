/*
* Sketch - Changing Directions of a DC motor using an H-Bridge
* 
* Based on Adafruit Arduino - Lesson 15. Bi-directional Motor
* Written by Simon Monk
* https://learn.adafruit.com/adafruit-arduino-lesson-15-dc-motor-reversing/overview
*
* Comments by Brian Cox
* May 30, 2019
*/

//Variable declarations for the Arduino pins
const int enablePin = 11;
const int in1Pin = 10;
const int in2Pin = 9;
const int switchPin = 7;
const int potPin = 0;

void setup(){
//Set the mode for the Arduino pins. 
//No need to set the mode for the potpin because it is automatically an Analog input.
pinMode(in1Pin, OUTPUT);
pinMode(in2Pin, OUTPUT);
pinMode(enablePin, OUTPUT);
pinMode(switchPin, INPUT_PULLUP); //Uses built in pullup resistor
}

void loop(){
// Read the value of the analog input and divide it by 4.
//The range for the analog input is 0-1023. When we send PWM, the range needs to be 0-255.

int speed = analogRead(potPin) / 4; 
// Create a boolean variable and asign a value based on the state of the switch
boolean reverse = digitalRead(switchPin);
// Call the function to drive the motor and pass it the speed and direction parameters
setMotor(speed, reverse);
} //end of loop function

void setMotor(int speed, boolean reverse){  //Creates the function and receives the speed and direction variables
analogWrite(enablePin, speed);              // Send PWM pulse to the enable pin of the H-bridge. Allows control over speed of the motor
// Using ! changes the boolean to the opposite state. That way in1Pin always receives the opposite of in2Pin
digitalWrite(in1Pin, ! reverse); 
digitalWrite(in2Pin, reverse);
}
