#include <Wire.h>
#include <Servo.h>


#define SLAVE_ADDRESS 0x08 // define communication i2c
int number = 0;
int state = 0; 

Servo mouve_roie;  // create servo object to control a servo

bool echeque = false;
bool echeque_math = false;

int reset_pin = 12;
int reine = 2;
int roie  = 3;
int cavalier_2 = 4;
int fou = A0;
int cavalier = A1;

void setup() {
  Serial.begin(9600); // start serial for output
  digitalWrite(reset_pin, HIGH);
  delay(200);
  pinMode(reset_pin, OUTPUT);
  digitalWrite(reset_pin, HIGH);
  
  pinMode(roie, INPUT);
  pinMode(fou, INPUT);
  pinMode(reine, INPUT);
  pinMode(cavalier_2, INPUT);
  
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
Serial.println(placement_roie());
//Serial.println(placement_cavalier());
//Serial.println(analogRead(cavalier));

  if (placement_fou() && placement_cavalier() && placement_reine() && placement_roie()) {
    echeque = true;
    Serial.println(placment_2());

    mouve_roie.write(50); 
  }
  if (echeque && placement_fou() && placement_cavalier() && !placement_reine() && placement_roie() && placment_2()){
    echeque_math = true;
  }
  if (echeque_math) {
    Serial.println();
  }
  delay(10);

}

bool placement_roie(){
  return (digitalRead(roie) != 0);
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
  if(x != 0) {
    delay(1000);
  }
}

void sendData(){
  Wire.write(echeque_math);
}
