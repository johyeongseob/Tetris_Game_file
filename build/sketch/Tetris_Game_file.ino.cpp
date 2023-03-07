#include <Arduino.h>
#line 1 "C:\\Users\\coolt\\Desktop\\github\\Tetris_Game_file\\Tetris_Game_file\\Tetris_Game_file.ino"
/* 
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
  Tetris_Game.ino

ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ 
*/ 

#include <LedControl.h>

#define Tetro_size 4                                  // tetromino's Size is 4x4
#define Tetro_type 7                                  // Seven distinct one-sided tetrominoes

LedControl lc =LedControl(12,11,10,4);                // dot_matrix: MAX 7219 DataIN=Pin12, CLK=pin11, CS=Pin10, number of dirver_modules=4

// Joy_stick: BB-PSJ SW=Pin8, X-A=A1, Y-A=A0
const int Y_value  = A1;
const int X_value = A0;
int num=0;


// Tetrominoes: I, J, L, O, S, T, Z
int Tetro[Tetro_type][Tetro_size][Tetro_size] = 
{
  {  // I Shape
    {1,0,0},
    {1,0,0},
    {1,0,0},
    {1,0,0}, 
  },  
  {  // J Shape
    {0,1,0},
    {0,1,0},
    {1,1,0},  
  },
  {  // L Shape
    {1,0,0},
    {1,0,0},
    {1,1,0},
  },
  {  // O Shape
    {1,1,0},
    {1,1,0},
    {0,0,0},
  },
  {  // S Shape
    {0,1,1},
    {1,1,0},
    {0,0,0},
  },       
  {  // T Shape
    {0,0,0},
    {1,1,1},
    {0,1,0},
  },
  {  // Z Shape
    {1,1,0},
    {0,1,1},
    {0,0,0},
  }
};


#line 63 "C:\\Users\\coolt\\Desktop\\github\\Tetris_Game_file\\Tetris_Game_file\\Tetris_Game_file.ino"
void setup();
#line 73 "C:\\Users\\coolt\\Desktop\\github\\Tetris_Game_file\\Tetris_Game_file\\Tetris_Game_file.ino"
void loop();
#line 94 "C:\\Users\\coolt\\Desktop\\github\\Tetris_Game_file\\Tetris_Game_file\\Tetris_Game_file.ino"
void ledSetup();
#line 63 "C:\\Users\\coolt\\Desktop\\github\\Tetris_Game_file\\Tetris_Game_file\\Tetris_Game_file.ino"
void setup()
{
  ledSetup();
  Serial.begin(9600);                                                // serial communication using a serial protocol. baud rate = 9600.
  pinMode(8, INPUT_PULLUP);       /* Z축 스위치에 별도의 저항이 달려있지 않기 때문에 스위치가 눌린지 안눌린지 헷깔려하는 `플로팅 현상`이 발생.
                                     이때문에 사용자가 쉽게 플로팅현상을 해결하기 위해서 아두이노에는 기본적으로 내부에 풀업저항이 달려있습니다.
                                     플로팅현상을 해결하기 위해서 내부 PULLUP 코드를 사용 하였습니다.*/
}


void loop()
{ 
  int addr, row; byte value =B11111111;                        
    for (row = 0; row < 8; row++) {
      if (analogRead(X_value) < 200){lc.setRow(1, row, value);}      // Test dot_matrix & joy_stick
      if (analogRead(X_value) > 800){lc.setRow(2, row, value);}
      if (analogRead(Y_value) < 200){lc.setRow(0, row, value);}
      if (analogRead(Y_value) > 800){lc.setRow(3, row, value);}
    }
  
  Serial.print(analogRead(X_value));                                 // Print X value
  Serial.print("  ");           
  Serial.print(analogRead(Y_value));                                 // Print Y value
  Serial.print("  ");           
  Serial.println(digitalRead(8));                                    // Print Z value(switch)
  delay (500);
  for(num=0; num<4; num++) {lc.clearDisplay(num);}
  }



void ledSetup()                                                      // dot_matrix setup function
{
 for(num=0; num<4; num++)
  {
   lc.shutdown(num, false);                                          // power-saving mode: off in 0~3
   lc.setIntensity(num,8);                                           // bright of matrix: set 8 in 0~15
   lc.clearDisplay(num);                                             // window initialization
  }
}

