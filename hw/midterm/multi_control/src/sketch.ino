#include <Stepper.h>
#define STEPS 200
#define SPEED 30
#define SIZE 3

Stepper stepper [SIZE] = {
  Stepper (STEPS, 10, 11, 12, 13),
  Stepper (STEPS, 6, 7, 8, 9),
  Stepper (STEPS, 2, 3, 4, 5)
};

int sensorReads [SIZE];
int sensors [SIZE] = { A0, A1, A2 };

void setup() {
  for (int i = 0; i < SIZE; i++)
    stepper[i].setSpeed(SPEED);
}

void loop() {
  for (int i = 0; i < SIZE; i++) {
    sensorReads[i] = analogRead(sensors[i]);
    if (sensorReads[i] <= (1023 / 3))
      stepper[i].step(-1);
    else if (sensorReads[i] >= (2 * 1023 / 3))
      stepper[i].step(1);
    //  else just don't move the stepper
  }
}
