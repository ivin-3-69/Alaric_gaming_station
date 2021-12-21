

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


    analogWrite(RED_LED, 244);
    analogWrite(GREEN_LED, 253);
    analogWrite(BLUE_LED, 255);
    delay(1000);


    

}
