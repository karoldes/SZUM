
#include <ros.h>
//#include <std_msgs/String.h>
#include <std_msgs/Int16.h>
ros::NodeHandle nh;
std_msgs::Int16 str_msg;
ros::Publisher chatter("chatter", &str_msg);

char hello[13] = "hello world!";
int liczba = 13;

 
int trigPin = 11;    // Trigger
int echoPin = 12;    // Echo
long duration, cm;
 
void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  nh.initNode();
  nh.advertise(chatter);
}
 
void loop() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  
str_msg.data = cm;
  chatter.publish(&str_msg);
  nh.spinOnce();
  
  delay(10);
}


