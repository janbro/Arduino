/* Ping Sensor Example
  
   This sketch reads a ping ultrasonic sensor and returns the
   distance to the closest object in range. To do this, it sends a pulse
   to the sensor to initiate a reading, then listens for a pulse 
   to return.  The length of the returning pulse is proportional to 
   the distance of the object from the sensor.
     
   The circuit:
    * +V connection of the PING))) attached to +5V
    * GND connection of the PING))) attached to ground
    * SIG connection of the PING))) attached to digital pin 7
   
   created 21 August 2013
   by Alejandro Munoz
 
   This example code is in the public domain.

 */
 
#include <Ping.h> 

Ping PingSensor(7); //Attach Ping Sensor on pin 7

void setup() {
  // initialize serial communication:9600
  Serial.begin(9600);
}

void loop()
{
  Serial.print(pingSensor.getPingDistance("in")); //Print ping distance distance in inches
  Serial.print("in, ");
  Serial.print(pingSensor.getPingDistance("cm"); //Print ping distance in centimeters
  Serial.print("cm");
  Serial.println();
  
  delay(100);
}