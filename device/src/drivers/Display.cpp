#include "Display.h"
#include <Arduino.h>
#include <TFT_eSPI.h>

static TFT_eSPI tft = TFT_eSPI();

void Display::init() {
    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);
}

void Display::clear() {
    tft.fillScreen(TFT_BLACK);
}

void Display::drawText(int x, int y, const char* text, uint16_t color, uint8_t size) {
    tft.setTextColor(color, TFT_BLACK);
    tft.setTextSize(size);
    tft.setCursor(x, y);
    tft.print(text);
}

void Display::drawFormatted(int x, int y, uint16_t color, uint8_t size, const char* fmt, ...) {
    tft.setTextColor(color, TFT_BLACK);
    tft.setTextSize(size);
    tft.setCursor(x, y);

    char buf[64];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);

    tft.print(buf);
}

    void Display::drawLine(int x1, int y1, int x2, int y2, uint16_t color){}
    void Display::drawRect(int x, int y, int w, int h, uint16_t color){}
    void Display::fillRect(int x, int y, int w, int h, uint16_t color){}

