#include "screens/Screen.h"
#include "MessageBus.h"
#include "Display.h"
#include "screens/MainScreen.h"
#include <TFT_eSPI.h>


unsigned long lastRender = 0;

void MainScreen::render(Display& d) {
    d.clear();
    d.drawText(10, 10, "HELLO", 0xFFFF, 2);

    d.clear();
        d.drawText(40, 20, "SPEED", TFT_DARKGREY, 2);
        d.drawFormatted(40, 50, TFT_GREEN, 5, "%.1f", speed);

        d.drawText(40, 140, "DIST", TFT_DARKGREY, 2);
        d.drawFormatted(40, 160, TFT_WHITE, 2, "%.2f km", dist);

        d.drawText(40, 180, "TIME", TFT_DARKGREY, 2);
        d.drawFormatted(40, 200, TFT_WHITE, 2, "%02d:%02d", sec/60, sec%60);
}


void MainScreen::update() {
    // nic
}

void MainScreen::onEvent(const Event& e) {
    // nic
}




/*class MainScreen : public Screen {
public:
    float speed = 0;
    float dist = 0;
    int sec = 0;

    void update() override {
        // tu możesz mieć logikę aktualizacji
    }

    void onEvent(const Event& e) override {
        if (e.type == EV_GPS_SPEED) speed = e.value;
        if (e.type == EV_GPS_RX_BYTES) { }
        if (e.type == EV_GPS_FIX_STATE) {}
    }

    void render(Display& d) override {
        d.clear();
        d.drawText(10, 10, "HELLO", 0xFFFF, 2);

        
        d.clear();
        d.drawText(40, 20, "SPEED", TFT_DARKGREY, 2);
        d.drawFormatted(40, 50, TFT_GREEN, 5, "%.1f", speed);

        d.drawText(40, 140, "DIST", TFT_DARKGREY, 2);
        d.drawFormatted(40, 160, TFT_WHITE, 2, "%.2f km", dist);

        d.drawText(40, 180, "TIME", TFT_DARKGREY, 2);
        d.drawFormatted(40, 200, TFT_WHITE, 2, "%02d:%02d", sec/60, sec%60);
    }
#include "Display.h"
#include <Arduino.h>
#include <TFT_eSPI.h>

static TFT_eSPI tft = TFT_eSPI();

void Display::init() {
    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);

    tft.setTextColor(TFT_DARKGREY);
    tft.setTextSize(2);
    tft.setCursor(40, 20);
    tft.print("SPEED");

    tft.setCursor(40, 140);
    tft.print("DIST");

    tft.setCursor(40, 180);
    tft.print("TIME");

    tft.setTextColor(TFT_RED, TFT_BLACK);
tft.setTextSize(2);
tft.setCursor(250, 10);
tft.print("GPS: ---");

}

void Display::update() {
    static float speed = 10;
    static float dist = 0.0;
    static int sec = 0;

    speed += 0.3;
    if (speed > 45) speed = 12;

    dist += 0.01;
    sec++;

    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    tft.setTextSize(5);
    tft.setCursor(40, 50);
    tft.printf("   %.1f   ", speed);

    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextSize(2);
    tft.setCursor(40, 160);
    tft.printf("    %.2f km   ", dist);

    tft.setCursor(40, 200);
    tft.printf("   %02d:%02d   ", sec/60, sec%60);

    while (bus.available()) {
    Event e = bus.pop();

    if (e.type == EV_GPS_FIX_STATE) {
        tft.setTextSize(2);
        tft.setCursor(250, 10);

        if (e.value == 1) {
            tft.setTextColor(TFT_GREEN, TFT_BLACK);
            tft.print("GPS: FIX ");
        } else {
            tft.setTextColor(TFT_RED, TFT_BLACK);
            tft.print("GPS: ... ");
        }
    }

    if (e.type == EV_GPS_SPEED) {
        float speed = e.value;
        tft.setTextColor(TFT_GREEN, TFT_BLACK);
        tft.setTextSize(5);
        tft.setCursor(40, 50);
        tft.printf("   %.1f   ", speed);
    }
    if (e.type == EV_GPS_RX_BYTES) {
    tft.setTextSize(2);
    tft.setTextColor(TFT_CYAN, TFT_BLACK);
    tft.setCursor(250, 30);
    tft.printf("RX: %d  ", e.value);
}



}
}
*/