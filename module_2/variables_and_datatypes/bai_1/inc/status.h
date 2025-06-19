#ifndef STATUS_H
#define STATUS_H

#include "config.h"

// System Mode
typedef enum {
    MODE_AUTO,
    MODE_MANUAL
}SystemMode_t;

// Pump Status
typedef enum {
    PUMP_OFF,
    PUMP_ON
}PumpStatus_t;

// Led Status
typedef enum {
    LED_NORMAL, 
    LED_WATERING,
    LED_LOW_MOISTURE_ALERT, 
    LED_ERROR
}LedStatus_t;

// System Status
typedef struct {
    SystemMode_t mode;      
    PumpStatus_t pumpStatus;
    LedStatus_t ledStatus;
    SystemConfig_t config;
} SystemStatus;

// Function Declaration
void initSystem();

#endif // STATUS_H
