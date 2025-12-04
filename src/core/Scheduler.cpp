#include "Scheduler.h"
#include "SystemClock.h"

void Scheduler::init(SystemClock* clockRef) {
    clock = clockRef;
}

void Scheduler::every(uint32_t intervalMs, std::function<void()> fn) {
    if (taskCount >= MAX_TASKS) return;
    tasks[taskCount] = Task(intervalMs, systemClock.now() + intervalMs, fn);
    taskCount++;
}

void Scheduler::run() {
    uint32_t now = systemClock.now();
    for (uint8_t i = 0; i < taskCount; i++) {
        if (now >= tasks[i].nextRun) {
            tasks[i].callback();
            tasks[i].nextRun = now + tasks[i].interval;
        }
    }
}