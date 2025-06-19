#ifndef WATERING_LOGIC_H
#define WATERING_LOGIC_H

#include "status.h"
#include "humidity_sensor.h"
#include "temperature_sensor.h"

void process_watering(SystemStatus* status, HumiditySensor* sensor, int value);


#endif // WATERING_LOGIC_H