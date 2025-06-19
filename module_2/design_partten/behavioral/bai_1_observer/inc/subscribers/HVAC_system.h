#ifndef HVAC_SYSTEM_H
#define HVAC_SYSTEM_H

#include "subscribers.h"

typedef struct {
    Subscriber base;
}HVACSystem;

void HVACSystemNotifierInit(HVACSystem* notifier);

#endif // HVAC_SYSTEM_H