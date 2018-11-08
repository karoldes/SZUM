#include <ros.h>
//#include <std_msgs/String.h>
#include <std_msgs/Int16.h>
ros::NodeHandle nh;

std_msgs::Int16 str_msg;
ros::Publisher chatter("chatter", &str_msg);

char hello[13] = "hello world!";
int liczba = 13;


void setup() 
{
  // put your setup code here, to run once:
  nh.initNode();
  nh.advertise(chatter);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  str_msg.data = liczba;
  chatter.publish(&str_msg);
  nh.spinOnce();

  delay(1000);
}
