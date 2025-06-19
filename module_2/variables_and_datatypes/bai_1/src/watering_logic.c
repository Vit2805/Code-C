#include <stdio.h>
#include <stdlib.h>
#include "wartering_logic.h"
#include "humidity_sensor.h"
#include "temperature_sensor.h"
#include "led_rgb.h"
#include "pump.h"
#include "status.h"
#include "config.h"

void process_watering(SystemStatus* status, HumiditySensor* sensor, int value) {
    if (status->mode != MODE_AUTO) {
        return;
    }

    sensor->humidity = value;

    printf("[SYSTEM]: Current humidity: %d %%\n");

    if (sensor->humidity < status->config.humidity_threshold_min) {
        printf("[SYSTEM]: Soil is too dry. Starting watering... \n");
        status->pumpStatus = PUMP_ON;
        status->ledStatus = LED_WATERING;
        turnPumpOn();
        updateLedStatus(status->ledStatus);
    } else if (sensor->humidity >= status->config.humidity_threshold_max) {
        printf("[SYSTEM]: Soil humid is sufficient. Stopping watering... \n");
        status->pumpStatus = PUMP_OFF;
        status->ledStatus = LED_NORMAL;
        turnPumpOff();
        updateLedStatus(status->ledStatus);
    } else {
        printf("[SYSTEM]: Humidity is in safe range. \n");
    }

}