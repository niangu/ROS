#include "ros/ros.h"
#include "beginner_tutorials/Num.h"

void messageCallback(const beginner_tutorials::Num::ConstPtr& msg)
{
  //这里使用了自定义消息类型int32 A，int32 B,int32 C
  ROS_INFO("I heard: [%d] [%d] [%d]", msg->A, msg->B, msg->C);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "example3_b");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("message", 1000, messageCallback);
  ros::spin();
  return 0;
}
