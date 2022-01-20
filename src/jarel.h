#ifndef JAREL_H
#define JAREL_H

#include "Arduino.h"

class jarel {
  public:
	jarel(byte pinA_, byte pinB_, byte pinS_, int positionDefault_ = 0, bool limited_ = false, int positionMin_ = 0, int positionMax_ = 100, int steps_ = 1);
	int position;
	int lastPosition;
	int positionDefault;
	int positionMin;
	int positionMax;
	bool enabled = true;
	int updatePosition();
	bool setPosition(int i);
	void resetPosition();
	bool increasePosition(int i = 1);
	bool decreasePosition(int i = 1);
	void enable();
	void disable();
	byte rotate();
	byte push();
	int pushTime();
	byte pushLong(int i);
	byte pushType(int i);
	void setTrigger(byte i);
	void setDebounceDelay(int i);
	void setErrorDelay(int i);
	void resetPush();

  private:
	byte _trigger = HIGH;
	byte _pinA;
	byte _pinB;
	byte _pinS;
	bool _limited;
	int _steps;
	unsigned long _currentTime;
	unsigned long _debounceRTime;
	unsigned long _debounceSTime;
	unsigned long _pushTime;
	unsigned int _debounceRDelay = 2;
	unsigned int _debounceSDelay = 100;
	bool _pulse = false;
	bool _pushStatus = false;
	bool _btnPressed = false;
	unsigned long _errorTime;
	unsigned int _errorDelay = 100;
	byte _errorLast = 0;
	bool _statusA = false;
	bool _statusB = false;
	bool _statusS = false;
	bool _statusA_prev = false;
	bool _statusS_prev = false;
	void _updateTime();
	void _setInputPins();
};

#endif