#include "Laser.h"

unsigned long standardDelay = 1350;

void laser_init()
{
   SYSCTL_RCGCGPIO_R |= 2; 
   Delay(1000);
   GPIO_PORTB_DIR_R |= 0x08;
   GPIO_PORTB_DEN_R |= 0x08; 
}


void laser_transmit_data(bool a, bool b, bool c)
{
  // start 
  
  Set_Bit(GPIO_PORTB_DATA_R, 3);
  Delay_MicroSecond(100000);
  
  ///////
  
  Clear_Bit(GPIO_PORTB_DATA_R, 3);
  if (a == true)
    Set_Bit(GPIO_PORTB_DATA_R, 3);
  
  Delay_MicroSecond(100000);
  
  Clear_Bit(GPIO_PORTB_DATA_R, 3);
  if (b == true)
    Set_Bit(GPIO_PORTB_DATA_R, 3);
  
  Delay_MicroSecond(100000);
  
  Clear_Bit(GPIO_PORTB_DATA_R, 3);
  if (c == true)
    Set_Bit(GPIO_PORTB_DATA_R, 3);
  
  Delay_MicroSecond(100000);
  
  Clear_Bit(GPIO_PORTB_DATA_R, 3);
  Delay_MicroSecond(100000);
} 