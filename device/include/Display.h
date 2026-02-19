#pragma once
#include <stdint.h>
#include <TFT_eSPI.h>

class Display {
public:
    void init();
    void clear();

    void drawText(int x, int y, const char* text,
                  uint16_t color = 0xFFFF,
                  uint8_t size = 2);

    void drawFormatted(int x, int y,
                       uint16_t color,
                       uint8_t size,
                       const char* fmt, ...);

    void drawLine(int x1, int y1, int x2, int y2, uint16_t color);
    void drawRect(int x, int y, int w, int h, uint16_t color);
    void fillRect(int x, int y, int w, int h, uint16_t color);
};
