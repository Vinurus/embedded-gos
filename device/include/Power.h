#pragma once
#include "MessageBus.h"

class Power {
public:
    Power(MessageBus& bus) : bus(bus) {}
    void init();
    void update();

private:
    MessageBus& bus;
};