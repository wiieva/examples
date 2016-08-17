
#include "gfx.h"
#include "gui.h"
#include "gui_router.h"
#include "gui_exec.h"

static int state = 0;

static void guiRecognizer_onShow (GUIWindow *win) {
    gwinProgressbarSetPosition (ghProgressRecording,0);
    gwinSetText(ghButtonStartSpeech,"Start speech",FALSE);
    gwinSetText(ghProgressRecording,"Waiting...",FALSE);
    gwinSetText (ghLabelRecognizeResult,"",FALSE);
}


int guiRecognizer_Progress (int state,int progress,const char *result,const char *subresult) {
    switch (state) {
        case RSRecording: 
            gwinSetText(ghProgressRecording,"Recording...",FALSE);
            break;
        case RSSending: 
            gwinSetText(ghProgressRecording,"Sending...",FALSE);
            break;
        case RSDone: 
            gwinSetText(ghProgressRecording,"Done",FALSE);
            gwinSetText (ghLabelRecognizeResult,result,TRUE);
            gwinSetText (ghLabelRecognizeResult2,subresult,TRUE);
            break;
        case RSError: 
            gwinSetText(ghProgressRecording,"http error!",FALSE);
            gwinSetText (ghLabelRecognizeResult,result,TRUE);
            break;
    }   
    gwinProgressbarSetPosition (ghProgressRecording,progress);
    
    GEvent* pe = geventEventWait(&glistener, 10);

    if (pe && pe->type == GEVENT_GWIN_BUTTON) {
    
        GEventGWinButton *we = (GEventGWinButton *)pe;
        if (we->gwin == ghButtonStartSpeech)
            return 0;
    }
    return 1;
}

void guiRecognizer_startRecognize () {
    gwinSetText(ghButtonStartSpeech,"Stop speech",FALSE);
    gwinSetText (ghLabelRecognizeResult,"",FALSE);
    gwinProgressbarSetPosition (ghProgressRecording,0);
    gfxSleepMilliseconds(200);
    
    guiExec_AudioRecognize (5, gwinCheckboxIsChecked (ghEnableVAD) ,guiRecognizer_Progress);
    gwinSetText(ghButtonStartSpeech,"Start speech",FALSE);

}

static int guiRecognizer_HandleEvent (GUIWindow *win,GEvent *pe) {
    switch (pe->type) {
        case GEVENT_GWIN_BUTTON: {
            GEventGWinButton *we = (GEventGWinButton *)pe;
            if (we->gwin == ghButtonStartSpeech)
                guiRecognizer_startRecognize ();
            else
                return 0;
            return 1;
        }            
    }
    
    return 0;
}

GUIWindow winRecognizer = {
    guiWindow_onInit,
    guiRecognizer_onShow,
    0,
    guiRecognizer_HandleEvent,
    0
};


