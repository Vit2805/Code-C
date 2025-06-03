#ifndef TEMP_SENSOR_H
#define TEMP_SENSOR_H

#include "publisher.h"

typedef struct {
    Publisher base;
    int isDetected;
}TempSensor;

void tempSensorInit(TempSensor* sensor);
void tempSensorTrigger(TempSensor* sensor, int isDetected);


#endif // TEMP_SENSOR_H