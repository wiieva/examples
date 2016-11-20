/******************************************************************************/
/* This file has been generated by the uGFX-Studio                            */
/*                                                                            */
/* http://ugfx.org                                                            */
/******************************************************************************/

#include "colors.h"
#include "widgetstyles.h"
#include "gui.h"

// GListeners
GListener glistener;

// GHandles
GHandle ghContainerMainFrame;
GHandle ghContainerStatus;
GHandle ghImagebox1_1;
GHandle ghLabelSsid;
GHandle ghLabelBatt;
GHandle ghLabelTime;
GHandle ghImagebox1;
GHandle ghContainerNavkeys;
GHandle ghLabel6;
GHandle ghButtonClose;
GHandle ghButtonMenu;
GHandle ghContainerMainMenu;
GHandle ghButtonPlayer;
GHandle ghButtonRecognize;
GHandle ghButtonWeather;
GHandle ghButtonRemote;
GHandle ghButtonSettings;
GHandle ghContainerWifiSettings;
GHandle ghKeyboard1;
GHandle ghInputPassword;
GHandle ghInputSSID;
GHandle ghLabel5_1;
GHandle ghLabel5;
GHandle ghContainerBrowseFile;
GHandle ghListFiles;
GHandle ghLabel5;
GHandle ghContainerAudioPlayer;
GHandle ghLabel5;
GHandle ghButton1;
GHandle ghButton1_1;
GHandle ghButton1_2;
GHandle ghContainerRemoteControl;
GHandle ghLabel5;
GHandle ghButtonRemotePower;
GHandle ghButtonRemoteVolumePlus;
GHandle ghButtonRemoteVolumeMinus;
GHandle ghButtonRemoteProgMinus;
GHandle ghButtonRemoteProgPlus;
GHandle ghButtonRemotePrev;
GHandle ghButtonRemotePause;
GHandle ghButtonRemoteNext;
GHandle ghLabel5_2;
GHandle ghImagebox3;
GHandle ghContainerWeather;
GHandle ghLabel5;
GHandle ghImagebox2;
GHandle ghImagebox2_1;
GHandle ghImagebox2_2;
GHandle ghLabelTemperature;
GHandle ghLabelHumidity;
GHandle ghLabelPressure;
GHandle ghContainerRecognizer;
GHandle ghButtonStartSpeech;
GHandle ghProgressRecording;
GHandle ghEnableVAD;
GHandle ghLabelRecognizeResult;
GHandle ghLabelRecognizeResult2;

// Fonts
font_t dejavu_sans_10;
font_t dejavu_sans_16;

// Images
gdispImage back;
gdispImage menu;
gdispImage music;
gdispImage mic;
gdispImage weather;
gdispImage remote;
gdispImage gear;
gdispImage file_reg;
gdispImage file_mp3;
gdispImage folder;

