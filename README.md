# my_51_learn
## 1、点亮一个LED
根据单片机原理图，LED 连接 P2 端口<br>
P2 端口地址为 0xA0 -> 0xA7 <br>
```c++
/* LED in 51 
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
```
- 函数:点亮LED_01<br>
`void LED_01_ON();`
- 函数:点亮第n个LED<br>
`coid LED_ON(u8 LED_num);`
- 函数:循环LED 1——>8<br>
`LED_circle();`
