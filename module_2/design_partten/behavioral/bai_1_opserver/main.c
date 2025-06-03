#include "sensors/door_sensor.h"
#include "sensors/smoke_sensor.h"
#include "sensors/temp_sensor.h"
#include "sensors/motion_sensor.h"
#include "subscribers/alram_system_controller.h"
#include "subscribers/mobile_app_notifier.h"
#include "subscribers/HVAC_system.h"
#include "subscribers/light_system.h"

#include <stdio.h>

int main() { 
    // Init sensor (publisher)
    DoorSensor doorSensor;
    doorSensorInit(&doorSensor);

    SmokeSensor smokeSensor;
    smokeSensorInit(&smokeSensor);

    MotionSensor motionSensor;
    motionSensorInit(&motionSensor);

    TempSensor tempSensor;
    tempSensorInit(&tempSensor);

    // Init subscribers
    MobileAppNotifier mobileApp;
    mobileAppNotiferInit(&mobileApp);

    AlarmSystemController alarmSystem;
    alarmSystemControllerInit(&alarmSystem);

    HVACSystem HVACSystem;
    HVACSystemNotifierInit(&HVACSystem);

    LightSystem lightSystem;
    lightSystemNotifierInit(&lightSystem);


    // Register subscribers to door sensor (publisher)
    doorSensor.base.subcribe(&doorSensor.base, (Subscriber*)&mobileApp);
    doorSensor.base.subcribe(&doorSensor.base, (Subscriber*)&alarmSystem);

    // Register subscribers to smoke sensor (publisher)
    smokeSensor.base.subcribe(&smokeSensor.base, (Subscriber*)&mobileApp);
    smokeSensor.base.subcribe(&smokeSensor.base, (Subscriber*)&alarmSystem);

    // Register subscribers to motion sensor (publisher)
    motionSensor.base.subcribe(&motionSensor.base, (Subscriber*)&lightSystem);




    // Simulate events
    printf("== Simulate Motion Event ==\n");
    motionSensorTrigger(&motionSensor, 1);


    return 0;

}