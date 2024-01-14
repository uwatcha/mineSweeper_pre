const int DIRECT[] = {1, 2, 3, 4, 5, 6};
const int REGISTER[] = {7, 8, 9, 10, 11, 12}; //bに登録する
const int ANODE[] = {1, 3, 10, 7, 8};
const int CATHODE[] = {12, 11, 2, 9, 4, 5, 6}; //0で通電

void resetDotMatrix () {/*int (*arrays)[7]*/
  int b = B00000000;
  for (int i=0; i<5; i++) {
    b |= write(ANODE[i], 0);
    for (int j=0; j<7; j++) {
      b |= write(CATHODE[j], 1);
    }
  }
  reg(b);
}
//ANODE[0]とCATHODE[6]が点灯しない
void dotMatrix () {/*int (*arrays)[7]*/
  resetDotMatrix();
  int b = B00000000;
  for (int i=0; i<5; i++) {
    b |= write(ANODE[i], 1);
    for (int j=0; j<7; j++) {
      b |= write(CATHODE[j], 0);
    }
  }
  // b |= write(1, 1);
  // b |= write(3, 1);
  // b |= write(10, 1);
  // b |= write(7, 1);
  // b |= write(8, 1);
  // b |= write(12, 0);
  // b |= write(11, 0);
  // b |= write(2, 0);
  // b |= write(9, 0);
  // b |= write(4, 0);
  // b |= write(5, 0);
  // b |= write(6, 0);
  reg(b); 
}

int write (int n, bool isHigh) { //問題はこの中
  int result;
  if (isValue(DIRECT, n)) {
    digitalWrite(MAT[n-1], isHigh);
    return 0;
  }
  else if (isValue(REGISTER, n)) {
    if (isHigh) result = B00100000;
    else      result = B00000000;
    result = result >> (n-7);
    return result;
  }
}

void reg (int b) {
  digitalWrite(REG_LATCH, LOW);
  shiftOut(REG_SER, REG_CLK, LSBFIRST, b);
  digitalWrite(REG_LATCH, HIGH);
}

bool isValue (int *array, int value) {
  int size;
  if (array==DIRECT || array==REGISTER) size = 6;
  else if (array==ANODE) size = 5;
  else if (array==CATHODE) size = 7;
  for (int i=0; i<size; i++) {
    if (array[i]==value) {
      return true;
    }
  }
  return false;
}

void initDotMatrix () {
  for (int i=1; i<7; i++) pinMode(MAT[i], OUTPUT);
  pinMode(REG_SER, OUTPUT);
  pinMode(REG_LATCH, OUTPUT);
  pinMode(REG_CLK, OUTPUT);
  digitalWrite(MAT[0], HIGH);//1
  digitalWrite(MAT[2], HIGH);//3
  digitalWrite(MAT[1], LOW);//2
  digitalWrite(MAT[3], LOW);//4
  digitalWrite(MAT[4], LOW);//5
  digitalWrite(MAT[5], LOW);//6
  reg(B00110100);
}