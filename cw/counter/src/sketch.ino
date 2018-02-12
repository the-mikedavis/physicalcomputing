#define SWITCH 4
#define LED 3

boolean pressing = false;
int counter = 0;

void setup() {
  Serial.begin(9600);
  pinMode(SWITCH, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  int switchRead = digitalRead(SWITCH);

  if (switchRead == 1 && !pressing) {
    pressing = true;
    counter++;
    Serial.print("Click: ");
    Serial.println(counter);
  } else if (switchRead == 0 && pressing)
    pressing = false;

  if (counter % 3 == 0) {
    digitalWrite(LED, LOW);
  } else if (counter % 3 == 1) {
    digitalWrite(LED, HIGH);
  } else if (counter % 3 == 2) {
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
  }
}
