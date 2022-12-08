/*
  Button Sample
  Press button 1 = led 1 on for 5 seconds
  Press button 2 = led 2 on for 10 seconds
*/

// constants won't change: set value to match your project.
const int led1Pin =  5;
const int led2Pin =  6;
const int button1Pin = 7;
const int button2Pin = 8;
const int debounce = 20; // button debounce time (milliseconds)
const long led1Interval = 5000;           // interval led will stay on (milliseconds)
const long led2Interval = 10000;           // interval led will stay on (milliseconds)

// Variables
int led1State = LOW;             // led1State used to set the LED1
int led2State = LOW;             // led2State used to set the LED2
int button1State = 0;         // variable for reading the pushbutton status
int button2State = 0;         // variable for reading the pushbutton status


// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis1 = 0;        // will store last time LED1 was on
unsigned long previousMillis2 = 0;        // will store last time LED2 was on


void setup() {
  // set the digital pin as output:
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(button1Pin, INPUT_PULLUP); // use internal resister to pullup no external resister use
  pinMode(button2Pin, INPUT_PULLUP); // use internal resister to pullup no external resister use
}

void loop() {
  // here is where you'd put code that needs to be running all the time.

  // get the current millis
  unsigned long currentMillis = millis();

  if(!led1State) { // if led not on, check if button press
      button1State = digitalRead(button1Pin);

      // check if the pushbutton is pressed. If it is, the buttonState is LOW:
      if (button1State == LOW) {
         // set the timer
         previousMillis1 = currentMillis;
         led1State = HIGH;
         // turn LED1 on:
         digitalWrite(led1Pin, HIGH);
         // debounce button
         delay(debounce);
      }
  } else { // if led is on check if it time to turn off
      if (currentMillis - previousMillis1 >= led1Interval) {
        // reset led to off
        led1State = LOW;
        // turn LED1 off:
        digitalWrite(led1Pin, LOW);
      }
  }

  // go for led 2 (I swap the if logic to show alternative of code that work the same)
  if(led2State) { // if led is on, check if it time to turn off
      if (currentMillis - previousMillis2 >= led2Interval) {
        // reset led to off
        led2State = LOW;
        // turn LED2 off:
        digitalWrite(led2Pin, LOW);
      }
  } else { // if led is off check if button is press
      button2State = digitalRead(button2Pin);

      // check if the pushbutton is pressed. If it is, the buttonState is LOW:
      if (button2State == LOW) {
         // set the timer
         previousMillis2 = currentMillis;
         led2State = HIGH;
         // turn LED2 on:
         digitalWrite(led2Pin, HIGH);
         // debounce button
         delay(debounce);
      }
  }

} // loop
