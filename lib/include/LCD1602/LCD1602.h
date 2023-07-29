#ifndef __LCD1602_H__
#define __LCD1602_H__

// LCD1602 

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