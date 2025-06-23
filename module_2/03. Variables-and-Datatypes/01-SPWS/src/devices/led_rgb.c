#include <stdio.h>
#include <stdlib.h>
#include "led_rgb.h"
#include "status.h"

// Function update led status
void updateLedStatus(LedStatus_t ledstatus) { 
    switch(ledstatus) {
        case LED_NORMAL:
            printf("[LED]:GREEN - Normal \n");
            break;
        case LED_WATERING: 
            printf("[LED]: BLUE - Watering \n");
            break;
        case LED_LOW_MOISTURE_ALERT:
            printf("[LED]: RED - Low Moisture\n");
            break;
        case LED_ERROR:
            printf("[LED]: Blink Red - Error\n");
            break;
    }
}