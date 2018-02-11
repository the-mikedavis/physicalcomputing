#define SENSOR_PIN A0
#define BASE_TEMP 20.0f

void setup() {
  Serial.begin(9600);
  for (int pin = 2; pin < 5; pin++) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }
}

void loop() {
  int sensor_val = analogRead(SENSOR_PIN);
  Serial.print("Sensor Value: ");
  Serial.print(sensor_val);
  float voltage = (sensor_val/1024.0) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C: ");
  float temp = (voltage - .5) * 100;
  Serial.println(temp);

  if (temp < BASE_TEMP) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temp >= BASE_TEMP + 2 && temp < BASE_TEMP + 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temp >= BASE_TEMP + 4 && temp < BASE_TEMP + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if (temp >= BASE_TEMP + 6 && temp < BASE_TEMP + 8) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }

  delay(1);
}
