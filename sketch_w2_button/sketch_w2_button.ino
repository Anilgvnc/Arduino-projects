/*
In this project we try to light a led with switch button.
You can try this code 
*/

void setup() {
  pinMode(3,OUTPUT);
  pinMode(5, INPUT);
}

void loop() {
    int read = digitalRead(5);
    digitalWrite(3, read);
    
    /*
    if(read == HIGH ){
      digitalWrite(3, HIGH);
    }
    else{
      digitalWrite(3, LOW);
    }
    */
    
}
