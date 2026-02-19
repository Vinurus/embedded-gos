#pragma once

class Display;
class Event;

class Screen {
public:
    virtual ~Screen() {}
    virtual void render(Display& display) = 0;
    virtual void update(Display& display) {}
    virtual void onEvent(const Event& e) {}
};
