int led=8;
int forward=9;
int backward=10;
int left=11;
int right=12;
int state=0;
int flag=0;        //makes sure that the serial only prints once the state
unsigned long time;

void setup() {
    // sets the pins as outputs:
    pinMode(forward, OUTPUT);
    pinMode(backward, OUTPUT);
    pinMode(left, OUTPUT);
    pinMode(right, OUTPUT);
    pinMode(led, OUTPUT);
    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
    time=millis();
}
 
void loop() {
    //if some date is sent, reads it and saves in state
    int temp=0;
    if(millis()-time>100){
      digitalWrite(led, LOW);
    }
    if(millis()-time>60000){
      keepAlive();
      time=millis();
    }
    if((temp=Serial.available()) > 0){ 
      digitalWrite(led, HIGH);
      for(int i=0;i<temp;i++){
        state = Serial.read();   
      }time=millis();
      flag=0;
      Serial.println(state);
    }else{
      state=0;
    }
    if (state == '2') {
        digitalWrite(forward, LOW);
        if(flag == 0){
          Serial.println("Forward");
          flag=1;
        }delay(100);
    }
    else if (state == '3') {
        digitalWrite(backward, LOW);
        if(flag == 0){
          Serial.println("Backward");
          flag=1;
        }delay(100);
    }else if (state == '1') {
        digitalWrite(right, LOW);
        if(flag == 0){
          Serial.println("Right");
          flag=1;
        }delay(100);
    }else if (state == '4') {
        digitalWrite(left, LOW);
        if(flag == 0){
          Serial.println("Left");
          flag=1;
        }delay(100);
    }else {
        digitalWrite(forward, HIGH);
        digitalWrite(backward, HIGH);
        digitalWrite(right, HIGH);
        digitalWrite(left, HIGH);
        if(flag == 0){
          Serial.println("Stop");
          flag=1;
        }
    }
}

void resetState(){
  state=0;
}

void keepAlive(){
  digitalWrite(right, LOW);
  delay(500);
  digitalWrite(right, HIGH);
}
