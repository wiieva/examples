#include "gfx.h"
#include "gui.h"
#include "gui_router.h"
#include "win_mainmenu.h"
#include "win_wifisettings.h"
#include "win_browsefile.h"
#include "win_remote.h"
#include "win_weather.h"
#include "win_recognizer.h"

static int guiMainMenu_handleEvent (GUIWindow *win,GEvent *pe) {
    switch (pe->type) {
        case GEVENT_GWIN_BUTTON: {
            GEventGWinButton *we = (GEventGWinButton *)pe;
            if (we->gwin == ghButtonSettings)
                guiWindow_Show (&winWifiSettings);
            else if (we->gwin == ghButtonPlayer)
                guiWindow_Show (&winBrowseFile);
            else if (we->gwin == ghButtonRecognize)
                guiWindow_Show (&winRecognizer);
            else if (we->gwin == ghButtonWeather)
                guiWindow_Show (&winWeather);
            else if (we->gwin == ghButtonRemote)
                guiWindow_Show (&winRemote);
            else
                return 0;
            return 1;
        }
        break;
    }
    return 0;
}

GUIWindow winMainMenu = {
    guiWindow_onInit,
    0,
    0,
    guiMainMenu_handleEvent,
    0
};

