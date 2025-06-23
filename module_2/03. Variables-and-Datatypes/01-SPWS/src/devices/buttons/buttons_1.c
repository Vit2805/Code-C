#include <stdio.h>
#include <stdlib.h>
#include "button_1.h"
#include "pump.h"
#include "led_rgb.h"

// Handle button 1
void handle_button_1(SystemStatus* status) {
    if (status->mode == MODE_AUTO) {
        status->mode = MODE_MANUAL;
        turnPumpOff();
        status->pumpStatus = PUMP_OFF;
        status->ledStatus = LED_NORMAL;
        updateLedStatus(status->ledStatus);
        printf("[BUTTON 1]: Switched to Manual Mode! \n");
    } else {
        status->mode = MODE_AUTO; 
        status->ledStatus = LED_NORMAL;
        updateLedStatus(status->ledStatus);
        printf("[BUTTON 1]: Switched to Auto Mode! \n");
    }
}

