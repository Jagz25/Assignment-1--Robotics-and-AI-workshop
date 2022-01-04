
String caesar_cipher_encryption(String x, int y) {
  String result = x;
  int transformed_index, char_index, char_ascii;
  for(int i = 0; i < x.length(); i++) {
    char_ascii = (int) x[i];
    char_index = (int) char_ascii % 32;
    
    if(char_ascii != 32) {
      transformed_index = (char_index + y) % 26;
      transformed_index = transformed_index % 26 == 0 ? 26 : transformed_index;
      transformed_index += 96;
      if(char_ascii < 96) transformed_index -= 32;
    } else
      transformed_index = char_ascii;
    result[i] = transformed_index;
  }
  return result;
}

String caesar_cipher_decryption(String x, int y) {
  String result = x;
  int transformed_index, char_index, char_ascii;
  for(int i = 0; i < x.length(); i++) {
    char_ascii = (int) x[i];
    char_index = (int) char_ascii % 32;
    
    if(char_ascii != 32) {
      transformed_index = (char_index - y + 26) % 26;
      transformed_index = transformed_index % 26 == 0 ? 26 : transformed_index;
      transformed_index += 96;
      if(char_ascii < 96) transformed_index -= 32;
    } else
      transformed_index = char_ascii;
    result[i] = transformed_index;
  }
  return result;
}
void setup() {
  Serial.begin(115200);
  delay(1000);
  
 
  
}

void loop() {
  String rcvString = "";
  int EorD=0;
  String encrypt="";
  String decrypt="";
  String output="";
  int key=1;
  input: if(Serial.available()) { //if number of bytes (characters) available for reading
      Serial.println("Would you like to encrypt or decrypt? Say 1 if you want to encrypt, Say 2 if you want to decrypt"); //print I received
      rcvString = Serial.readString();
      EorD=rcvString.toInt();
      if (EorD=1){
        Serial.println("Enter your text please");
        encrypt = Serial.readString();
        Serial.println("How much do you want to shift by?");
        key = Serial.readString().toInt();
        output= caesar_cipher_encryption(encrypt,key);
        Serial.println("Here's your encrypted text:"+(output));
      }
      else if (EorD=0){
       Serial.println("Enter your text please");
       decrypt = Serial.readString(); 
       Serial.println("How much was your text shifted?");
       key = Serial.readString().toInt();
       output= caesar_cipher_decryption(decrypt,key);
       Serial.println("Here's your decrypted text:"+(output));
      }
      else{
        Serial.println("try again");
        goto input;
      }
  
}
}
