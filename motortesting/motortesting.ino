#include <Servo.h>

Servo servoA; // create servo object to control a servo

int potpin = 0; // analog pin used to connect the potentiometer
int val; // variable to read the value from the analog pin
int lastval = 90;
int servoAPosition;
int servoBPosition;

void setup() {
    servoA.attach(9); 
    Serial.begin(9600);
    delay(1000);
}

void loop() {
    val = analogRead(potpin);
    int servpos = servoA.read();
    Serial.println(servpos);    
    if(val > lastval + 20){
        Serial.print("LastVal = ");
        Serial.println(lastval);
        Serial.print("val = ");
        Serial.println(val);  
        Serial.println("Open");
        servoA.writeMicroseconds(700);
        delay(1000);    
    }
    if(val < lastval - 20){
        Serial.print("LastVal = ");
        Serial.println(lastval);
        Serial.print("val = ");
        Serial.println(val);  
        Serial.println("Close");
        servoA.writeMicroseconds(2300);
        delay(1000);    
    }
    lastval = val;    
    delay(50);
}
