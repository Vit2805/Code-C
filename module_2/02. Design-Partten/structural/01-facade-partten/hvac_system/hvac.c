#include <stdio.h>
#include <stdlib.h>
#include "hvac.h"

static void autoMode(){ 
    printf("AutoMode. \n");
}

static void coolingMode() {
    printf("Cooling. \n");
}

static void warmingMode() {
    printf("warmingMode. \n");
}

static void setTemperature(int temp) {
    printf("Set temperature to: %d", temp);
}

// Function to create HVAC System
HVACSystem* createHVACSystem() {
    HVACSystem* system = (HVACSystem*)malloc(sizeof(HVACSystem));
    system->autoMode= autoMode;
    system->coolingMode = coolingMode;
    system->warmingMode = warmingMode;
    system->setTemperature = setTemperature;
    
    return system;
}