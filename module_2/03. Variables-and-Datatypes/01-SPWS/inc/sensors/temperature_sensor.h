#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

// Temperature Sensor Structure
typedef struct {
    void (*init)(void);
    int (*temperature)(int value);
}TemperatureSensor;

// Function declaration
void initTemperatureSensor();
int temperatureSensorRead(int temperature);
TemperatureSensor createTemperatureSensor();

#endif // TEMPERATURE_SENSOR_H