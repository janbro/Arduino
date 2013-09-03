// MoveForward
// Created by: Alejandro Munoz
#include <Servo.h> 
 
Servo leftMotor;
Servo rightMotor;
const int pingPin = 7;
 
int leftPos = 0;    // variable to store the servo position 
int rightPos = 0;
int pos=180;
boolean right = true;
 
void setup() 
{ 
  leftMotor.attach(A0);  // attaches the vex motor on pin Analog 0 to the servo object
  rightMotor.attach(A1);  // attaches the vex motor on pin Analog 1 to the servo object
  pinMode(pingPin, OUTPUT);
} 
 
 
void loop() 
{
    if(pingDistance()<8){  //Check if within danger zone
      stop();
      delay(100);
      //right = checkSides();
      right = random(0,2)==0;  //Turn in random direction
      while(pingDistance()<9){  //While still facing a wall, turn
        if(right){
          turnRight();
        }
        else{
          turnLeft();
        }
      }
      delay(250); //Give some extra turn time after getting outside of dangerzone to compensate for fatness
      stop();
    }
    forward();
    delay(10);
}

boolean checkSides(){
  int rightSide;
  int leftSide;
  turnRight();
  delay(500);
  stop();
  rightSide = pingDistance();
  delay(250);
  turnLeft();
  delay(1000);
  stop();
  leftSide = pingDistance();
  delay(250);
  if(rightSide>leftSide)
    return true;
  else
    return false;
}

void stop(){
  leftMotor.write(90);
  rightMotor.write(90);
  
}

void forward(){
  leftMotor.write(180);
  rightMotor.write(0);
}

void reverse(){
  leftMotor.write(0);
  rightMotor.write(180);
}

void turnRight(){
  leftMotor.write(0);
  rightMotor.write(0);
}

void turnLeft(){
  leftMotor.write(180);
  rightMotor.write(180);
}

long pingDistance(){  //Get distance in inches

 // establish variables for duration of the ping, 
  // and the distance result in inches and centimeters:
  long duration, inches, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
  return inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration); 
}


long microsecondsToInches(long microseconds)  //Ping sensor distance cm
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)  //Ping sensor distance cm
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
