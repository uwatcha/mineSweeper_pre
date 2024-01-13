uint8_t SPEAKER  =  3;
uint8_t VOLUME   = A2;
uint8_t BUTTON_A = A3;
uint8_t BUTTON_B = A4;
uint8_t BUTTON_C = A5;

void setup() {
  Serial.begin(9600);
  pinMode(SPEAKER, OUTPUT);
  pinMode(BUTTON_A, INPUT);
  pinMode(BUTTON_B, INPUT);
  pinMode(BUTTON_C, INPUT);
  pinMode(VOLUME, INPUT);
}

void loop() {
  volume();
  buttonA();
  buttonB();
  buttonC();
  noTone(SPEAKER);
}