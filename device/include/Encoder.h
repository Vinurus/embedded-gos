#pragma once
#include "MessageBus.h"

class Encoder {
public:
    Encoder(MessageBus& bus) : bus(bus) {}
    void init();
    void update();

private:
    MessageBus& bus;
};