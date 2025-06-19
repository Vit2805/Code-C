#ifndef LED_RGB_H
#define LED_RGB_H

#include "status.h"

// Led Stucture
typedef struct {
    LedStatus_t currentLedStatus;
}LedRgb;

// Funtion declarations
void updateLedStatus(LedStatus_t ledstatus);

#endif // LED_RGB_H