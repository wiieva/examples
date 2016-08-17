#include "gfx.h"
#include "gui.h"
#include "gui_router.h"
#include "win_browsefile.h"


int guiWifiSettings_handleEvent (GUIWindow *win,GEvent *event) {
    return 0;
}

void guiWifiSettings_onShow (GUIWindow *win) {
    
}

GUIWindow winWifiSettings = {
    guiWindow_onInit,
    guiWifiSettings_onShow,
    0,
    guiWifiSettings_handleEvent,
    0
};

