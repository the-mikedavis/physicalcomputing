long interval = 1000L;
long prevMillis = 0L;

void setup() {
  Serial.begin(9600);
}

void loop() {
  long time = millis();
  if (time - prevMillis >= interval) {
    prevMillis = time;
  }
}
