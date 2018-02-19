#include "pitch.h"
#define PIEZO 3

int counter = 0;
long pMillis = 0L;
int interval = 500;
const int seqLength = 5;
int toneSequence[seqLength] = {NOTE_A6, NOTE_B6, NOTE_C6, NOTE_E6, NOTE_F6};

void setup() {
  pinMode(PIEZO, OUTPUT);
}

void loop() {
  if (millis() - pMillis >= interval) {
    pMillis = millis();
    counter++;
    Serial.println(counter);
    tone(PIEZO, toneSequence[counter], 100);
  }

  if(counter >= seqLength){
    counter = 0;
  }
}

