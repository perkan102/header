#pragma once

class AppPlatform;

// Size : 8
class AppPlatformListener {
public:
	// void** vtable; #0 0x0
	AppPlatform* app; // #4 0x4
public:
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