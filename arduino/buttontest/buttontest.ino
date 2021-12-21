#define RED_LED 5
#define BLUE_LED 9
#define GREEN_LED 6


int button1 = 2;

int status1 = false;
void setup(){
  pinMode(button1, INPUT_PULLUP); 

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
}
  void mode1(){
       analogWrite(RED_LED, 255);
    analogWrite(GREEN_LED, 0);
    analogWrite(BLUE_LED, 0);
    delay(1000);

    analogWrite(RED_LED, 255);
    analogWrite(GREEN_LED, 119);
    analogWrite(BLUE_LED, 0);
    delay(1000);

    analogWrite(RED_LED, 255);
    analogWrite(GREEN_LED, 242);
    analogWrite(BLUE_LED, 0);
    delay(1000);

    analogWrite(RED_LED, 106);
    analogWrite(GREEN_LED, 255);
    analogWrite(BLUE_LED, 0);
    delay(1000);

    analogWrite(RED_LED, 0);
    analogWrite(GREEN_LED, 255);
    analogWrite(BLUE_LED, 150);
    delay(1000);

    analogWrite(RED_LED, 0);
    analogWrite(GREEN_LED, 234);
    analogWrite(BLUE_LED, 255);
    delay(1000);

    analogWrite(RED_LED, 0);
    analogWrite(GREEN_LED, 45);
    analogWrite(BLUE_LED, 255);
    delay(1000);

    analogWrite(RED_LED, 111);
    analogWrite(GREEN_LED, 0);
    analogWrite(BLUE_LED, 255);
    delay(1000);

    analogWrite(RED_LED, 255);
    analogWrite(GREEN_LED, 0);
    analogWrite(BLUE_LED, 200);
    delay(1000);

    analogWrite(RED_LED, 255);
    analogWrite(GREEN_LED, 255);
    analogWrite(BLUE_LED, 255);
    delay(1000);
 
  }


void loop(){
  if (digitalRead(button1) == true) {
    status1 = !status1;
    if(status1 == true){
      mode1();
    }  
    else{
      analogWrite(GREEN_LED, 0);
      analogWrite(RED_LED, 0);
      analogWrite(BLUE_LED, 0);
    }
   while(digitalRead(button1) == true);
  delay(50);
}
}
