#include <Wire.h>

#define SLAVE_ADDRESS 0x12

int interupteur = 2;
int porte = 3;
bool etat_porte = false;
int x = 0; 

void setup() {
  Wire.begin(SLAVE_ADDRESS);
  Serial.begin(9600);
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
  pinMode(interupteur, INPUT);
  pinMode(porte, OUTPUT);
}

void loop() {
  
  // put your main code here, to run repeatedly:
  if (digitalRead(interupteur) == 0){
     etat_porte = (etat_porte)? false : true;
     delay(1000);
  }
  if  (etat_porte) {
    digitalWrite(3, etat_porte);
    delay(3000);
    etat_porte = false;
    digitalWrite(3, false);
    delay(1000);
  }
}

void receiveData(int byteCount){

//   while (1 < Wire.available()) { // loop through all but the last
//    char c = Wire.read(); // receive byte as a character
//    Serial.print(c);         // print the character
//  }
  x = Wire.read();    // receive byte as an integer
  etat_porte = x; 
}

void sendData(){
 Wire.write(etat_porte);
}
