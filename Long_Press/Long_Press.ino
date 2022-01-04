#define ONBOARD_LED 2    // LED IO2
#define ONBOARD_SW  9    // Switch IO9
int current_LED = LOW;
const int pressTime  = 1000; // 1 second
int prevBTNState = LOW;  // the previous state from the input pin
int nowBTNState;     // the current reading from the input pin
unsigned long pressedTime  = 0;
unsigned long releasedTime = 0;

void setup() {
   Serial.begin(115200); //set up serial library baud rate to 115200
   pinMode(ONBOARD_LED, OUTPUT);
   pinMode(ONBOARD_SW, INPUT);

   digitalWrite(ONBOARD_LED, current_LED);    // turn the LED off by making the voltage LOW  
}

void loop() {
    
    nowBTNState = digitalRead(ONBOARD_SW);
    
  
  if(prevBTNState == HIGH && nowBTNState == LOW)        // button asserted low, so a press goes from high to low
    pressedTime = millis();
  else if(prevBTNState == LOW && nowBTNState == HIGH) { // button is released
    releasedTime = millis();
    long pressDuration = releasedTime - pressedTime;
    if( pressDuration > pressTime )
      Serial.println("I think you did a long press :)");

}
}
