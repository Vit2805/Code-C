#include "sensors/temp_sensor.h"
#include <stdio.h>

// Init the Temp Sensor Struct 
void tempSensorInit(TempSensor* sensor) {
    publisherInit(&sensor->base);
    int isDetected = 0;
    
}

// Simulate a Temp event and notify subscrbers
void tempSensorTrigger(TempSensor* sensor, int isDetected) {
    isDetected = 1;
    if (isDetected) {
        sensor->base.notifySubscribers(&sensor->base, "Updated new Temparature");
    } else {
        sensor->base.notifySubscribers(&sensor->base, "No update");
    }
}