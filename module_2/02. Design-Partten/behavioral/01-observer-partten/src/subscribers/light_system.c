#include "subscribers/light_system.h"
#include <stdio.h>

void lightSystemUpdate(Subscriber* self, Publisher* context, const char* eventInfo) {
    (void)self; (void)context;
    printf("[Light System] Light: %s\n", eventInfo);
}


void lightSystemNotifierInit(LightSystem* notifier) {
    notifier->base.update = lightSystemUpdate;
    notifier->base.data = NULL;
}