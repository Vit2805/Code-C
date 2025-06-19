#ifndef PUBLISHER_H
#define PUBLISHER_H

#include "subscribers.h"

#define MAX_SUBSCRIBERS 10


// Publisher structor
typedef struct Publisher {
    Subscriber* subscribers[MAX_SUBSCRIBERS];
    int subCount;

    void (*subcribe)(struct Publisher* self, Subscriber* s);
    void (*unsubcribe)(struct Publisher* self, Subscriber* s);
    void (*notifySubscribers)(struct Publisher* self, const char* eventInfo);
} Publisher;

void publisherInit(Publisher* pub);

# endif // PUBLISHER_H