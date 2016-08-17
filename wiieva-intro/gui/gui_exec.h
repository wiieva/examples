#pragma once

#ifdef __cplusplus
extern "C" {
#endif

enum RCCommands
{
    RCCmdPower,
    RCCmdVolumePlus,
    RCCmdVolumeMunus,
    RCCmdProgPlus,
    RCCmdProgMinus,
    RCCmdNext,
    RCCmdPrev,
    RCCmdPause
};

void guiExec_RCCommand (int vendor, int cmd);



enum RecognizeStates {
	RSRecording,
	RSSending,
	RSError,
	RSDone
};

typedef int (*guiCb_RecognizeProgress) (int state,int progress,const char *result,const char *subresult);
int guiExec_AudioRecognize (int seconds,int vad,guiCb_RecognizeProgress callback);

typedef void (*guiCb_FileFound) (int isDir,const char *name);
int guiExec_getFileList (const char *dir,guiCb_FileFound callback);

typedef int (*guiCb_PlayProgress) (int progress);
int guiExec_playFile (const char *fileName,guiCb_PlayProgress callback);





#ifdef __cplusplus
}
#endif
