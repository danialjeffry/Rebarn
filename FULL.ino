//This arduino code is generated by PictoBlox

//Included Libraries
#include <Servo.h>
#include <DHT.h>

//MACROS are defined here
float getDistance(int trig,int echo){
    pinMode(trig,OUTPUT);
    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    pinMode(echo, INPUT);
    return pulseIn(echo, HIGH)/58.0;
}
Servo Servo11;
#define DHTPIN_3 3
#define DHTTYPE DHT11
DHT dht_3(DHTPIN_3, DHTTYPE);

void setup() {
  //put your setup code here, to run once:
  Servo11.attach(11);
  dht_3.begin();
  pinMode(2, OUTPUT);
  pinMode(5, INPUT);
  pinMode(13, OUTPUT);
  
  
}

void loop() {
  //put your main code here, to run repeatedly:
  
  
  if((getDistance(7, 6) < 10)) {
    Servo11.write(180);
  }
  else {
    Servo11.write(0);
  }
  if((dht_3.readTemperature() > 37)) {
    digitalWrite(2, true);
  }
  else {
    digitalWrite(2, false);
  }
  if((analogRead(5) < 600)) {
    digitalWrite(13, true);
  }
  else {
    digitalWrite(13, false);
  }
}
