/* Reads the value of a LDR on A0 and displays the brightness level across a 10 LED bard graph
 * Assumes that all 10 LEDs on the graph are connected on sequential Arduino digital pins.
 *  
 * Written by Brian Cox 4/28/2019
 */

int firstLedPin = 2;  // The Arduino pin for the first LED in the bar graph.
int lastLedPin = 11;  // The Arduino pin for the last LED in the bar graph.
int sensorPin = 0;   // The Arduino pin receiving input from the LDR.
int sensorValue = 0;  // This varible will store the reading from the LDR. 
int counter;          // This will be used as a loop counter.

// the setup routine runs once when you press reset:
void setup() { 
  //Set the 10 LED pins as outputs.
  for(int counter=firstLedPin; counter<=lastLedPin; counter++){
    pinMode(counter,OUTPUT);
  }
}

// the loop routine runs over and over again forever:
void loop(){
  driveBarGraphUsingSwitch();
  delay(10); // Adds a delay of 10 ms to provide stability. Remember that the LEDs are turned off at the beginning of a loop. This ensures they will stay on for 10ms.
}


/* driveBarGraphUsingSwitch()                                                                 
 * This function uses a switch statement to drive the LED bard graph. 
 * This is an efficient design becuase is only makes a decision once and then runs the proper statements.
 */ 

 void driveBarGraphUsingSwitch(){
  //Turn all LEDs off
  for(counter=firstLedPin; counter<=lastLedPin+1; counter++){
    digitalWrite(counter, LOW);
  }
  // read the input on analog pin 0:
  int sensorValue = analogRead(sensorPin);
  
  // Activate the appropriate number of LEDs in the bar graph based on the value on A0. (The range is 0 to 1023)
  // Considering that there are 10 LEDs in the bar graph, and there are 1024 possible numbers for the input: (1024 / 10 = 102.4) each increment will be 102.
  
  switch(sensorValue){
    case 50 ... 104:        //In order to ensure that all LEDs are off if it is relatively dark, the lowest value that triggers an LED is 50.
      digitalWrite(firstLedPin, HIGH);
      break;
    case 105 ... 207:
      for(counter=firstLedPin; counter<=firstLedPin+1; counter++){
        digitalWrite(counter, HIGH);
      }
      break;
    case 208 ... 310:
      for(counter=firstLedPin; counter<=firstLedPin+2; counter++){
        digitalWrite(counter, HIGH);
      }
      break;
    case 311 ... 414:
      for(counter=firstLedPin; counter<=firstLedPin+3; counter++){
        digitalWrite(counter, HIGH);
      }
      break;
    case 415 ... 517:
      for(counter=firstLedPin; counter<=firstLedPin+4; counter++){
        digitalWrite(counter, HIGH);
      }
      break;
    case 518 ... 620:
      for(counter=firstLedPin; counter<=firstLedPin+5; counter++){
        digitalWrite(counter, HIGH);
      }
      break;
    case 621 ... 723:
      for(counter=firstLedPin; counter<=firstLedPin+6; counter++){
        digitalWrite(counter, HIGH);
      }
      break;
    case 724 ... 806:
      for(counter=firstLedPin; counter<=firstLedPin+7; counter++){
        digitalWrite(counter, HIGH);
      }
      break;
    case 807 ... 908:
      for(counter=firstLedPin; counter<=firstLedPin+8; counter++){
        digitalWrite(counter, HIGH);
      }
      break;
    case 909 ... 1024:
      for(counter=firstLedPin; counter<=firstLedPin+9; counter++){
        digitalWrite(counter, HIGH);
      }
      default:
      break;
  } //End of switch statement
 } //End of the function driveBarGraphUsingSwitch()