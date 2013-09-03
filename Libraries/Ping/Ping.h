#ifndef Ping_h
#define Ping_h
#include "Arduino.h"

class Ping
{
	public:
		Ping(int pin);
		long getPingDistance(String units);
	private:
		long microsecondsToInches(long microseconds);
		long microsecondsToCentimeters(long microseconds);
		int _pin;
};

#endif