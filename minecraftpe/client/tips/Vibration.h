#pragma once

class Vibration {
public:
	virtual ~Vibration();
	virtual void vibrate(int) = 0;
};