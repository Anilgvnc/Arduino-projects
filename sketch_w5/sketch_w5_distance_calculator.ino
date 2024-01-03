/*
Sensor; distance calculator
*/

#define trigpin 4
#define echopin 2
long time;
double distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  Serial.println("DISTANCE MEASUREMENT WITH ARDUINO");
}

void loop() {
  digitalWrite(trigpin, LOW);
  delayMicroseconds(3);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  time= pulseIn(echopin, HIGH);
  distance=(time * 0.0343) / 2;
  Serial.print(distance);
  Serial.print("cm is distance");
  delay(500);
}
