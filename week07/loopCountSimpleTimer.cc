#include <SimpleTimer.h>
SimpleTimer timerCnt; // 재사용이 가능함

unsigned long loopCnt;

void timerCntFunc(){
  Serial.println(loopCnt);
  loopCnt = 0;
}

void setup() {
  Serial.begin(115200);
  Serial.println();

  timerCnt.setInterval(1000,timerCntFunc); //milli-sec,func
}

voidd loop(){
  timerCnt.run();
  loopCnt++; //loopCnt = loopCnt + 1;
}
