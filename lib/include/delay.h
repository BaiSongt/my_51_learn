#ifndef __DELAY_H__
#define __DELAY_H__

typedef unsigned int u16;
typedef unsigned char u8;

/**
 * @brief 延时10us time=1时大约延时1us
 * @param time_ms
 */
void delay10us(u16 time)
{
  while (time--)
  {
    time--;
  }
}

#endif