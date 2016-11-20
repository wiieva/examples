#!/bin/bash


sed -i '' "s/#define GDISP_NEED_CONVEX_POLYGON FALSE/#define GDISP_NEED_CONVEX_POLYGON TRUE/g" $1/gfxconf.h
sed -i '' "s/wi.customDraw = gwinButtonDraw_Image/extern void gwinButtonDraw_ImageText(GWidgetObject *gw, void *param); wi.customDraw = gwinButtonDraw_ImageText/g" $1/gui.c
sed -i '' "s/wi.g.parent = 0/wi.g.parent = ghContainerMainFrame/g" $1/gui.c


sed -i '' "s/#endif//" $1/gfxconf.h
echo  '
// Additional defines

#ifdef __ets__
#define GFX_ROM_DATA_ATTR __attribute__((section(".irom.text")))
#define GFX_NEED_ROM_ALIGN32_READ TRUE
#define _setjmp setjmp
#endif

#define GDISP_NEED_TEXT_WORDWRAP TRUE
#endif
' >> $1/gfxconf.h

sed -i '' "s/static const char/static const GFX_ROM_DATA_ATTR char/g" $1/rsc/{*.h,*.c}
sed -i '' "s/static const uint/static const GFX_ROM_DATA_ATTR uint/g" $1/rsc/{*.h,*.c}
sed -i '' "s/static const ROMFS_DIRENTRY/static const GFX_ROM_DATA_ATTR ROMFS_DIRENTRY/g" $1/rsc/{*.h,*.c}
