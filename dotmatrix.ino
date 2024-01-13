const int DIRECT[] = {1, 2, 3, 4, 5, 6};
const int REGISTER[] = {7, 8, 9, 10, 11, 12};
const int ANODE[] = {1, 3, 10, 7, 8};
const int CATHODE[] = {12, 11, 2, 9, 4, 5, 6};
const int tmp[] = {1, 0, 0, 0, 0};
const int LED[7][5] = {
  {0,1,1,1,0},
  {1,0,0,0,1},
  {1,0,0,0,1},
  {1,0,0,0,1},
  {1,1,1,1,1},
  {1,0,0,0,1},
  {1,0,0,0,1}
};
void dotMatrix () {
  Serial.println("============================");
  int b = B00000000;

  b |= write(1,  0);
  b |= write(3,  0);
  b |= write(10, 0);
  b |= write(7,  1);
  b |= write(8,  0);

  b |= write(12, 1);
  b |= write(11, 1);
  b |= write(2,  1);
  b |= write(9,  1);
  b |= write(4,  1);
  b |= write(5,  1);
  b |= write(6,  0);
  reg(b);

  // for (int i=0; i<5; i++) {
  //   b |= write(anode[i], tmp[i]);
  //   b |= write(12, 1);
  //   b |= write(11, 1);
  //   b |= write(2,  1);
  //   b |= write(9,  0);
  //   b |= write(4,  1);
  //   b |= write(5,  1);
  //   b |= write(6,  1);
  //   reg(b);
  // }


  
  //Serial.print(b, BIN);
  // digitalWrite(MAT[1], LOW);
  // digitalWrite(MAT[3], HIGH);
  // //digitalWrite(10, LOW);
  // //digitalWrite(7, HIGH);
  // //digitalWrite(8, LOW);

  // //digitalWrite(12, HIGH);
  // //digitalWrite(11, HIGH);
  // digitalWrite(MAT[2], LOW);
  // //digitalWrite(9, HIGH);
  // digitalWrite(MAT[4], HIGH);
  // digitalWrite(MAT[5], LOW);
  // digitalWrite(MAT[6], HIGH);
  
  Serial.println("============================");
}
int write (int n, bool isHi) {
  Serial.println("------------------");
  if (isValue(DIRECT, n)) {
    if (isHi) digitalWrite(MAT[n], HIGH);
    else      digitalWrite(MAT[n], LOW);
    return 0;
  }
  else if (isValue(REGISTER, n)) {
    int tmp;
    if (isHi) tmp = B00100000;
    else       tmp = B00000000;
    Serial.println(n);
    Serial.println(tmp, BIN);
    tmp = tmp >> (n-7);
    // Serial.println(n);
    // Serial.println(tmp, BIN);
    return tmp;
  }
  Serial.println("------------------");
}

void initDotMatrix () {
  for (int i=1; i<7; i++) pinMode(MAT[i], OUTPUT);
  pinMode(REG_SER, OUTPUT);
  pinMode(REG_LATCH, OUTPUT);
  pinMode(REG_CLK, OUTPUT);
  digitalWrite(MAT[1], LOW);
  digitalWrite(MAT[3], LOW);
  digitalWrite(MAT[2], HIGH);
  digitalWrite(MAT[4], HIGH);
  digitalWrite(MAT[5], HIGH);
  digitalWrite(MAT[6], HIGH);
  reg(B00001011);
  
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
/*
2：7　　high
3：8　　high
4：9　　low
5：10　 high
6：11　 low
7：12   low
*/