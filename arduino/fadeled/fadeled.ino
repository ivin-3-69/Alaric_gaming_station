
#define GREEN_LED 9
int brightness = 255;
int gBright = 0;

int fadeSpeed = 10;
void setup() {
  // put your setup code here, to run once:
  pinMode(GREEN_LED, OUTPUT);
}
void TurnOn() { 
   for (int i = 0; i < 256; i++) {
       analogWrite(GREEN_LED, gBright);
       gBright +=1;
       delay(fadeSpeed);
   } 
}
void TurnOff() {
   for (int i = 0; i < 256; i++) {
       analogWrite(GREEN_LED, brightness);
       brightness -= 1;
       delay(fadeSpeed);
   }
}
void loop()
{
   TurnOn();
   delay(5000);
   TurnOff();
}
