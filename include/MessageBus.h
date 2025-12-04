#pragma once
#include <Arduino.h>

#define MAX_EVENTS 16

struct Event {
    uint8_t type;
};

class MessageBus {
public:
    void publish(Event e);
    bool available();
    Event pop();
    void dispatch(); // placeholder – will expand later

private:
    Event queue[MAX_EVENTS];
    uint8_t head = 0;
    uint8_t tail = 0;
};