static void createPageMainFrame(void)
{
	GWidgetInit wi;
	gwinWidgetClearInit(&wi);


	// create container widget: ghContainerMainFrame
	wi.g.show = FALSE;
	wi.g.x = 0;
	wi.g.y = 0;
	wi.g.width = 176;
	wi.g.height = 220;
	wi.g.parent = ghContainerMainFrame;
	wi.text = "Container";
	wi.customDraw = 0;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghContainerMainFrame = gwinContainerCreate(0, &wi, 0);

	// create container widget: ghContainerNavkeys
	wi.g.show = TRUE;
	wi.g.x = 0;
	wi.g.y = 198;
	wi.g.width = 176;
	wi.g.height = 22;
	wi.g.parent = ghContainerMainFrame;
	wi.text = "Container1";
	wi.customDraw = gwinContainerDraw_Std;
	wi.customParam = 0;
	wi.customStyle = &white_copy;
	ghContainerNavkeys = gwinContainerCreate(0, &wi, 0);

	// create container widget: ghContainerStatus
	wi.g.show = TRUE;
	wi.g.x = 0;
	wi.g.y = 0;
	wi.g.width = 176;
	wi.g.height = 18;
	wi.g.parent = ghContainerMainFrame;
	wi.text = "";
	wi.customDraw = gwinContainerDraw_Std;
	wi.customParam = 0;
	wi.customStyle = &white_copy;
	ghContainerStatus = gwinContainerCreate(0, &wi, 0);

	// create button widget: ghImagebox1_1
	wi.g.show = TRUE;
	wi.g.x = 141;
	wi.g.y = 1;
	wi.g.width = 16;
	wi.g.height = 16;
	wi.g.parent = ghContainerStatus;
	ghImagebox1_1 = gwinImageCreate(0, &wi.g);
	gwinImageOpenFile(ghImagebox1_1, "rsc/batt_full_chg.bmp");

	// Create label widget: ghLabelSsid
	wi.g.show = TRUE;
	wi.g.x = 2;
	wi.g.y = 2;
	wi.g.width = 50;
	wi.g.height = 14;
	wi.g.parent = ghContainerStatus;
	wi.text = "gp_home";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = &white_copy;
	ghLabelSsid = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(ghLabelSsid, FALSE);

	// Create label widget: ghLabelBatt
	wi.g.show = TRUE;
	wi.g.x = 111;
	wi.g.y = 2;
	wi.g.width = 32;
	wi.g.height = 14;
	wi.g.parent = ghContainerStatus;
	wi.text = "100%";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = &white_copy;
	ghLabelBatt = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(ghLabelBatt, FALSE);

	// Create label widget: ghLabelTime
	wi.g.show = TRUE;
	wi.g.x = 73;
	wi.g.y = 2;
	wi.g.width = 30;
	wi.g.height = 14;
	wi.g.parent = ghContainerStatus;
	wi.text = "12:00";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = &white_copy;
	ghLabelTime = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(ghLabelTime, FALSE);
	gwinSetFont(ghLabelTime, dejavu_sans_10);
	gwinRedraw(ghLabelTime);

	// create button widget: ghImagebox1
	wi.g.show = TRUE;
	wi.g.x = 157;
	wi.g.y = 0;
	wi.g.width = 16;
	wi.g.height = 16;
	wi.g.parent = ghContainerStatus;
	ghImagebox1 = gwinImageCreate(0, &wi.g);
	gwinImageOpenFile(ghImagebox1, "rsc/wifi_full.bmp");

	// Create label widget: ghLabel6
	wi.g.show = TRUE;
	wi.g.x = 88;
	wi.g.y = 0;
	wi.g.width = 0;
	wi.g.height = 22;
	wi.g.parent = ghContainerNavkeys;
	wi.text = "";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = &unnamed;
	ghLabel6 = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(ghLabel6, TRUE);

	// create button widget: ghButtonClose
	wi.g.show = TRUE;
	wi.g.x = 2;
	wi.g.y = 1;
	wi.g.width = 86;
	wi.g.height = 20;
	wi.g.parent = ghContainerNavkeys;
	wi.text = "";
	extern void gwinButtonDraw_ImageText(GWidgetObject *gw, void *param); wi.customDraw = gwinButtonDraw_ImageText;
	wi.customParam = &back;
	wi.customStyle = &white_copy;
	ghButtonClose = gwinButtonCreate(0, &wi);

	// create button widget: ghButtonMenu
	wi.g.show = TRUE;
	wi.g.x = 90;
	wi.g.y = 1;
	wi.g.width = 86;
	wi.g.height = 20;
	wi.g.parent = ghContainerNavkeys;
	wi.text = "";
	extern void gwinButtonDraw_ImageText(GWidgetObject *gw, void *param); wi.customDraw = gwinButtonDraw_ImageText;
	wi.customParam = &menu;
	wi.customStyle = &white_copy;
	ghButtonMenu = gwinButtonCreate(0, &wi);
}

