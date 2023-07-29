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
独立按键一侧接地，为低电平，另外一侧为高电平 <br>
按键接通，高电平转为低电平，key_n 1 -> 0 <br>
即 当按键电平为 0 时，按键按下，线路接通 <br>

```c++
/**
 * KEY in 51 
 * KEY order
 * D     K1    K2    K3    K4    
 * P3    P3_1  P3_0  P3_2  P3_3
 * 
 * P3 in 51
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

## 3、数码管
数码管有共阴极连接，共阳极连接 <br>
引脚定义： 数码管显示一个数字8，加上一个小数点 一共8个LED 通过一个八位二进制正好控制一个数字 <br>
多个数码管，会共用引脚，四个数码管一组，8个针脚控制显示，4个针脚控制显示位置<br>
但是一次只能显示一个，由于人有视觉暂留，通过不断刷新数码管，起到动态显示的效果。 <br>
__138译码器__    3input   8 output Y0-Y7 <br>
使能：相当于一种开关 <br>
3个输入端: P22 P23 P24   二进制转10 <br>
101  5   Y5 -> 0  其他 = 1

__数码管的残影__ 
先位选，再段选，由于上一位显示后，信息没有清除，会影响下一位显示。 <br>
将显示内容清除，再显示，可以避免残影

- 函数:数码管显示<br>
`void Nixie(u8 location, u8 Number);`

## 4、LCD1602a
__引脚：__
- VSS GND
- VDD VCC
- VO  对比度调节-电位器
- RS  DATA/COMMAND  1-DATA 0-COM
- RW  READ/WRITE    1-R    0-W
- E   ENGIN   使能   1-数据有效 下降沿执行命令
- D0~D7 data in
- A   背光电源+
- K   背光电源-

__地址__<br>
0x80      0/0
0x80+0x40 1/0
number + 0x30

__时序结构__<br>
- init
```c++
// 0x38 八位数据接口，两行显示，5*7点阵
// 0x0C 显示开，光标关，闪烁关
// 0x06 读写操作后，光标自动加一，画面不动
// 0x01 clear 
```
- 显示字符
```c++
// 0x80|AC 设置光标位
// 发送数据
// ...
```
- 移屏 0x18

