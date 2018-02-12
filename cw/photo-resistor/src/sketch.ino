#define LED 3
#define MAX(A,B) ((A) >= (B) ? (A) : (B))
#define MIN(A,B) ((A) <= (B) ? (A) : (B))

int minRead = 1024;
int maxRead = 0;

void setup() {
    Serial.begin(9600);
    pinMode(LED, OUTPUT);
}

void loop() {
    int photoRead = analogRead(A0);
    Serial.print("Photo Sensor: ");
    Serial.print(photoRead);

    minRead = MIN(photoRead, minRead);
    maxRead = MAX(photoRead, maxRead);
    int val = map(photoRead, minRead, maxRead, 0, 255);

    Serial.print(", output value: ");
    Serial.println(val);

    analogWrite(LED, val);
}
