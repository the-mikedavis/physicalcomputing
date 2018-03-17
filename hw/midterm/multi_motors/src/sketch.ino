#include <Stepper.h>
#define STEPS 200
#define DELAY 1000

Stepper s1 (STEPS, 10, 11, 12, 13);
//Stepper s1 (STEPS, 8, 9, 10, 11);
Stepper s2 (STEPS, 6, 7, 8, 9);
Stepper s3 (STEPS, 2, 3, 4, 5);

void setup() {
  s1.setSpeed(30);
  s2.setSpeed(30);
  s3.setSpeed(30);
}

void loop() {
  s1.step(1);
  s2.step(1);
  s3.step(1);
  //delay(DELAY);
}
