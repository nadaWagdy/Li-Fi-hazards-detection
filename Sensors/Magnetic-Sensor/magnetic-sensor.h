#ifndef MAGNETIC_SENSOR_H_
#define MAGNETIC_SENSOR_H_

#include "../../tm4c123gh6pm.h"
#include "../../bitwise_operation.h"
#include "../Ultrasonic-Sensor/ultrasonic-sensor.h"
#include "../../Li-Fi/Laser.h"

void magnetic_init();
void magnetic_get_read();


#endif