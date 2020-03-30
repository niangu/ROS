#include "ros/ros.h"
#include "beginner_tutorials/AddTwoInts.h" //包含先前所创建的srv文件

//对3个变量求和，并将计算结果发生给其他节点，Request为上一部分的请求，而Response为下一部分的响应
bool add(beginner_tutorials::AddTwoInts::Request  &req,
         beginner_tutorials::AddTwoInts::Response &res)
{
  res.sum = req.A + req.B + req.C;
  ROS_INFO("request: A=%d, B=%d C=%d", (int)req.A, (int)req.B, (int)req.C);
  ROS_INFO("sending back response: [%d]", (int)res.sum);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_3_ints_server");
  ros::NodeHandle n;

  //创建服务并在ROS中发布广播
  ros::ServiceServer service = n.advertiseService("add_3_ints", add);
    
  ROS_INFO("Ready to add 3 ints."); //在命令行窗口输出信息
  ros::spin();

  return 0;
}

