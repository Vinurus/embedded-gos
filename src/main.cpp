#include <Arduino.h>
#include "SystemClock.h"
#include "Scheduler.h"
#include "MessageBus.h"
#include "Display.h"
#include "Buttons.h"
#include "Encoder.h"
#include "SpeedSensor.h"
#include "Power.h"

SystemClock sysClock;
Scheduler scheduler;
MessageBus bus;

Display display(bus);
Buttons buttons(bus);
Encoder encoder(bus);
SpeedSensor speed(bus);
Power power(bus);

void setup() {
    Serial.begin(115200);
    Serial.println("GOS Firmware starting...");

    sysClock.init();
    scheduler.init(&sysClock);

    display.init();
    buttons.init();
    encoder.init();
    speed.init();
    power.init();

    scheduler.every(100, [&](){ display.update(); });
    scheduler.every(5,   [&](){ buttons.update(); });
    scheduler.every(5,   [&](){ encoder.update(); });
    scheduler.every(20,  [&](){ speed.update(); });
    scheduler.every(100, [&](){ power.update(); });
}

void loop() {
    scheduler.run();
    bus.dispatch();
}