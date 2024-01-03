/*
joystick
*/
  int xPin = A0;
  int yPin = A1;
  int buttonPin = 2;
  int xPos;
  int yPos;
  int buttonState;

void setup() {
  Serial.begin(9600);
  pinMode(xPin, INPUT);
  pinMode(yPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  xPos = analogRead(xPin);
  yPos = analogRead(yPin);
  buttonState = digitalRead(buttonPin);
  Serial.print("Position of x: ");
  Serial.print(xPos );
  Serial.print("Position of y: ");
  Serial.print(yPos);
  Serial.print("Button state is: ");
  Serial.print(buttonState);
  delay(1000);
}
