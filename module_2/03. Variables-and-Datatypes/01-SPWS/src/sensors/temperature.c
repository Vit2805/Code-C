#include <stdio.h>
#include <stdlib.h>
#include "temperature_sensor.h"

void initTemperatureSensor() {
    printf("Temperature sensor initialized. \n");
}

int temperatureSensorRead(int temperature) {
    return temperature;
}

TemperatureSensor createTemperatureSensor() {
    TemperatureSensor sensor;
    sensor.init = initTemperatureSensor;
    sensor.temperature = temperatureSensorRead;
    
    return sensor;
}