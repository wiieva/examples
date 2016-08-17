cmake_minimum_required (VERSION 3.0)
INCLUDE (CMakeForceCompiler)

set (ESP_ROOT     /Users/oleg/projects/my/Arduino)
set (VARIANT      wiieva)
set (FLASH_LAYOUT eagle.flash.512k0.ld)
SET (FLASH_SIZE   4M)

set (ESP_LIBS   ${ESP_ROOT}/libraries)
set (TOOLS_ROOT ${ESP_ROOT}/tools)
set (TOOLS_BIN  ${TOOLS_ROOT}/xtensa-lx106-elf/bin)
set (SDK_ROOT   ${ESP_ROOT}/tools/sdk)
file (GLOB ESP_TOOL ${TOOLS_ROOT}/esptool/esptool)
file (GLOB MKSPIFFS ${TOOLS_ROOT}/mkspiffs/mkspiffs)
set (UPLOAD_RATE 921600)
set (UPLOAD_DEV  /dev/tty.usb*)

set (spiffsdir ${CMAKE_SOURCE_DIR}/spiffs)
set (SPIFFS_ADDR 0x6B000)
set (SPIFFS_SIZE 64k)
set (SPIFFS_ENABLE 0)

set (ARDUINO_LIBS
    "${ESP_LIBS}/ugfx-wiieva-lcd"
    "${ESP_LIBS}/ESP8266WiFi/src"
	"${ESP_LIBS}/ESP8266HTTPClient/src"
	"${ESP_LIBS}/SPI"
    "${ESP_LIBS}/SD/src"
    "${ESP_LIBS}/SD/src/utility")

set (CMAKE_SYSTEM_NAME Linux)
set (CMAKE_SYSTEM_PROCESSOR arm)
CMAKE_FORCE_C_COMPILER (xtensa-lx106-elf-gcc GNU)
CMAKE_FORCE_CXX_COMPILER (xtensa-lx106-elf-g++ GNU)
set (CMAKE_ASM_COMPILER xtensa-lx106-elf-gcc)
set (CMAKE_OBJCOPY xtensa-lx106-elf-objcopy)
set (CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set (CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set (CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
enable_language (ASM)

set (PRJ wiieva-intro)
project (${PRJ})

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

function(PREPEND var suffix)
   set(listVar "")
   foreach(f ${ARGN})
      list(APPEND listVar "${f}${suffix}")
   endforeach(f)
   set(${var} "${listVar}" PARENT_SCOPE)
endfunction(PREPEND)

file (GLOB sketch_SRC "*.cpp" "*.c" "*.h" "gui/*.c" "gui/output/gui.c")


file (GLOB_RECURSE core_SRC 
        ${ESP_ROOT}/cores/esp8266/*
        ${ESP_ROOT}/variants/${VARIANT}/*
)

prepend (libs_SRCS_Path "/*" ${ARDUINO_LIBS})
file (GLOB libs_SRC ${libs_SRCS_Path})
set (SRCS ${sketch_SRC} ${core_SRC} ${libs_SRC})

set (INCLUDES
        ${ESP_ROOT}/cores/esp8266/
        ${ESP_ROOT}/variants/${VARIANT}
        ${SDK_ROOT}/include
        ${SDK_ROOT}/lwip/include
        ${ARDUINO_LIBS}
        ${ESP_LIBS}/ugfx
        ${ESP_LIBS}/ugfx/src
        gui
        gui/output
)

add_definitions(-DGFX_USE_OS_ARDUINO=TRUE -DGFX_OS_INIT_NO_WARNING)
add_definitions(-DGOOGLE_API_KEY="${GOOGLE_API_KEY}")
add_definitions (-D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ -DF_CPU=160000000L -DARDUINO=10605 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DESP8266)


file (GLOB ldscript ${SDK_ROOT}/ld/${FLASH_LAYOUT})
file (GLOB eboot ${ESP_ROOT}/bootloaders/eboot/eboot.elf)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections")
set (CMAKE_ASM_FLAGS "-g -x assembler-with-cpp -MMD")
set (CMAKE_EXE_LINKER_FLAGS "-w -nostdlib -Wl,--no-check-sections -u call_user_start -Wl,-static -Wl,-script=${ldscript} -Wl,--gc-sections -Wl,-wrap,system_restart_local -Wl,-wrap,register_chipv6_phy -Wl,--start-group")
link_directories(${SDK_ROOT}/lib ${SDK_ROOT}/libc/xtensa-lx106-elf/lib)

add_executable (${PRJ} ${SRCS})
target_include_directories (${PRJ} PRIVATE ${INCLUDES})
target_link_libraries (${PRJ} hal phy net80211 lwip wpa main pp smartconfig wps crypto axtls c m gcc  stdc++ -Wl,--end-group)
add_custom_command (TARGET ${PRJ} POST_BUILD COMMAND ${ESP_TOOL} ARGS -eo ${eboot} -bo ${PRJ}.bin -bz ${FLASH_SIZE} -bs .text -bp 4096 -ec -eo ${PRJ} -bs .irom0.text -bs .text -bs .data -bs .rodata -bc -ec )

if (SPIFFS_ENABLE)
    add_custom_command (TARGET ${PRJ} PRE_BUILD COMMAND ${MKSPIFFS} -c ${spiffsdir} ${PRJ}.spiffs )
    add_custom_target (upload COMMAND ${ESP_TOOL} -q -cd nodemcu -cb ${UPLOAD_RATE} -cp ${UPLOAD_DEV} -ca 0x00000 -cf ${PRJ}.bin -ca ${SPIFFS_ADDR} -cf ${PRJ}.spiffs )
else ()
    add_custom_target (upload COMMAND ${ESP_TOOL} -q -cd nodemcu -cb ${UPLOAD_RATE} -cp ${UPLOAD_DEV} -ca 0x00000 -cf ${PRJ}.bin )
endif ()
