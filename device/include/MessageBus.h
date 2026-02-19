#pragma once
#include <Arduino.h>

#define MAX_EVENTS 16

struct Event {
    uint8_t type;
    int value;
};

enum EventType {
    EV_SPEED_CHANGED,
    EV_BUTTON_PRESS,
    EV_ENCODER_TURN,
    EV_POWER_UPDATE,
    EV_GPS_SPEED,
    EV_GPS_LAT,
    EV_GPS_LON,
    EV_GPS_FIX_STATE,
    EV_GPS_RX_BYTES
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