#pragma once

#include <string>

#include "AppPlatformListener.h"

class AppContext;

// Size : 16
class App : public AppPlatformListener {
public:
	bool _init; // #8 0x8
	bool _quit; // #9 0x9
	AppContext* context; // #12 0xC
public:
	App(int, char**);
	virtual ~App();
	virtual void onLowMemory();
	virtual void onAppSuspended();
	virtual void onAppResumed();
	virtual void onAppFocusLost();
	virtual void onAppTerminated();
	virtual void audioEngineOn();
	virtual void audioEngineOff();
	virtual void muteAudio();
	virtual void unMuteAudio();
	virtual void destroy();
	virtual void loadState(void*, int);
	virtual void saveState(void**, int*);
	virtual bool useTouchScreen();
	virtual void setTextboxText(const std::string&);
	virtual void draw();
	virtual void update();
	virtual void setUISizeAndScale(int, int, float);
	virtual void setRenderingSize(int, int);
	virtual void quit();
	virtual bool wantToQuit();
	virtual void init();
	void init(AppContext&);
	void changeContext(AppContext&);
};