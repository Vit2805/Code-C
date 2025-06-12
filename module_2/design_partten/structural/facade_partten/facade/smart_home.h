#ifndef SMART_SYSTEM_H
#define SMART_SYSTEM_H

#include "hvac.h"
#include "lighting.h"
#include "security_system.h"

typedef struct {
    LightingSystem* lighting;
    SecuritySystem* security;
    HVACSystem* hvac;
}SmartHomeSystem;

SmartHomeSystem* createSmartHomeSystem();
void activateMorningRoutine(SmartHomeSystem* facade);
void activateAwayMode(SmartHomeSystem* facade);
void setMovieNightScence(SmartHomeSystem* facade);

#endif // SMART_SYSTEM_H