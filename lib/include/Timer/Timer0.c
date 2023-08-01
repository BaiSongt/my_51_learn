#include "Timer0.h"

#include <reg51.h> // 包含51单片机的寄存器定义

void timer0_init() // 初始化定时器0
{
    // TMOD &= 0xF0;
    TMOD |= 0x01; // 设置定时器0为16位自动重载模式
    // TMOD = TMOD & 0xF0; // 把TMOD的低四位清零，高四位保持不变
    // TMOD = TMOD | 0x01; // 把TMOD的最低位置一，高四位保持不变
    TF0 = 0;    //  清除TF0标志
    TH0 = 0xFC; // 设置定时器0的初始值为0xFC67，使定时器每隔1ms中断一次
    TL0 = 0x18; // 64525/256
    ET0 = 1;    // 允许定时器0中断
    TR0 = 1;    // 启动定时器0
    EA = 1;     // 允许总中断
}

// void timer0_isr() __interrupt 1 // 定时器0中断服务函数
// {
//     static unsigned int count = 0; // 计数器，用于计算定时器中断的次数
//     count++;                       // 每次定时器中断，计数器加1
//     if (count >= 1000)             // 如果计数器达到1000，即1秒
//     {
//         count = 0; // 重置计数器
//         // 这里可以添加需要执行的操作，例如控制LED闪烁等
//     }
// }

