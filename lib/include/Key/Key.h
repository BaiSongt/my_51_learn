#ifndef __KEY_H__
#define __KEY_H__

typedef unsigned char u8;
typedef unsigned int u16;


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


#define KEY_1 P3_1
#define KEY_2 P3_0
#define KEY_3 P3_2
#define KEY_4 P3_3

/**
 * @brief KEY_1 控制第2个LED
 * @param LED_n 
 */
void KEY1_LED_1();

/**
 * @brief KEY_2 控制所有LED
 * 按一下开，按一下关
 */
void KEY2_LED_PIN();

/**
 * @brief KEY_3 控制LED 显示二进制
 */
void KEY3_show_LED_bin();

/**
 * @brief 按一下KEY4 右移LED
 */
void KEY4_right_move_led();

/**
 * @brief 按一下KEY1 左移LED
 */
void KEY1_left_move_led();


#endif
