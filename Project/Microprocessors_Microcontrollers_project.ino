#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Servo.h>
Servo myservo;
int pos=0;
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);
const byte rows=4;
const byte cols=3;
 
char key[rows][cols]={
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};
byte rowPins[rows]={13,2,3,4};
byte colPins[cols]={5,6,7};
Keypad keypad= Keypad(makeKeymap(key),rowPins,colPins,rows,cols);
char* password="1923";
int currentposition=0;
int rLed=10;
int gLed=11;
int buzz=8;
int invalidcount=0;
 
 
 
void setup()
{
 
showscreen();
Serial.begin(9600);
pinMode(rLed, OUTPUT);
pinMode(gLed, OUTPUT);
pinMode(buzz, OUTPUT);
myservo.attach(9);
 
lcd.begin(16,2);
 
}
 
void loop()
{
    if( currentposition==0)
    {
        showscreen(); 
    }
    int l ;
    char code=keypad.getKey();
  	if(code!=NO_KEY)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Password:");
      lcd.setCursor(7,1);
      lcd.print(" ");
      lcd.setCursor(7,1);
      for(l=0;l<=currentposition;++l)
      {
        lcd.print("*");
        keypress();
      }
      if (code==password[currentposition])
      {
          ++currentposition;
          if(currentposition==4)
          {
              unlockdoor();
              currentposition=0;
          }
      }
      else
      {
        ++invalidcount;
        if(invalidcount>=3)
        {
          	invalidcount=0;
            locked();
        }else
        { 
        	incorrect();
        	currentposition=0;
        }
      }
	}
}
//When user writes the correct password, door unlocks.
void unlockdoor()
{
  digitalWrite(gLed, HIGH);
  delay(900);
  

  lcd.setCursor(0,0);
  lcd.println(" ");
  lcd.setCursor(1,0);
  lcd.print("Your password");
  lcd.setCursor(2,1);
  lcd.println("is correct!");
  lcd.setCursor(15,1);
  lcd.println(" ");
  lcd.setCursor(16,1);
  lcd.println(" ");
  lcd.setCursor(14,1);
  lcd.println(" ");
  lcd.setCursor(13,1);
  lcd.println(" ");
  unlockbuzz();
  digitalWrite(gLed, LOW);
  
  for(pos = 180; pos>=0; pos-=5)
    {
    myservo.write(pos);
    delay(5);
  }
  delay(2000);



  delay(1000);
  counterbeep();

  delay(1000);
 
  for(pos = 0; pos <= 180; pos +=5)
  {
      myservo.write(pos); 
      delay(15);


      currentposition=0;

      lcd.clear();
      showscreen();
  }
}
 
//************WRONG CODE FUNCTION********//
 
void incorrect()
{
  delay(500);
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Pass");
  lcd.setCursor(6,0);
  lcd.print("Incorrect");
  lcd.setCursor(15,1);
  lcd.println(" ");
  lcd.setCursor(4,1);
  lcd.println("Try again!");

  lcd.setCursor(13,1);
  lcd.println(" ");
  Serial.println("Pass incorrect you are unauthorized");
  digitalWrite(rLed, HIGH);
  digitalWrite(buzz, HIGH);
  delay(3000);
  lcd.clear();
  digitalWrite(rLed, LOW);
  digitalWrite(buzz,LOW);
  showscreen();
}

void clearscreen()
{
lcd.setCursor(0,0);
lcd.println(" ");
lcd.setCursor(0,1);
lcd.println(" ");
lcd.setCursor(0,2);
lcd.println(" ");
lcd.setCursor(0,3);
lcd.println(" ");
}

void keypress()
{
  digitalWrite(buzz, HIGH);
  delay(50);
  digitalWrite(buzz, LOW);
}

void showscreen()
{
  lcd.setCursor(0,0);
  lcd.println("*Enter the pass*");
  lcd.setCursor(1 ,1);

  lcd.println("To unlock door");
}

