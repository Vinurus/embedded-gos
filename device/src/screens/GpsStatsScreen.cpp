#include "screens/GpsStatsScreen.h"
#include "Display.h"
#include "MessageBus.h"

void GpsStatsScreen::render(Display& d) {
    d.clear();

    d.drawText(20, 10, "GPS STATS", TFT_YELLOW, 3);

    d.drawText(20, 50,  "Speed:", TFT_WHITE, 2);
    d.drawText(20, 80,  "Alt:",   TFT_WHITE, 2);
    d.drawText(20, 110, "Head:",  TFT_WHITE, 2);
    d.drawText(20, 140, "Sats:",  TFT_WHITE, 2);
    d.drawText(20, 170, "Fix:",   TFT_WHITE, 2);
    d.drawText(20, 200, "HDOP:",  TFT_WHITE, 2);
    d.drawText(20, 230, "Lat:",   TFT_WHITE, 2);
    d.drawText(20, 260, "Lon:",   TFT_WHITE, 2);
    d.drawText(20, 290, "RX Bytes:",   TFT_WHITE, 2);
}

void GpsStatsScreen::update(Display& d) {
    d.drawFormatted(140, 50,  TFT_GREEN, 2, "%.1f km/h", speed);
    d.drawFormatted(140, 80,  TFT_GREEN, 2, "%.1f m", altitude);
    d.drawFormatted(140, 110, TFT_GREEN, 2, "%.0f deg", heading);
    d.drawFormatted(140, 140, TFT_GREEN, 2, "%d", sats);
    d.drawFormatted(140, 170, TFT_GREEN, 2, "%d", fix);
    d.drawFormatted(140, 200, TFT_GREEN, 2, "%.1f", hdop);
    d.drawFormatted(140, 230, TFT_GREEN, 2, "%.6f", lat);
    d.drawFormatted(140, 260, TFT_GREEN, 2, "%.6f", lon);
    d.drawFormatted(140, 290, TFT_GREEN, 2, "%d", rxBytes);
}
void GpsStatsScreen::onEvent(const Event& e) {
    switch (e.type) {
        case EV_GPS_SPEED:      speed = e.value; break;
        case EV_GPS_ALT:        altitude = e.value; break;
        case EV_GPS_HEADING:    heading = e.value; break;
        case EV_GPS_SATS:       sats = e.value; break;
        case EV_GPS_FIX_STATE:  fix = e.value; break;
        case EV_GPS_HDOP:       hdop = e.value; break;
        case EV_GPS_LAT:        lat = e.value; break;
        case EV_GPS_LON:        lon = e.value; break;
        case EV_GPS_RX_BYTES:   rxBytes = e.value; break;
    }
}
