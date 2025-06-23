#ifndef MOTION_SENSOR_H
#define MOTION_SENSOR_H

#include "publisher.h"

typedef struct {
    Publisher base;
    int isActive;
}MotionSensor;

void motionSensorInit(MotionSensor* sensor);
void motionSensorTrigger(MotionSensor*, int isActive);

#endif // MOTION_SENSOR_H