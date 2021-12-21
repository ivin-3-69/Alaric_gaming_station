/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-button-toggle-led
 */

#include <ezButton.h>
#define RED_LED 6
#define BLUE_LED 5
#define GREEN_LED 3
#define WARM_LED 9
#define COOL_LED 10

int workstatus = 0; //1 -> work Mode , 0 -> game Mode
char incomingByte = 0;
int state = 0;

const int BUTTON_PIN1 = 2; 
const int BUTTON_PIN2 = 7;

ezButton button1(BUTTON_PIN1);  // create Button object that attach to pin 6;
ezButton button2(BUTTON_PIN2); 

int ledmode = 0;
int workledmode = 0;
int gameledmode = 0;
int i=0;

void workmode1(){
  analogWrite(WARM_LED, 255);
  analogWrite(COOL_LED, 255);
  analogWrite(RED_LED, 30);
  analogWrite(GREEN_LED, 0);
  analogWrite(BLUE_LED, 0);
}
void workmode2(){
  analogWrite(WARM_LED, 255);
  analogWrite(COOL_LED, 255);
  analogWrite(RED_LED, 30);
  analogWrite(GREEN_LED, 15);
  analogWrite(BLUE_LED, 0);
}
void workmode3(){
  analogWrite(WARM_LED, 255);
  analogWrite(COOL_LED, 255);
  analogWrite(RED_LED, 40);
  analogWrite(GREEN_LED, 30);
  analogWrite(BLUE_LED, 0);
}
void workmode4(){
  analogWrite(WARM_LED, 255);
  analogWrite(COOL_LED, 255);
  analogWrite(RED_LED, 0);
  analogWrite(GREEN_LED, 40);
  analogWrite(BLUE_LED, 20);
}
void workmode5(){
  analogWrite(WARM_LED, 255);
  analogWrite(COOL_LED, 255);
  analogWrite(RED_LED, 0);
  analogWrite(GREEN_LED, 6);
  analogWrite(BLUE_LED, 40);
}
void workmode6(){
  analogWrite(WARM_LED, 255);
  analogWrite(COOL_LED, 255);
  analogWrite(RED_LED, 40);
  analogWrite(GREEN_LED, 0);
  analogWrite(BLUE_LED, 26);
}

void gamemode1(){
  
  analogWrite(WARM_LED, 0);
  analogWrite(COOL_LED, 0);
  analogWrite(RED_LED, 255);
  analogWrite(GREEN_LED, 0);
  analogWrite(BLUE_LED, 0);
}
void gamemode2(){
  analogWrite(WARM_LED, 0);
  analogWrite(COOL_LED, 0);
  analogWrite(RED_LED, 255);
  analogWrite(GREEN_LED, 119);
  analogWrite(BLUE_LED, 0);
}
void gamemode3(){
  analogWrite(WARM_LED, 0);
  analogWrite(COOL_LED, 0);
  analogWrite(RED_LED, 255);
  analogWrite(GREEN_LED, 242);
  analogWrite(BLUE_LED, 0);
}
void gamemode4(){
  analogWrite(WARM_LED, 0);
  analogWrite(COOL_LED, 0);
  analogWrite(RED_LED, 0);
  analogWrite(GREEN_LED, 255);
  analogWrite(BLUE_LED, 150);
}
void gamemode5(){
  analogWrite(WARM_LED, 0);
  analogWrite(COOL_LED, 0);
  analogWrite(RED_LED, 0);
  analogWrite(GREEN_LED, 45);
  analogWrite(BLUE_LED, 255);
}
void gamemode6(){
  analogWrite(WARM_LED, 0);
  analogWrite(COOL_LED, 0);
  analogWrite(RED_LED, 255);
  analogWrite(GREEN_LED, 0);
  analogWrite(BLUE_LED, 2000);
}


void setup() {
  Serial.begin(9600);         // initialize serial
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(WARM_LED, OUTPUT);
  pinMode(COOL_LED, OUTPUT);
  button1.setDebounceTime(50); 
  button2.setDebounceTime(50);
}

void loop() {
  button1.loop(); 
  button2.loop(); 
  
  if(button1.isPressed()) 
  {
    if(workstatus == 0){
      workstatus = 1;
    }
    else{
      workstatus = 0;
    }
    
  }
  if(button2.isPressed()) {
      if(workstatus == 0){
        if(gameledmode<6)
        {
          gameledmode = gameledmode+1;
        }
        else{
          gameledmode = 0;
        }
      }
      else{
        if(workledmode<6){
          workledmode = workledmode+1;
        }
        else{
          workledmode = 0;
        }
      }
  }
    if(Serial.available()>0)
    {
        incomingByte = Serial.read();
        state = incomingByte - '0';
      if (state == 1)
      {
        workstatus = !workstatus;
      }
  
      if (state == 2)
      {
        if(ledmode == 5)
        {
          ledmode = 0;
        }
        else
        {
          ledmode = ledmode+1; 
        }
      }

    }
    if(workstatus == 0)
    {
      if(gameledmode == 0)
      {
          Serial.println("game mode 0");
          delay(20);
          analogWrite(WARM_LED, 0);
          analogWrite(COOL_LED, 0);
          analogWrite(GREEN_LED, 0);
          analogWrite(RED_LED, 0);
          analogWrite(BLUE_LED, 0);
      }
      else if(gameledmode == 1)
      {
          Serial.println("game mode 1");
          delay(20);
          gamemode1();
      } 
      else if(gameledmode == 2)
      {
          Serial.println("game mode 2");
          delay(20);
          gamemode2();
      }   
      else if(gameledmode == 3)
      {
          Serial.println("game mode 3");
          delay(20);
          gamemode3();
      }   
      else if(gameledmode == 4)
      {
          Serial.println("game mode 4");
          delay(20);
          gamemode4();
      }   
      else if(gameledmode == 5)
      {
          Serial.println("game mode 5");
          delay(20);
          gamemode5();
      }
      else if(gameledmode == 6)
      {
          Serial.println("game mode 6");
          delay(20);
          gamemode6();
      }
    }
    else if(workstatus == 1)
    {
      if(workledmode == 0)
      {
          Serial.println("work mode 0");
          delay(20);
          analogWrite(WARM_LED, 0);
          analogWrite(COOL_LED, 0);
          analogWrite(GREEN_LED, 0);
          analogWrite(RED_LED, 0);
          analogWrite(BLUE_LED, 0);
      }
      else if(workledmode == 1)
      {
          Serial.println("work mode 1");
          delay(20);
          workmode1();
      } 
      else if(workledmode == 2)
      {
          Serial.println("work mode 2");
          delay(20);
          workmode2();
      }   
      else if(workledmode == 3)
      {
          Serial.println("work mode 3");
          delay(20);
          workmode3();
      }   
      else if(workledmode == 4)
      {
          Serial.println("work mode 4");
          delay(20);
          workmode4();
      }   
      else if(workledmode == 5)
      {
          Serial.println("work mode 5");
          delay(20);
          workmode5();
      }
      else if(workledmode == 6)
      {
          Serial.println("work mode 6");
          delay(20);
          workmode6();
      }
  }   
}
    
 
