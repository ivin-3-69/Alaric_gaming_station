

//define pins for the red, green and blue LEDs
#define RED_LED 5
#define BLUE_LED 9
#define GREEN_LED 6


void setup() {
  //set up pins to output.
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

}


void loop(){


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
