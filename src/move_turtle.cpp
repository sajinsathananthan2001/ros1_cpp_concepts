#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"



int main(int argc, char** argv)
{
    ros::init(argc, argv, "cpp_publisher");
    ros::NodeHandle nh;

    geometry_msgs::Twist velocity;

    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",10); 

    ros::Rate loop_rate(10);

    while(ros::ok())
    {
        velocity.linear.x = 0.5;
        velocity.angular.z = 0.1;
        pub.publish(velocity);
        ros::spinOnce();
        loop_rate.sleep(); 
    }

    // Enter the ROS event loop
       


    return 0;
}