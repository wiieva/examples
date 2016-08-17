#include <gfx.h>
#include "gui.h"
#include "gui_helpers.h"
#include "gui_router.h"
#include "win_mainmenu.h"
#include "win_wifisettings.h"
#include "win_browsefile.h"
#include "win_recognizer.h"
#include "win_audioplayer.h"
#include "win_weather.h"
#include "win_remote.h"

GUIWindow *curWindow =0;

void guiWindow_onInit (GUIWindow *win,GHandle handle,coord_t x,coord_t y,coord_t w,coord_t h) {
    
    win->handle = handle;
    gwinResize(win->handle,w,h); gwinMove(win->handle,x,y);
}

void guiWindow_Show (GUIWindow *win) {
    
    if (win == curWindow)
        return;
    
    if (curWindow && curWindow->onClose)
        curWindow->onClose (curWindow);
    
    if (curWindow)
        gwinHide (curWindow->handle);
    
    curWindow = win;
    
    if (curWindow->onShow)
        curWindow->onShow (curWindow);

    gwinShow (curWindow->handle);
}

void guiWindow_EventLoop(uint32_t timeout) {
    GEvent* pe = geventEventWait(&glistener, 5000);

    if (!pe)
        return;

    if (curWindow && curWindow->onEvent)
        if (curWindow->onEvent (curWindow,pe))
            return;
        
    switch (pe->type) {
        case GEVENT_GWIN_BUTTON: {
            GEventGWinButton *we = (GEventGWinButton *)pe;
            if (we->gwin == ghButtonClose) {
                guiWindow_Show(&winMainMenu);
           }
        }
        break;
#if GINPUT_NEED_KEYBOARD
        case GEVENT_KEYBOARD: {
            GEventKeyboard *ke = (GEventKeyboard *)pe;
            uint8_t c = ke->c[0];
            if (c == GKEY_RIGHT || c == GKEY_DOWN || c == GKEY_LEFT || c == GKEY_UP) {
                guiMoveKeyboardFocus (c);
            }
#endif
        }
        break;
    }
}

void guiInit () {
    gfxInit();
    gdispSetBacklight(100);
    gdispSetContrast(100);

    geventListenerInit(&glistener);
    geventAttachSource(&glistener, ginputGetKeyboard(0), 0);
    gwinAttachListener(&glistener);

    guiCreate();

    coord_t y = ghContainerStatus->height;
    coord_t height = ghContainerMainFrame->height - y - ghContainerNavkeys->height;
    coord_t width = ghContainerMainFrame->width;

    winMainMenu.onInit (&winMainMenu,ghContainerMainMenu,0,y,width,height);
    winBrowseFile.onInit (&winBrowseFile,ghContainerBrowseFile,0,y,width,height);
    winWifiSettings.onInit (&winWifiSettings,ghContainerWifiSettings,0,y,width,height);
    winRecognizer.onInit (&winRecognizer,ghContainerRecognizer,0,y,width,height);
    winRemote.onInit (&winRemote,ghContainerRemoteControl,0,y,width,height);
    winWeather.onInit (&winWeather,ghContainerWeather,0,y,width,height);

    guiWindow_Show(&winMainMenu);
}
