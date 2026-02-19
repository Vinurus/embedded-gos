#include "Buttons.h"
#include <Arduino.h>

void Buttons::init() {
    pinMode(pin, INPUT_PULLUP);
}

void Buttons::update() {
    bool state = digitalRead(pin);

    // wykrycie zbocza: HIGH -> LOW (wciśnięcie)
    if (lastState == HIGH && state == LOW) {
        Event e;
        e.type = EV_BUTTON_PRESS;
        e.value = 1;
        bus.publish(e);
    }

    lastState = state;
}

