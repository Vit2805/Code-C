#include "subscribers/HVAC_system.h"
#include <stdio.h>

void HAVCSystemUpdate(Subscriber* self, Publisher* context, const char* eventInfo) {
    (void)self; (void)context;
    printf("[HVAC System] Alarm: %s\n", eventInfo);
}

void HVACSystemNotifierInit(HVACSystem* notifier) {
    notifier->base.update = HAVCSystemUpdate;
    notifier->base.data = NULL;
}