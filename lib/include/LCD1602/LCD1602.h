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

// 这段代码定义了一些函数来控制LCD1602液晶屏的显示。其中包括初始化函数、写入命令和数据函数、显示字符、字符串、数字、有符号数字、十六进制数字和二进制数字的函数。
//  void delay1ms(); //@12.000MHz
// 这个函数是延时1毫秒的函数，使用的时钟频率为12MHz。
//  void LCD1602_WriteCommand(u8 com);
// 这个函数用来向LCD1602液晶屏写入命令。
//  void LCD1602_WriteData(u8 data);
// 这个函数用来向LCD1602液晶屏写入数据。
//  void LCD1602_Init();
// 这个函数用来初始化LCD1602液晶屏。
//  void LCD1602_ShowChar(u8 line, u8 colum, unsigned char _char);
// 这个函数用来在指定位置显示一个字符。
//  void LCD1602_ShowString(u8 line, u8 colum,u8 *_str);
// 这个函数用来在指定位置显示一个字符串。
//  void LCD1602_ShowNum(u8 line, u8 colum, u16 _num, u8 length);
// 这个函数用来在指定位置显示一个数字，可以指定数字的长度。
//  void LCD1602_ShowSignedNum(u8 line, u8 colum, int _num, u8 length);
// 这个函数用来在指定位置显示一个有符号数字，可以指定数字的长度。
//  void LCD1602_ShowHexNum(u8 line, u8 colum, u16 _num, u8 length);
// 这个函数用来在指定位置显示一个十六进制数字，可以指定数字的长度。
//  void LCD1602_ShowBinNum(u8 line, u8 colum, u16 _num, u8 length);
// 这个函数用来在指定位置显示一个二进制数字，可以指定数字的长度。
// by Chat-GPT4 Bito

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