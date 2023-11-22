/*

*/

void setup() {
    pinMode(23,OUTPUT);//23 is pin number.
}

void loop() {
    digitalWrite(23, HIGH);//HIGH commet for 5V.
    delay(1000);
    digitalWrite(23, LOW);//LOW for ground.
    delay(1000);
}
