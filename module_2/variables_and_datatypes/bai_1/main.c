#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "humidity_sensor.h"
#include "temperature_sensor.h"
#include "wartering_logic.h"
#include "led_rgb.h"
#include "pump.h"
#include "config.h"
#include "status.h"

// Các biến toàn cục
SystemConfig_t systemConfig;
HumiditySensor humiditySensor;
TemperatureSensor temperatureSensor;
LedRgb led;
Pump pump;

int main(void) {
    // Innit System
    printf("Initializing Smart Plant Watering System...\n");

    systemConfig = defaultSystemConfig();  

    humiditySensor = createHumiditySensor();
    temperatureSensor = createTemperatureSensor();


    createLedRgb(&led);
    createPump(&pump);

    printf("System initialized in AUTO mode.\n");

    // 2. Vòng lặp chính
    while (1) {
        // 2.1 Đọc cảm biến
        int currentHumidity = humiditySensor.humidity(35);  // giá trị mô phỏng
        int currentTemp     = temperatureSensor.temperature(28); // giá trị mô phỏng

        // 2.2 Kiểm tra nút nhấn
        handleButton1(&systemConfig, &pump); // chuyển MODE
        handleButton2(&systemConfig, &pump); // tưới thủ công

        // 2.3 Logic tưới nước tự động nếu ở chế độ AUTO
        if (systemConfig.system_status == MODE_AUTO) {
            handleAutoWatering(currentHumidity, &systemConfig, &pump, &led);
        }

        // 2.4 Cập nhật LED theo trạng thái bơm
        if (pump.status == PUMP_ON) {
            setLedRgbStatus(LED_WATERING);
        } else if (currentHumidity < systemConfig.humidity_threshold_min) {
            setLedRgbStatus(LED_LOW_MOISTURE_ALERT);
        } else {
            setLedRgbStatus(LED_NORMAL);
        }

        // 2.5 Thông báo trạng thái hệ thống
        printf("[Status] Humidity: %d%%, Temperature: %dC, Pump: %s, Mode: %s\n",
               currentHumidity,
               currentTemp,
               pump.status == PUMP_ON ? "ON" : "OFF",
               systemConfig.system_status == MODE_AUTO ? "AUTO" : "MANUAL");

        // 2.6 Delay vòng lặp
        sleep(5); // 5 giây (mô phỏng chu kỳ)
    }

    return 0;
}
