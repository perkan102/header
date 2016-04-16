#pragma once

#include "App.h"

class Vec2;

class MinecraftClient : public App {
public:
	virtual ~MinecraftClient();
	virtual void onLowMemory();
	virtual void onAppSuspended();
	virtual void onAppResumed();
	virtual void onAppFocusLost();
	virtual void onAppFocusGained();
	virtual void audioEngineOn();
	virtual void audioEngineOff();
	virtual void muteAudio();
	virtual void unMuteAudio();
	virtual bool useTouchScreen();
	virtual void setTextboxText(const std::string&);
	virtual void update();
	virtual void setUISizeAndScale(int, int, float);
	virtual void setRenderingSize(int, int);
	virtual void init();
	virtual void handleBack(bool);
	virtual void handleBack();
	virtual void onInternetUpdate();
	virtual void canActivateKeyboard();
	virtual void onLevelCorrupt();
	virtual void onGameModeChagned();
	virtual void onGameSessionReset();
	virtual void createSkin();
	virtual void onLevelExit();
	virtual void onTick(int, int);
	virtual void vibrate(int);
	virtual void enableKeyboard(const std::string&, int, bool, bool, const Vec2&);
	virtual void disableKeyboard();
	virtual void isKeyboardEnabled();
	virtual void isKeyboardActive();
	virtual void getKeyboardHeight();
};