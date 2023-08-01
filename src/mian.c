#include "Clock/Clock.h"
#include <reg51.h>

volatile u8 sec = 0;
volatile u8 min = 0;
volatile u8 hour = 0;
void main()
{
  timer0_init();
  LCD1602_Init();
  LCD1602_ShowString(1, 1, "Clock:");
  while (1)
  {
    Clock_current(sec, min, hour);
  }
}
void timer0_isr() __interrupt 1 // 定时器0中断服务函数
{
  static unsigned int count = 0; // 计数器，用于计算定时器中断的次数
  TL0 = 0x18;
  TH0 = 0xFC;
  count++;          // 每次定时器中断，计数器加1
  if (count >= 500) // 如果计数器达到500，即0.5秒
  {
    count = 0; // 重置计数器
    sec++;     // 更新秒数
    if (sec >= 10)
    {
      sec = 0;
      min++; // 更新分钟
      if (min >= 10)
      {
        min = 0;
        hour++; // 更新小时
        if (hour >= 14)
        {
          hour = 0;
        }
      }
    }
  }
}