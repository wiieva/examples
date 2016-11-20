
#include <Arduino.h>
#include <SPI.h>
#include <SdFat.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiievaWiring.h>
#include <WiievaRecorder.h>
#include <WiievaPlayer.h>
#include <WiievaIRSend.h>
#include <WiievaInput.h>

#include "gfx.h"
#include "gui.h"
#include "gui_router.h"
#include "gui_exec.h"

using namespace wiieva;

ESP8266WiFiMulti WiFiMulti;
HTTPClient http;
SdFat SD;

#define UPLOAD_AUDIO_URL "http://www.google.com/speech-api/v2/recognize?output=json&lang=en&key=" GOOGLE_API_KEY
#define PLAY_AUDIO_URL "http://wiieva.com/files/ichwill_128.mp3"


void initLCD ()
{
    AIO_Sys_Info sys_info = {0};
    wiieva::recvBuffer (AIO_CMD_GET_SYSINFO,sizeof (sys_info),(uint8_t*)&sys_info);
    Serial.printf("Wiieva:\r\nhw_version=%08X\r\nsf_version=%08X\r\nhas_touch=%d\r\nhas_nav=%d\r\n",sys_info.hw_ver,sys_info.aio_sw_ver,sys_info.has_touch,sys_info.has_4way);

}

void guiExec_RCCommand (int vendor, int cmd) {
    WiievaIRSend IRSend;
    uint32_t code = 0;
    switch (cmd) {
        case RCCmdPower:      code = 0xA90 ; break;
        case RCCmdVolumePlus: code = 0x490 ; break;
        case RCCmdVolumeMunus:code = 0xC90 ; break;
        case RCCmdProgPlus:   code = 0x090 ; break;
        case RCCmdProgMinus:  code = 0x890 ; break;
        case RCCmdNext:       code = 0x0 ; break;
        case RCCmdPrev:       code = 0x0 ; break;
        case RCCmdPause:      code = 0x0 ; break;
    };

    Serial.printf("send ir =%04X\n",code);
    for (int i = 0; i < 5;++i) {
        IRSend.sendSony(code,12);
        yield ();
        delay (45);
    }
}

void ParseGoogleJson (char *buf,const char *str,size_t buf_len) {

    *buf = 0;
    while (buf_len>3) {
        str = strstr (str, "\"transcript\":\"");
        if (!str)
            break;
        str += 14;
        char *_end = strchr (str,'\"');
        size_t len = _end?_end-str:strlen (str);
        if (len > buf_len-2)
            len = buf_len-2;
        strncpy (buf,str,len);
        buf[len++] = ';';
        buf[len] = 0;
        buf += len;
        str += len;
        buf_len -= len;
    }
}

int guiExec_AudioRecognize (int seconds,int vad,guiCb_RecognizeProgress callback) {

    WiievaRecorder recorder (2000*seconds);

    Serial.printf ("Start recording\r\n");
    recorder.start (AIO_AUDIO_IN_SPEEX);

    int res, cb_res;
    int millis_start = millis();
    int vad_pause_cnt = 0;

    do {
        res = recorder.run ();
        cb_res = callback (RSRecording,recorder.recordedSize() * 100 / (seconds*2000),0,0);

        // check VAD if need
        if (vad && millis () - millis_start > 1000 && !recorder.checkVad())
            vad_pause_cnt++;
        else
            vad_pause_cnt = 0;
    } while (res && cb_res && vad_pause_cnt < 30);

    recorder.stop ();
    cb_res = callback (RSSending,20,0,0);

    http.begin(UPLOAD_AUDIO_URL);
    http.addHeader ("Content-Type","audio/x-speex-with-header-byte; rate=8000");
    int httpCode = http.sendRequest ("POST",&recorder,recorder.recordedSize());

    if(httpCode > 0) {
        Serial.printf("[HTTP] POST... code: %d\r\n", httpCode);
        String payload = http.getString();
        Serial.println(payload);
        if(httpCode == HTTP_CODE_OK) {
            char tmpBuf[512];
            ParseGoogleJson(tmpBuf,payload.c_str(),sizeof (tmpBuf));
            char *subres = strstr (tmpBuf,";");
            if (subres)
                *subres++ = 0;

            cb_res = callback (RSDone,100,tmpBuf,subres);
        } else
        {
            cb_res = callback (RSError,100,payload.c_str(),0);
        }

    } else {
        Serial.printf("[HTTP] POST... failed, error: %s\r\n", http.errorToString(httpCode).c_str());
        cb_res = callback (RSError,100,http.errorToString(httpCode).c_str(),0);
    }

    http.end();
    return 0;

}
int guiExec_getFileList (const char *dirName,guiCb_FileFound callback) {

    File dir;
    char name[128];
    dir = SD.open(dirName);
    if (!dir)
        return 0;

    for (;;) {

        File entry =  dir.openNextFile();
        if (! entry)
            break;
        name[0] = 0;
        entry.getName(name,sizeof (name));
        if (name[0] != '.')
        {
            callback (entry.isDirectory(),name);
            entry.close();
        }
    }
    dir.close();
}


int guiExec_playFile (const char *fileName,guiCb_PlayProgress callback) {

    WiievaPlayer player (10000);
    File f = SD.open(fileName);

    if (!f) {
        Serial.printf ("Can't open file\r\n");
        return 0;
    }

    Serial.printf ("Start playing\r\n");
    player.start (AIO_AUDIO_OUT_MP3);

    while (callback (10))
        player.run(f);

    Serial.printf ("Stop playing\r\n");
    player.stop ();
    f.close();
    return 1;

}

void setup ()
{
    Serial.begin (115200);
    Serial.setDebugOutput(true);

    initLCD ();
    guiInit ();

    yield ();
    WiFiMulti.addAP("gp_home", "12345ABCDE");
    WiFiMulti.addAP("Restream", "HelloRestream");

   if (!SD.begin(WIIEVA_SD_CS))
       Serial.println("Error init microsd card!");
    wdt_disable();

}

void startPlayUrl ()
{
    WiievaPlayer player (40000);

    Serial.printf ("Start playing\r\n");

    http.begin(PLAY_AUDIO_URL);
    int httpCode = http.GET  ();
    Serial.printf("[HTTP] GET... code: %d\r\n", httpCode);
    if(httpCode != HTTP_CODE_OK)
        return;
    player.start (AIO_AUDIO_OUT_MP3);

    while ( !digitalRead (WIIEVA_KB_PWR))
        player.run(http.getStream());

    Serial.printf ("Stop playing\r\n");
    player.stop ();

    while (digitalRead (WIIEVA_KB_PWR));
}


void loop ()
{
    static uint16_t prev = 0;

    guiWindow_EventLoop(2);
    WiFiMulti.run();

    uint16_t cur = sendCommand (AIO_CMD_TEST,SEND_CMD_FL_ANSWER);
    if (cur != prev +1)
       Serial.printf ("ERROR !!!!!!!!!%d -> %d\r\n",prev,cur);
    prev = cur;
}