static void createPageMainMenu(void)
{
	GWidgetInit wi;
	gwinWidgetClearInit(&wi);


	// create container widget: ghContainerMainMenu
	wi.g.show = FALSE;
	wi.g.x = 0;
	wi.g.y = 0;
	wi.g.width = 176;
	wi.g.height = 220;
	wi.g.parent = ghContainerMainFrame;
	wi.text = "Container";
	wi.customDraw = 0;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghContainerMainMenu = gwinContainerCreate(0, &wi, 0);

	// create button widget: ghButtonPlayer
	wi.g.show = TRUE;
	wi.g.x = 2;
	wi.g.y = 17;
	wi.g.width = 56;
	wi.g.height = 66;
	wi.g.parent = ghContainerMainMenu;
	wi.text = "Player";
	extern void gwinButtonDraw_ImageText(GWidgetObject *gw, void *param); wi.customDraw = gwinButtonDraw_ImageText;
	wi.customParam = &music;
	wi.customStyle = 0;
	ghButtonPlayer = gwinButtonCreate(0, &wi);

	// create button widget: ghButtonRecognize
	wi.g.show = TRUE;
	wi.g.x = 60;
	wi.g.y = 17;
	wi.g.width = 56;
	wi.g.height = 66;
	wi.g.parent = ghContainerMainMenu;
	wi.text = "Speech";
	extern void gwinButtonDraw_ImageText(GWidgetObject *gw, void *param); wi.customDraw = gwinButtonDraw_ImageText;
	wi.customParam = &mic;
	wi.customStyle = 0;
	ghButtonRecognize = gwinButtonCreate(0, &wi);

	// create button widget: ghButtonWeather
	wi.g.show = TRUE;
	wi.g.x = 116;
	wi.g.y = 17;
	wi.g.width = 56;
	wi.g.height = 66;
	wi.g.parent = ghContainerMainMenu;
	wi.text = "Weather";
	extern void gwinButtonDraw_ImageText(GWidgetObject *gw, void *param); wi.customDraw = gwinButtonDraw_ImageText;
	wi.customParam = &weather;
	wi.customStyle = 0;
	ghButtonWeather = gwinButtonCreate(0, &wi);

	// create button widget: ghButtonRemote
	wi.g.show = TRUE;
	wi.g.x = 2;
	wi.g.y = 100;
	wi.g.width = 56;
	wi.g.height = 66;
	wi.g.parent = ghContainerMainMenu;
	wi.text = "Remote";
	extern void gwinButtonDraw_ImageText(GWidgetObject *gw, void *param); wi.customDraw = gwinButtonDraw_ImageText;
	wi.customParam = &remote;
	wi.customStyle = 0;
	ghButtonRemote = gwinButtonCreate(0, &wi);

	// create button widget: ghButtonSettings
	wi.g.show = TRUE;
	wi.g.x = 60;
	wi.g.y = 100;
	wi.g.width = 56;
	wi.g.height = 66;
	wi.g.parent = ghContainerMainMenu;
	wi.text = "Settings";
	extern void gwinButtonDraw_ImageText(GWidgetObject *gw, void *param); wi.customDraw = gwinButtonDraw_ImageText;
	wi.customParam = &gear;
	wi.customStyle = 0;
	ghButtonSettings = gwinButtonCreate(0, &wi);
}

static void createPageWifiSettings(void)
{
	GWidgetInit wi;
	gwinWidgetClearInit(&wi);


	// create container widget: ghContainerWifiSettings
	wi.g.show = FALSE;
	wi.g.x = 0;
	wi.g.y = 0;
	wi.g.width = 176;
	wi.g.height = 220;
	wi.g.parent = ghContainerMainFrame;
	wi.text = "Container";
	wi.customDraw = 0;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghContainerWifiSettings = gwinContainerCreate(0, &wi, 0);

	// Create keyboard widget: ghKeyboard1
	wi.g.show = TRUE;
	wi.g.x = -2;
	wi.g.y = 100;
	wi.g.width = 178;
	wi.g.height = 80;
	wi.g.parent = ghContainerWifiSettings;
	wi.text = "Keyboard1";
	wi.customDraw = gwinKeyboardDraw_Normal;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghKeyboard1 = gwinKeyboardCreate(0, &wi);

	// Create textedit widget: ghInputPassword
	wi.g.show = TRUE;
	wi.g.x = 5;
	wi.g.y = 65;
	wi.g.width = 168;
	wi.g.height = 24;
	wi.g.parent = ghContainerWifiSettings;
	wi.text = "";
	wi.customDraw = gwinTexteditDefaultDraw;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghInputPassword = gwinTexteditCreate(0, &wi, 50);

	// Create textedit widget: ghInputSSID
	wi.g.show = TRUE;
	wi.g.x = 5;
	wi.g.y = 20;
	wi.g.width = 168;
	wi.g.height = 24;
	wi.g.parent = ghContainerWifiSettings;
	wi.text = "default";
	wi.customDraw = gwinTexteditDefaultDraw;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghInputSSID = gwinTexteditCreate(0, &wi, 50);

	// Create label widget: ghLabel5_1
	wi.g.show = TRUE;
	wi.g.x = 5;
	wi.g.y = 46;
	wi.g.width = 120;
	wi.g.height = 18;
	wi.g.parent = ghContainerWifiSettings;
	wi.text = "Wifi password";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghLabel5_1 = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(ghLabel5_1, FALSE);

	// Create label widget: ghLabel5
	wi.g.show = TRUE;
	wi.g.x = 5;
	wi.g.y = 1;
	wi.g.width = 120;
	wi.g.height = 18;
	wi.g.parent = ghContainerWifiSettings;
	wi.text = "Wifi SSID";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghLabel5 = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(ghLabel5, FALSE);
}

