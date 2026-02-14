#include "screens/Screen.h"

Screen* currentScreen = nullptr;

void setScreen(Screen* s) {
    currentScreen = s;
}
