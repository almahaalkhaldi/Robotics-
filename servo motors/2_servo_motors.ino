#include <Servo.h>
Servo moto;
void setup()
{
   delay(2000);
  moto.attach(7);
  moto.write(170);
  delay(3000);
  moto.write(90);
  delay(3000);
  moto.write(170);
  delay(2000);
  moto.detach();
  
  delay(2000);
  moto.attach(8);
  moto.write(15);
  delay(3000);
  moto.write(170);
  delay(2000);
  moto.detach();
  
}

void loop(){}