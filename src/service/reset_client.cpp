// my_ros1_package/src/reset_client.cpp
#include "ros/ros.h"
#include "std_srvs/Empty.h"

int main(int argc, char** argv) {
    ros::init(argc, argv, "reset_client");
    ros::NodeHandle nh;

    ros::ServiceClient resetClient = nh.serviceClient<std_srvs::Empty>("/reset");

    std_srvs::Empty srv;

    resetClient.call(srv);

    //here you can call by this method but below method is the best practice

    // if (resetClient.call(srv)) {
    //     ROS_INFO("Reset request sent successfully");
    // } else {
    //     ROS_ERROR("Failed to call reset service");
    //     return 1;
    // }

    return 0;
}