void armservo()
{

  for (pos=180;pos<=180;pos+=50)
  {
    myservo.write(pos);
    delay(5);
  }
  delay(5000);

  for(pos=180;pos>=0;pos-=50)
  {
  	myservo.write(pos);
  }
}

// Generates noise with buzzer when the door is unlocked.
void unlockbuzz()
{
  digitalWrite(buzz, HIGH);
  delay(80);
  digitalWrite(buzz, LOW);
  delay(80);
  digitalWrite(buzz, HIGH);
  delay(80);
  digitalWrite(buzz, LOW);
  delay(200);
  digitalWrite(buzz, HIGH);
  delay(80);
  digitalWrite(buzz, LOW);
  delay(80);
  digitalWrite(buzz, HIGH);
  delay(80);
  digitalWrite(buzz, LOW);
  delay(80);
}

// Starts a counter to re-lock the beep.
void counterbeep()
{
delay(1200);
 
 
lcd.clear();
digitalWrite(buzz, HIGH);
 
lcd.setCursor(2,15);
lcd.println(" ");
lcd.setCursor(2,14);
lcd.println(" ");
lcd.setCursor(2,0);
delay(200);
lcd.println("Re-locking in");
 
lcd.setCursor(4,1);
lcd.print("5");
delay(200);
lcd.clear();
lcd.setCursor(2,0);
lcd.println("Re-locking in");
digitalWrite(buzz,LOW);
delay(1000);
//2
digitalWrite(buzz, HIGH);
lcd.setCursor(2,0);
lcd.println("Re-locking in");
lcd.setCursor(4,1); //2
lcd.print("4");
delay(100);
lcd.clear();
lcd.setCursor(2,0);
lcd.println("Re-locking in");
digitalWrite(buzz,LOW);
delay(1000);
//3
digitalWrite(buzz, HIGH);
lcd.setCursor(2,0);
lcd.println("Re-locking in");
lcd.setCursor(4,1); //3
lcd.print("3");
delay(100);
lcd.clear();
lcd.setCursor(2,0);
lcd.println("Re-locking in");
digitalWrite(buzz,LOW);
delay(1000);
//4
digitalWrite(buzz, HIGH);
lcd.setCursor(2,0);
lcd.println("Re-locking in");
lcd.setCursor(4,1); //4
lcd.print("2");
delay(100);
lcd.clear();
lcd.setCursor(2,0);
lcd.println("Re-locking in");
digitalWrite(buzz,LOW);
delay(1000);
//
digitalWrite(buzz, HIGH);
lcd.setCursor(4,1);
lcd.print("1");
delay(100);
lcd.clear();
lcd.setCursor(2,0);
lcd.println("Re-locking in");
digitalWrite(buzz,LOW);
delay(1000);
//5
digitalWrite(buzz, HIGH);
delay(40);
digitalWrite(buzz,LOW);
delay(40);
digitalWrite(buzz, HIGH);
delay(40);
digitalWrite(buzz,LOW);
delay(40);
digitalWrite(buzz, HIGH);
delay(40);
digitalWrite(buzz,LOW);
delay(40);
digitalWrite(buzz, HIGH);
delay(40);
digitalWrite(buzz,LOW);
lcd.clear();
lcd.setCursor(2,0);
lcd.print("RE-LOCKING");
delay(500);
lcd.setCursor(12,0);
lcd.print(".");
delay(500);
lcd.setCursor(13,0);
lcd.print(".");
delay(500);
lcd.setCursor(14,0);
lcd.print(".");
delay(400);
lcd.clear();
lcd.setCursor(4,0);
lcd.print("LOCKED!");
delay(440);
}

//If user type wrong password system will be locked.
void locked()
{
  lcd.clear();
  delay(1000);
  lcd.setCursor(2,0);
  lcd.print("System locked");
  lcd.setCursor(1,1);
  lcd.print("Out of attempt");
  digitalWrite(buzz, HIGH);
  delay(3500);
  digitalWrite(buzz, LOW);
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("WAIT FOR ");
  lcd.setCursor(5,1);
  lcd.print("30 SECONDS");
  delay(30000);
  lcd.clear(); 
}
