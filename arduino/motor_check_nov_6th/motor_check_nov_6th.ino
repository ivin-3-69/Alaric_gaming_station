#include <ezButton.h>
#define dirPin 2
#define stepPin 3
#define LED 13  
#define LED2 12 
int state = 0;
bool yeet1 = 0;
bool yeet2 = 0;
int workstatus = 0;
int switch_pin1 = 8;
int switch_pin2 = 9;
const int BUTTON_PIN2 = 7;


ezButton button2(BUTTON_PIN2);

void setup() {
  Serial.begin(9600);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(LED, OUTPUT); // Declare the LED as an output
  pinMode(LED2, OUTPUT);
  pinMode(switch_pin1, INPUT);
  pinMode(switch_pin2, INPUT);
  button2.setDebounceTime(50);
}
void loop() {
  button2.loop();
  
  if(digitalRead(switch_pin1) == 0 && yeet1 == 1){
    
    state=0;
    if(workstatus == 0){
      workstatus = 1;
    }
    else{
      workstatus = 0;
    }
  }
  
  yeet1 = digitalRead(switch_pin1);

  if(digitalRead(switch_pin2) == 0 && yeet2 == 1){
    
    state=0;
    if(workstatus == 0){
      workstatus = 1;
    }
    else{
      workstatus = 0;
    }
  }
  
  yeet2 = digitalRead(switch_pin2);


   if(button2.isPressed()) 
  {
//    Serial.println("button 2 pressed");
//    state = 1;

    if(state == 0){
      state = 1;
    }
    else{
      state = 0;
    }
    
  }
  if(state==1){

    digitalWrite(dirPin, HIGH);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(100);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(100);
    Serial.println("up");




    
//    if(workstatus == 0){
//        Serial.println("up");
//        digitalWrite(LED, HIGH); 
//        digitalWrite(LED2, LOW);
//
//        
//        digitalWrite(dirPin, HIGH);
//        digitalWrite(stepPin, HIGH);
//        delayMicroseconds(100);
//        digitalWrite(stepPin, LOW);
//        delayMicroseconds(100);
//    }
//    else
//    {
//      Serial.println("down");
//      digitalWrite(LED2, HIGH); 
//      digitalWrite(LED, LOW);
//
//      
//      digitalWrite(dirPin, LOW);
//      digitalWrite(stepPin, HIGH);
//      delayMicroseconds(100);
//      digitalWrite(stepPin, LOW);
//      delayMicroseconds(100);
//    }
  }
  else
  {
//    Serial.println("gear off");
    digitalWrite(LED, LOW); 
    digitalWrite(LED2, LOW);
  }   
  delay(50); 
//  Serial.println(digitalRead(switch_pin));
//  Serial.println(state);
}
