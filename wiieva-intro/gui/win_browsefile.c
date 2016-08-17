#include "gfx.h"
#include "gui.h"
#include "gui_router.h"
#include "win_browsefile.h"
#include "gui_exec.h"

static char curDir[256];

void guiBrowseFile_AddFileToList (int dir,const char *name) {

    gwinListAddItem(ghListFiles, name, TRUE);

}

static void guiBrowseFile_onShow (GUIWindow *win) {

    gwinListDeleteAll(ghListFiles);
    strcpy (curDir,"/");
    int res = guiExec_getFileList (curDir, guiBrowseFile_AddFileToList);
}

int guiBrowseFile_PlayProgress (int progress) {
    GEvent* pe = geventEventWait(&glistener, 1);

    if (pe /*&& pe->type == GEVENT_GWIN_BUTTON*/) 
        return 0;
    return 1;
}

int guiBrowseFile_PlayFile () {
    char fullPath[256];
    strcpy (fullPath,curDir);
    
    const char *fname = gwinListGetSelectedText(ghListFiles);
    strcat (fullPath,fname);
    guiExec_playFile(fullPath,guiBrowseFile_PlayProgress);

}

static int guiBrowseFile_HandleEvent (GUIWindow *win,GEvent *pe) {
    switch (pe->type) {
        case GEVENT_GWIN_LIST: {
            GEventGWinList *le = (GEventGWinList *)pe;
            guiBrowseFile_PlayFile ();
            return 1;
        }
    }
    return 0;
}

GUIWindow winBrowseFile = {
    guiWindow_onInit,
    guiBrowseFile_onShow,
    0,
    guiBrowseFile_HandleEvent,
    0
};

