#ifndef SYSTEM_CLOCK_H
#define SYSTEM_CLOCK_H

#include <Arduino.h>

class SystemClock {
public:
    void init();
    uint32_t now() const;
};

extern SystemClock systemClock;

#endif