static void createPageBrowseFile(void)
{
	GWidgetInit wi;
	gwinWidgetClearInit(&wi);


	// create container widget: ghContainerBrowseFile
	wi.g.show = FALSE;
	wi.g.x = 0;
	wi.g.y = 0;
	wi.g.width = 176;
	wi.g.height = 220;
	wi.g.parent = ghContainerMainFrame;
	wi.text = "Container";
	wi.customDraw = 0;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghContainerBrowseFile = gwinContainerCreate(0, &wi, 0);

	// Create list widget: ghListFiles
	wi.g.show = TRUE;
	wi.g.x = -2;
	wi.g.y = 20;
	wi.g.width = 178;
	wi.g.height = 160;
	wi.g.parent = ghContainerBrowseFile;
	wi.text = "List1";
	wi.customDraw = gwinListDefaultDraw;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghListFiles = gwinListCreate(0, &wi, FALSE);
	gwinListSetScroll(ghListFiles, scrollSmooth);
	gwinSetFont(ghListFiles, dejavu_sans_16);
	gwinRedraw(ghListFiles);
	gwinListAddItem(ghListFiles, "File1", FALSE);
	gwinListAddItem(ghListFiles, "File2", FALSE);
	gwinListAddItem(ghListFiles, "Item3", FALSE);
	gwinListAddItem(ghListFiles, "Item4", FALSE);
	gwinListAddItem(ghListFiles, "Item5", FALSE);
	gwinListAddItem(ghListFiles, "Item6", FALSE);
	gwinListSetSelected(ghListFiles, 0, FALSE);
	gwinListSetSelected(ghListFiles, 1, FALSE);
	gwinListSetSelected(ghListFiles, 2, FALSE);
	gwinListSetSelected(ghListFiles, 3, FALSE);
	gwinListSetSelected(ghListFiles, 4, FALSE);
	gwinListSetSelected(ghListFiles, 5, FALSE);

	// Create label widget: ghLabel5
	wi.g.show = TRUE;
	wi.g.x = 1;
	wi.g.y = 1;
	wi.g.width = 120;
	wi.g.height = 18;
	wi.g.parent = ghContainerBrowseFile;
	wi.text = "Browse files";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghLabel5 = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(ghLabel5, FALSE);
}

static void createPageAudioPlayer(void)
{
	GWidgetInit wi;
	gwinWidgetClearInit(&wi);


	// create container widget: ghContainerAudioPlayer
	wi.g.show = FALSE;
	wi.g.x = 0;
	wi.g.y = 0;
	wi.g.width = 176;
	wi.g.height = 220;
	wi.g.parent = ghContainerMainFrame;
	wi.text = "Container";
	wi.customDraw = 0;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghContainerAudioPlayer = gwinContainerCreate(0, &wi, 0);

	// Create label widget: ghLabel5
	wi.g.show = TRUE;
	wi.g.x = 1;
	wi.g.y = 1;
	wi.g.width = 120;
	wi.g.height = 18;
	wi.g.parent = ghContainerAudioPlayer;
	wi.text = "Browse files";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghLabel5 = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(ghLabel5, FALSE);

	// create button widget: ghButton1
	wi.g.show = TRUE;
	wi.g.x = 50;
	wi.g.y = 136;
	wi.g.width = 16;
	wi.g.height = 16;
	wi.g.parent = ghContainerAudioPlayer;
	wi.text = "";
	extern void gwinButtonDraw_ImageText(GWidgetObject *gw, void *param); wi.customDraw = gwinButtonDraw_ImageText;
	wi.customParam = &file_reg;
	wi.customStyle = 0;
	ghButton1 = gwinButtonCreate(0, &wi);

	// create button widget: ghButton1_1
	wi.g.show = TRUE;
	wi.g.x = 67;
	wi.g.y = 136;
	wi.g.width = 16;
	wi.g.height = 16;
	wi.g.parent = ghContainerAudioPlayer;
	wi.text = "";
	extern void gwinButtonDraw_ImageText(GWidgetObject *gw, void *param); wi.customDraw = gwinButtonDraw_ImageText;
	wi.customParam = &file_mp3;
	wi.customStyle = 0;
	ghButton1_1 = gwinButtonCreate(0, &wi);

	// create button widget: ghButton1_2
	wi.g.show = TRUE;
	wi.g.x = 87;
	wi.g.y = 137;
	wi.g.width = 16;
	wi.g.height = 16;
	wi.g.parent = ghContainerAudioPlayer;
	wi.text = "";
	extern void gwinButtonDraw_ImageText(GWidgetObject *gw, void *param); wi.customDraw = gwinButtonDraw_ImageText;
	wi.customParam = &folder;
	wi.customStyle = 0;
	ghButton1_2 = gwinButtonCreate(0, &wi);
}

