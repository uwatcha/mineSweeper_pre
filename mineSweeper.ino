const int doremi[] = {262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494, 523, 554, 587, 622, 659, 698, 740, 784, 831, 880, 932, 988, 1047};
uint8_t SPEAKER = 3;
uint8_t VOLUME  = A2;
uint8_t BUTTON_A = A3;
uint8_t BUTTON_B = A4;
uint8_t BUTTON_C = A5;
int VOLUME_MARGIN = 8;
bool buttonFlag = false;
int currentMode = -1;


void setup() {
  Serial.begin(9600);
  pinMode(SPEAKER, OUTPUT);
  pinMode(BUTTON_A, INPUT);
  pinMode(BUTTON_B, INPUT);
  pinMode(BUTTON_C, INPUT);
  pinMode(VOLUME, INPUT);
}

void loop() {
  buttonA();
  buttonB();
  buttonC();
  // if (currentMode==-1) currentMode = getMode();
  // if (currentMode!=getMode()) {
  //   currentMode = getMode();
  //   soundModeChange();
  // }
  // else {
  //   //noTone(SPEAKER);
  // }
  

  // if (buttonIsON(BUTTON_B)) {
  //   soundMine();
  // }
  // else {
  //   //noTone(SPEAKER);
  // }
  //Serial.println(analogRead(VOLUME));
  noTone(SPEAKER);
}

void buttonA () {
  if (buttonIsON(BUTTON_A)) {
    switch (getMode()) {
      case 1://上
      break;
      case 2://下
      break;
      case 3://左
      break;
      case 4://右
      break;
    }
  }
}


void buttonB () {
  if (buttonIsON(BUTTON_B)) {

  }
}

void buttonC () {
  if (buttonIsON(BUTTON_C)) {

  }
}

bool buttonIsON (uint8_t button) {
  delay(50);
  if (digitalRead(button)==LOW && !buttonFlag) {
    buttonFlag = true;
    buttonSound(button);
    return 1;
  }
  else if (digitalRead(button)==LOW && buttonFlag) {
    return 0;
  }
  else {
    buttonFlag = false;
    return 0;
  }
}

int getMode() {
  float value = analogRead(VOLUME);
  if      (VOLUME_MARGIN+  0    <= value&&value <  30    -VOLUME_MARGIN) return  2;
  else if (VOLUME_MARGIN+  30   <  value&&value <  341   -VOLUME_MARGIN) return  3;
  else if (VOLUME_MARGIN+  341  <  value&&value <  682   -VOLUME_MARGIN) return  1;
  else if (VOLUME_MARGIN+  682  <  value&&value <  993   -VOLUME_MARGIN) return  4;
  else if (VOLUME_MARGIN+  993  <  value&&value <= 1023)                 return  2;
  else                                                                   return -1;
}

void buttonSound(uint8_t button) {
  if (button==BUTTON_A) {
    tone(SPEAKER, doremi[5]);
    delay(20);
  }
  else if (button==BUTTON_B) {
    tone(SPEAKER, doremi[20]);
    delay(35);
    tone(SPEAKER, doremi[18]);
    delay(15);
  }
  else if (button==BUTTON_C) {
    tone(SPEAKER, doremi[18]);
    delay(35);
    tone(SPEAKER, doremi[20]);
    delay(35);
    tone(SPEAKER, doremi[22]);
    delay(35);
  }
}