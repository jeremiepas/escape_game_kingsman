#include <Wire.h>

#define SLAVE_ADDRESS 0x04

int etape_1 = 2;
int etape_2 = 3;
int led_1   = 4;
int led_2   = 5;
int trape   = 6;
int x       = 0;
bool opened = true;
bool enigme_end = false;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin(SLAVE_ADDRESS);
  Wire.onRequest(sendData);

  pinMode(etape_1, INPUT);
  pinMode(etape_2, INPUT);

  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(trape, OUTPUT);

}

void loop() {
  Serial.println(digitalRead(etape_1));
  // put your main code here, to run repeatedly:
  digitalWrite(led_1, digitalRead(etape_1));
  digitalWrite(led_2, digitalRead(etape_2));

  if (digitalRead(etape_1) == 1 && digitalRead(etape_2) == 1){
    if(opened){
      digitalWrite(trape, HIGH);
      delay(3000);
      digitalWrite(trape, LOW);
      opened = false;
      enigme_end = true;
    }
  } else {
    opened = true;
    enigme_end = false;
  }
}

void receiveData(int byteCount){
  x = Wire.read();
  if (x == 1) {
    digitalWrite(trape, HIGH);
    delay(3000);
    digitalWrite(trape, LOW);
  }
  else {
    enigme_end = false;
  }
}

void sendData() {
  Wire.write(enigme_end);
}
