자리번호 22

라즈베리에서 한글이 깨질 때
sudo apt-get install fonts-unfonts-core -y
sudo apt-get install ibus ibus-hangul -y
sudo reboot

라즈베리에서 python설치
pip install opencv-contrib-python
    ->error가 뜸
    -버전때문이라서 날려버릴거임(sudo rm /usr/lib/python3.11/EXTERNALLY-MANAGED)
sudo apt-get install python3-opencv

스왑 메모리 키우기
sudo vim /et/dphys-swapfile

카메라 테스트하는 파이썬 코드

텔레그램 봇 설치하기
pip install python-telegram-bot 00upgrade
git clone https://github.com/python-telegram-bot/python-telegram-bot
pip install python-telegram-bot[job-queue] --pre

파일을 받을 수 있다ls로 확인하면 텔레그램파일이 있을것이다
cd python-telegram-bot/

examples파일로 들어간다
cd examples/

timerbot에서 내 토큰으로 바꾼다
vim timerbot.py로 들어가서
application = Application.builder().token(여기에 토큰 적기).build()

python timerbot.py로 실행 

텔레그램에서 내가 만든 봇으로 들어가서
/start
/set 10

을 치면 Beep 문자가 오고 10초마다 사진이 찍혀서 올라온다


