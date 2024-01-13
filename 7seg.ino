AE7SEGGPIO ae7seg(SEG_LATCH, SEG_SDI, SEG_SCK);
int count = 0;
void seg() {
  ae7seg.beginWrite();
  ae7seg.writeNumber(count);
  ae7seg.endWrite();
  count = (++count)%10;
}