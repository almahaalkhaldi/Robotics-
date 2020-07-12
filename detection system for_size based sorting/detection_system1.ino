#include<Servo.h>

Servo servo;

int IR;

void setup() {
servo.attach(8);
pinMode(A0, INPUT);
}

void loop() {
IR = digitalRead(A0);
  if(IR == HIGH){
   servo.write(180);
  }
  else{
   servo.write(0);
   }
}