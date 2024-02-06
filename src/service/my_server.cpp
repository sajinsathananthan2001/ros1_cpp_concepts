
#include "ros/ros.h" 
#include "ros1_cpp_concepts/my_srv.h" 
#include <iostream> 
#include <sstream> 
using namespace std; 
 
bool my_service_callback(ros1_cpp_concepts::my_srv::Request &req, 
    ros1_cpp_concepts::my_srv::Response &res) { 
    std::stringstream ss; 
    ss << "Received Here"; 
    res.result = req.x + req.y;
    return true; 
} 
 
int main(int argc, char **argv) { 
    ros::init(argc, argv, "my_srv_server"); 
    ros::NodeHandle nh; 
    ros::ServiceServer service = nh.advertiseService("my_service", my_service_callback); 
    ROS_INFO("Ready to receive from client."); 
    ros::spin(); 
    return 0; 
} 













