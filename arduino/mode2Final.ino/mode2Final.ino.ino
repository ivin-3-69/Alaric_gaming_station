

//define pins for the red, green and blue LEDs
#define RED_LED 9
#define BLUE_LED 5
#define GREEN_LED 6


void setup() {
  //set up pins to output.
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

}


void loop(){

for (int i=0;i<256;i++)
{
  analogWrite(GREEN_LED,i);
  analogWrite(RED_LED, 255);
  analogWrite(BLUE_LED, 0);
  delay(10);
}
for (int i=255;i>=0;i--)
{
  analogWrite(GREEN_LED,255);
  analogWrite(RED_LED, i);
  analogWrite(BLUE_LED, 0);
    delay(10);

}


for (int i=0;i<256;i++)
{
  analogWrite(GREEN_LED,255);
  analogWrite(RED_LED, 0);
  analogWrite(BLUE_LED, i);
      delay(10);

}


for (int i=255;i>=0;i--)
{
  analogWrite(GREEN_LED,i);
  analogWrite(RED_LED, 0);
  analogWrite(BLUE_LED, 255);
      delay(10);

}

for (int i=0;i<256;i++)
{
  analogWrite(GREEN_LED,0);
  analogWrite(RED_LED, i);
  analogWrite(BLUE_LED, 255);
      delay(10);

}
for (int i=255;i>=0;i--)
{
  analogWrite(GREEN_LED,0);
  analogWrite(RED_LED, 255);
  analogWrite(BLUE_LED, i);
      delay(10);

}
  
}
