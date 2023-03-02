# 1 "C:\\Users\\coolt\\Desktop\\github\\Tetris_Game_file\\Tetris_Game_file\\Tetris_Game_file.ino"
# 2 "C:\\Users\\coolt\\Desktop\\github\\Tetris_Game_file\\Tetris_Game_file\\Tetris_Game_file.ino" 2

LedControl lc =LedControl(12,11,10,4);
int num;

void setup()
{
 for(num=0; num<4; num++) // 매트릭스 0번부터 3번까지 세팅
  {
   lc.shutdown(num,false); // 0~3번까지 매트릭스 절전모드 해제
   lc.setIntensity(num,8); // 매트릭스의 밝기 선언 0~15의 수
   lc.clearDisplay(num); // 매트릭스 led를 초기화
  }
}

// matrix 함수 선언
void matrix()
{
  // 한글 '매'를 이진수로 배열 선언
   byte m[8]={
             5,
             5,
             245,
             151,
             149,
             245,
             5,
             5
             };
  // 한글 '트'를 이진수로 배열 선언
 byte t[8]={
            60,
            32,
            60,
            32,
            60,
            0,
            126,
            0
            };


 // 한글 '릭'를 이진수로 배열 선언
 byte r[8]={
            122,
            10,
            122,
            66,
            122,
            0,
            62,
            2
           };
  // 한글 '스'를 이진수로 배열 선언
 byte x[8]={
            0,
            8,
            20,
            34,
            65,
            0,
            127,
            0
            };

 // lc.setRow 함수는 행(Row) 기준으로 도트매트릭스를 제어 lc.setRow(matrix_number,Row,value)
 for(int j=0; j<8; j++)
 {
   lc.setRow(3,j,m[j]); // 0번째 매트릭스에서 '매'출력
   lc.setRow(2,j,t[j]); // 1번째 매트릭스에서 '트'출력
   lc.setRow(1,j,r[j]); // 2번째 매트릭스에서 '릭'출력
   lc.setRow(0,j,x[j]); // 3번째 매트릭스에서 '스'출력
 }
 delay(1000);
}

void loop() {
  matrix();
  for(num=0; num<4; num++) // 4개의 매트릭스led 초기화
 {
  lc.clearDisplay(num);
 }
 delay(1000);
}
