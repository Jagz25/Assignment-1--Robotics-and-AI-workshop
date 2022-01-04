/*
  Prime Number Generator
  
  This program starts from the number 3 and prints all
  the primes occuring after it up until 4,294,967,295.
  
*/

int x = 2;    
int z = 1;    
int y;        
boolean prime; 
int numbers[29];

void setup(){
  Serial.begin(115200);  // initalize serial communication
}

void loop(){
  for (int x= 2; x<=200; x++){
    for(int y = 2; y< x  ; y ++){
      
      if(x % y == 0){ 
        prime = false;
        break;
      }
    }
    if (x==y){
        prime= true;
        numbers[z]=y;
        z++;
        Serial.print(x)+ ", ";
      }
        if (z=30){
      break;
      } 
      
  }
Serial.println ("the 26th number in this series is: "+(numbers[25]));
}
