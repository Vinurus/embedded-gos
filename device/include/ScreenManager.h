#pragma once
#include "screens/Screen.h"

extern Screen* currentScreen;
extern Screen* previousScreen;

void setScreen(Screen* s);
bool isNewScreen();

