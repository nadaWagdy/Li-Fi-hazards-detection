#ifndef FUME_SENSOR_H_
#define FUME_SENSOR_H_

#include "../../tm4c123gh6pm.h"
#include "../../ADC/adc.h"

#define THRESHOLD 1000  // Adjust threshold based on sensor


void fume_sensor_init();
void fume_sensor_start();
void delayMs(unsigned long n);

#endif