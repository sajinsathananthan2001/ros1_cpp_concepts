#include "ros/ros.h"
#include "std_msgs/String.h"


void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("I heard: [%s]", msg->data.c_str());
}


int main(int argc, char** argv)
{
    ros::init(argc, argv, "cpp_subscriber");
    ros::NodeHandle nh;

    std_msgs::String msg;

    ros::Subscriber sub = nh.subscribe("chatter", 10,chatterCallback);

    // Enter the ROS event loop
    ros::spin();

    return 0;
}