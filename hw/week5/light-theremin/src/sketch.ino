int sensorValue;
int sensorLow=1023;
int sensorHigh=0;
#define LED 13

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  while (millis() < 5000) {
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh)
      sensorHigh = sensorValue;
    if (sensorValue < sensorLow)
      sensorLow = sensorValue;
  }
  digitalWrite(LED, LOW);
}

void loop() {
  sensorValue = analogRead(A0);
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
  tone(8, pitch, 20);
  delay(10);
}
