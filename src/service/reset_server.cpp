// my_ros1_package/src/reset_server.cpp
#include "ros/ros.h"
#include "std_srvs/Empty.h"

bool resetCallback(std_srvs::Empty::Request& req, std_srvs::Empty::Response& res) {
    ROS_INFO("Resetting turtlesim server");
    // Implement your reset logic here
    return true;
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "reset_server");
    ros::NodeHandle nh;

    ros::ServiceServer resetService = nh.advertiseService("/reset", resetCallback);

    ROS_INFO("Reset server ready.");

    ros::spin();

    return 0;
}