static void createPageRemoteControl(void)
{
	GWidgetInit wi;
	gwinWidgetClearInit(&wi);


	// create container widget: ghContainerRemoteControl
	wi.g.show = FALSE;
	wi.g.x = 0;
	wi.g.y = 0;
	wi.g.width = 176;
	wi.g.height = 220;
	wi.g.parent = ghContainerMainFrame;
	wi.text = "Container";
	wi.customDraw = 0;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghContainerRemoteControl = gwinContainerCreate(0, &wi, 0);

	// Create label widget: ghLabel5
	wi.g.show = TRUE;
	wi.g.x = 20;
	wi.g.y = 14;
	wi.g.width = 70;
	wi.g.height = 18;
	wi.g.parent = ghContainerRemoteControl;
	wi.text = "RC";
	wi.customDraw = gwinLabelDrawJustifiedCenter;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghLabel5 = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(ghLabel5, FALSE);
	gwinSetFont(ghLabel5, dejavu_sans_16);
	gwinRedraw(ghLabel5);

	// create button widget: ghButtonRemotePower
	wi.g.show = TRUE;
	wi.g.x = 112;
	wi.g.y = 6;
	wi.g.width = 50;
	wi.g.height = 32;
	wi.g.parent = ghContainerRemoteControl;
	wi.text = "POWER";
	wi.customDraw = gwinButtonDraw_Normal;
	wi.customParam = 0;
	wi.customStyle = &black;
	ghButtonRemotePower = gwinButtonCreate(0, &wi);

	// create button widget: ghButtonRemoteVolumePlus
	wi.g.show = TRUE;
	wi.g.x = 44;
	wi.g.y = 90;
	wi.g.width = 40;
	wi.g.height = 32;
	wi.g.parent = ghContainerRemoteControl;
	wi.text = "+";
	wi.customDraw = gwinButtonDraw_Normal;
	wi.customParam = 0;
	wi.customStyle = &black;
	ghButtonRemoteVolumePlus = gwinButtonCreate(0, &wi);
	gwinSetFont(ghButtonRemoteVolumePlus, dejavu_sans_16);
	gwinRedraw(ghButtonRemoteVolumePlus);

	// create button widget: ghButtonRemoteVolumeMinus
	wi.g.show = TRUE;
	wi.g.x = 44;
	wi.g.y = 132;
	wi.g.width = 40;
	wi.g.height = 32;
	wi.g.parent = ghContainerRemoteControl;
	wi.text = "-";
	wi.customDraw = gwinButtonDraw_Normal;
	wi.customParam = 0;
	wi.customStyle = &black;
	ghButtonRemoteVolumeMinus = gwinButtonCreate(0, &wi);
	gwinSetFont(ghButtonRemoteVolumeMinus, dejavu_sans_16);
	gwinRedraw(ghButtonRemoteVolumeMinus);

	// create button widget: ghButtonRemoteProgMinus
	wi.g.show = TRUE;
	wi.g.x = 96;
	wi.g.y = 132;
	wi.g.width = 40;
	wi.g.height = 32;
	wi.g.parent = ghContainerRemoteControl;
	wi.text = "-";
	wi.customDraw = gwinButtonDraw_Normal;
	wi.customParam = 0;
	wi.customStyle = &black;
	ghButtonRemoteProgMinus = gwinButtonCreate(0, &wi);
	gwinSetFont(ghButtonRemoteProgMinus, dejavu_sans_16);
	gwinRedraw(ghButtonRemoteProgMinus);

	// create button widget: ghButtonRemoteProgPlus
	wi.g.show = TRUE;
	wi.g.x = 96;
	wi.g.y = 90;
	wi.g.width = 40;
	wi.g.height = 32;
	wi.g.parent = ghContainerRemoteControl;
	wi.text = "+";
	wi.customDraw = gwinButtonDraw_Normal;
	wi.customParam = 0;
	wi.customStyle = &black;
	ghButtonRemoteProgPlus = gwinButtonCreate(0, &wi);
	gwinSetFont(ghButtonRemoteProgPlus, dejavu_sans_16);
	gwinRedraw(ghButtonRemoteProgPlus);

	// create button widget: ghButtonRemotePrev
	wi.g.show = TRUE;
	wi.g.x = 18;
	wi.g.y = 48;
	wi.g.width = 40;
	wi.g.height = 32;
	wi.g.parent = ghContainerRemoteControl;
	wi.text = "<";
	wi.customDraw = gwinButtonDraw_Normal;
	wi.customParam = 0;
	wi.customStyle = &black;
	ghButtonRemotePrev = gwinButtonCreate(0, &wi);
	gwinSetFont(ghButtonRemotePrev, dejavu_sans_16);
	gwinRedraw(ghButtonRemotePrev);

	// create button widget: ghButtonRemotePause
	wi.g.show = TRUE;
	wi.g.x = 70;
	wi.g.y = 48;
	wi.g.width = 40;
	wi.g.height = 32;
	wi.g.parent = ghContainerRemoteControl;
	wi.text = "II";
	wi.customDraw = gwinButtonDraw_Normal;
	wi.customParam = 0;
	wi.customStyle = &black;
	ghButtonRemotePause = gwinButtonCreate(0, &wi);
	gwinSetFont(ghButtonRemotePause, dejavu_sans_16);
	gwinRedraw(ghButtonRemotePause);

	// create button widget: ghButtonRemoteNext
	wi.g.show = TRUE;
	wi.g.x = 122;
	wi.g.y = 48;
	wi.g.width = 40;
	wi.g.height = 32;
	wi.g.parent = ghContainerRemoteControl;
	wi.text = ">";
	wi.customDraw = gwinButtonDraw_Normal;
	wi.customParam = 0;
	wi.customStyle = &black;
	ghButtonRemoteNext = gwinButtonCreate(0, &wi);
	gwinSetFont(ghButtonRemoteNext, dejavu_sans_16);
	gwinRedraw(ghButtonRemoteNext);

	// Create label widget: ghLabel5_2
	wi.g.show = TRUE;
	wi.g.x = 144;
	wi.g.y = 118;
	wi.g.width = 15;
	wi.g.height = 18;
	wi.g.parent = ghContainerRemoteControl;
	wi.text = "P ";
	wi.customDraw = gwinLabelDrawJustifiedCenter;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghLabel5_2 = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(ghLabel5_2, FALSE);
	gwinSetFont(ghLabel5_2, dejavu_sans_16);
	gwinRedraw(ghLabel5_2);

	// create button widget: ghImagebox3
	wi.g.show = TRUE;
	wi.g.x = 20;
	wi.g.y = 118;
	wi.g.width = 16;
	wi.g.height = 16;
	wi.g.parent = ghContainerRemoteControl;
	ghImagebox3 = gwinImageCreate(0, &wi.g);
	gwinImageOpenFile(ghImagebox3, "rsc/volume.bmp");
}

