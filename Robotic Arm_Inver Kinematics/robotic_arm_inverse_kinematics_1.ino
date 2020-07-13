#include <Servo.h>
Servo moto1;
Servo moto2;
int L1= 10; // length of arm 1
int L2= 12; // length of arm 2
float x=1; 
float y=4; 
float q1,q2,Q1,Q2,m;
int Q= 200;


void setup()
{ moto1.attach (5);
  moto2.attach (6);
}

void loop()
 
{m= (pow(x,2)+pow(y,2)-pow(L1,2)-pow(L2,2))/(2*L1*L2);
 q2=acos(m);
 Q2=q2*180/PI;
 Q1=Q-Q2;
 moto1.write(Q1);
 moto2.write(Q2);
 delay(7000);
 
 
}