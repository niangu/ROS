#include "ros/ros.h"
#include "beginner_tutorials/Num.h"
#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "example3_a");
  ros::NodeHandle n;
  ros::Publisher pub = n.advertise<beginner_tutorials::Num>("message", 1000);
  ros::Rate loop_rate(10);
  while (ros::ok())
  {
    //这里使用了自定义消息类型int32 A，int32 B,int32 C
    beginner_tutorials::Num msg;
    msg.A = 1;
    msg.B = 2;
    msg.C = 3;
    pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
