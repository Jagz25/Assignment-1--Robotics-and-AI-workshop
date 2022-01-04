#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

#define I2C_SDA 19
#define I2C_SCL 18

#define PEXP_I2CADDR 0x23
#define OLED_I2CAADR 0x3C

uint8_t expanderData;
SSD1306AsciiWire oled;

uint8_t IOexpanderRead(int address) {
    uint8_t _data;
    Wire.requestFrom(address, 1);
    if(Wire.available()) {
        _data = Wire.read();
    }
    return _data;
}

void setup() {
   Wire.begin(I2C_SDA, I2C_SCL);    
    
    Serial.begin(115200); //set up serial library baud rate to 115200
    Serial.println("IO Port Expander Test");
}

void loop() {
  oled.begin(&Adafruit128x64, OLED_I2CAADR);
  expanderData = IOexpanderRead(PEXP_I2CADDR);
  oled.setFont(Adafruit5x7);
  oled.clear();
  oled.print("Line module readings");
  oled.println(expanderData & 0x1F , BIN);
  oled.clear();

}
