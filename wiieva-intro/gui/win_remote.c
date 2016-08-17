#include "gfx.h"
#include "gui.h"
#include "gui_router.h"
#include "gui_exec.h"

void guiRemote_onShow (GUIWindow *win) {
}



int guiRemote_HandleEvent (GUIWindow *win,GEvent *event) {
   switch (event->type) {
        case GEVENT_GWIN_BUTTON: {
            GEventGWinButton *we = (GEventGWinButton *)event;
            if (we->gwin == ghButtonRemoteVolumeMinus)
                guiExec_RCCommand (0,RCCmdVolumeMunus);
            else if (we->gwin == ghButtonRemoteVolumePlus)
                guiExec_RCCommand (0,RCCmdVolumePlus);
            else if (we->gwin == ghButtonRemotePower)
                guiExec_RCCommand (0,RCCmdPower);
            else if (we->gwin == ghButtonRemoteProgPlus)
                guiExec_RCCommand (0,RCCmdProgPlus);
            else if (we->gwin == ghButtonRemoteProgMinus)
                guiExec_RCCommand (0,RCCmdProgMinus);
            else if (we->gwin == ghButtonRemoteNext)
                guiExec_RCCommand (0,RCCmdNext);
            else if (we->gwin == ghButtonRemoteNext)
                guiExec_RCCommand (0,RCCmdPrev);
            else
                return 0;
            return 1;
        }
        break;
    }
    return 0;
}

GUIWindow winRemote = {
    guiWindow_onInit,
    guiRemote_onShow,
    0,
    guiRemote_HandleEvent,
    0
};


