# 1 "C:\\Users\\coolt\\Desktop\\github\\Tetris_Game_file\\Tetris_Game_file\\Tetris_Game_file.ino"
/* 

ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

  Tetris_Game.ino



  Search any function in arduino on the official arduino website.

  Link: https://www.arduino.cc/



ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ 

*/
# 11 "C:\\Users\\coolt\\Desktop\\github\\Tetris_Game_file\\Tetris_Game_file\\Tetris_Game_file.ino"
# 12 "C:\\Users\\coolt\\Desktop\\github\\Tetris_Game_file\\Tetris_Game_file\\Tetris_Game_file.ino" 2




LedControl lc =LedControl(12,11,10,4); // dot_matrix: MAX 7219 DataIN=Pin12, CLK=pin11, CS=Pin10, number of dirver_modules=4

// Joy_stick: BB-PSJ SW=Pin8, X-A=A1, Y-A=A0
const int Y_value = A1;
const int X_value = A0;
int num=0;


// Tetrominoes: I, J, L, O, S, T, Z
int Tetro[7 /* Seven distinct one-sided tetrominoes*/][4 /* tetromino's Size is 4x4*/][4 /* tetromino's Size is 4x4*/] =
{
  { // I Shape
    {1,0,0},
    {1,0,0},
    {1,0,0},
    {1,0,0},
  },
  { // J Shape
    {0,1,0},
    {0,1,0},
    {1,1,0},
  },
  { // L Shape
    {1,0,0},
    {1,0,0},
    {1,1,0},
  },
  { // O Shape
    {1,1,0},
    {1,1,0},
    {0,0,0},
  },
  { // S Shape
    {0,1,1},
    {1,1,0},
    {0,0,0},
  },
  { // T Shape
    {0,0,0},
    {1,1,1},
    {0,1,0},
  },
  { // Z Shape
    {1,1,0},
    {0,1,1},
    {0,0,0},
  }
};

int devices=lc.getDeviceCount();


void setup()
{
  ledSetup();
  Serial.begin(9600); // serial communication using a serial protocol. baud rate = 9600.
  pinMode(8, 0x2); // adds built-in resistance to the electrical circuit.
  randomSeed(analogRead(0)); // initializes the pseudo-random number generator

}


void loop()
{
  int addr, row; byte value =255;
    for (row = 0; row < 8; row++) {
      if (analogRead(X_value) < 200){lc.setRow(1, row, value);} // Test dot_matrix & joy_stick
      if (analogRead(X_value) > 800){lc.setRow(2, row, value);}
      if (analogRead(Y_value) < 200){lc.setRow(0, row, value);}
      if (analogRead(Y_value) > 800){lc.setRow(3, row, value);}
    }

  Serial.print(analogRead(X_value)); // Print X value
  Serial.print("  ");
  Serial.print(analogRead(Y_value)); // Print Y value
  Serial.print("  ");
  Serial.println(digitalRead(8)); // Print Z value(switch)
  Serial.print("  ");
  Serial.println(devices);
  delay (500);
  for(num=0; num<4; num++) {lc.clearDisplay(num);}
  }



void ledSetup() // dot_matrix setup function
{
 for(num=0; num<4; num++)
  {
   lc.shutdown(num, false); // power-saving mode: off in 0~3
   lc.setIntensity(num,8); // bright of matrix: set 8 in 0~15
   lc.clearDisplay(num); // window initialization
  }
}
