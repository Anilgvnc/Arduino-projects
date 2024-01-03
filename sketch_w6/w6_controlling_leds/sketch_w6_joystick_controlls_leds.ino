/*
Control leds from joystick
*/

  int xPin = A0;
  int yPin = A1;
  int buttonPin = 2;
  int xPos;
  int yPos;
  int buttonState;
  
  int xMin = 10;
  int xMax = 9;
  int yMin = 11;
  int yMax = 8;

void setup() {
  Serial.begin(115200);
  pinMode(xMin, OUTPUT);
  pinMode(xMax, OUTPUT);
  pinMode(yMin, OUTPUT);
  pinMode(yMax, OUTPUT);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(xMin, HIGH);
  digitalWrite(xMax, HIGH);
  digitalWrite(yMin, HIGH);
  digitalWrite(yMax, HIGH);
  delay(1000);
  digitalWrite(xMin, LOW);
  digitalWrite(xMax, LOW);
  digitalWrite(yMin, LOW);
  digitalWrite(yMax, LOW);
}

void loop() {
  
   Serial.print("Switch:  ");
    Serial.print(digitalRead(buttonPin));
    Serial.print("\n");
    Serial.print("X-axis: ");
    Serial.println(float(analogRead(xPin)* (100.0/1023.0)));
    Serial.print("Y-axis: ");
    Serial.println(float(analogRead(yPin)* (100.0/1023.0)));
    Serial.print("\n\n");
    delay(100);
    
    
    
     if (analogRead(xPin)>512) {
    int  Xmax = map(analogRead(xPin), 513, 1023, 0, 255); 
    digitalWrite(xMax, HIGH);
    delay(10);
    digitalWrite(xMax, LOW);
  }
  if (analogRead(xPin)<512) {
    int  Xmin = map(analogRead(xPin), 0, 512, 0, 255); 
    digitalWrite(xMin, HIGH);
    delay(10);
    digitalWrite(xMin, LOW);
  }
  if (analogRead(yPin)>512) {
    int  Ymax = map(analogRead(yPin), 513, 1023, 0, 255); 
    digitalWrite(yMax, HIGH);
    delay(10);
    digitalWrite(yMax, LOW);
  }
  if (analogRead(yPin)<512) {
    int  Ymin = map(analogRead(yPin), 0, 512, 0, 255); 
    digitalWrite(yMin, HIGH);
    delay(10);
    digitalWrite(yMin, LOW);
  }
}
