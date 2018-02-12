#define SWITCH 4

boolean pressing = false;
int counter = 0;

void setup() {
  Serial.begin(9600);
  pinMode(SWITCH, INPUT);
}

void loop() {
  int switchRead = digitalRead(SWITCH);

  if (switchRead == 1 && !pressing) {
    pressing = true;
    counter++;
  } else if (switchRead == 0 && pressing)
    pressing = false;

  Serial.print(pressing ? "true" : "false");
  Serial.print(", counter: ");
  Serial.println(counter);
}
