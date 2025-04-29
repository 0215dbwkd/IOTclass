Raspberry Pi

터미널에서
sudu apt install vim -v

mkdir 학번으로 폴더 만들었다
cd 사용해서 학번파일로 들어간다

vim test.py 들어간다  i를 눌러  insert 모드
print("Hello") 입력하고
esc누르고 :wq로 저장하고 나간다
" 가 @로 나와서 문제가 생김
왼쪽위 라즈베리 모양을 눌러서 Preferences로 들어간다 그리고 키보드 layout에서 모델을 Generic 102-key PC로 하고 us로 바꾸면 문제 해결

python test.py로 실행
