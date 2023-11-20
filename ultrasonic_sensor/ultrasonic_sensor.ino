#include <Servo.h>
Servo myservo;

const int trigPin = 10;
const int echoPin = 11;
int pos = 0;
float duration, distance;


void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  myservo.attach(9);
}


void loop() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(10);
  if (distance <=3)
  {
   
    myservo.write(0);              
    delay(10);
  }

  if (distance >=13)
  {
   
    myservo.write(90);              
    delay(10);
  }
}
   
  

 
