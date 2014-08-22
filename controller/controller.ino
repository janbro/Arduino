//Controller Input
#define MAX_PLAYBACK_TIME 500
int slider = A0;
int joyX = A1;
int joyY = A2;
int rotPot = A3;
int switchButton = 2;
int button = 3;
int led = 13;
int brightness = 0;
boolean increase = true;
//boolean record = false;
//boolean playback = false;
//String recordedMovements[MAX_PLAYBACK_TIME];
//int count=0;
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
  int joyInfo[2] = {map(analogRead(joyX),0,1023,1750,1250),map(analogRead(joyY),0,1023,1250,1750)};
  int switchInfo = map(!digitalRead(switchButton),0,1,1000,2000);
  int buttonInfo = map(digitalRead(button),0,1,1000,2000);
  int checksum = sliderInfo + rotPotInfo + joyInfo[0] + joyInfo[1] + switchInfo;// + buttonInfo;
  if(switchInfo/1000-1){
    incrementBrightness(4);
  }else{
    digitalWrite(led,LOW);
  }
  /*
  if(switchInfo/1000-1){
    record = true;
  }else{
    record = false;
  }if(buttonInfo/1000-1){
    playback=!playback;
  }
  if(!record||count>=MAX_PLAYBACK_TIME)
    digitalWrite(led,LOW);
  if(record&&count<MAX_PLAYBACK_TIME){
    incrementBrightness(4);
    String space = " ";
    recordedMovements[count] = joyInfo[0]+space+joyInfo[1]+space+rotPotInfo+space+sliderInfo+space+switchInfo+space+checksum+space;
    count++;//160
  }
  else if(playback){
    for(int i=0;i<count;i++){
      if(recordedMovements[i] == NULL)
        break;
      Serial.print("Playback: ");
      Serial.println(recordedMovements[i]);
    }
    //Clear
    memset(recordedMovements,NULL,sizeof(recordedMovements));
    count = 0;
    playback = false;
  }
  //Serial.print(count);
  //Serial.print(":");
  //Serial.print(playback);
  //Serial.print(":");
  //Serial.println(record);
  */
  //JoyX
  //JoyY
  //RotPot
  //Slider
  //Switch
  //Checksum
  
  Serial.print(joyInfo[0]);
  Serial.print(" ");
  Serial.print(joyInfo[1]);
  Serial.print(" ");
  Serial.print(rotPotInfo);
  Serial.print(" ");
  Serial.print(sliderInfo); 
  Serial.print(" ");
  Serial.print(switchInfo);
  Serial.print(" ");
  Serial.print(checksum);
  Serial.println(" ");
  //Serial.print("aaaaaaaaaaaaaaaaaaa");
  //Serial.println(count);
}

void incrementBrightness(int incVal){
  analogWrite(led,brightness);
  if(increase){
    brightness+=incVal;
    if(brightness>=255-incVal)
      increase = false;
  }
  else{
    brightness-=incVal;
    if(brightness<=0)
      increase = true;
  }
}
