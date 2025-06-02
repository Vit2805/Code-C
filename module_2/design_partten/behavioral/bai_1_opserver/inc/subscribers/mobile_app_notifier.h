#ifndef MOBILE_APP_NOTIFIER_H
#define MOBILE_APP_NOTIFIER_H

#include "../subscribers.h"

typedef struct { 
    Subscriber base;
}MobileAppNotifier;

void mobileAppNotiferInit(MobileAppNotifier *notifier);

#endif // MOBILE_APP_NOTIFIER_H