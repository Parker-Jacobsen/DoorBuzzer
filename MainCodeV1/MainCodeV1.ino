//This program responds to a microphone pulse, triggering a servo to activate the door release button
/************************************************/
#include <Servo.h>
#include <SoftwareSerial.h>
/************************************************/

Servo doorServo;//create servo object to control a servo

//Servo angles
const int doorRelease=28;
const int doorPress=57;  

const int sensorPin = A0; // select the input pin for the potentiometer

int sensorValue = 0; // variable to store the value coming from the sensor
int max=0;

void setup () 
{
  Serial.begin (9600);
  doorServo.attach(11);//attachs the servo on pin 9 to servo object
  doorServo.write(doorRelease);//Start at 28 degrees 
  Serial.println("APPLICATION START");
}
 
void loop () 
{
  Serial.println("Loop Start");

  sensorValue = analogRead (sensorPin);
  if (sensorValue>max)
  {
        max=sensorValue;
  }
  if(sensorValue>23)
  {   
      Serial.println("DoorPress");
      doorServo.write(doorPress);
      delay(300);
      doorServo.write(doorRelease);
      delay(300);
  }
  Serial.println();
  Serial.print("Current Value:\t");
  Serial.print(sensorValue, DEC);
  Serial.print("\tMax:\t");
  Serial.println(max);
  delay(1000);
}


