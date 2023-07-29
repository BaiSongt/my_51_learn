#include "LCD1602/LCD1602.h"
#include "delay.h"

void main()
{
  LCD1602_Init();
  LCD1602_ShowString(1,1,"Hello World!");
  LCD1602_ShowBinNum(2,1,0xA5,8);
  LCD1602_ShowString(1,15,"WelCome to China!");
  while (1)
  {
    LCD1602_WriteCommand(0x18);
    delay(500);
  }
  
}