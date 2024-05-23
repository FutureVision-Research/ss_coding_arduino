/* May 2024 Challenge - without bonus challenge
  Write a sketch and build a circuit that lights up four LEDs from four different digital pins.
  LED 1 should be red. It should light up for one second, then turn off.
  LED 2 should be green. It should light up and wait for 5 seconds before going on to the next step.
  LED 3 should be red. It should light up for 7 seconds and then turn off.
  LED 4 should be green. It should light up for 9 seconds.
  Then turn all LEDs off for 30 seconds and then restart.
  Notes: Use whichever GPIO pins you want to use. Don’t forget your resistors! 

  Written by Brian Cox May 2024
*/

const int LED1 = 3;
const int LED2 = 4;
const int LED3 = 5;
const int LED4 = 6;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

void loop() {
  //Power up LED1 for one second then turn off
  digitalWrite(LED1, HIGH);
  delay(1000);
  digitalWrite(LED1, LOW);
  //Power up LED2, then wait for five seconds before continuing
  digitalWrite(LED2, HIGH);
  delay(5000);
  //Power up LED3 for seven seconds then turn off
  digitalWrite(LED3, HIGH);
  delay(7000);
  digitalWrite(LED3, LOW);
  //Power up LED4 for nine seconds then turn off
  digitalWrite(LED4, HIGH);
  delay(9000);
  digitalWrite(LED4, LOW);
  //Power off LED2 which was left on, as requested in the challenge description
  digitalWrite(LED2, LOW);
  //Wait thirty seconds then restart
  delay(30000);
}
