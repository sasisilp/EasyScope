#include <Stepper.h>
#include <SPI.h>
byte address = 0x00;
int CS = 10;

//define step size
#define stepsize 5 //1 step = 0.04mm, so 5steps=0.2mm

//define RPM
#define rpm 1.5 //1.5rpm = 5steps/s

//define number of steps in 1 rev of motor
#define stepsPerRev 200

// Define Motor Pins (2 Motors used)
//for Motor1 (x-direction) NEED TO DEFINE PIN!!!
#define 1_DirectionPin 5
#define 1_StepsPin 6

//for Motor2 (y-direction)
#define 2_DirectionPin ??
#define 2_StepsPin ??

// Define two motor objects
// The sequence 1-3-2-4 is required for proper sequencing of 2BBYJ48
Stepper stepper1(stepsPerRev, 1_StepsPin, 1_DirectionPin);//x-direction
Stepper stepper2(stepsPerRev, 2_StepsPin, 2_DirectionPin);//y-direction

void setup() {
  //images capture
  pinMode (CS, OUTPUT);
  SPI.begin();
  //x-direction
  stepper1.setSpeed(rpm);
  //y-direction
  stepper2.setSpeed(rpm);
}

void loop() {
  // put your main code here, to run repeatedly:

if (click forward in x){
  //move forward 0.2mm in positive x-direction
  stepper1.step(stepsize);//moving 0.2mm (5 steps)
   delay(500);
}

if (click forward in y){
  //move forward 0.2mm  in positive y-direction
  stepper2.step(stepsize);//moving 0.2mm (5 steps)
   delay(500);
}

if (click backward in x){
  //move forward 0.2mm  in negative x-direction
  stepper1.step(-stepsize);//moving 0.2mm (5 steps)
   delay(500);
}

if (click backward in y){
  //move forward 0.2mm in negative y-direction
  stepper2.step(-stepsize);//moving 0.2mm (5 steps)
   delay(500);
}

  //stop Motors
  if (click stop){
  stepper1.setSpeed(0);
  stepper2.setSpeed(0);
  }
  
  //once click run
  if (click run) {
    int xstep = 0;
    int i = 0;
    for (i = 1; i <= 5; i++) {
      for (xstep = 1; xstep <= 10; xstep++) { //moving 10 steps
        //move in +ve x-direction 0.2mm/step
        stepper1.step(stepsize);
        delay(500);//delay 500ms
        digitalPotWrite(0);//capture image
      }
      //move in y-direction (downward) 0.2mm/step
      stepper2.step(stepsize); //<<need to check direction + or -
       delay(500);
      digitalPotWrite(0);
      for (xstep = 1; xstep <= 10; xstep++)  { //moving 10 steps
        //move in -ve x-direction 0.2mm/step
        stepper1.step(-stepsize);
        delay(500);
        digitalPotWrite(0);
      }
      //move in y-direction (downward) 0.2mm/step
      stepper2.step(stepsize); //<<need to check direction + or -
       delay(500);
      digitalPotWrite(0);
    }
  }

}

int digitalPotWrite(int value)
{
digitalWrite(CS, LOW);
SPI.transfer(address);
SPI.transfer(value);
digitalWrite(CS, HIGH);
}
