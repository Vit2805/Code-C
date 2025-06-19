#include "sensors/motion_sensor.h"
#include <stdio.h>
#include <string.h>

// Init the Motion Sensor struct
void motionSensorInit(MotionSensor* sensor) {
    publisherInit(&sensor->base);
    sensor->isActive = 0;
}

// Simulate a motion event and notify subscribers
void motionSensorTrigger(MotionSensor* sensor, int isActive) {
    sensor->isActive = isActive;
    if (isActive) {
        sensor->base.notifySubscribers(&sensor->base, "Motion Detected");
    } else {
        sensor->base.notifySubscribers(&sensor->base, "No Motion Detected");
    }
}

