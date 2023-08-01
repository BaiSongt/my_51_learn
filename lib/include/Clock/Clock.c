#include "Clock/Clock.h"

#include <reg51.h>

void Clock(u8 sec, u8 min, u8 hour)
{
  if (sec == 10)
  {
    sec = 0;
    min += 1;
  }
  if (min == 10)
  {
    sec = 0;
    min = 0;
    hour += 1;
  }
  LCD1602_ShowNum(2, 7, sec, 2);
  LCD1602_ShowNum(2, 4, min, 2);
  LCD1602_ShowNum(2, 1, hour, 2);
  LCD1602_ShowChar(2, 3, ':');
  LCD1602_ShowChar(2, 6, ':');
}

void Clock_current(u8 sec, u8 min, u8 hour)
{
  LCD1602_ShowNum(2, 7, sec, 2);
  LCD1602_ShowChar(2, 3, ':');
  LCD1602_ShowChar(2, 6, ':');
  LCD1602_ShowNum(2, 4, min, 2);
  LCD1602_ShowNum(2, 1, hour, 2);
}

void Key1ResetClock(u8 sec, u8 min, u8 hour)
{
  if (KEY_1 == 0)
  {
    delay1ms();
    while (KEY_1 == 0)
      ;
    delay1ms();
    LCD1602_ShowString(1, 8, "Reset");

    sec = 0;
    min = 0;
    hour = 0;
    Key3PuaseClock(sec, min, hour);
  }
}

void Key2StartClock(u8 sec, u8 min, u8 hour)
{
  if (KEY_2 == 0)
  {
    delay1ms();
    while (KEY_2 == 0)
      ;
    delay1ms();
    LCD1602_ShowString(1, 8, "Start");
    while (1)
    {
      Clock(sec, min, hour);
    }
  }
}

void Key3PuaseClock(u8 sec, u8 min, u8 hour)
{
  u8 current_sec;
  u8 current_min;
  u8 current_hour;
  if (KEY_3 == 0)
  {
    delay1ms();
    while (KEY_3 == 0)
      ;
    delay1ms();
    current_sec = sec;
    current_min = min;
    current_hour = hour;

    LCD1602_ShowString(1, 8, "Pause");
    Clock_current(current_sec, current_min, current_hour);
  }
}