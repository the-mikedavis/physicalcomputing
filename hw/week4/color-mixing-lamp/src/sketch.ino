#define GREEN_OUT 9
#define RED_OUT 11
#define BLUE_OUT 10

#define RED_IN A0
#define GREEN_IN A1
#define BLUE_IN A2

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup() {
  pinMode(GREEN_OUT, OUTPUT);
  pinMode(RED_OUT, OUTPUT);
  pinMode(BLUE_OUT, OUTPUT);
}

void loop() {
  redSensorValue = analogRead(RED_IN);
  delay(5);
  greenSensorValue = analogRead(GREEN_IN);
  delay(5);
  blueSensorValue = analogRead(BLUE_IN);

  redValue = redSensorValue / 4;
  greenValue = greenSensorValue / 4;
  blueValue = blueSensorValue / 4;

  analogWrite(RED_OUT, redValue);
  analogWrite(GREEN_OUT, greenValue);
  analogWrite(BLUE_OUT, blueValue);
}
