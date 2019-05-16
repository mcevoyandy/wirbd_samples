#include <ros.h>
#include <Servo.h>
#include <std_msgs/Int32.h>

ros::NodeHandle  nh;
std_msgs::Int32 servo_state_msg;
uint32_t servo_position = 0;
Servo my_servo;

ros::Publisher servo_state_pub("servo_state", &servo_state_msg);

void servo_cmd_callback( const std_msgs::Int32& servo_cmd_msg){
  servo_position = servo_cmd_msg.data;

  servo_state_msg.data = servo_position;
  
}

ros::Subscriber<std_msgs::Int32> servo_cmd_sub("servo_cmd", &servo_cmd_callback);

void setup()
{ 
  pinMode(LED_BUILTIN, OUTPUT);
  nh.initNode();
  nh.subscribe(servo_cmd_sub);
  nh.advertise(servo_state_pub);

  my_servo.attach(9);
}

void loop()
{  
  my_servo.write(servo_position);
  servo_state_pub.publish(&servo_state_msg);
  
  nh.spinOnce();
  delay(1);
}
