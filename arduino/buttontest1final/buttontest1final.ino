/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-button-toggle-led
 */

#include <ezButton.h>
#define RED_LED 9
#define BLUE_LED 5
#define GREEN_LED 6

/// constants won't change
const int BUTTON_PIN1 = 2; // the number of the pushbutton pin
const int BUTTON_PIN2 = 7;

ezButton button1(BUTTON_PIN1);  // create Button object that attach to pin 6;
ezButton button2(BUTTON_PIN2); 

// variables will change:
int ledState1 = LOW; 
int ledState2 = LOW;
int rarray[]={255,255,255,106,0  ,0  ,0  ,111,255,255};
int garray[]={0  ,119,242,255,255,234,45 ,0  ,0  ,255};
int barray[]={0  ,0  ,0  ,0  ,150,255,255,255,200,255};
int i=0;


void setup() {
  Serial.begin(9600);         // initialize serial
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  button1.setDebounceTime(50); 
  button2.setDebounceTime(50);
}

void loop() {

  button1.loop(); 
  button2.loop(); 
  
  if(button1.isPressed()) {
    ledState1 = !ledState1;
    ledState2 = LOW;
    i=0;
  }
  if(button2.isPressed()) {
    ledState2 = !ledState2;
    ledState1 = LOW;
    i=0;
  }
  
  if(ledState1 == HIGH){
      analogWrite(RED_LED,   rarray[i/22]);
      analogWrite(GREEN_LED, garray[i/22]);
      analogWrite(BLUE_LED,  barray[i/22]);
      i++;
      if(i==220)
      {
        i=0;
      }
      delay(50);
    }  
    else{
      analogWrite(GREEN_LED, 0);
      analogWrite(RED_LED, 0);
      analogWrite(BLUE_LED, 0);
    }

    
    if(ledState2 == HIGH){
      if(i<256){
      analogWrite(GREEN_LED,i);
      analogWrite(RED_LED, 255);
      analogWrite(BLUE_LED, 0);
      }
      else if(i>=256 && i<512){
        analogWrite(GREEN_LED,255);
        analogWrite(RED_LED, 511-i);
        analogWrite(BLUE_LED, 0);
      }
      else if(i>=512 && i<768){
        analogWrite(GREEN_LED,255);
        analogWrite(RED_LED, 0);
        analogWrite(BLUE_LED, i-512);
      }
      else if(i>=768 && i<1024){
        analogWrite(GREEN_LED,1023-i);
        analogWrite(RED_LED, 0);
        analogWrite(BLUE_LED, 255);
      }


      else if(i>=1024 && i<1280){
        analogWrite(GREEN_LED,0);
        analogWrite(RED_LED, i-1024);
        analogWrite(BLUE_LED, 255);
      }
      else if(i>=1280 && i<1536){
        analogWrite(GREEN_LED,0);
        analogWrite(RED_LED, 255);
        analogWrite(BLUE_LED, 1535-i);
      }

      
      i++;
      if(i==1536)
      {
        i=0;
      }
      delay(7);
    }  
    else{
      analogWrite(GREEN_LED, 0);
      analogWrite(RED_LED, 0);
      analogWrite(BLUE_LED, 0);
    }
    
  }
    
 
