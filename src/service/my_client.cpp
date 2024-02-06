
#include "ros/ros.h" 
#include "ros1_cpp_concepts/my_srv.h" 
#include <iostream> 
#include <sstream> 
using namespace std; 
 
int main(int argc, char **argv) 
{ 
 ros::init(argc, argv, "my_client"); 
 ros::NodeHandle n; 
 ros::Rate loop_rate(10); 
 ros::ServiceClient client = n.serviceClient<ros1_cpp_concepts::my_srv>("my_service"); 
 while (ros::ok()) 
 { 
  ros1_cpp_concepts::my_srv srv; 
    
  srv.request.x = 28; 
  srv.request.y = 85;

  if (client.call(srv)) 
  { 
 
//    ROS_INFO(srv.response.result.c_int()); 
   ROS_INFO("Sum: %ld", (long int)srv.response.result);
 
  } 
  else 
  { 
   ROS_ERROR("Failed to call service"); 
   return 1; 
  } 
 
 ros::spinOnce(); 
 loop_rate.sleep(); 
 
 } 
 return 0; 
} 
