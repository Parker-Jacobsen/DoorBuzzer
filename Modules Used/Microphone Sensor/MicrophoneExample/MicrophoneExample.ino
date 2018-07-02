//Program that reads from arduino microphone every second and tracks highest value 

const int sensorPin = A0; // select the input pin for the potentiometer

int sensorValue = 0; // variable to store the value coming from the sensor
int max=0;
int min=1023;

void setup() 
{
  Serial.begin(9600);
  Serial.println("APPLICATION START");

}

void loop() 
{
  sensorValue = analogRead (sensorPin);
  if (sensorValue>max)
    {
        max=sensorValue;
    }
    if (sensorValue<min)
    {
        min=sensorValue;
    }
  Serial.print("Current Value:\t");
  Serial.print(sensorValue, DEC);
  Serial.print("\tMax:\t");
  Serial.print(max);
  Serial.print("\tMin:");
  Serial.println(min);

  delay(1000);
}
