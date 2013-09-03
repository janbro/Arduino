/*
Car Test
Makes the modified RC car go in a figure 8.
Plug the striped white wires into the Arduino pins as
*/
int forward = 12; // forward pin
int reverse = 11; // reverse pin
int left = 10; // left pin
int right = 9; // right pin
// The setup() method runs once, when the sketch starts
void setup() {
// initialize the digital pins as an outputs:
pinMode(forward, OUTPUT);
pinMode(reverse, OUTPUT);
pinMode(left, OUTPUT);
pinMode(right, OUTPUT);
}
void go_forward()
{
digitalWrite(forward,HIGH); // turn forward motor on
digitalWrite(reverse,LOW); // turn revers motor off
}
void go_reverse()
{
digitalWrite(reverse,HIGH); // turn reverse motor on
digitalWrite(forward,LOW); // turn forward notor off
}
void stop_car()
{
digitalWrite(reverse,LOW); // turn revers motor off
digitalWrite(forward,LOW); // turn forward motor off
digitalWrite(left,LOW);
digitalWrite(right,LOW);
}
void go_left()
{
digitalWrite(left,HIGH); // turn left motor on
digitalWrite(right,LOW); // turn right motor off
}
void go_right()
{
digitalWrite(right,HIGH); // turn right motor on
digitalWrite(left,LOW); // tune left motor off
}
// the loop() method runs over and over again,
// as long as the Arduino has power
void loop()
{go_reverse();
delay(1000);
stop_car();
delay(3000);
go_forward();
delay(1000);
stop_car();
delay(3000);
go_right();
delay(3000);
go_left();
delay(3000);
}
