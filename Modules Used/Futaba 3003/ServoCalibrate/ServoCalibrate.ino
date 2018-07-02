#include "Arduino.h"
#include <SoftwareSerial.h>
/************************************************/
#include <Servo.h>
/************************************************/
Servo doorServo;//create servo object to control a servo
Servo talkServo;
/************************************************/

//Servo angles
const int talkRelease=28;
const int talkPress=61;
const int doorRelease=28;
const int doorPress=61;

void setup () 
{
  Serial.begin(9600);
  doorServo.attach(9);//attachs the servo on pin 9 to servo object
  doorServo.write(doorRelease);//Start at 28 degrees 
  talkServo.attach(10);//attachs the servo on pin 9 to servo object
  talkServo.write(talkRelease);//Start at 28 degrees 
  Serial.println("APPLICATION START");
}


void loop () 
{   
  delay (1000);
  doorServo.write(doorPress);
  delay(300);
  doorServo.write(doorRelease);
  delay(300);
}

