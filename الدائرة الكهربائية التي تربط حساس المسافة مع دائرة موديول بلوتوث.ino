// C++ code
//
#include <SoftwareSerial.h>
SoftwareSerial myserial(5,6);

#include <Servo.h>
int trig=9;
int echo=8;
int dt=10;
Servo servo;


void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  servo.attach(7);
}

void loop()
{
  
  if (calc_dis()<10)
  {
    for (int i=0;i<=540;i++)
    {
      servo.write(i);
      delay(1);
    }
    delay(100);
    for (int i=540;i>=0;i--)
    {
      servo.write(i);
      delay(1);
    }
    delay(100);
  }
}

int calc_dis()
{
  int duration,distance;
  digitalWrite(trig, HIGH);
  delay(dt); // Wait for 10 millisecond(s)
  digitalWrite(trig, LOW);
  duration=pulseIn(echo,HIGH);
  distance=(duration/2)/29.1;
  return distance;
}
