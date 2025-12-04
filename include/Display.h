#pragma once
#include "MessageBus.h"

class Display {
public:
    Display(MessageBus& bus) : bus(bus) {}
    void init();
    void update();

private:
    MessageBus& bus;
};