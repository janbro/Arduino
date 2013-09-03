/*Ping.cpp - Library for getting distance in centimeters or inches.
*Created by Alejandro Munoz, August 14, 2013.
*Public Methods:getPingDistance(String units)<--"in" or "cm"
*/

#include "Ping.h"
#include "Arduino.h"

Ping::Ping(int pin)
{
	pinMode(pin, INPUT);
	_pin = pin;
}

long Ping::getPingDistance(String units)
{
  // establish variables for duration of the ping, 
  // and the distance result in inches and centimeters:
  long duration, inches, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(_pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(_pin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(_pin, INPUT);
  duration = pulseIn(_pin, HIGH);

  // convert the time into a distance
  if(units.equals("in"))
    return microsecondsToInches(duration);
  else if(units.equals("cm"))
    return microsecondsToCentimeters(duration);
  else
    return -1;
}

long Ping::microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  return microseconds / 74 / 2;
}

long Ping::microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
