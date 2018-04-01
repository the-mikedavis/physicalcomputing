#include <Stepper.h>
//  Number of steps in one 360 deg. rotation
#define STEPS 200
//  RPM: rotations per minute; 60 is the max.
#define SPEED 30
//  number of steppers
#define SIZE 3

//  initialize a collection of steppers
Stepper stepper [SIZE] = {
  Stepper (STEPS, 10, 11, 12, 13),
  Stepper (STEPS, 6, 7, 8, 9),
  Stepper (STEPS, 2, 3, 4, 5)
};

//  initialize a collection of sensors (potentiometers)
int sensorReads [SIZE];
int sensors [SIZE] = { A0, A1, A2 };

void setup() {
  //  set their speed in RPM
  for (int i = 0; i < SIZE; i++)
    stepper[i].setSpeed(SPEED);
}

void loop() {
  //  for each stepper
  for (int i = 0; i < SIZE; i++) {
    //  read the potentiometer
    sensorReads[i] = analogRead(sensors[i]);
    //  step if necessary
    if (sensorReads[i] <= (1023 / 3))
      stepper[i].step(-1);
    else if (sensorReads[i] >= (2 * 1023 / 3))
      stepper[i].step(1);
    //  else just don't move the stepper
  }
}
