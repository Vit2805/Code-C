#ifndef CONFIG_H
#define CONFIG_H

#define DEFAULT_HUMIDITY_MIN 20 // %
#define DEFAULT_HUMIDITY_MAX 80 // %
#define DEFAULT_WATERING_MAX 20 // sec
#define DEFAULT_SENSOR_INTERVAL 10 // m
#define DEFAULT_SYSTEM_STATUS MODE_AUTO // status

// System config
typedef struct {
    int humidity_threshold_min;
    int humidity_threshold_max;
    int watering_time_max;
    int sensor_check_interval;
    char system_status;
}SystemConfig_t;

void systemInit(); 

#endif // CONFIG_H