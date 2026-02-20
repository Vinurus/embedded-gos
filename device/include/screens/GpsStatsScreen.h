#pragma once
#include "screens/Screen.h"

class GpsStatsScreen : public Screen {
public:
    float speed = 0;
    float altitude = 0;
    float heading = 0;
    int sats = 0;
    int fix = 0;
    float hdop = 0;
    double lat = 0;
    double lon = 0;
    int rxBytes = 0;

    void render(Display& d) override;
    void update(Display& d) override;
    void onEvent(const Event& e) override;
};
