//Week 3 - Delayed leds with button hold press.

int pin1 = 1;
int pin2 = 2;
int pin3 = 3;
int pinInput = 5;
int timer = 250;

void setup()
{
  for(int thisPin = 1; thisPin<4; thisPin++){
    pinMode(thisPin, OUTPUT);
  }
  pinMode(pinInput, INPUT);
}

void loop()
{
  int read = digitalRead(pinInput);
  for(int thisPin = 1; thisPin<4; thisPin++){
    digitalWrite(thisPin, read);
    
    delay(timer);
    
    digitalWrite(thisPin, LOW);
  }
}