static void createPageWeather(void)
{
	GWidgetInit wi;
	gwinWidgetClearInit(&wi);


	// create container widget: ghContainerWeather
	wi.g.show = FALSE;
	wi.g.x = 0;
	wi.g.y = 0;
	wi.g.width = 176;
	wi.g.height = 220;
	wi.g.parent = ghContainerMainFrame;
	wi.text = "Container";
	wi.customDraw = 0;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghContainerWeather = gwinContainerCreate(0, &wi, 0);

	// Create label widget: ghLabel5
	wi.g.show = TRUE;
	wi.g.x = 26;
	wi.g.y = 10;
	wi.g.width = 120;
	wi.g.height = 18;
	wi.g.parent = ghContainerWeather;
	wi.text = "Weather";
	wi.customDraw = gwinLabelDrawJustifiedCenter;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghLabel5 = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(ghLabel5, FALSE);
	gwinSetFont(ghLabel5, dejavu_sans_16);
	gwinRedraw(ghLabel5);

	// create button widget: ghImagebox2
	wi.g.show = TRUE;
	wi.g.x = 24;
	wi.g.y = 36;
	wi.g.width = 32;
	wi.g.height = 32;
	wi.g.parent = ghContainerWeather;
	ghImagebox2 = gwinImageCreate(0, &wi.g);
	gwinImageOpenFile(ghImagebox2, "rsc/weath_temp.bmp");

	// create button widget: ghImagebox2_1
	wi.g.show = TRUE;
	wi.g.x = 24;
	wi.g.y = 80;
	wi.g.width = 32;
	wi.g.height = 32;
	wi.g.parent = ghContainerWeather;
	ghImagebox2_1 = gwinImageCreate(0, &wi.g);
	gwinImageOpenFile(ghImagebox2_1, "rsc/weath_humidity.bmp");

	// create button widget: ghImagebox2_2
	wi.g.show = TRUE;
	wi.g.x = 24;
	wi.g.y = 124;
	wi.g.width = 32;
	wi.g.height = 32;
	wi.g.parent = ghContainerWeather;
	ghImagebox2_2 = gwinImageCreate(0, &wi.g);
	gwinImageOpenFile(ghImagebox2_2, "rsc/weath_pressure.bmp");

	// Create label widget: ghLabelTemperature
	wi.g.show = TRUE;
	wi.g.x = 60;
	wi.g.y = 44;
	wi.g.width = 100;
	wi.g.height = 18;
	wi.g.parent = ghContainerWeather;
	wi.text = "10 С";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghLabelTemperature = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(ghLabelTemperature, FALSE);
	gwinSetFont(ghLabelTemperature, dejavu_sans_16);
	gwinRedraw(ghLabelTemperature);

	// Create label widget: ghLabelHumidity
	wi.g.show = TRUE;
	wi.g.x = 60;
	wi.g.y = 88;
	wi.g.width = 100;
	wi.g.height = 18;
	wi.g.parent = ghContainerWeather;
	wi.text = "60 %";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghLabelHumidity = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(ghLabelHumidity, FALSE);
	gwinSetFont(ghLabelHumidity, dejavu_sans_16);
	gwinRedraw(ghLabelHumidity);

	// Create label widget: ghLabelPressure
	wi.g.show = TRUE;
	wi.g.x = 60;
	wi.g.y = 132;
	wi.g.width = 100;
	wi.g.height = 18;
	wi.g.parent = ghContainerWeather;
	wi.text = "750 kPA";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghLabelPressure = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(ghLabelPressure, FALSE);
	gwinSetFont(ghLabelPressure, dejavu_sans_16);
	gwinRedraw(ghLabelPressure);
}

