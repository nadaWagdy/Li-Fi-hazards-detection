#include "magnetic-sensor.h"

void magnetic_init()
{
   //GPIO_PORTB_DIR_R |= 0x04;
   SYSCTL_RCGCGPIO_R |= 2; 
   GPIO_PORTB_DIR_R &= ~0x04;
   GPIO_PORTB_DEN_R |= 0x04;
   
   /* The following part will be deleted and is only there for testing the sensor */
  /*************************************************************************************/
  /*Iniitialize PF3 as a digital output pin */
		SYSCTL_RCGCGPIO_R |= 0x20U;  /* turn on bus clock for GPIOF */
		Delay(1000);							 /* 10 msec delay to enable the clock */
		GPIO_PORTF_DIR_R       = 0x0EU;  /* set GREEN pin as a digital output pin */
		GPIO_PORTF_DEN_R       = 0x0EU;  /* Enable PF3 pin as a digital pin */
  /*************************************************************************************/
}



void magnetic_get_read()
{
    if(Get_Bit(GPIO_PORTB_DATA_R , 2))
    { 
       //GPIO_PORTF_DATA_R  = 0x08;     
    }
    else 
    {
      // door is opened
       //GPIO_PORTF_DATA_R  = 0x04;
      laser_transmit_data(1, 0, 1);
    }
}
