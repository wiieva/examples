#include "gfx.h"
#include "gui.h"
#include "gui_router.h"

void guiWeather_onShow (GUIWindow *win) {
}

int guiWeather_HandleEvent (GUIWindow *win,GEvent *event) {
    return 0;
}

GUIWindow winWeather = {
    guiWindow_onInit,
    guiWeather_onShow,
    0,
    guiWeather_HandleEvent,
    0
};