static void createPageRecognizer(void)
{
	GWidgetInit wi;
	gwinWidgetClearInit(&wi);


	// create container widget: ghContainerRecognizer
	wi.g.show = FALSE;
	wi.g.x = 0;
	wi.g.y = 0;
	wi.g.width = 176;
	wi.g.height = 220;
	wi.g.parent = ghContainerMainFrame;
	wi.text = "Container";
	wi.customDraw = 0;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghContainerRecognizer = gwinContainerCreate(0, &wi, 0);

	// create button widget: ghButtonStartSpeech
	wi.g.show = TRUE;
	wi.g.x = 10;
	wi.g.y = 150;
	wi.g.width = 100;
	wi.g.height = 20;
	wi.g.parent = ghContainerRecognizer;
	wi.text = "Start Speech";
	wi.customDraw = gwinButtonDraw_Normal;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghButtonStartSpeech = gwinButtonCreate(0, &wi);

	// Create progressbar widget: ghProgressRecording
	wi.g.show = TRUE;
	wi.g.x = 10;
	wi.g.y = 20;
	wi.g.width = 156;
	wi.g.height = 20;
	wi.g.parent = ghContainerRecognizer;
	wi.text = "Recodrding...";
	wi.customDraw = gwinProgressbarDraw_Std;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghProgressRecording = gwinProgressbarCreate(0, &wi);
	gwinProgressbarSetRange(ghProgressRecording, 0, 100);
	gwinProgressbarSetPosition(ghProgressRecording, 25);

	// create checkbox widget: ghEnableVAD
	wi.g.show = TRUE;
	wi.g.x = 116;
	wi.g.y = 150;
	wi.g.width = 50;
	wi.g.height = 20;
	wi.g.parent = ghContainerRecognizer;
	wi.text = "VAD";
	wi.customDraw = gwinCheckboxDraw_CheckOnLeft;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghEnableVAD = gwinCheckboxCreate(0, &wi);
	gwinCheckboxCheck(ghEnableVAD, FALSE);

	// Create label widget: ghLabelRecognizeResult
	wi.g.show = TRUE;
	wi.g.x = 10;
	wi.g.y = 50;
	wi.g.width = 156;
	wi.g.height = 40;
	wi.g.parent = ghContainerRecognizer;
	wi.text = "";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghLabelRecognizeResult = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(ghLabelRecognizeResult, FALSE);
	gwinSetFont(ghLabelRecognizeResult, dejavu_sans_16);
	gwinRedraw(ghLabelRecognizeResult);

	// Create label widget: ghLabelRecognizeResult2
	wi.g.show = TRUE;
	wi.g.x = 10;
	wi.g.y = 90;
	wi.g.width = 156;
	wi.g.height = 60;
	wi.g.parent = ghContainerRecognizer;
	wi.text = "";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghLabelRecognizeResult2 = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(ghLabelRecognizeResult2, FALSE);
}

