#ifndef HUMIDITY_SENSOR_H
#define HUMIDITY_SENSOR_H

// Humidity Sensor Structure
typedef struct {
    void (*init)(void);
    int (*humidity)(int value);
}HumiditySensor;

// Function declaration
void initHumiditySensor();
int humiditySensorRead(int humidity);
HumiditySensor createHumiditySensor();

#endif // HUMIDITY_SENSOR_H

