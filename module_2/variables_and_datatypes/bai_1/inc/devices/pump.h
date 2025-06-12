#ifndef PUMP_H
#define PUMP_H

#include "status.h"

// Pump structure
typedef struct {
    PumpStatus_t currentPumpStatus;
    void (*pumpHandler)(PumpStatus_t status, const char *format, ...);
}Pump;


// Funtion declarations
void initPump(Pump* pump);
void turnPumpOn(Pump* pump, PumpStatus_t status);
void turnPumpOff(Pump* pump, PumpStatus_t status);

#endif // PUMP_H