void guiShowPage(unsigned pageIndex)
{
	// Hide all pages
	gwinHide(ghContainerMainFrame);
	gwinHide(ghContainerMainMenu);
	gwinHide(ghContainerWifiSettings);
	gwinHide(ghContainerBrowseFile);
	gwinHide(ghContainerAudioPlayer);
	gwinHide(ghContainerRemoteControl);
	gwinHide(ghContainerWeather);
	gwinHide(ghContainerRecognizer);

	// Show page selected page
	switch (pageIndex) {
	case 0:
		gwinShow(ghContainerMainFrame);
		break;

	case 1:
		gwinShow(ghContainerMainMenu);
		break;

	case 2:
		gwinShow(ghContainerWifiSettings);
		break;

	case 3:
		gwinShow(ghContainerBrowseFile);
		break;

	case 4:
		gwinShow(ghContainerAudioPlayer);
		break;

	case 5:
		gwinShow(ghContainerRemoteControl);
		break;

	case 6:
		gwinShow(ghContainerWeather);
		break;

	case 7:
		gwinShow(ghContainerRecognizer);
		break;

	default:
		break;
	}
}

void guiCreate(void)
{
	GWidgetInit wi;

	// Prepare fonts
	dejavu_sans_10 = gdispOpenFont("DejaVuSans10");
	dejavu_sans_16 = gdispOpenFont("DejaVuSans16");

	// Prepare images
	gdispImageOpenFile(&back, "rsc/back.bmp");
	gdispImageOpenFile(&menu, "rsc/menu.bmp");
	gdispImageOpenFile(&music, "rsc/music.bmp");
	gdispImageOpenFile(&mic, "rsc/mic.bmp");
	gdispImageOpenFile(&weather, "rsc/weather.bmp");
	gdispImageOpenFile(&remote, "rsc/remote.bmp");
	gdispImageOpenFile(&gear, "rsc/gear.bmp");
	gdispImageOpenFile(&file_reg, "rsc/file_reg.bmp");
	gdispImageOpenFile(&file_mp3, "rsc/file_mp3.bmp");
	gdispImageOpenFile(&folder, "rsc/folder.bmp");

	// GWIN settings
	gwinWidgetClearInit(&wi);
	gwinSetDefaultFont(dejavu_sans_10);
	gwinSetDefaultStyle(&white, FALSE);
	gwinSetDefaultColor(black_studio);
	gwinSetDefaultBgColor(white_studio);

	// Create all the display pages
	createPageMainFrame();
	createPageMainMenu();
	createPageWifiSettings();
	createPageBrowseFile();
	createPageAudioPlayer();
	createPageRemoteControl();
	createPageWeather();
	createPageRecognizer();

	// Select the default display page
	guiShowPage(0);

}

