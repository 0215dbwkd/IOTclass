NCD 제어
I2C 통신의 구조를 알아보고 사용해본다

통신 프로토콜
하드웨어끼리 통신하는 걸 배우는거임
메시지, 대화를 하는데 사용되는 규칙


I2C = I스퀘어C
연결된, 집적회로

SDA
-> Serial Data   A는 그냥 A,B,C .. 임

하나의 관리자가 여러개의 센서를 가질 수 있음

127개 사용가능
실제로 사용은 112개 정도이다 15개가 예약되어서 

UART 1:1 통신이다 할려면 2개 정도 장치를 가능
I2C는 여러개 가능, 마스터는 하나만

I2C의 통신은 SDA, SCL에 마스터랑 슬레이브가 연결 되어 있음
LOW(0)만 유지한다

풀업 저항을 다는 이유:
high로 유지하기 위해서.

'반드시 풀업 저항이 필요하다.'

데이터 선이 LOW로 내려가면 시작이고 HIGH로 올라간 순간 스탑이다
한 바이트씩 끊고 에코보냄
최상위 비트틀 먼저 

A4 가 데이터 A5가 클럭 선

LCD 이름이 1602(16*2)

데이터 상태(SDA)가 low이면 ACK, HIGH이면 NACK이다.
A4 -> SDA
A5 -> SCL


https://github.com/johnrickman/LiquidCrystal_I2C -> code -> Download zip -> 문서에 Arduino에 libraries 에 압축풀기

아두이노에서  위에 SKetch 에 include Library에  LiquidCrystal_I2C 클릭
