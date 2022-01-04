/* 
 *  Ex_03 - Conditional
 *  Simple communication through the Serial monitor.
 *  
 */
String rcvString = "";
int height = 0;
int weight = 0;
String output = "";
float BMI = 0;
int Idealmin;
int Idealmax;
#include <string>

void setup() {
   Serial.begin(115200); //set up serial library baud rate to 115200
   delay(1000);
   Serial.println("Hi! Let's check how healthy you are. Please answer the next two questions.");
}

void loop() {
   if(Serial.available()) { //if number of bytes (characters) available for reading
      Serial.print("How tall are you? (answer in (m) please)"); //print I received
      rcvString = Serial.readString();
      height = rcvString.toInt(); // read string until newline character
      Serial.print("How much do you weigh? (answer in (kg) please)");
      rcvString = Serial.readString();
      weight = rcvString.toInt(); 
      BMI= (weight/(height*height));
      Idealmin= (18.5*(height*height));
      Idealmax= (24.9*(height*height));

      if (BMI < 16) {
        output="You're severely underweight, go bulk up, eat more! You need to be between" + std::string((Idealmin) + " kg or " + (Idealmax) + " kg.");
      }
      else if (BMI > 16 && BMI < 18.4) {
        output="You're underweight. Eat more. You need to be between" + std::string((Idealmin) + " kg or " + (Idealmax) + " kg.");
      }
      else if (BMI > 18.4 && BMI < 24.9){
        output="You're in the normal BMI range.";
      }
      else if (BMI > 24.9 && BMI < 29.9) {
        output="You're overweight. Lose some weight. You need to be between" + std::string((Idealmin) + " kg or " + (Idealmax) + " kg.");
      }
      else if (BMI > 29.9 && BMI < 34.9) {
        output="You're Moderetely obese. Excersice more. You need to be between" + std::string((Idealmin) + " kg or " + (Idealmax) + " kg.");
      }
      else if (BMI > 35.0 && BMI < 39.9) {
        output="You're Severely obese. Excersice more eat healthier.You need to be between" + std::string((Idealmin) + " kg or " + (Idealmax) + " kg.");
      }
      else if (BMI > 39.9) {
        output="You're Moribdly obese. Excersice more, go on a diet.You need to be between" + std::string((Idealmin) + " kg or " + (Idealmax) + " kg.");
      }


      Serial.println("");
      Serial.println("Hi! Let's check how healthy you are. Please answer the next two questions.");
   }
      Serial.print(output);
}
