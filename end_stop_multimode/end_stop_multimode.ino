#include <Wire.h>

#define I2C_SDA 19
#define I2C_SCL 18

#define PEXP_I2CADDR 0x23

uint8_t expanderData;

#define ONBOARD_LED 2    // LED IO2
#define ONBOARD_SW  9    // Switch IO9
int current_LED = LOW;

byte current_mode = 0;
long lastLED_Activity = 0;
byte current_ButtonState = HIGH;
byte previous_ButtonState = HIGH;

//Write a byte to the IO expander
void IOexpanderWrite(byte address, byte _data) {
    Wire.beginTransmission(address);
    Wire.write(_data);
    Wire.endTransmission(); 
}

//Read a byte from the IO expander
uint8_t IOexpanderRead(int address) {
    uint8_t _data;
    Wire.requestFrom(address, 1);
    if(Wire.available()) {
        _data = Wire.read();
    }
    return _data;
}

void setup() {
  Serial.begin(115200); //set up serial library baud rate to 115200
   pinMode(ONBOARD_LED, OUTPUT);
   pinMode(ONBOARD_SW, INPUT);

   digitalWrite(ONBOARD_LED, current_LED);
   IOexpanderWrite(PEXP_I2CADDR, 0xff);
}

void loop() {
   expanderData = IOexpanderRead(PEXP_I2CADDR);
    current_ButtonState = (bitRead(0,1));
    
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
