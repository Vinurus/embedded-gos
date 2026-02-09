#pragma once
#include <TinyGPSPlus.h>
#include "MessageBus.h"

class GpsSensor {
public:
    GpsSensor(MessageBus& bus);
    void init();
    void update();

private:
    MessageBus& bus;
    TinyGPSPlus gps;
};