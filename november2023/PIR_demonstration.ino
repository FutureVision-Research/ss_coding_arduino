/* Uses a Passive Infrared Sensor (PIR) to detect motion.
 * When motion is detected, the sensor will send 3 volts to the sensor pin. (3Volts is considered high by 5Volt Arduinos)
 * This will cause an LED to light up.
 */
const int LEDPIN = 9;        //Set pin for LED
const int SENSORPIN = 12;    //Set pin for PIR sensor
int sensorState = 0;            //Variable to record the state of the PIR sensor

void setup() {
  pinMode(LEDPIN, OUTPUT);     //Set pin for LED as output
  pinMode(SENSORPIN, INPUT);   //Set pin for PIR sensor as input
}

void loop() {
  sensorState = digitalRead(SENSORPIN); //Read the state of the sensor pin
  
  if (sensorState == HIGH){             //Cause the LED to glow if the sensor pin is high.  Otherwise, turn the LED off.
    digitalWrite(LEDPIN, HIGH);
  } else {
    digitalWrite(LEDPIN, LOW);
  }
}