#include "screens/GpsStatsScreen.h"
#include "Display.h"

void GpsStatsScreen::render(Display& d) {
    d.clear();
    d.drawText(20, 20, "GPS DEBUG", TFT_YELLOW, 3);
}

void GpsStatsScreen::update(Display& d) {
    
}
void GpsStatsScreen::onEvent(const Event& e) {
    
}
