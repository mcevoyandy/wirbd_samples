#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>
ros::NodeHandle  nh;
std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);
char hello[13] = "hello world!";
void callback(const std_msgs::Empty& toggle_msg) {
  digitalWrite(
    LED_BUILTIN,HIGH-digitalRead(LED_BUILTIN));
  str_msg.data = hello;
  chatter.publish( &str_msg );
}
ros::Subscriber<std_msgs::Empty> 
  sub("toggle_led", callback);
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  nh.initNode();
  nh.advertise(chatter);
  nh.subscribe(sub);
}
void loop() {
  nh.spinOnce();
  delay(500);
}
