#pragma once
#include "MessageBus.h"

class Buttons {
public:
    Buttons(MessageBus& bus) : bus(bus) {}
    void init();
    void update();

private:
    MessageBus& bus;
    const int pin = 12;   
    bool lastState = HIGH;
};
