#include <gfx.h>
#include <string.h>
#include <src/gwin/gwin_class.h>
#include "gui.h"
#include "gui_helpers.h"


#define MAXCOORD 32767

#if GINPUT_NEED_KEYBOARD
void guiMoveKeyboardFocus (uint8_t c) {

    GHandle focused = gwinGetFocus ();
    GHandle	gh, best = focused, next = focused;

    coord_t x = (c==GKEY_LEFT)?0:MAXCOORD;
    coord_t y = (c==GKEY_UP)?0:MAXCOORD;

    // Do not grab left right from input
    if (focused && focused->vmt && !strcmp (((gwidgetVMT*)focused->vmt)->g.classname ,"TextEdit"))
        if (c== GKEY_RIGHT||c== GKEY_LEFT)
            return;

    // Do not grab left right from list
    if (focused && focused->vmt && !strcmp (((gwidgetVMT*)focused->vmt)->g.classname ,"List"))
        if (c== GKEY_UP||c== GKEY_DOWN)
            return;

    for(gh = gwinGetNextWindow(focused); ; gh = gwinGetNextWindow(gh)) {
        if (!gh) {
            if (!focused)
                break;
            else
                gh = gwinGetNextWindow(0);
        }
        if (gh == focused)
            break;

        if ((gh->flags & (GWIN_FLG_WIDGET|GWIN_FLG_ENABLED|GWIN_FLG_SYSENABLED|GWIN_FLG_VISIBLE|GWIN_FLG_SYSVISIBLE))
                != (GWIN_FLG_WIDGET|GWIN_FLG_ENABLED|GWIN_FLG_SYSENABLED|GWIN_FLG_VISIBLE|GWIN_FLG_SYSVISIBLE) ||
                !(((gwidgetVMT*)gh->vmt)->KeyboardEvent)
                )
            continue;
        if ((c == GKEY_RIGHT || c == GKEY_DOWN) && next == focused)
            next = gh;

        if ((c == GKEY_UP || c == GKEY_LEFT))
            next = gh;

        if ((c == GKEY_RIGHT && gh->x > focused->x && gh->x <= x && abs(gh->y - focused->y) <= y) ||
            (c == GKEY_LEFT && gh->x < focused->x && gh->x >= x && abs(gh->y - focused->y) <= y))
        {
            best = gh; x = gh->x; y = abs(gh->y - focused->y);
        } else if ((c == GKEY_DOWN && gh->y > focused->y && gh->y <= y && abs(gh->x - focused->x) <= x) ||
                (c == GKEY_UP && gh->y < focused->y && gh->y >= y && abs(gh->x - focused->x) <= x)) {
            best = gh; y = gh->y; x = abs(gh->x - focused->x);
        }
    }
    gwinSetFocus(best==focused?next:best);

}

static void guiDrawFocusRect(GWidgetObject *gx, coord_t x, coord_t y, coord_t cx, coord_t cy) {
    uint16_t i;

    for (i = 0; i < GWIN_FOCUS_HIGHLIGHT_WIDTH; i++) {
        gdispGDrawBox(gx->g.display, gx->g.x+x+i, gx->g.y+y+i, cx-2*i, cy-2*i, (&gx->g == gwinGetFocus())?gx->pstyle->focus:gx->pstyle->background);
    }
}
#endif

void gwinButtonDraw_ImageText(GWidgetObject *gw, void *param) {
    coord_t sy;

    const GColorSet* colors;
    if (!gwinGetEnabled((GHandle)gw)) {
        colors = &gw->pstyle->disabled;
        sy = 2 * gw->g.height;
    } else if ((gw->g.flags & GBUTTON_FLG_PRESSED)) {
        colors = &gw->pstyle->pressed;
        sy = 0;
    } else {
        colors = &gw->pstyle->enabled;
        sy = 0;
    }

    gdispImage *img = (gdispImage*)param;

    int x = gdispGImageDraw(gw->g.display, img, gw->g.x + (gw->g.width-img->width)/2, gw->g.y+1, gw->g.width, gw->g.height, 0, sy);

    gdispGDrawStringBox(gw->g.display, gw->g.x+1, gw->g.y+gw->g.height-15 , gw->g.width-2, 15, gw->text, gw->g.font, colors->text, justifyCenter);

#if GINPUT_NEED_KEYBOARD
    // Render highlighted border if focused
    guiDrawFocusRect (gw, 0, 0, gw->g.width-1, gw->g.height-1);
#endif
}
