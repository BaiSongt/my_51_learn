#ifndef __LCD1602_H__
#define __LCD1602_H__

// LCD1602 
/**
 * 这是一个LCD1602驱动的头文件，定义了一些函数和数据类型
 * 用于控制和操作LCD1602液晶显示屏。其中包括了延时函数、
 * 写命令函数、写数据函数等。还定义了一些显示函数，用于在
 * LCD1602屏幕上显示字符、字符串、数字、十六进制数和二进
 * 制数。这些函数可以根据需要在程序中调用，以实现对LCD1602
 * 的控制和显示。
 */

typedef unsigned char u8;
typedef unsigned int u16;

void delay1ms(); //@12.000MHz
void LCD1602_WriteCommand(u8 com);
void LCD1602_WriteData(u8 data);

void LCD1602_Init();
void LCD1602_ShowChar(u8 line, u8 colum, unsigned char _char);
void LCD1602_ShowString(u8 line, u8 colum,u8 *_str);
void LCD1602_ShowNum(u8 line, u8 colum, u16 _num, u8 length);
void LCD1602_ShowSignedNum(u8 line, u8 colum, int _num, u8 length);
void LCD1602_ShowHexNum(u8 line, u8 colum, u16 _num, u8 length);
void LCD1602_ShowBinNum(u8 line, u8 colum, u16 _num, u8 length);




#endif