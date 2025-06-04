## 목차
  - Wi-Fi
```
- MAC service set, MAC data frame
- CSMA/CA 동작 방식
```
  - ZigBee
```
- ZigBee 물리 계층
- MAC 계층 슈퍼프레임
- 분산 주소 할당 기법의 이해 및 응용 연습
    * C(skip){d}
- 지그비 라우팅 기법 (트리, 메쉬)
```

## Wi-Fi
  - IEEE 표준에 따른 비교
```
IEEE(Institute of Electrical and Electronics Engineers)는 전기, 전자공학, 컴퓨터 공학, 정보 기술 등 다양한 공학 분야에서 세계 최대의 전문가 단체입니다.
IEEE는 기술 혁신을 촉진하고, 표준을 개발하며, 회원들에게 전문 교육, 네트워킹, 연구 발표 기회를 제공합니다.
```
  - Wi-Fi 구성
```
-IEEE 802.11 Working Group에서 표준화 작업
-AP (Access Point)와 station (STA)으로 구성
    * AP : 유무선 공유기
    * STA: 노트북, 스마트폰 등
```
- Wi-Fi Service Set
```
- BSS(Basic Service Set)
    * AP가 없으면 ad hoc 모드
    * AP가 있으면 infrastructure 모드
- ESS(Extended Service Set)
    * 두 개 이상의 BSS들이 모여서 구성
------------------------------------------------
ESS : Extended service set
BSS : Basic service set
AP  : Access point
------------------------------------------------

Distribution system ---- sever or Gateway
-AP - BSS 
-AP - BSS 
-AP - BSS 
```
- MAC 방식
```
- PCF(Point coordination function)
    * Option
    * 중앙집중식 Polling 방식 사용
- DCF(Distributed coordination function)
    * CSMA/CA 사용. Station에서 사용
```
- MAC Data Frame
- 주소 체계

## MAC 계층 - 채널 접근 방식
- CSMA-CA
```
- Carrier sense Multiple Access with Collision Avoidance
- CS (Caarrier Sense : 네트워크가 현재 사용 중인지 알아냄
- MA (Multiple Access) : 네트워크가 비어있으면 누구든 사용 가능
- CA (Collision Avoidance) : 충돌 회피
```
- Hidden Terminal Problem (숨겨진 노드 문제)
```
- 중간 터미널(A)는 양쪽 터미널(B,C)와 통신이 가능
- 양쪽 터미널(B,C)는 서로의 통신을 감지하지 못함
    * 신호 전송 범위가 달라서 서로의 존재를 알 수가 없음
    * 즉,  Carrier Sening이 힘듦 <- *RTS, CTS 를 사용하는 이유*
-----------------------------------------------------------
Range of B              Range of C

            B -> A <- C
a. Stations B and C are not in each other's range
------------------------------------------------------------
```
- 일반적인 CSMA-CA 동작 방식 (무선 랜 등에서 사용)
```
- *경합 방식* : 채널을 사용하고자 하는 기기들끼리 경쟁
- 1. 기기 A는 다른 기기가 데이터를 송신중인지 감지
- 2. 만약 송신 중이면 대기한다. (이를 *백오프(backoff) 한다고 함)
- 3. 송신 시작까지의 시간은 랜덤 한 시간이 할당된다.
- 4. 기다린 후, 다시 반송파 감지를 해서 다른 반송파가 있는지 확인
- 5. 데이터 전송을 시작한다
    * 단계 1 : 송신 단 -> 수신 단 : RTS(Request To Send)
    * 단계 2 : 수신 단 -> 송신 단 : CTS(Clear To Send)
    * 단계 3 : 송신 단 -> 수신 단 : Data 전송
    * 단계 4 : 수신 단 -> 송신 단 : ACK(ACKnowledgement)
```
- RTS-CTS-DATA-ACK 방식 (일반적 CSMA-CA)
```
- 송신 측에서 RTS 전송 후, 수신 측에서 CTS 전송
- 송신 측에서 CTS를 전송 받지 못하면, 일정 시간 대기 후, RTS를 다시 전송


        송신 측(Sender) O ----------> O 수신 측 (Receiver)
                              RTS
                        <-----------
                              CTS
                         ------------>
                             DATA
                         <-----------
                              ACK
Sender    | RTS |            |             DATA             |
Receiver           | CTS |                                      | ACK |
```
## 참고 : CSMA-CD
- CSMA-CD (Collision Detection)
```
- 이더넷 (Ethernet)에 쓰이는 채널 접근 방식
- 송신 중 충돌이 감지(detection)되면, 전송을 중지하고 
  랜덤한 시간 동안 기다리고 (백오프), 다시 전송 시도
- 유선에서는 구현이 쉬우나, 무선에서는 어려움
    * Why? : 유선에서는 송신 중에, 수신기를 켜 둘 수 있으나,
                 무선에서는 송신 중, 수신기를 켜두기 어렵다.
```
- CSMA-CA의 CSMA-CD와 비교한 장단점
```
- 장점 : 저 가격으로 구현
- 단점 : 데이터 전송이 많이 지연될 수 있음
    * (전송 빈도가 높아지면, 충돌 방지 신호의 전송 속도가 느려짐)
```
## ZigBee 스택
- 스택
```
- 프로토콜, 소프트웨어 관한 집합체라 볼 수 있음
```
- 지그비 스택
```
- 지그비에서 정의한 프로토콜 들의 구현
![image](https://github.com/user-attachments/assets/654e774c-7107-411c-961f-2c967d46d141)
```
