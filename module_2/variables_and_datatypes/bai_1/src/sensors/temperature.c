#include <stdio.h>
#include <stdlib.h>
#include "temperature_sensor.h"

void initTemperatureSensor() {
    printf("Temperature sensor initialized. \n");
}

int temperatureSensorRead(int temperature) {
    printf("Temperature: %d ", temperature);
}

TemperatureSensor createTemperatureSensor() {
    TemperatureSensor sensor;
    sensor.init = initTemperatureSensor;
    sensor.temperature = temperatureSensorRead;
    return sensor;
}