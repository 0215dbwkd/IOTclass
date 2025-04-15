int a1 = 2;
int a2 = 3;
int a3;

void setup() {
  Serial.begin(115200);
  Serial.println();

  // 아래 a1, a2, a3는 인수(argument)임
  sum(a1, a2, a3);
  Serial.println(a3);
}

void loop(){
}

//아래 a,b,c는 매개 변수(parameter)dla
void sum(int a, int b, int& c){ // & 주소값을 받음
  c = a + b;
}
