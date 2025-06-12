#ifndef HVAC_SYSTEM_H
#define HVAC_SYSTEM_H

typedef struct {
    void (*autoMode)(void);
    void (*coolingMode)(void);
    void (*warmingMode)(void);
    void (*setTemperature)(int temp);
}HVACSystem;

HVACSystem* createHVACSystem();

#endif // HVAC_SYSTEM_H