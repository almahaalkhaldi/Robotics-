#include <Servo.h>

Servo S1;
Servo S2;
Servo S3;
Servo S4;
Servo S5;
Servo S6;

//Given Variables
float a3=14;
float a4=11;
float d1=9;
float d5=3;

float t1=0.5;
float t2=0.5;
float t3=0.5;
float t4=0.5;
float t5=0.5;
float t6=0.5;
float pi= 3.14;

// Known oreintation parameters 
float nx; float ny; float nz; 
float ox; float oy; float oz; 
float ax; float ay; float az; 

// Unknown position parameters 
float px; float py; float pz; 


void setup()
  
{
  S1.attach(3); 
  S2.attach(5); 
  S3.attach(6); 
  S4.attach(9); 
  S5.attach(10); 
  S6.attach(11); 
  
  //Calculating the unkown parameters using equations 
  px = (a4* (cos (t1)* cos(t2)- sin(t1)*sin(t2))* cos(t3)* cos(t4))- (a4* (cos (t1)* cos(t2)- sin(t1)*sin(t2))* sin(t3)* sin(t4))+ ((cos(t1)*sin(t2)+ sin(t1)*cos(t2))*d5)+(a3*(cos(t1)* cos(t2)- sin(t1)*sin(t2))*cos(t3));
  py = (a4* (cos (t1)* sin(t2)+ sin(t1)*cos(t2))* cos(t3)* cos(t4))- (a4* (cos (t1)* sin(t2)+ sin(t1)*cos(t2))* sin(t3)* sin(t4))- ((cos(t1)*cos(t2)- sin(t1)*sin(t2))*d5)+(a3*(cos (t1)* sin(t2)+ sin(t1)*cos(t2))*cos(t3));
  pz = (a4*sin(t3)*cos(t4)) - (a4* cos(t3)*sin(t4)) + (a3*sin(t3))+d1;
  
 //Printing the end effector's x, Y & Z coordinates 
  Serial.begin (9600); 
  Serial.print ("X= "); Serial.println (px, DEC); 
  Serial.print ("Y= "); Serial.println (py, DEC); 
  Serial.print ("Z= "); Serial.println (pz, DEC);
  
}


void loop()
{
 S1.write (t1* (180/pi)); 
 S2.write (t2* (180/pi));  
 S3.write (t3* (180/pi)); 
 S4.write (t4* (180/pi));   
 S5.write (t5* (180/pi));  
 S6.write (t6* (180/pi));
}