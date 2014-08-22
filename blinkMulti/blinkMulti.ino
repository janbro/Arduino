/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  for(int i=2;i<=9;i++){
    pinMode(i,OUTPUT);
  }
}

// the loop routine runs over and over again forever:
void loop() {
  for(int i=2;i<=8;i+=2){
    digitalWrite(i-1,LOW);
    digitalWrite(i, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);
    digitalWrite(i, LOW);   // turn the LED on (HIGH is the voltage level)
  }
  for(int i=8;i>=2;i-=2){
    digitalWrite(i-1,LOW);
    digitalWrite(i, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);
    digitalWrite(i, LOW);   // turn the LED on (HIGH is the voltage level)
  }
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}
