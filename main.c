#include "tm4c123gh6pm.h"
#include "Sensors/Fume-Sensor/fume_sensor.h"
#include "Sensors/Ultrasonic-Sensor/ultrasonic-sensor.h"
#include "Sensors/Magnetic-Sensor/magnetic-sensor.h"
#include "Li-Fi/Laser.h"


int main(void)
{
  magnetic_init();
  ultrasonic_sensor_init();
  laser_init();
  while(1)
  {
      magnetic_get_read();
      ultrasonic_sensor_start();
  }
}