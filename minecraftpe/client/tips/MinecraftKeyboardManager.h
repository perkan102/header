#pragma once

#include <string>

class Vec2;

// Size : 12
class MinecraftKeyboardManager {
public:
	// void** vtable; #0 0x0
	bool active; // #4 0x4
	float height; // #8 0x8
public:
	virtual ~MinecraftKeyboardManager();
	virtual void enableKeyboard(const std::string&, int, bool, bool, const Vec2&);
	virtual void forceActivateKeyboard(const std::string&, int, bool, bool, const Vec2&);
	virtual void disableKeyboard();
	virtual bool canActivateKeyboard();
	virtual bool isKeyboardEnabled();
	virtual float getKeyboardHeight();
	void setForcedHeight(float);
};