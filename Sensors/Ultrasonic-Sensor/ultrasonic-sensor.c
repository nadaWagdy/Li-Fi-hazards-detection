#include "ultrasonic-sensor.h"

/* global variables to store and display distance in cm */
unsigned int time; /*stores pulse on time */
unsigned int distance; /* stores measured distance value */
char mesg[20];  /* string format of distance value */

void ultrasonic_sensor_init(void)
{
  Timer0ACapture_init();
  
  /* The following part will be deleted and is only there for testing the sensor */
  /*************************************************************************************/
  /*Iniitialize PF3 as a digital output pin */
		SYSCTL_RCGCGPIO_R |= 0x20U;  /* turn on bus clock for GPIOF */
		Delay(1000);							 /* 10 msec delay to enable the clock */
		GPIO_PORTF_DIR_R       = 0x0EU;  /* set GREEN pin as a digital output pin */
		GPIO_PORTF_DEN_R       = 0x0EU;  /* Enable PF3 pin as a digital pin */
  /*************************************************************************************/
}

void ultrasonic_sensor_start(void)
{
  time = Measure_distance(); /* take pulse duration measurement */ 
    distance = (time * 10625)/10000000; /* convert pulse duration into distance */
    sprintf(mesg, "\r\nDistance = %d cm", distance); /*convert float type distance data into string */
    
    
    /* The following part will be deleted and is only there for testing the sensor*/
    /*************************************************************************************/
    if(distance > MAX_DISTANCE)
      GPIO_PORTF_DATA_R  = 0x08;
    else if (distance < MAX_DISTANCE)
      GPIO_PORTF_DATA_R  = 0x04;
    Delay(2000);
    /*************************************************************************************/
}

/* This function captures consecutive rising and falling edges of a periodic signal */
/* from Timer Block 0 Timer A and returns the time difference (the period of the signal). */
unsigned long Measure_distance(void)
{
  int lastEdge, thisEdge;
	
  /* Given 10us trigger pulse */
  GPIO_PORTA_DATA_R &= ~ (1<<4);                  /* make trigger  pin high */
  Delay_MicroSecond(10);                        /*10 seconds delay */
  GPIO_PORTA_DATA_R |= (1<<4);                  /* make trigger  pin high */
  Delay_MicroSecond(10);                        /*10 seconds delay */
  GPIO_PORTA_DATA_R &= ~ (1<<4);                 /* make trigger  pin low */

  while(1)
  {
    TIMER0_ICR_R = 4;                                     /* clear timer0A capture flag */
    
    while((TIMER0_RIS_R & 4) == 0) ;                     
    //while(!Get_Bit(TIMER0_RIS_R, 2)) ;                       /* wait till captured */
    
    //if(Get_Bit(GPIO_PORTB_DATA_R, 5))                                    /*check if rising edge occurs */
    if(GPIO_PORTB_DATA_R & (1<<6))
    {
      lastEdge = TIMER0_TAR_R;                                   /* save the timestamp */
                                                                /* detect falling edge */
      TIMER0_ICR_R = 4;                                           /* clear timer0A capture flag */
      
      while((TIMER0_RIS_R & 4) == 0) ;                         
      //while(!Get_Bit(TIMER0_RIS_R, 2)) ;                       /* wait till captured */

      thisEdge = TIMER0_TAR_R;                                    /* save the timestamp */
      return (thisEdge - lastEdge);                              /* return the time difference */
    }
  }
}

void Delay(unsigned long counter)
{
  unsigned long i = 0;
  
  for(i=0; i< counter*1000; i++);
}


