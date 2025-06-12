#include <stdio.h>
#include <stdlib.h>
#include "humidity_sensor.h"

void initHumiditySensor() {
    printf("Humidity sensor initialized, \n");
}

int humiditySensorRead(int humidity) {
    printf("Humidity: %d %\n", humidity);
}

HumiditySensor createHumiditySensor() {
    HumiditySensor sensor;
    sensor.init = initHumiditySensor;
    sensor.humidity = humiditySensorRead;
    return sensor;
}