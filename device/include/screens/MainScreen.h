#include "screens/Screen.h"
#include "MessageBus.h"
#include "Display.h"
#include <TFT_eSPI.h>

class MainScreen : public Screen {
public:
    float speed;
    float dist;
    int sec ;

    void update() override;

    void onEvent(const Event& e) override;

    void render(Display& d) override;
};
