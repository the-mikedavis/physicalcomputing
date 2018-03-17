#include <Stepper.h>
#define STEPS 200
#define SPEED 60

int sensorVal = 0;

Stepper stp (STEPS, 10, 11, 12, 13);

void setup() {
  stp.setSpeed(SPEED);
}

void loop() {
  sensorVal = analogRead(A0);
  if (sensorVal <= (1023 / 3))
    stp.step(-1);
  else if (sensorVal >= (2 * 1023 / 3))
    stp.step(1);
  //  else do nothing
}
