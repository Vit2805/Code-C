#include <stdio.h>
#include <unistd.h>
#include "pump.h"
#include "led_rgb.h"
#include "button_2.h"
#include "config.h"

// Handle Button 2
void handle_button_2(SystemStatus* status) {
    if (status->mode != MODE_MANUAL) {
        printf("[BUTTON 2]: Manual watering only available in Manual Mode! \n");
        return;
    } else {
        printf("[BUTTON 2]: Manual Watering stated for %d seconds... \n", DEFAULT_WATERING_MAX);
        turnPumpOn();
        status->pumpStatus = PUMP_ON;
        status->ledStatus = LED_WATERING;
        updateLedStatus(status->ledStatus);

        sleep(DEFAULT_WATERING_MAX);

        turnPumpOff();
        status->pumpStatus = PUMP_OFF;
        status->ledStatus = LED_NORMAL;
        updateLedStatus(status->ledStatus);
        printf("[BUTTON 2]: Manual Watering done! \n");
    }
}