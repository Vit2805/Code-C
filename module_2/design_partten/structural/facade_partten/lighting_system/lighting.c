#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lighting.h"


static void turnOn() {
    printf("Light turned on. \n");
}

static void turnOff() {
    printf("Light turned off. \n");
}

static void setBrightness(int level) {
    printf("Birghtness set to %d. \n", level);
}

// Function to create a LightingSystem
LightingSystem* createLightingSystem() {
    LightingSystem* system = (LightingSystem*)malloc(sizeof(LightingSystem));
    system->turnOn = turnOn;
    system->turnOff = turnOff;
    system->setBrightness = setBrightness;
    return system;
}