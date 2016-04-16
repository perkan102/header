#pragma once

class AppPlatform;

class AppPlatformListener {
public:
	// void** vtable;
	AppPlatform* app;

	AppPlatformListener();
	AppPlatformListener(bool);
	virtual ~AppPlatformListener();
	virtual void onLowMemory();
	virtual void onAppSuspended();
	virtual void onAppResumed();
	virtual void onAppFocusLost();
	virtual void onAppFocusGained();
	virtual void onAppTerminated();
	void initListener(float);
	void terminate();
};