//Controller Input

int slider = A0;
int joyX = A1;
int joyY = A2;
int rotPot = A3;
int switchButton = 2;
int button = 3;
int led = 13;
int brightness = 0;
boolean increase = true;
// the setup routine runs once when you press reset:
void setup(){                
  Serial.begin(9600);
  pinMode(slider,INPUT);
  pinMode(rotPot,INPUT);
  pinMode(joyX,INPUT);
  pinMode(joyY,INPUT);
  pinMode(switchButton,INPUT);
  pinMode(button,INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  int sliderInfo = map(analogRead(slider),0,1023,2000,1000);
  int rotPotInfo = map(analogRead(rotPot),0,1023,1000,2000);
  int joyInfo[2] = {map(analogRead(joyX),0,1023,2000,1000),map(analogRead(joyY),0,1023,1000,2000)};
  boolean switchInfo = !digitalRead(switchButton);
  boolean buttonInfo = digitalRead(button);
  int checksum = sliderInfo + rotPotInfo + joyInfo[0] + joyInfo[1] + switchInfo + buttonInfo;
  if(switchInfo){
  analogWrite(led,brightness);
  if(increase){
    brightness+=10;
    if(brightness>=245)
      increase = false;
  }
  else{
    brightness-=10;
    if(brightness<=0)
      increase = true;
  }
  }else{
    digitalWrite(led,LOW);
  }
  Serial.print("Slider:");
  Serial.print(sliderInfo);
  Serial.print(" RotPot:");
  Serial.print(rotPotInfo);
  Serial.print(" x:");
  Serial.print(joyInfo[0]);
  Serial.print(" y:");
  Serial.print(joyInfo[1]);
  Serial.print(" Switch:");
  Serial.print(switchInfo);
  Serial.print(" JoyButton:");
  Serial.print(buttonInfo);
  Serial.print("Checksum:");
  Serial.println(checksum);
  delay(10); 
}
