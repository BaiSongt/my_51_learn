#include "MatrixKeys.h"
#include <reg51.h>

// 定义矩阵键盘的行和列数
#define ROWS 4
#define COLS 4
#define MKeys_PIN P1

// 矩阵键盘按键值映射表
unsigned char keymap[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

// 定义矩阵键盘的行和列引脚
#define COL1  P1_3
#define COL2  P1_2
#define COL3  P1_1
#define COL4  P1_0
#define ROW1  P1_7
#define ROW2  P1_6
#define ROW3  P1_5
#define ROW4  P1_4

// 初始化矩阵键盘
void initKeypad()
{
  // 将行引脚设置为为上拉输入
  ROW1 = 1;
  ROW2 = 1;
  ROW3 = 1;
  ROW4 = 1;
  // 将列引脚设置为低电平
  COL1 = 0;
  COL2 = 0;
  COL3 = 0;
  COL4 = 0;
}


unsigned char Matrix_Keys()
{
  unsigned char key = 0xFF; // 初始化按键值为无效值 1111 1111

  ROW1 = 0;
  ROW2 = 1;
  ROW3 = 1;
  ROW4 = 1;
  if(COL1 == 0) {key = keymap[0][0];}
  if(COL2 == 0) {key = keymap[0][1];}
  if(COL3 == 0) {key = keymap[0][2];}
  if(COL4 == 0) {key = keymap[0][3];}

  ROW1 = 1;
  ROW2 = 0;
  ROW3 = 1;
  ROW4 = 1;
  if(COL1 == 0) {key = keymap[1][0];}
  if(COL2 == 0) {key = keymap[1][1];}
  if(COL3 == 0) {key = keymap[1][2];}
  if(COL4 == 0) {key = keymap[1][3];}

  ROW1 = 1;
  ROW2 = 1;
  ROW3 = 0;
  ROW4 = 1;
  if(COL1 == 0) {key = keymap[2][0];}
  if(COL2 == 0) {key = keymap[2][1];}
  if(COL3 == 0) {key = keymap[2][2];}
  if(COL4 == 0) {key = keymap[2][3];}

  ROW1 = 1;
  ROW2 = 1;
  ROW3 = 1;
  ROW4 = 0;
  if(COL1 == 0) {key = keymap[3][0];}
  if(COL2 == 0) {key = keymap[3][1];}
  if(COL3 == 0) {key = keymap[3][2];}
  if(COL4 == 0) {key = keymap[3][3];}

  return key;
}

