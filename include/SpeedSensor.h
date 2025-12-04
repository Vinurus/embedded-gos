#pragma once
#include "MessageBus.h"

class SpeedSensor {
public:
    SpeedSensor(MessageBus& bus) : bus(bus) {}
    void init();
    void update();

private:
    MessageBus& bus;
};