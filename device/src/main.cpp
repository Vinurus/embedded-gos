#include <Arduino.h>
#include "SystemClock.h"
#include "Scheduler.h"
#include "MessageBus.h"
#include "Display.h"
#include "Buttons.h"
#include "Encoder.h"
#include "SpeedSensor.h"
#include "Power.h"
#include "GpsSensor.h"

SystemClock sysClock;
Scheduler scheduler;
MessageBus bus;

Buttons buttons(bus);
Encoder encoder(bus);
SpeedSensor speed(bus);
Power power(bus);
GpsSensor gps(bus);


void setup() {
    Serial.begin(115200);

    sysClock.init();
    scheduler.init(&sysClock);

    display->init();
    buttons.init();
    encoder.init();
    speed.init();
    power.init();
    gps.init();

    scheduler.every(5,   [&](){ buttons.update(); });
    scheduler.every(5,   [&](){ encoder.update(); });
    scheduler.every(20,  [&](){ speed.update(); });
    scheduler.every(100, [&](){ power.update(); });
    scheduler.every(50, [&](){ gps.update(); });

}

void loop() {
    scheduler.run();
    bus.dispatch();
    currentScreen->update();
    currentScreen->render(display);

}