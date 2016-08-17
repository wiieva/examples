#!/bin/bash


sed -i '' "s/#define GDISP_NEED_CONVEX_POLYGON FALSE/#define GDISP_NEED_CONVEX_POLYGON TRUE/g" $1/gfxconf.h
sed -i '' "s/wi.customDraw = gwinButtonDraw_Image/extern void gwinButtonDraw_ImageText(GWidgetObject *gw, void *param); wi.customDraw = gwinButtonDraw_ImageText/g" $1/gui.c
sed -i '' "s/wi.g.parent = 0/wi.g.parent = ghContainerMainFrame/g" $1/gui.c


sed -i '' "s/#endif//" $1/gfxconf.h
echo  '
// Additional defines

#ifdef __ets__
#define GFILE_ROMFS_DATA_ATTR __attribute__((section(".irom.text")))
#define _setjmp setjmp
#else
#define GFILE_ROMFS_DATA_ATTR
#endif

#define GFILE_ROMFS_ALIGN32_READ TRUE
#define GDISP_NEED_TEXT_WORDWRAP TRUE
#endif
' >> $1/gfxconf.h

sed -i '' "s/static const/static const GFILE_ROMFS_DATA_ATTR/g" $1/rsc/*.h

