#include "ros/ros.h"
#include "std_msgs/String.h"





int main(int argc, char** argv)
{
    ros::init(argc, argv, "cpp_publisher");
    ros::NodeHandle nh;

    std_msgs::String msg;

    ros::Publisher pub = nh.advertise<std_msgs::String>("chatter",10); 

    ros::Rate loop_rate(10);

    while(ros::ok())
    {
        msg.data = "Vanakkam da Maple!";
        pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep(); 
    }

    // Enter the ROS event loop
       


    return 0;
}