
#ifndef __DIGITAL_H__
#define __DIGITAL_H__

typedef unsigned char u8;
typedef unsigned int u16;

#define local_1 P2_2
#define local_2 P2_3
#define local_3 P2_4
#define digital_pin P2


/**
 * local 1 2 3 输入138译码器的 位置信号
 * P2 为 数码管的显示信号PIN
 * 数字                  
 * 0    1100 0000   0xC0
 * 1    1111 1001   0xF9   
 * 2    1010 0100   0xA4  
 * 3    1011 0000   0xB0  
 * 4    1001 1001   0x99  
 * 5    1001 0010   0x92  
 * 6    1000 0010   0x82  
 * 7    1111 1000   0xF8  
 * 8    1000 0000   0x80  
 * 9    1001 0000   0x90  
 * DP   0000 0001   0x01
 */

static u8 NixieTable[10] = {
  ~0xC0,
  ~0xF9,
  ~0xA4,
  ~0xB0,
  ~0x99,
  ~0x92,
  ~0x82,
  ~0xF8,
  ~0x80,
  ~0x90
};

/**
 * @brief 数码管显示
 * @param location 显示位置
 * @param Number 显示数字
 */
void Nixie(u8 location, u8 Number);


#endif
