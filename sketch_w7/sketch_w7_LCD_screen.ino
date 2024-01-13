// LiquidCrystal - Version: Latest
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

/*
calculating distance and displayin to the LCD screen.
*/
LiquidCrystal_I2C lcd(0x27, 16, 2); // If don't work try this command into parentheses -> (0x3f)

// Sensor
#define trigpin 4
#define echopin 2
long time;
double distance;

void setup()
{
  lcd.init();
  lcd.clear();

  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
}

void loop()
{
  lcd.backlight();
  lcd.setCursor(0, 0);

  digitalWrite(trigpin, LOW);
  delayMicroseconds(3);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  time = pulseIn(echopin, HIGH);
  distance = (time * 0.0343) / 2;
  if (distance < 10)
  {
    lcd.print("Get away from me");
  }
  else
  {
    lcd.print("Distance Calcul.");
  }
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.setCursor(8, 1);
  lcd.print("cm");
  delay(500);
}
