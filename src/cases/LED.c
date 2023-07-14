#include <LED.h>
#include <delay.h>


/**
 * @brief 点亮第一个LED
 */
void LED_01_ON()
{
     LED_1 = 0;
}

/**
 * @brief 设置LED 1-8 单个灯亮
 * @param LED_num
 */
void LED_ON(unsigned char LED_num)
{
     LED_PIN = 0xFF << LED_num;
}

/**
 * @brief LED 流水灯
 */
void LED_circle()
{
     for (u8 i = 1; i <= 8; ++i)
     {
          LED_ON(i);
          delay10us(10E6);
     }
}