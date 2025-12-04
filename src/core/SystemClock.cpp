#include "SystemClock.h"

SystemClock systemClock;

void SystemClock::init() {
    // na esp32 można tu nic nie robić
}

uint32_t SystemClock::now() const {
    return millis();
}