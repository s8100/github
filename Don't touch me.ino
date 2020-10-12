#include <Servo.h>
Servo SV;
int g = 5;
int r = 6;
int trig = 8;
int echo = 9;

void setup() {
  SV.attach(10);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
}

void loop() {
  analogWrite(r, 0);
  analogWrite(g, 0);
  
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH);
  long distance = (340*duration)/2/10000;

  if(distance <= 10){
    analogWrite(r, 255);
    SV.write(100);
    delay(3000);
    }else{
    analogWrite(g, 255);  
    SV.write(10);
    }
  }
