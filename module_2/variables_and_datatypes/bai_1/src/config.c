#include "config.h"
#include "status.h"
#include <stdio.h>

SystemConfig_t defaultSystemConfig(void) {
    SystemConfig_t config;
    config.humidity_threshold_min = DEFAULT_HUMIDITY_MIN;
    config.humidity_threshold_max = DEFAULT_HUMIDITY_MAX;
    config.watering_time_max      = DEFAULT_WATERING_MAX;
    config.sensor_check_interval  = DEFAULT_SENSOR_INTERVAL;
    config.system_status          = DEFAULT_SYSTEM_STATUS;

    return config;
}
