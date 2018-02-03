#define BNT 2
int switch_state = 0;

void setup() {
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(BTN, INPUT);
}

void loop() {
    switch_state = digitalRead(BTN);

    if (switch_state == LOW) {
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
    } else {
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);

        delay(250);
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        delay(250);
    }
}
