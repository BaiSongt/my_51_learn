#include <reg51.h>
#include "Key.h"
void main()
{
  P2 = ~0x01;
  while (1)
  {
    KEY4_right_move_led();
    KEY1_left_move_led();
  }
}