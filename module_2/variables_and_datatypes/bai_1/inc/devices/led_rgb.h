#ifndef LED_RGB_H
#define LED_RGB_H

#include "status.h"

// Led Stucture
typedef struct {
    LedStatus_t currentLedStatus;
    void (*ledHandler)(LedStatus_t status, const char *format, ...);
}LedRgb;

// Funtion declarations
void initLedRgb(LedRgb* led);
void updateLedRgbStatus(LedRgb* led, LedStatus_t status);

#endif // LED_RGB_H