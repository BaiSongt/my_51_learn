#include "Key/MatrixKeys.h"
#include "LCD1602/LCD1602.h"
#include "delay.h"

unsigned char key;

void main()
{
  LCD1602_Init();
  LCD1602_ShowString(1, 3, "Hello World!");
  u8 colum = 0;
  u8 key_old = 0;
  while (1)
  {
    key = Matrix_Keys();
    if (key != 0xFF)
    {
      if (key_old == key)
      {
        LCD1602_ShowChar(2, colum, key);
      }
      else if (colum <= 16)
      {
        colum += 1;
        LCD1602_ShowChar(2, colum, key);
        key_old = key;
      }
      else
      {
        colum = 0;
        LCD1602_Init();
        LCD1602_ShowString(1, 3, "Hello World!");
      }
    }
  }
}