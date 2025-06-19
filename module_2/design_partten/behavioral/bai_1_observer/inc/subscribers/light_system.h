#ifndef LIGHT_SYSTEM_H
#define LIGHT_SYSTEM_H

#include "subscribers.h"

typedef struct {
    Subscriber base;
}LightSystem;

void lightSystemNotifierInit(LightSystem* notifier);

#endif // LIGHT_SYSTEM_H