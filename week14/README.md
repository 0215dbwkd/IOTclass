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
```
![image](https://github.com/user-attachments/assets/1273d109-ce20-4f0c-9087-a3520b9ab6de)
```
- 주소 체계
```
![image](https://github.com/user-attachments/assets/add23ea0-451f-44d0-a56d-b76609a70d6a)
```
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

### 물리(PHY) 계층
- IEEE 802.15.4 PHY 계층 특징
```
- *무선으로 직접 데이터를 주고 받는 계층*
- *3개의 밴드에 27개의 채널 사용*
- *DSSS (Direct Sequence Spread Spectrum) 사용*
- 빠른 응답지원
    * 조이스틱과 같은 빠른 응답이 필요한 기기도 지원함
- 전력소모를 최소화하는 전력 관리
    * 잠복기 (수면기)에서도 잘 동작
```
- 3개 밴드에 27개의 채널 사용
```
![image](https://github.com/user-attachments/assets/3b38547d-138a-4664-bc91-cc8f25f7cb56)
```
{참고 : 무선 랜과의 충돌}
- 2.4GHz 대역에서 무선 랜과 겹치는 채널있음
```
- Channel 25, 26번은 독자적으로 겹치지 않음
- Channel 15, 20번도 무선 랜의 채널 선택이 권고안대로 되어 있다면 겹치지 않음
- 무선 랜이 사용하지 않는 채널 구간은 사용 가능
![image](https://github.com/user-attachments/assets/b6d5ca60-f015-4470-b2a1-4c301b3706f0)
```
- DSSS (Direct Sequence Spread Spectrum)
```
- 직접 시퀀스 확산 스펙트럼 변조 방식
   * 변조 : 아날로그 (반송파)에 정보를 싣는 과정
              : 정보를 담기 위해 파형의 크기, 주파수, 위상 등을 변형
- 양쪽 모두가 알고 있는 슈도 랜덤(pseudo random) 값인 +1 이나 -1을 데이터에 곱해서 보낸다.
- -> 이 시퀀스는 실제 반복되는 비트보다 훨씬 길이가 길어져서 높은 주파수가 된다. -> 수신 측에서는 신호를 얻기 위해서 슈도 랜덤을 다시 곱하면 된다. (1 X 1 = 1, -1 X -1 = 1)
-*CDMA*에서 사용되는 기술
![image](https://github.com/user-attachments/assets/9e1a7aca-eefb-48a9-802d-f5e2ed62cfb6)
```
## MAC 계층
- MAC 계층 특징
```
- 세 종류의 기기가 정의됨
    * Network Coordinator (NC) : 네트워크 코디네이터
             - 네트워크를 관리함
    * Full Function Device (FFD) : 전기능기기
    * Reduced Function Device (RFD) : 축소기능기기
- MAC의 선택 사양
    * 비콘 없는 (Non-Beacon) 통신
              - Non-slotted CSMA-CA 통신, 수신 패킷 성공을 위해 확인 응답
    * 비콘 (Beacon) 사용 통신
              - Slotted CSMA-CA 통신, 슈퍼 프레임 사용
```
- {MAC 계층 - 지그비 기기}
- 지그비의 CSMA-CA
```
- *RTS, CTS 를 사용하지 않음*
- 비콘 없는 (Non-Beacon) 통신
    * Non-slotted CSMA-CA 통신, 수신 패킷 성공을 위해 확인 응답
- 비콘 (Beacon) 사용 통신
    * Slotted CSMA-CA 통신, 슈퍼 프레임 사용
    * 백오프 하는 시간을 슬롯 단위로 한다.
```
- MAC 계층 특징
```
- 세종류의 기기가 정의됨
    * Network Coordinator (NC) : 네트워크 코디네이터
           - 네트워크를 관리함
    * Full Function Device(FFD) : 축소기능기기
- MAC의 선택 사양
    * 비콘 없는 (Non-Beacon) 통신
          - Non-slotted CSMA-CA 통신, 수신 패킷 성공을 위해 확인 응답
    * 비콘 (Beacon) 사용 통신
          - Slotted SCMA-CA 통신, 슈퍼 프레임 사용
```
- {MAC 계층 - 슈퍼프레임}
- 슈퍼 프레임 (Super Frame) 구조
```
- 최대 16개의 슬롯(Slot)으로 구성
- 슈퍼프레임은 비콘 (Beacon), CAP(Contention Access Period), CFP(Contention Free Period)으로 구성
    * 비활성화 구간이 있을 수 있음
- 슈퍼프레임은 최소 15ms에서 최소 245초 가능
- 항상 비콘으로 시작
    * 비콘은 PAN 코디네이터 (네트워크 코디네이터)가 송신
![image](https://github.com/user-attachments/assets/bec9946f-44ea-41df-85fe-c1d16d04bde1)
```
- CAP, 경쟁 구간
```
- 슬롯 단위의 시간에 맞추어 송수신
```
- CFP, 경쟁 없이 송수신하는 구간
```
- 코디네이터가 슬롯을 예약하여 지그비 기기들이 그 슬롯 시간에 송수신
    * GTS : 예약된 슬롯을 GTS (Guaranteed Time Slot)이라 함
- CFP는 0 ~ 7개의 슬롯까지 할당 가능
```
- Beacon(비콘)
```
- 비콘에 따라 시간 동기화를 하여 슬롯 단위 송수신 가능
- GTS가 어느 기기에 할당되었는지 알려줌
```
- {참고 : 비활성화 구간}
- 비활성화 구간
```
- 지그비 기기의 전력 사용을 적게 하여 기기 수명을 늘리기 위해 비활성화 구간 사용
- 비활성화 구간에서 송수신기를 꺼둔다.
    * 경우에 따라,  Processor의 대부분의 기능을 꺼두는 경우도 있음
```
- {MAC 계층 - 데이터 프레임}
- 데이터 프레임 (Data Frame)
```
- 데이터의 송수긴에 사용
- Frame control 필드 : Frame type, 주소 형식 등 Frame에  관한 정보
- Sequence Number 필드 : Frame의 일렬 번호 -> 전송 확인하기 이해 사용
- Payload 필드 : 실제 Data가 실리는 곳
- Frame check Sequence 필드 : Frame의 error를 check
![image](https://github.com/user-attachments/assets/5cc3cc8c-5c5b-4654-9960-bcd3192e211c)
```
- {MAC 계층 - 주소}
- MAC 주소
``` 
- PAN (Personal Area Network) ID + 주소
- PAN ID : 네트워크 주소, 코디네이터가 할당한 ID
- Address : 2 Byte 또는 8 Byte
    * 2 Byte : 코디네이터가 할당해준 주소
    * 8 Byte : 처음 제작될 때 제작사가 할당해준 주소
      * ++참고 : Byte를 Octet이라고 함
```
- MAC 주소 필드
```
- 주소 또는 PAN ID + 주소로 목적지(Destination)과 근원지(Source)를 표현
```
- MAc 주소 표시 방법
```
- 0/2는 없을 수도 있고, 2 Byte를 쓸 수도 있다는 의미
- 대표적인 쓰임
    * 같은 네트워크 내 : 목적지 주소(2) + 근원지 주소(2) -> 4byte
    * 다른 네트워크 간 : 목적지 PAN ID(2) + 목적지 주소(2)
                                 근원지 PAn ID(2) + 근원지 주소(2) -> 8 byte
    *  다른 네트워크 간에서 코디네이터가 부여한 주소를 사용하지 않을 때: 
           목적지 PAN ID(2) +목적지 주소(8)
            근원지 PAN ID(2) + 근원지 주소(8) -> 20 byte
![image](https://github.com/user-attachments/assets/58887ce0-237f-4fbf-9f30-e8211ea1e5c3)

- 어떤 주소 형식인지, 어떤 것을 (0)으로 하여 사용하지 않는지는, Frame control 필드에 표시된다.
```
- 분산 주소 할당 기법 (Distributed Address Assignment Mechanism)
```
- 16 비트 어드레스 할당 방법
- ZigBee 장치를 가진 노드가 ZigBee 네트워크에 참여할 때 이 노드의 부모 노드가 정해진 식에 따라 부여
- ZigBee 라우터는 모두 자신의 자식 노드에게 주소 할당을 할 수 있음 -> 분산 방식
```
- 중앙 집중 할당 기법과의 비교
```
- 중앙 집중 할당 기법 : 하나의 노드가 모든 네트워크의 기기의 주소를 할당 -> 제어 메시지 (제어 트래픽)이 많이 필요
- 분산 주소 할당 기법의 장점 : *네트워크 상의 트래픽을 줄일 수 있음*
```
- {MAC계층 - ZigBee 주소 할당}
- 분산 할당 식 - 깊이에 따른 주소 할당 크기
```
# C(skip){d} = {1 + C(m) - R(m) - C(m) * R(m)^{L(m)-d-1}}/{1-R(m)}
-----------------------------------------------------------------
* C(m) : 최대 자식의 개수
* L(m) : 네트워크 Tree 의 최대 깊이
* R(m) : 자식으로 가질 수 있는 최대 ZigBee 라우터 개수
* d : 현재 노드의 깊이
* C(skip){d} : 깊이 d 노드가 가질 수 있는 주소의 부분 블록 크기
* n : 어떤 부모 노드를 통해 네트워크에 참여한 노드의 순서
* A(parent) : 부모노드의 주소
* A(n) : n - 번째 엔드 디바이스의 주소
----------------------------------------------------------------
```
- 분산 할당의 예
```
- C(m) = 3, R(m) = 3, L(m) = 3
![image](https://github.com/user-attachments/assets/e69e89dc-b9bf-42b7-a690-342b5126c2c3)
```
