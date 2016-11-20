cmake_minimum_required(VERSION 2.8)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release")

set(PRJ guisimulator)
project(${PRJ})
set(GFXLIB /Users/oleg/Projects/my/uGFX)

file (GLOB_RECURSE gfx_SRC ${GFXLIB}/src/*)
file (GLOB_RECURSE gfx_mk_SRC ${GFXLIB}/src/*_mk.c)
file (GLOB_RECURSE gfx_font_SRC ${GFXLIB}/src/gdisp/fonts/*)
list (REMOVE_ITEM  gfx_SRC ${gfx_mk_SRC} ${gfx_font_SRC})

file (GLOB gui_SRC *.c ../*.c ../output/gui.c)

set(SRCS
	${gui_SRC}
	${gfx_SRC}
    ${GFXLIB}/drivers/multiple/SDL/gdisp_lld_SDL.c

)

set(INCLUDES
    ${GFXLIB}/drivers/multiple/SDL
    ../output/rsc
    ../output
    ..
    ${GFXLIB}
)

add_definitions (-DGDISP_SCREEN_WIDTH=176 -DGDISP_SCREEN_HEIGHT=220 -DGFX_OS_PRE_INIT_FUNCTION=sdl_driver_init -DGFX_USE_OS_OSX=TRUE)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fmax-type-align=4" )

find_package (sdl2)
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(${PRJ} ${SRCS})
target_include_directories(${PRJ} PRIVATE ${INCLUDES})
target_link_libraries(${PRJ} ${LIBRARIES} ${SDL2_LIBRARIES})
