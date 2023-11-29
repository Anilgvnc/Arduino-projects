//Week 3 - Delayed leds with for loop.

int pin1 = 1;
int pin2 = 2;
int pin3 = 3;
int pin4 = 4;
int timer = 500;

void setup()
{
  for(int pinSet = 1; pinSet < 5; pinSet++){
    pinMode(pinSet,OUTPUT);
  }
}

void loop()
{ 
  
  for(int pinSet = 1; pinSet < 5; pinSet++){
    digitalWrite(pinSet, HIGH);
    delay(timer);
    digitalWrite(pinSet, LOW);
  }
  for(int pinSet = 5; pinSet > 1; pinSet--){
    digitalWrite(pinSet, HIGH);
    delay(timer);
    digitalWrite(pinSet, LOW);
  }
}