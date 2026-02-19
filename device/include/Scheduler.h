#pragma once
#include <Arduino.h>
#include <functional>

#define MAX_TASKS 16

class SystemClock;

struct Task {
    uint32_t interval;
    uint32_t nextRun;
    std::function<void()> callback;

    Task() {}
    Task(uint32_t i, uint32_t n, std::function<void()> c)
        : interval(i), nextRun(n), callback(c) {}
};

class Scheduler {
public:
    void init(SystemClock* clock);
    void every(uint32_t intervalMs, std::function<void()> fn);
    void run();

private:
    SystemClock* clock;
    Task tasks[MAX_TASKS];
    uint8_t taskCount = 0;
};