#include <Wire.h>

#define SLAVE_ADDRESS 0x03
int number = 0;
int state = 0;
const int analogPin = A0;
const int portementeau1 = A0;
const int portementeau2 = A1;
const int portementeau3 = A2;
const int portementeau4 = A3;

int p1[2] = {1010, 1028}; //1020 1026          // variable to store the value read
int p2[2] = {565,630};
int p3[2] = {1008,1022};
int p4[2] = {230,350};
bool enigme = false;
void setup()
{
  Serial.begin(9600);              //  setup serial
  Wire.begin(SLAVE_ADDRESS);
  Wire.onRequest(sendData);

}

void loop()
{
Serial.println(analogRead(portementeau4));
//  Serial.print(',');
 // Serial.println( p4[0] < analogRead(portementeau4) && p4[1] >  analogRead(portementeau4));
//  Serial.print(',');
  Serial.println(enigme);
//  Serial.print(',');
//  Serial.println(analogRead(portementeau4));
  enigme = ((p1[0] < analogRead(portementeau1) && p1[1] >  analogRead(portementeau1)) && p2[0] < analogRead(portementeau2) && p2[1] >  analogRead(portementeau2) && p3[0] < analogRead(portementeau3) && p3[1] >  analogRead(portementeau3) && p4[0] < analogRead(portementeau4) && p4[1] >  analogRead(portementeau4));

 delay(10);
}

void sendData(){
  Wire.write(enigme);
}
