#include "gfx.h"
#include "gui.h"
#include "gui_router.h"
#include "win_browsefile.h"
#include "gui_exec.h"

#define files_grow_gap 32
#define max_path 256

typedef struct {
    int is_dir;
    char *name;
} FileRecord;

static FileRecord *files = 0;
static char        curDir[max_path];
static int         filesCnt=0,filesAlloced = 0;

extern gdispImage folder,file_mp3,file_reg;

void guiBrowseFile_AddFileToList (int dir,const char *name) {
    
    if (filesCnt >= filesAlloced) {
        FileRecord *newfiles = (FileRecord *)malloc (sizeof (FileRecord) * (filesCnt + files_grow_gap));
        if (files) {
            memcpy (newfiles,files,sizeof (FileRecord) * filesCnt);
            free (files);
        }
        files = newfiles;
        memset (files + filesCnt * sizeof (FileRecord),0, sizeof (FileRecord) * files_grow_gap );
        filesAlloced = filesCnt + files_grow_gap;
    }
    
    char visname[max_path];
    strcpy (visname,name);
    int i,width=0;
    
    for ( i = 1; i < strlen (name); ++i) {
        width = gdispGetStringWidthCount (name,ghListFiles->font,i);
        if (width+36 > ghListFiles->width) {
            i--; break;
        }
    }
    visname[i] = 0;

    int id = gwinListAddItem(ghListFiles, visname, TRUE);

    if (dir)
        gwinListItemSetImage (ghListFiles,id,&folder);
    else if (strstr (name,"mp3") || strstr (name,"MP3"))
        gwinListItemSetImage (ghListFiles,id,&file_mp3);
    else 
        gwinListItemSetImage (ghListFiles,id,&file_reg);
    
    files[filesCnt].name = strdup (name);
    files[filesCnt++].is_dir = dir;
     
}


static void guiBrowseFile_ClearFileRecords () {
    int i = 0;
    for (i = 0; i < filesCnt; ++i)
        free (files[i].name);
    free (files);
    files = 0;
    filesCnt = 0;
    filesAlloced = 0;
}


static void guiBrowseFile_Opendir(const char *dir) {

    guiBrowseFile_ClearFileRecords ();
    
    if (gwinListItemCount(ghListFiles))
        gwinListSetSelected(ghListFiles,0,TRUE);
    gwinListDeleteAll(ghListFiles);

    guiBrowseFile_AddFileToList (1,"..");
    strcpy (curDir,dir);
    int res = guiExec_getFileList (curDir, guiBrowseFile_AddFileToList);

}

static void guiBrowseFile_onShow (GUIWindow *win) {

    guiBrowseFile_Opendir("/");
}

static void guiBrowseFile_onHide (GUIWindow *win) {

    guiBrowseFile_ClearFileRecords ();
}


int guiBrowseFile_PlayProgress (int progress) {
    GEvent* pe = geventEventWait(&glistener, 1);

    if (pe /*&& pe->type == GEVENT_GWIN_BUTTON*/) 
        return 0;
    return 1;
}

int guiBrowseFile_PlayFile () {
    char fullPath[max_path];
    strcpy (fullPath,curDir);
    
    int idx = gwinListGetSelected(ghListFiles);
    
    if (idx >= filesCnt || idx < 0)
        return 0;
    if (files[idx].is_dir) {
        if (!strcmp (files[idx].name,"..")) {
            fullPath[strlen(fullPath)-1] = 0;
            char *p = strrchr (fullPath,'/');
            if (p)
                *(p+1) = 0;
        } else
        {
        
            strcat (fullPath,files[idx].name);
            strcat (fullPath,"/");
        }
        guiBrowseFile_Opendir (fullPath);
        return 1;
    }
    strcat (fullPath,files[idx].name);
    guiExec_playFile(fullPath,guiBrowseFile_PlayProgress);
    return 1;
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
    guiBrowseFile_onHide,
    guiBrowseFile_HandleEvent,
    0
};

