#include <MultiStepper.h>
#include <AccelStepper.h>
#include <MultiStepper.h>
#include <Stepper.h>

//define step size
#define stepsize 5 //1 step = 0.04mm, so 5steps=0.2mm
#define maxstep 1000//max it can go is 1000 steps = 40mm in x&y directions

// Define Motor Pins (2 Motors used)
//for Motor1 (x-direction) NEED TO DEFINE PIN!!!
#define DirectionPin 5
#define StepsPin 6

//define number of steps in 1 rev of motor
#define steps 200
#define interface 1 //stepper driver with Step and Direction pins

AccelStepper stepper1(interface, StepsPin, DirectionPin);//x-direction

void setup() {
  // put your setup code here, to run once:
 //x-direction
  stepper1.setMaxSpeed(1000);//1 step/s , sets the max permittied speed, when run() will accelerate up to the speed set here
  stepper1.setSpeed(1000);
  //y-direction
}

void loop() {
  // put your main code here, to run repeatedly:
stepper1.move(stepsize);//moving 0.2mm (5 steps)
  stepper1.runSpeedToPosition();//run at set speed until reach target position
}
