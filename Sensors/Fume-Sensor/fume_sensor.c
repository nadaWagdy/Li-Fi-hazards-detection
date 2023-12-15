#include "fume_sensor.h"

unsigned int adc_value;

void fume_sensor_init()
{
  adc0_ss3_init();
  
  /* This is temporary and will be replaced with Li-Fi part */
  /**************************************************************************************************************/
  /*Iniitialize PF3 as a digital output pin */
		SYSCTL_RCGCGPIO_R |= 0x20U;  /* turn on bus clock for GPIOF */
		delayMs(10);							 /* 10 msec delay to enable the clock */
		GPIO_PORTF_DIR_R       = 0x0EU;  /* set GREEN pin as a digital output pin */
		GPIO_PORTF_DEN_R       = 0x0EU;  /* Enable PF3 pin as a digital pin */ 
 /*******************************************************************************************************************/
}
void fume_sensor_start()
{
  adc0_ss3_convert();
  delayMs(20);
  adc_value = ADC0_SSFIFO3_R; 			/* read adc coversion result from SS3 FIFO*/
  adc0_ss3_clear_conversion();
  /* This part will be replaced with Li-Fi */
  /**************************************************************************************************************/
  if(adc_value >= 1000){
            GPIO_PORTF_DATA_R  = 0x08;
        } /* turn on green LED*/
        else if (adc_value < 1000){ 
            GPIO_PORTF_DATA_R  = 0x00;
        } /* turn off green LED*/
  /**************************************************************************************************************/
}
void delayMs(unsigned long n)
{
  volatile unsigned long i,j;             //volatile is important for variables incremented in code
	for(i=0;i<n;i++)
		for(j=0;j<3180;j++)         //delay for 1 msec
		{}
}
