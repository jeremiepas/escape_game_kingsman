#include <Wire.h>

#define SLAVE_ADDRESS 0x05
int number = 0;
int state = 0;

void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  
  Serial.begin(9600); // start serial for output
  // initialize i2c as slave
  Wire.begin(SLAVE_ADDRESS);

  // define callbacks for i2c communication
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);

  Serial.println("Ready!");
}

void loop() {
  delay(100);
  digitalRead(3);
  number = digitalRead(3);
  digitalWrite(3, digitalRead(2)); // set the LED on
  
}

// callback for received data
void receiveData(int byteCount){

  while(Wire.available()) {
    number = 0;
    Serial.print("data received: ");
//    Serial.println(nu/mber);

    if (number == 1){

      if (state == 0){
        digitalWrite(3, HIGH); // set the LED on
        state = 1;
      }
      else{
        digitalWrite(3, LOW); // set the LED off
          state = 0;
      }
    }
  }
}

// callback for sending data
void sendData(){
  Wire.write(number);
}
