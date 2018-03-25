#include <Wire.h>

#define SLAVE_ADDRESS 0x03

int number = 0;
int state = 0;

const int analogPin = A0;
const int portemanteau1 = A0;
const int portemanteau2 = A1;
const int portemanteau3 = A2;
const int portemanteau4 = A3;

int p1[2] = {1010, 1028}; //1020 1026
int p2[2] = {565,630};
int p3[2] = {1008,1022};
int p4[2] = {230,350};
bool enigme = false;

void setup()
{
  Serial.begin(9600);
  Wire.begin(SLAVE_ADDRESS);
  Wire.onRequest(sendData);
}

void loop()
{
  Serial.println(analogRead(portemanteau4));
  enigme = ((p1[0] < analogRead(portemanteau1) && p1[1] >  analogRead(portemanteau1)) && p2[0] < analogRead(portemanteau2) && p2[1] >  analogRead(portemanteau2) && p3[0] < analogRead(portemanteau3) && p3[1] >  analogRead(portemanteau3) && p4[0] < analogRead(portemanteau4) && p4[1] >  analogRead(portemanteau4));
  delay(10);
}

void sendData(){
  Wire.write(enigme);
}
