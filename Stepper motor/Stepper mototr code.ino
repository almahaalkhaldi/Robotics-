#include <Stepper.h>

int spr = 64 ; // based on mototr specification (steps per round)
Stepper moto (spr, 8 , 10 , 9 , 11 );

void setup () {
moto.setSpeed( 60 ); // speed of motor
}

void loop () {
moto.step(3*spr) ;
delay (500) ;
moto.step(-500) ;
delay (500) ; 
}