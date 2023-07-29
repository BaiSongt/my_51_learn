#include <reg51.h>
#include "LCD1602.h"

#define LCD1602_RS P2_6 // com
#define LCD1602_RW P2_5 // write
#define LCD1602_E P2_7  // 使能
#define LCD1602_PIN P0  // data_port

void delay1ms()
{
  u8 i, j;
  i = 2;
  j = 239;
  do
  {
    while (--j)
      ;
  } while (--i);
}

void LCD1602_SetCursor(u8 line, u8 colum)
{
  if (line == 1)
  {
    LCD1602_WriteCommand(0x80 | (colum - 1));
  }
  else
  {
    LCD1602_WriteCommand(0x80 | (colum - 1) + 0x40);
  }
}

void LCD1602_WriteCommand(u8 com)
{
  LCD1602_RS = 0;
  LCD1602_RW = 0;
  LCD1602_PIN = com;
  LCD1602_E = 1;
  delay1ms();
  LCD1602_E = 0;
  delay1ms();
}

void LCD1602_WriteData(u8 data)
{
  LCD1602_RS = 1;
  LCD1602_RW = 0;
  LCD1602_PIN = data;
  LCD1602_E = 1;
  delay1ms();
  LCD1602_E = 0;
  delay1ms();
}

void LCD1602_Init()
{
  LCD1602_WriteCommand(0x38);
  LCD1602_WriteCommand(0x0C);
  LCD1602_WriteCommand(0x06);
  LCD1602_WriteCommand(0x01);
}

void LCD1602_ShowChar(u8 line, u8 colum, unsigned char _char)
{
  LCD1602_SetCursor(line, colum);
  LCD1602_WriteData(_char);
}
void LCD1602_ShowString(u8 line, u8 colum, u8 *_str)
{
  LCD1602_SetCursor(line, colum);
  for (; *_str != '\0'; _str++)
  {
    LCD1602_WriteData(*_str);
  }
}

u16 pow(u16 x, u16 y)
{
  u16 res = 1;
  for (u8 i = 0; i < y; ++i)
  {
    res = res * x;
  }
  return res;
}

void LCD1602_ShowNum(u8 line, u8 colum, u16 _num, u8 length)
{
  LCD1602_SetCursor(line, colum);
  for (u8 i = length; i > 0; --i)
  {
    LCD1602_WriteData((_num / (pow(10, i - 1))) % 10 + '0');
  }
}

void LCD1602_ShowSignedNum(u8 line, u8 colum, int _num, u8 length)
{
  int number = 0;
  LCD1602_SetCursor(line, colum);
  if (_num >= 0)
  {
    LCD1602_WriteData('+');
    number = _num;
  }
  else
  {
    LCD1602_WriteData('-');
    number = -_num;
  }

  for (u8 i = length; i > 0; --i)
  {
    LCD1602_WriteData((number / (pow(10, i - 1))) % 10 + '0');
  }
}

void LCD1602_ShowHexNum(u8 line, u8 colum, u16 _num, u8 length)
{
  LCD1602_SetCursor(line, colum);
  u8 singleNumber;
  for (u8 i = length; i > 0; --i)
  {
    singleNumber = (_num / (pow(16, i - 1))) % 16;
    if (singleNumber < 10)
    {
      LCD1602_WriteData(singleNumber + '0');
    }
    else
    {
      LCD1602_WriteData(singleNumber + 'A' - 10);
    }
  }
}
void LCD1602_ShowBinNum(u8 line, u8 colum, u16 _num, u8 length)
{
  LCD1602_SetCursor(line, colum);
  u8 singleNumber;
  for (u8 i = length; i > 0; --i)
  {
    singleNumber = (_num / (pow(2, i - 1))) % 2;
    if (singleNumber < 2)
    {
      LCD1602_WriteData(singleNumber + '0');
    }
    else
    {
      LCD1602_WriteData(singleNumber + 'A' - 10);
    }
  }
}
