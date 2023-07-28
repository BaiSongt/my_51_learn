#include <reg51.h>
#include "Digital.h"

/**
 * @brief 数码管显示
 * @param location 显示位置
 * @param Number 显示数字
 */
void Nixie(u8 location, u8 Number)
{
  switch (location)
  {
  case 1:
    local_1=0; local_2=0;local_3=0;
    break;
  case 2:
    local_1=1; local_2=0;local_3=0;
    break;
  case 3:
    local_1=0; local_2=1;local_3=0;
    break;
  case 4:
    local_1=1; local_2=1;local_3=0;
    break;
  case 5:
    local_1=0; local_2=0;local_3=1;
    break;
  case 6:
    local_1=1; local_2=0;local_3=1;
    break;
  case 7:
    local_1=0; local_2=1;local_3=1;
    break;
  case 8:
    local_1=1; local_2=1;local_3=1;
    break;
  }
  P0=NixieTable[Number];
}