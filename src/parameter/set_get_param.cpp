#include "ros/ros.h"

int main(int argc, char** argv) {
    // Initialize the ROS node
    ros::init(argc, argv, "parameter_example");
    
    // Create a NodeHandle
    ros::NodeHandle nh;

    // Set a parameter
    nh.setParam("/example_param", "Hello, ROS!");

    // Get the parameter value
    std::string paramValue;
    if (nh.getParam("/example_param", paramValue)) {
        ROS_INFO("Value of '/example_param': %s", paramValue.c_str());
    } else {
        ROS_ERROR("Failed to get parameter '/example_param'");
    }

    // Shutdown the node
    ros::shutdown();

    return 0;
}
