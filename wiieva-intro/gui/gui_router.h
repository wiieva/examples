#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _GUIWindow {
    void (*onInit) (struct _GUIWindow *win,GHandle handle,coord_t x,coord_t y,coord_t w,coord_t h);
    void (*onShow) (struct _GUIWindow *win);
    void (*onClose) (struct _GUIWindow *win);
    int (*onEvent) (struct _GUIWindow *win,GEvent *e);
    GHandle handle;
} GUIWindow;

void guiWindow_EventLoop(uint32_t timeout);
void guiWindow_Show (GUIWindow *win);
void guiWindow_onInit (GUIWindow *win,GHandle handle,coord_t x,coord_t y,coord_t w,coord_t h);

void guiInit ();


#ifdef __cplusplus
}
#endif
