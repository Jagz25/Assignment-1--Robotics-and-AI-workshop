#define ONBOARD_LED 2    // LED IO2
#define ONBOARD_SW  9    // Switch IO9

int current_LED = LOW;

byte current_mode = 0;
long lastLED_Activity = 0;
byte current_ButtonState = HIGH;
byte previous_ButtonState = HIGH;

void setup() {
   Serial.begin(115200); //set up serial library baud rate to 115200
   pinMode(ONBOARD_LED, OUTPUT);
   pinMode(ONBOARD_SW, INPUT);

   digitalWrite(ONBOARD_LED, current_LED);    // turn the LED off by making the voltage LOW  
}

void loop() {
    
    current_ButtonState = digitalRead(ONBOARD_SW);
    
    // Transition from High to Low, Button press instance
    if ((current_ButtonState == LOW) && (previous_ButtonState == HIGH)){
        current_mode = (current_mode >= 3)? 0 : current_mode + 1;
        Serial.print("Button Mode ");
        Serial.println(current_mode);
    }
    previous_ButtonState = current_ButtonState;
   switch (current_mode) {
    case 0:
    digitalWrite(ONBOARD_LED, ((millis() / 1000) % 2 == 0)? LOW: HIGH);
    break;

    case 1:
    digitalWrite(ONBOARD_LED, ((millis() / 1000) % 3 == 0)? LOW: HIGH);// every 1/3 of a second
    break;

    case 2:
    digitalWrite(ONBOARD_LED, ((millis() / 1000) % 5 == 0)? LOW: HIGH);// every 1/5 of a second
    break;

    case 3:
    digitalWrite(ONBOARD_LED, ((millis() / 1000) % 7 == 0)? LOW: HIGH);// every 1/7 of a second
    break;

    default:
    digitalWrite(ONBOARD_LED, ((millis() / 1000) % 2 == 0)? LOW: HIGH);
    break;
}
    

   

    
}
