#include <Wire.h>
#include <Servo.h>


#define SLAVE_ADDRESS 0x08 // define communication i2c
int number = 0;
int state = 0; 

Servo mouve_roie;  // create servo object to control a servo

bool echeque = false;
bool echeque_math = false;
int  affiche_code =  6;
int  reset_pin = 12;
int  reine = 3;
int  roie  = 4;
int  cavalier_2 = A2;
int  fou = A0;
int  cavalier = A1;

void setup() {
  Serial.begin(9600); // start serial for output
  digitalWrite(reset_pin, HIGH);
  delay(200);
  pinMode(affiche_code, OUTPUT);
  pinMode(reset_pin, OUTPUT);
  digitalWrite(reset_pin, HIGH);
  
  pinMode(roie, INPUT);
  pinMode(fou, INPUT);
  pinMode(reine, INPUT);
  pinMode(cavalier, INPUT);
  
  // define callbacks for i2c communication
  Wire.begin(SLAVE_ADDRESS);
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);

  // define callbacks for i2c communication
  Serial.println("Ready!");
  mouve_roie.attach(5);
  mouve_roie.write(0); 
}

void loop() {
//    Serial.println(placement_fou());
//Serial.println(digitalRead(roie));
 Serial.println(digitalRead(cavalier_2));
// Serial.println(analogRead(fou));

  if (placement_fou() && placement_cavalier() && placement_reine() && placement_roie()) {
    echeque = true;
    mouve_roie.write(50); 
  }
  if (echeque && placement_fou() && !placement_cavalier() && placement_reine() && placement_roie() && placment_2()){
    echeque_math = true;
  }
  if (echeque_math) {
    digitalWrite(affiche_code, HIGH);
  } else {
    digitalWrite(affiche_code, LOW);
  }
  delay(10);

}

bool placement_roie(){
  return (digitalRead(roie) == 0);
}
bool placement_fou(){
 return (digitalRead(fou) == 0) ;
}
bool placement_reine(){
  return (digitalRead(reine) == 0);
}
bool placement_cavalier(){
  return (analogRead(cavalier) >= 400 && analogRead(cavalier) <= 505);
}

bool placment_2(){
  return  (digitalRead(cavalier_2) == 0);
}

void receiveData(int byteCount){

//  while(Wire.available()) {
//    
//  }
  int x = Wire.read();   // receive byte as an integer
  Serial.println(x);
  if(x == 2) {
    digitalWrite(reset_pin, LOW);
  }
  if (x == 1) {
    echeque_math = true;
  }
  if (x == 0) {
    echeque_math = false;
  }
}

void sendData(){
  Wire.write(echeque_math);
}
