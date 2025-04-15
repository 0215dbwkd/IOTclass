
void setup() {
  Serial.begin(115200);
  Serial.println();  // put your setup code here, to run once:
}

void loop() {
  static unsigned long loopCnt = 0;  // put your main code here, to run repeatedly:
  static unsigned long nextMil = millis() + 1000;

  loopCnt++; 
  
  if(millis() > nextMil){
    nextMil = millis() + 1000;
    Serial.println(loopCnt);
    loopCnt = 0;
  }
}
