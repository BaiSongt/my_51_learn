#include <reg51.h>
#include "delay.h"
#include "Key.h"
#include "LED/LED.h"

u8 local = 0;
void KEY1_LED_1()
{
  if (KEY_1 == 0)
  {
    LED_1 = 0;
  }
  else
  {
    LED_1 = 1;
    ;
  }
}

void KEY2_LED_PIN()
{
  if (KEY_2 == 0) // 按键按下
  {
    delay10us(20);
    while (KEY_2 == 0)
      ; // 按键按下
    delay10us(20);
    LED_PIN = ~LED_PIN; // 状态取反
  }
}

/**
 * @brief KEY_3 控制LED 显示二进制
 */
void KEY3_show_LED_bin()
{
  u8 LEDnum = 0;
  while (1)
  {
    if (KEY_3 == 0)
    {
      delay10us(20);
      while (KEY_3 == 0)
        ;
      delay10us(20);
      LEDnum++;
      LED_PIN = LEDnum;
    }
  }
}

/**
 * @brief 按一下KEY1 左移LED
 */
void KEY1_left_move_led()
{
  if (KEY_1 == 0)
  {
    delay10us(20);
    while (KEY_1 == 0)
      ;
    delay10us(20);
    // u8 越界检查
    if (local == 0)
    {
      local = 7;
    }
    else
    {
      local--;
    }
    // 0000 0001 << 2   0000 0100  取反 1111 1011
    // 0000 0001 << 1   0000 0010  取反 1111 1101
    LED_PIN = ~(0x01 << local);
  }
}

/**
 * @brief 按一下KEY4 右移LED
 */
void KEY4_right_move_led()
{
  if (KEY_4 == 0)
  {
    delay10us(20);
    while (KEY_4 == 0)
      ;
    delay10us(20);
    local++;
    if (local >= 8)
    {
      local = 0;
    }
    // 0000 0001 << 1   0000 0010  取反 1111 1101
    // 0000 0001 << 2   0000 0100  取反 1111 1011
    LED_PIN = ~(0x01 << local);
  }
}