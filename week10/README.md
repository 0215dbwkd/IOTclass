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
import cv2
import sys
import time

cap = cv2.VideoCapture(0)
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
if not cap.isOpened():
  print("camera open error")
  exit()

while true:
  ret, image=cap.read()
  if not ret:
    print("frame read error")
    break
  cv2.imshow('CAMERA', image)
  if cv2.waitKey(1) & 0xFF == ord('q'):
    break

#  if cv2.waitKey(30)>0:
#    break
  time.sleep(10)
  cv2.imwrite("image.jpg",image)

cap.release()
cv2.destroyAllWindows()
  
