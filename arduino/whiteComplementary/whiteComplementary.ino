#define RED_LED 6
#define BLUE_LED 5
int fadeSpeed = 30;

void setup() {
  // put your setup code here, to run once:
   pinMode(RED_LED, OUTPUT);
   pinMode(BLUE_LED, OUTPUT);
}
void TurnOn() { 
   for (int i = 0; i < 256; i++) {
       analogWrite(RED_LED, i);
       analogWrite(BLUE_LED, 255-i);
       delay(fadeSpeed);
   }
   for (int i = 0; i < 256; i++) {
       analogWrite(RED_LED, 255-i);
       analogWrite(BLUE_LED, i);
       delay(fadeSpeed);
   }
 
}

void loop()
{
     TurnOn();
  }
