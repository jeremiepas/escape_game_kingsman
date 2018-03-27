#include <Wire.h>

#define SLAVE_ADDRESS 0x12

int interupteur = 2;
int porte = 3;
bool etat_porte = false;
int x = 0;

void setup() {
  Wire.begin(SLAVE_ADDRESS);
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);

  pinMode(interupteur, INPUT);
  pinMode(porte, OUTPUT);
}

void loop() {
  if (digitalRead(interupteur) == 0){
     etat_porte = (etat_porte)? false : true;
     delay(1000);
  }
  digitalWrite(3, etat_porte);
}

void receiveData(int byteCount){

  x = Wire.read();    // receive byte as an integer
  etat_porte = x;

}

void sendData(){
//  Wire.write();
}
