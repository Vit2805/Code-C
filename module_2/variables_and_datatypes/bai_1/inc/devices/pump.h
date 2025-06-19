#ifndef PUMP_H
#define PUMP_H

#include "status.h"

// Pump structure
typedef struct {
    PumpStatus_t currentPumpStatus;
}Pump;

// Funtion declarations
void turnPumpOn(void);
void turnPumpOff(void);

#endif // PUMP_H