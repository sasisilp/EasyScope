#include <MultiStepper.h>
#include <AccelStepper.h>
#include <Stepper.h>

//define step size
#define stepsize 5 //1 step = 0.04mm, so 5steps=0.2mm
#define maxstep 1000//max it can go is 1000 steps = 40mm in x&y directions

//define number of steps in 1 rev of motor
#define steps 200

// Define Motor Pins (2 Motors used)
//for Motor1 (x-direction) NEED TO DEFINE PIN!!!
#define motorPin1 4
#define motorPin2 5
#define motorPin3 6
#define motorPin4 7

//for Motor2 (y-direction)
#define motorPin5 8
#define motorPin6 9
#define motorPin7 10
#define motorPin8 11

// Define two motor objects
// The sequence 1-3-2-4 is required for proper sequencing of 2BBYJ48
AccelStepper stepper1(steps, motorPin1, motorPin3, motorPin2, motorPin4);//x-direction
AccelStepper stepper2(steps, motorPin5, motorPin7, motorPin6, motorPin8);//y-direction

void setup() {
  // put your setup code here, to run once:
  //x-direction
  stepper1.setMaxSpeed(1000);//1 step/s , sets the max permittied speed, when run() will accelerate up to the speed set here
  stepper1.setSpeed(50);
  //y-direction
  stepper2.setMaxSpeed(1000);//1 step/s , sets the max permittied speed, when run() will accelerate up to the speed set here
  stepper2.setSpeed(50);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (click right) {//move forward 0.2mm in positive x-direction
    stepper1.move(stepsize);//moving 0.2mm (5 steps)
    stepper1.runSpeedToPosition();//run at set speed until reach target position
  }

  if (click UP) {//move forward 0.2mm  in positive y-direction
    stepper2.move(stepsize);//moving 0.2mm (5 steps)
    stepper2.runSpeedToPosition();//run at set speed until reach target position
  }

  if (click left) {//move forward 0.2mm  in negative x-direction
    stepper1.move(-stepsize);//moving 0.2mm (5 steps)
    stepper1.runSpeedToPosition();//run at set speed until reach target position
  }

  if (click down) {//move forward 0.2mm in negative y-direction
    stepper2.move(-stepsize);//moving 0.2mm (5 steps)
    stepper2.runSpeedToPosition();//run at set speed until reach target position
  }

  if (click stop) {//stop Motors
    stepper1.stop();
    stepper2.stop();
  }

  //while button is pressed, move infinietly
  while (right is true) {
    stepper1.move(maxstep);//move in +ve x-direction
    stepper1.runSpeed();
  }
  while (left is true) {
    stepper1.move(-maxstep);//move in -ve x-direction
    stepper1.runSpeed();
  }

  while (up is true) {
    stepper2.move(maxstep);//move in -ve y-direction
    stepper2.runSpeed();
  }

  while (down is true) {
    stepper2.move(-maxstep);//move in -ve y-direction
    stepper2.runSpeed();
  }

  //once click run
  if (click run) {
    int xstep = 0;
    int i = 0;
    for (i = 1; i < 5; i++) {
      for (xstep = 1; xstep < 10; xstep++) { //moving 10 steps
        //move in +ve x-direction 0.2mm/step
        stepper1.move(stepsize);
        stepper1.runSpeedToPosition();
        //**THEN CAPTURE IMAGE
      }
      //move in y-direction (downward) 0.2mm/step
      stepper2.move(stepsize); //<<need to check direction + or -
      stepper2.runSpeedToPosition();
      //**THEN CAPTURE IMAGE
      for (xstep = 1; xstep < 10; xstep++)  { //moving 10 steps
        //move in -ve x-direction 0.2mm/step
        stepper1.move(-stepsize);
        stepper1.runSpeedToPosition();
        //**THEN CAPTURE IMAGE
      }
      //move in y-direction (downward) 0.2mm/step
      stepper2.move(stepsize); //<<need to check direction + or -
      stepper2.runSpeedToPosition();
      //**THEN CAPTURE IMAGE
    }
  }

}
