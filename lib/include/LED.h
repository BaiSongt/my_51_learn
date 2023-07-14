#ifndef __LED_H__
#define __LED_H__

#include <reg51.h>

typedef unsigned char u8;
typedef unsigned int u16;


/**
 * LED in 51 
 * LED order
 * D     1     2     3     4    5     6     7     8
 * P2    P2_0  P2_1  P2_2  P2_3 P2_4  P2_5  P2_6  P2_7
 * 
 * P2 in 51
 *  __sbit __at (0xA0) P2_0 ;
 *  __sbit __at (0xA1) P2_1 ;
 *  __sbit __at (0xA2) P2_2 ;
 *  __sbit __at (0xA3) P2_3 ;
 *  __sbit __at (0xA4) P2_4 ;
 *  __sbit __at (0xA5) P2_5 ;
 *  __sbit __at (0xA6) P2_6 ;
 *  __sbit __at (0xA7) P2_7 ;
 * 
 * order    8   ->  1
 * 默认高电平 1111 1111 = 0xFF
 * 点亮则拉低 1111 1110 = 0xFE
 */

#define LED_PIN P2
#define LED_1 P2_0
#define LED_2 P2_1
#define LED_3 P2_2
#define LED_4 P2_3
#define LED_5 P2_4
#define LED_6 P2_5
#define LED_7 P2_6
#define LED_8 P2_7

void LED_01_ON();

void LED_ON(u8 LED_num);


#endif
