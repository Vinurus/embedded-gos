#include "MessageBus.h"

void MessageBus::publish(Event e) {
    uint8_t next = (head + 1) % MAX_EVENTS;
    if (next != tail) {
        queue[head] = e;
        head = next;
    }
}

bool MessageBus::available() {
    return head != tail;
}

Event MessageBus::pop() {
    Event e = queue[tail];
    tail = (tail + 1) % MAX_EVENTS;
    return e;
}

void MessageBus::dispatch() {
    // placeholder – real handler logic will be added later
}