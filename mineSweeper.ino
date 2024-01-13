#include "ae7seg.h"
uint8_t SPEAKER   =  2;
uint8_t VOLUME    = A2;
uint8_t BUTTON_A  = A3;
uint8_t BUTTON_B  = A4;
uint8_t BUTTON_C  = A5;
uint8_t SEG_LATCH = A1;
uint8_t SEG_SDI   =  3;
uint8_t SEG_SCK   =  4;
uint8_t REG_SER   = 11;
uint8_t REG_LATCH = 12;
uint8_t REG_CLK   = 14;
uint8_t MAT_7     = 10;
uint8_t MAT_8     =  9;
uint8_t MAT_9     =  8;
uint8_t MAT_10    =  7;
uint8_t MAT_11    =  6;
uint8_t MAT_12    =  5;

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
  pinMode(REG_SER, OUTPUT);
  pinMode(REG_LATCH, OUTPUT);
  pinMode(REG_, OUTPUT);
}

void loop() {
  volume();
  buttonA();
  buttonB();
  buttonC();
  seg(ctoi('F'));
  noTone(SPEAKER);
}