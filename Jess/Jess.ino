#include <MultiStepper.h>
#include <AccelStepper.h>
#include <Stepper.h>
#include <SPI.h>

//define step size
#define stepsize 5 //1 step = 0.04mm, so 5steps=0.2mm

//define number of steps in 1 rev of motor
#define steps 200
#define interface 1 //stepper driver with Step and Direction pins
#define enablePin ??

// Define Motor Pins (2 Motors used)
//for Motor1 (x-direction) NEED TO DEFINE PIN!!!
#define DirectionPinM1 5
#define StepsPinM1 6

//for Motor2 (y-direction)
#define 2_DirectionPin 6??
#define 2_StepsPin 5??

byte address = 0x00;
int CS= 10;
 
// Define two motor objects
// The sequence 1-3-2-4 is required for proper sequencing of 2BBYJ48
AccelStepper stepper1(interface, StepsPinM1, DirectionPinM1);//x-direction
AccelStepper stepper2(interface, 2_StepsPin, 2_DirectionPin);//y-direction
setEnablePin(enablePin);

void setup() {
  // put your setup code here, to run once:
  //x-direction
  stepper1.setMaxSpeed(1000);//1 step/s , sets the max permittied speed, when run() will accelerate up to the speed set here
  stepper1.setSpeed(50);
  //y-direction
  stepper2.setMaxSpeed(1000);//1 step/s , sets the max permittied speed, when run() will accelerate up to the speed set here
  stepper2.setSpeed(50);
  pinMode (CS, OUTPUT);
  SPI.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

  //move forward 0.2mm in positive x-direction
  stepper1.move(stepsize);//moving 0.2mm (5 steps)
  stepper1.runSpeedToPosition();//run at set speed until reach target position

  //move forward 0.2mm  in positive y-direction
  stepper2.move(stepsize);//moving 0.2mm (5 steps)
  stepper2.runSpeedToPosition();//run at set speed until reach target position

  //move forward 0.2mm  in negative x-direction
  stepper1.move(-stepsize);//moving 0.2mm (5 steps)
  stepper1.runSpeedToPosition();//run at set speed until reach target position

  //move forward 0.2mm in negative y-direction
  stepper2.move(-stepsize);//moving 0.2mm (5 steps)
  stepper2.runSpeedToPosition();//run at set speed until reach target position

  //stop Motors
  stepper1.stop();
  stepper2.stop();

int digitalPotWrite(int value)
{
digitalWrite(CS, LOW);// no current through pin 10
SPI.transfer(address);
SPI.transfer(value);
digitalWrite(CS, HIGH);//upon receiving a value, current flows through pin 10, resistance is high 
}

  //once click run
  if (click run) {
    int xstep = 0;
    int i = 0;
    for (i = 1; i <= 5; i++) {
      for (xstep = 1; xstep <= 10; xstep++) { //moving 10 steps
        //move in +ve x-direction 0.2mm/step
        stepper1.move(stepsize);
        stepper1.runSpeedToPosition();
        digitalPotWrite(0); //no resistance here. Camera is triggered.
        delay(2000);//image captured
        
      }
      //move in y-direction (downward) 0.2mm/step
      stepper2.move(stepsize); //<<need to check direction + or -
      stepper2.runSpeedToPosition();
      digitalPotWrite(0); //no resistance here. Camera is triggered.
      delay(2000);//image captured
        
      for (xstep = 1; xstep <= 10; xstep++)  { //moving 10 steps
        //move in -ve x-direction 0.2mm/step
        stepper1.move(-stepsize);
        stepper1.runSpeedToPosition();
        digitalPotWrite(0); //no resistance here. Camera is triggered.
        delay(2000);//image captured
        
      }
      //move in y-direction (downward) 0.2mm/step
      stepper2.move(stepsize); //<<need to check direction + or -
      stepper2.runSpeedToPosition();
      digitalPotWrite(0); //no resistance here. Camera is triggered.
      delay(2000);//image captured
        
    }
  }

}
