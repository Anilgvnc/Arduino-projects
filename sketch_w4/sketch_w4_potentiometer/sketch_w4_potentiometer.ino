/*
Potentiometer
*/

#define Apin A0
int val = 0; //analog value

void setup() {
  Serial.begin(9600);//open-console(console time)
}

void loop() {
  val = analogRead(Apin);
  float voltage = (5.00 / 1024) * val;
  Serial.println(voltage);// Write through to the console
  delay(100);
}
