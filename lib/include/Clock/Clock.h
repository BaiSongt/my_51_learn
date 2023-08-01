#ifndef __CLOCK_H__
#define __CLOCK_H__

#include "LCD1602/LCD1602.h"

#define KEY_1 P3_1
#define KEY_2 P3_0
#define KEY_3 P3_2
#define KEY_4 P3_3

void Clock( u8 sec, u8 min, u8 hour);
void Clock_current(u8 sec, u8 min, u8 hour);
void Key1ResetClock( u8 sec, u8 min, u8 hour);
void Key2StartClock( u8 sec, u8 min, u8 hour);
void Key3PuaseClock( u8 sec, u8 min, u8 hour);

#endif