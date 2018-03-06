
#include <Servo.h>

Servo mouve_roie;  // create servo object to control a servo

int number = 0;
int state = 0;

bool echeque = false;
bool echeque_math = false;

int roie  = 3;
int reine = 2;
int reine_2 = 4;
int cavalier = A2;
int fou = A0;

void setup() {
  pinMode(roie, INPUT);
  pinMode(reine, INPUT);
  pinMode(reine_2, INPUT);
  Serial.begin(9600); // start serial for output
  // initialize i2c as slave

  // define callbacks for i2c communication
  Serial.println("Ready!");
  mouve_roie.attach(5);
  mouve_roie.write(50); 
}

void loop() {

   
  if (placement_fou() && placement_cavalier() && placement_reine() && placement_roie()) {
    echeque = true;
    mouve_roie.write(150); 
  }
  if (stape_0 && placement_fou() && placement_cavalier() && !placement_reine() && placement_roie() && placment_2()){
    echeque_math = true;
  }
  
  delay(100);
  digitalRead(reine);
  number = analogRead(A0);

  Serial.println(placement_reine());
  
}
bool placement_roie(){
  return (digitalRead(roie) != 0);
}
bool placement_fou(){
 return (analogRead(fou) >= 24 && analogRead(fou) <= 33) ;
}
bool placement_reine(){
  return (digitalRead(reine) == 0);
}
bool placement_cavalier(){
  return (analogRead(cavalier) >= 500 && analogRead(cavalier) <= 535);
}

bool placment_2(){
  return  (digitalRead(reine_2) == 0)
}
}
