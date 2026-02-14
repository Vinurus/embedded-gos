#include "screens/Screen.h"
#include "MessageBus.h"
#include "Display.h"
#include <TFT_eSPI.h>

class MainScreen : public Screen {
public:
    float speed = 0;
    float dist = 0;
    int sec = 0;

    void update() override {
        // tu możesz mieć logikę aktualizacji
    }

    void onEvent(const Event& e) override {
        if (e.type == EV_GPS_SPEED) speed = e.value;
        if (e.type == EV_GPS_RX_BYTES) { /* ... */ }
        if (e.type == EV_GPS_FIX_STATE) { /* ... */ }
    }

    void render(Display& d) override {
        d.clear();
        d.drawText(40, 20, "SPEED", TFT_DARKGREY, 2);
        d.drawFormatted(40, 50, TFT_GREEN, 5, "%.1f", speed);

        d.drawText(40, 140, "DIST", TFT_DARKGREY, 2);
        d.drawFormatted(40, 160, TFT_WHITE, 2, "%.2f km", dist);

        d.drawText(40, 180, "TIME", TFT_DARKGREY, 2);
        d.drawFormatted(40, 200, TFT_WHITE, 2, "%02d:%02d", sec/60, sec%60);
    }
};
