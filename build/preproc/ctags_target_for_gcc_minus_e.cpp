# 1 "C:\\Users\\coolt\\Desktop\\github\\Tetris_Game_file\\Tetris_Game_file\\Tetris_Game_file.ino"
/*

아두이노 연결 순서



도트 매트릭스

DIN=Pin12, CS=Pin10, CLK=pin11, VCC=5V, GND=GND



조이스틱

SW=Pin8, X-A=Analog Pin1, Y-A=Analog Pin0, VCC=5V, GND=GND

*/
# 11 "C:\\Users\\coolt\\Desktop\\github\\Tetris_Game_file\\Tetris_Game_file\\Tetris_Game_file.ino"
# 12 "C:\\Users\\coolt\\Desktop\\github\\Tetris_Game_file\\Tetris_Game_file\\Tetris_Game_file.ino" 2

LedControl lc =LedControl(12,11,10,4);
int num;

void setup() // 보드의 특정 핀 기능 설정, 시리얼 통신 속도 등 기본적인 설정을 하는 부분
{
 for(num=0; num<4; num++) // 매트릭스 0번부터 3번까지 세팅
  {
   lc.shutdown(num,false); // 0~3번까지 매트릭스 절전모드 해제
   lc.setIntensity(num,8); // 매트릭스의 밝기 선언 0~15의 수
   lc.clearDisplay(num); // 매트릭스 led를 초기화
  }
  Serial.begin(9600); // 시리얼 통신을 하기위한 통신속도 설정
  pinMode(8, 0x2); /* Z축 스위치에 별도의 저항이 달려있지 않기 때문에 스위치가 눌린지 안눌린지 헷깔려하는 `플로팅 현상`이 발생.

                                 이때문에 사용자가 쉽게 플로팅현상을 해결하기 위해서 아두이노에는 기본적으로 내부에 풀업저항이 달려있습니다.

                                 플로팅현상을 해결하기 위해서 내부 PULLUP 코드를 사용 하였습니다.*/
# 28 "C:\\Users\\coolt\\Desktop\\github\\Tetris_Game_file\\Tetris_Game_file\\Tetris_Game_file.ino"
}

// matrix 함수 선언
void matrix()
{ byte m[8]={5, 5, 245, 151, 149, 245, 5, 5}; // 한글 '매'를 이진수로 배열 선언
  byte t[8]={60, 32, 60, 32, 60, 0, 126, 0}; // 한글 '트'를 이진수로 배열 선언
  byte r[8]={122, 10, 122, 66, 122, 0, 62, 2}; // 한글 '릭'를 이진수로 배열 선언
  byte x[8]={0, 8, 20, 34, 65, 0, 127, 0}; // 한글 '스'를 이진수로 배열 선언

 // lc.setRow 함수는 행(Row) 기준으로 도트매트릭스를 제어 lc.setRow(matrix_number,Row,value)
 for(int j=0; j<8; j++)
 {
  if (analogRead(A1) < 200){lc.setRow(3,j,m[j]);}
  if (analogRead(A1) > 800){lc.setRow(2,j,t[j]);}
  if (analogRead(A0) < 200){lc.setRow(1,j,r[j]);}
  if (analogRead(A0) > 800){lc.setRow(0,j,x[j]);}
  //  lc.setRow(3,j,m[j]);     // 3번째 매트릭스에서 '매'출력
  //  lc.setRow(2,j,t[j]);     // 2번째 매트릭스에서 '트'출력
  //  lc.setRow(1,j,r[j]);     // 1번째 매트릭스에서 '릭'출력
  //  lc.setRow(0,j,x[j]);     // 0번째 매트릭스에서 '스'출력
 }
 delay(50);
}

void loop() {
  matrix();
  for(num=0; num<4; num++) // 4개의 매트릭스led 초기화
 {
  lc.clearDisplay(num);
 }

  Serial.print(analogRead(A1)); // X축 값이 표기됩니다.
  Serial.print("  "); // 중간에 공백칸을 두었습니다.
  Serial.print(analogRead(A0)); // X축 값이 표기됩니다.
  Serial.print("  ");
  Serial.println(digitalRead(8)); // Z축(스위치) 값이 표기됩니다.
}
