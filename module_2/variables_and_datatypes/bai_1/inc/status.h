#ifndef STATUS_H
#define STATUS_H

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
    LED_ERRROR
}LedStatus_t;






#endif // STATUS_H
