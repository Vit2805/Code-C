#include <stdio.h>
#include <stdint.h>
#include <smart_home.h>

// Function to create Smart Home 
SmartHomeSystem* createSmartHomeSystem() {
    SmartHomeSystem* facade = (SmartHomeSystem*)malloc(sizeof(SmartHomeSystem));
    facade->lighting = createLightingSystem;
    facade->hvac = createHVACSystem;
    facade->security = createSecuritySystem;
    return facade;
}

void activateMorningRoutine(SmartHomeSystem* facade) {
    facade->lighting->turnOn();
    facade->lighting->setBrightness(80);
    facade->hvac->autoMode();
    facade->security->deactivateAlarm();
    printf("Morning routine activated. \n");
}

void activateAwayMode(SmartHomeSystem* facade) { 
    facade->lighting->turnOff();
    facade->security->activateAlarm();
    facade->hvac->autoMode();
    printf("Away mode activated. \n");
}

void setMovieNightScene(SmartHomeSystem* facade) {
    facade->lighting->setBrightness(30);
    facade->hvac->warmingMode();
    facade->security->deactivateAlarm();
    printf("Movie night scene set. \n");
}