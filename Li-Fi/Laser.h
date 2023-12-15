#ifndef LASER_H_
#define LASER_H_

#include "../tm4c123gh6pm.h"
#include "../bitwise_operation.h"
#include "../Timer/Timer0A.h"
#include "../Sensors/Ultrasonic-Sensor/ultrasonic-sensor.h"
#include <stdbool.h>

void laser_init();
void laser_transmit_data(bool a, bool b, bool c);

#endif