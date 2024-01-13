#include "ae7seg.h"
uint8_t SPEAKER   =  3;
uint8_t VOLUME    = A2;
uint8_t BUTTON_A  = A3;
uint8_t BUTTON_B  = A4;
uint8_t BUTTON_C  = A5;
uint8_t SEG_LATCH = A1;
uint8_t SEG_SDI   = A0;
uint8_t SEG_SCK   = 13;

void setup() {
  Serial.begin(9600);
  pinMode(SPEAKER, OUTPUT);
  pinMode(BUTTON_A, INPUT);
  pinMode(BUTTON_B, INPUT);
  pinMode(BUTTON_C, INPUT);
  pinMode(VOLUME, INPUT);
  pinMode(SEG_LATCH, OUTPUT);
  pinMode(SEG_SDI, OUTPUT);
  pinMode(SEG_SCK, OUTPUT);
}

void loop() {
  buttonA();
  buttonB();
  buttonC();
  seg(ctoi('F'));
  noTone(SPEAKER);
}