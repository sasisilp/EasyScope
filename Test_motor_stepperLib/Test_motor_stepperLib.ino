#include <Stepper.h>

#define stepsPerRev 200
#define DirectionPin 5
#define StepsPin 6
#define stepsize 5 //1 step = 0.04mm, so 5steps=0.2mm
#define rpm 1.5 //1.5rpm = 5steps/s

Stepper stepper1(stepsPerRev, StepsPin, DirectionPin); //x-direction


void setup() {
    stepper1.setSpeed(rpm);
}

void loop() {
 //move forward 0.2mm in positive x-direction
  stepper1.step(stepsize);
  delay(500); //0.5s
}
