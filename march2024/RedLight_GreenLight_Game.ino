/*
  Red Light / Green Light Game
  
  Description: Build a circuit that controls a red and green LED through a relay. A pushbutton should trigger the relay.
  
  Reminders: The relay must be powered by a 9volt battery and controlled through a 2N2222 transistor and you must put a diode across the coil of the relay.
  
  Behavior: When the circuit is powered, the green LED should automatically glow. When you push the button, the relay should turn off the green LED and cause the red LED to glow.
  
  Connections: Pin 9 on the Arduino should control the relay. Pin 10 on the Arduino should be connected to the pushbutton.

  Written by Brian Cox March 7, 2024
*/ 

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 10;  // the input pin for the button
const int relayPin = 9;    // the output pin for the transistor controlling the relay

// variables will change:
int buttonState = 1;  // variable for reading the pushbutton status

void setup() {
  // initialize the buttun pin as an input with built in pullup resistor
  pinMode(buttonPin, INPUT_PULLUP);
  // initialize the pushbutton pin as an input:
  pinMode(relayPin, OUTPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == LOW) {
    // activate relay
    digitalWrite(relayPin, HIGH);
  } else {
    // deactivate relay:
    digitalWrite(relayPin, 
  }LOW);
}
