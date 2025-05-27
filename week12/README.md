Cygwin

cd /opt/tinyos-2.x/apps/Blink/ <- 전에 실습했던것

make telosb  

make telosb install.10 하면 use에 저장하는 것

깃허브에서 서브 코드를 가져와 메인코드를 짠다
cd TestLowOneHopSht_sc/ 가져온 파일로 들어간다

TestAppC.nc
Radio가 들어가면 무선으로 소통한다는 이야기다
TestAppC.nc

Test.h
여러줄을 사용할때 열거형인 enum을 사용한다
uint16 ->  unsing int 16bit
1024면 1초 10240 이면 10초이다

TestC.nc파일까지 만들고
Make telosb

