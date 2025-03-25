NCD 제어
I2C 통신의 구조를 알아보고 사용해본다

통신 프로토콜
하드웨어끼리 통신하는 걸 배우는거임
메시지, 대화를 하는데 사용되는 규칙

I2C = I스퀘어C
연결된, 집적회로

Serial Data   A는 그냥 A,B,C .. 임

하나의 관리자가 여러개의 센서를 가질 수 있음
실제로 사용은 112개 정도이다 15개가 예약되어서 

UART 1:1 통신이다 할려면 2개 정도 장치를 가능
I2C는 여러개 가능, 마스터는 하나만

I2C의 통신은 SDA, SCL에 마스터랑 슬레이브가 연결 되어 있음
LOW(0)만 유지한다
풀업 저항을다는 이유가 저 친구들을 high로 유지하려고
반드시 풀업 저항이 필요하다.

데이터 선이 LOW로 내려가면 시작이고 HIGH로 올라간 순간 스탑이다
한 바이트씩 끊고 에코보냄
최상위 비트틀 먼저 

A4 가 데이터 A5가 클럭 선

LCD 이름이 1602(16*2)

데이터 상태(SDA)가 low이면 ACK, HIGH이면 NACK이다.
A4 -> SDA
A5 -> SCL


LCD 아두이노 코드

#include <Wire.h> // I2C 총신을 위한 기본 라이브러리
#include <LiquidCrystal_I2C.h> // I2C LCD 라이브러리

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  lcd.init();				// I2C LCD 초기화
  lcd.backlight();			// 백라이트 켜기
  lcd.print("LCD init");
  delay (2000);
  lcd.clear();
}

void loop()
{
  lcd.setCursor(16,0);
  lcd.print("Hello, World!");
  
  for (int position = 0; position < 16; position++) {
    lcd.scrollDisplayLeft();
    delay(150);
  }
}



아두이노 1602 LCS I2C 주소 찾기
#include <Wire.h> // I2C 통신을 위한 라이브러리

void setup() {
  Serial.begin(9600); // 시리얼 모니터 시작 (속도 : 9600 baud)
  Wire.begin();       // I2C 통신 시작
  Serial.println("I2C Scanner Running..."); // 시작 메시지 출력
}

void loop() {
  Serial.println("Scanning..."); // 검색 시작 메시지 출력

  for (byte address = 1; address < 127; address++) { // I2C 주소 범위 : 0x01 ~ 0x7F (1~127)
    Wire.beginTransmission(address);                 // 특정 주소로 통신 시작
    if (Wire.endTransmission() == 0) {               // 응답이 0이면 I2C 장치가 존재함
      Serial.print("I2C 장치 발견: 0x");             // 발견된 장치 주소 출력
      Serial.println(address, HEX);                  // 16진수(HEX) 형식으로 출력
      delay(500);                                    // 0.5초 대기 (너무 빠르게 반복되지 않도록)
    }
  }

  Serial.println("Scan Complete! Retrying in 5 seconds...\n");
  delay(5000); // 5초 후 다시 검색
}


https://github.com/johnrickman/LiquidCrystal_I2C -> code -> Download zip -> 문서에 Arduino에 libraries 에 압축풀기

아두이노에서  위에 SKetch 에 include Library에  LiquidCrystal_I2C 클릭
