#ifndef ULTRASONIC_SENSOR_H_
#define ULTRASONIC_SENSOR_H_

#include "../../tm4c123gh6pm.h"
#include "../../Timer/Timer0A.h"
#include "../../Li-Fi/Laser.h"
#include <stdio.h>

#define MAX_DISTANCE 10

void ultrasonic_sensor_init(void);
void ultrasonic_sensor_start(void);
unsigned long Measure_distance(void);
void Delay(unsigned long counter);

#endif