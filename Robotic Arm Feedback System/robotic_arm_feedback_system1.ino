#include <Servo.h>

int pot_pin_claw = A0; // from left to right potentio 1
int pot_pin_bottom = A1;// potentio 4
int pot_pin_joint1 = A2;// potentio 2
int pot_pin_joint2 = A3;// potentio 3

int value_claw; // motor 1
int value_bottom;// motor 2
int value_joint1;// motor 3
int value_joint2;// motor 4

Servo servo_claw;
Servo servo_bottom;
Servo servo_joint1;
Servo servo_joint2;

void setup() {
  servo_claw.attach(2);
  servo_bottom.attach(3);
  servo_joint1.attach(4);
  servo_joint2.attach(5);
  Serial.begin(9600);
}

void loop() {
  int pot_inputs[4];
  pot_inputs[0] = analogRead(pot_pin_claw); // read pot inputs
  pot_inputs[1] = analogRead(pot_pin_bottom);
  pot_inputs[2] = analogRead(pot_pin_joint1);
  pot_inputs[3] = analogRead(pot_pin_joint2);

  if(pot_inputs[0] > 511) { // since the function of the claw is only to open and close, 
    //there is no need for a wide range of analog values in the potentiometer (0). 
    value_claw = 1;
  } else {
    value_claw = 0;
  } // turn on pot (0) when the input signal > 511=2.5 v, otherwise turn off the claw. 
  
  value_bottom = map(pot_inputs[1], 110, 800, 180, 0); // change the range of analog values from 10 bits to 8 bits (1 byte)
  value_joint1 = map(pot_inputs[2], 1023, 600, 30, 160); // we use a wide range of values for bottom and joint 1&2, since a wide range of motion is desired.
  value_joint2 = map(pot_inputs[3], 170, 880, 180, 0);

  if(value_claw) {
    servo_claw.write(180); // the angles at which the claw is set to open and close. when the angle is 180 the claw is on, when the angle is 80 the claw is off. 
  } else {
    servo_claw.write(80);
  }
  
  servo_bottom.write(value_bottom); // setting servo motor angles depending on potentiometers.
  servo_joint1.write(value_joint1);
  servo_joint2.write(value_joint2);

  delay(5);
}