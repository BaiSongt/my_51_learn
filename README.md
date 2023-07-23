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

## 2、独立按键

独立按键连接P3的0-3口达到按键通断的输入，以控制P2口的LED. <br>

```c++
/**
 * KEY in 51 
 * KEY order
 * D     K1    K2    K3    K4    
 * P3    P3_1  P3_0  P3_2  P3_3
 * 
 * P2 in 51
 * __sbit __at (0xB0) P3_0 ;
 * __sbit __at (0xB1) P3_1 ;
 * __sbit __at (0xB2) P3_2 ;
 * __sbit __at (0xB3) P3_3 ;
 * 
 * 默认高电平 1111 1111 = 0xFF
 * 点亮则拉低 1111 1110 = 0xFE
 * 
 * 按下点亮
 * 松手熄灭
 */
```
- `function` 独立按键控制第n个 LED <br>
  `void KEY_LED_n();`
- `function`  KEY_2 控制所有LED 按一下开，按一下关<br>
`void KEY2_LED_PIN();`
- `function`  KEY_3 控制LED 显示二进制 <br>
`void KEY3_show_LED_bin();`
- `function`  按一下KEY4 右移LED <br>
`void KEY4_right_move_led();`
- `function`  按一下KEY1 左移LED <br>
`void KEY1_left_move_led();`


