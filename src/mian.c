// #include <reg51.h>
#include "Digital.h"
#include "delay.h"

void main()
{

  while (1)
  {
    for(u8 i = 0; i <= 8; ++i)
    {
      Nixie(i,i);
      delay10us(00);
    }
  }
}