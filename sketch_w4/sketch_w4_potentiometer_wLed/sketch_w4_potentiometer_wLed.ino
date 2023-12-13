/*
Potentiometer with led
*/

#define Apin A0
#define Lpin 3
int val = 0; //analog value

void setup() {
  Serial.begin(9600);
}

void loop() {
  val = analogRead(Apin);
  val = map(val, 0, 1023, 0, 255);
  analogWrite(Lpin, val);
  Serial.println(val);
}