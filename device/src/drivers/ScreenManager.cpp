#include "screens/Screen.h"



Screen* currentScreen = nullptr;
Screen* previousScreen = nullptr;


void setScreen(Screen* s) {
    previousScreen = currentScreen;
    currentScreen = s;
    
    
    
}

bool isNewScreen(){
    if(currentScreen != previousScreen)
        return true;
    return false;
}