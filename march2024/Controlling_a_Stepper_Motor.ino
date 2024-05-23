/*
* Controlling a Stepper Motor
*
* Based on Adafruit Arduino - Lesson 16. Stepper
* Written by Simon Monk
* https://learn.adafruit.com/adafruit-arduino-lesson-16-stepper-motors/overview
*
* Comments by Brian Cox
* May 30, 2019
*/

#include <Stepper.h>    //Loads library for stepper motor support

//Set variables for the four stepper motor pins
int in1Pin = 12;
int in2Pin = 11;
int in3Pin = 10;
int in4Pin = 9;

//Create the stepper motor object. First argument is the number of steps the motors needs for one full rotation.
Stepper motor(512, in1Pin, in2Pin, in3Pin, in4Pin);

void setup(){
// Set all four stepper motor pins as outputs
pinMode(in1Pin, OUTPUT);
pinMode(in2Pin, OUTPUT);
pinMode(in3Pin, OUTPUT);
pinMode(in4Pin, OUTPUT);

// Start serial support
Serial.begin(9600);

// Set speed for the motor in Rotations Per Minute (RPM)
motor.setSpeed(20);
}
void loop(){
//Asks for input using a serial connection. (Use Serial Monitor)
if (Serial.available()){
Serial.println("Enter number of steps. Use negative number to reverse direction.");

// Creates a variable and receives entry from user
int steps = Serial.parseInt();

// Sends steps to motor
motor.step(steps);
}// End of Serial.available conditional
}// End of loop
