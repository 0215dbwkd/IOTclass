미세먼지 센서
아두이노 프로글매 코드

int Vo = A0;
int V_led = 12;

float Vo_value = 0;
float Voltage = 10;
float dustDensity = 0;

void setup() {
  Serial.begin(9600);
  pinMode(V_led, OUTPUT);  
  pinMode(Vo, INPUT);
}

void loop() {
  digitalWrite(V_led, LOW); 
  delayMicroseconds(280);
  
  Vo_value = analogRead(Vo);
  delayMicroseconds(40);
  
  digitalWrite(V_led, HIGH); 
  delayMicroseconds(9600);  

  // Voltage = Vo_value * 5.0 / 1023.0;
  // dustDensity = (Voltage - 0.5) / 0.005; 환원식 안씀

  // Serial.println("dust=");
  Serial.println(Vo_value);
  
  delay(1000);
}
