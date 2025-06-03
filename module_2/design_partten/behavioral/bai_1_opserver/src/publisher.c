#include "publisher.h"
#include "string.h"


// Function to subcribe to publisher
void publisherSubcribe(Publisher* self, Subscriber* s) {
    if (self->subCount < MAX_SUBSCRIBERS) {
        self->subscribers[self->subCount++] = s;
    }
}

// Function to Unsubcribe 
void publisherUnSubcribe(Publisher* self, Subscriber* s) {
    for (int i = 0; i < MAX_SUBSCRIBERS; i++) { 
        if (self->subscribers[i] == s) {
            for (int j = i; j < self->subCount; j++) {
                self->subscribers[j] = self->subscribers[j+1];
            }
            self->subCount--;
            break;
        }
    }
}

// Notifi all subcribers about an event
void pubisherNotifiSubcribers(Publisher* self, const char* eventInfo) {
    for (int i = 0; i < self->subCount; i++) {
        if (self->subscribers[i] && self->subscribers[i]->update) {
            self->subscribers[i]->update(self->subscribers[i], self, eventInfo);
        }
    }
}

// Inittialize the publisher struct
void publisherInit(Publisher* pub) {
    memset (pub, 0, sizeof(Publisher));
    pub->subcribe = publisherSubcribe;
    pub->unsubcribe = publisherUnSubcribe;
    pub->notifySubscribers = pubisherNotifiSubcribers;
}