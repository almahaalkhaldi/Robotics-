#include <Servo.h>
Servo moto1;
Servo moto2;
int L1= 30; // length of arm 1
int L2= 15; // length of arm 2
float q1=180; // angle of motor 1 in degree
float q2=70; // angle of motor 1 in degree
float x,y,Q1,Q2;


void setup()
{ moto1.attach (9);
  moto2.attach (10);
}

void loop()
{
  moto1.write(q1);
  moto2.write(q2);
  Q1=(q1/180)*PI; // angle of motor 1 in radians 
  Q2=(q2/180)*PI; // angle of motor 2 in radians 
  x= (L1*cos(Q1))+(L2*cos(Q1+Q2));
  y= (L1*sin(Q1))+(L2*sin(Q1+Q2));
  
  delay(7000);
}