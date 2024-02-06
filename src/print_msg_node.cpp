
#include "ros/ros.h"
#include "std_msgs/String.h"





int main(int argc, char** argv)
{
    ros::init(argc, argv, "simple_cpp_node");
    ros::NodeHandle nh;

    ROS_INFO("Hello world!");
    ROS_WARN("Hello world!");
    ROS_DEBUG("Hello world!");
    ROS_ERROR("Hello world!");
    ROS_FATAL("Hello world!");

    // Enter the ROS event loop
    ros::spin();

    return 0;
}
