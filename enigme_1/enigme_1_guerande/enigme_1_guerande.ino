#include <Wire.h>

#define SLAVE_ADDRESS 0x03
int number = 0;
int state = 0;
const int analogPin = A0;
const int portementeau1 = A0;
const int portementeau2 = A1;
const int portementeau3 = A2;
const int portementeau4 = A3;

int p1[2] = {0,0};           // variable to store the value read
int p2[2] = {0,0};
int p3[2] = {0,0};
int p4[2] = {0,0};
bool enigme = false;
void setup()
{
  Serial.begin(9600);              //  setup serial
  Wire.begin(SLAVE_ADDRESS);
  Wire.onRequest(sendData);

}

void loop()
{
  Serial.println(analogRead(analogPin));
  enigme = (p1[0] > analogRead(analogPin) && p1[1] <  analogRead(analogPin) && p2[0] > analogRead(analogPin) && p2[1] <  analogRead(analogPin) && p3[0] > analogRead(analogPin) && p3[1] <  analogRead(analogPin) && p4[0] > analogRead(analogPin) && p4[1] <  analogRead(analogPin));

 delay(10);
}

void sendData(){
  Wire.write(enigme);
}
