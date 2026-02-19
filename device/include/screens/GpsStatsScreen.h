#pragma once
#include "screens/Screen.h"

class GpsStatsScreen : public Screen {
public:
    void render(Display& d) override;
    void update(Display& d) override;
    void onEvent(const Event& e) override;
};
