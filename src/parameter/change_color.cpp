
#include "ros/ros.h"
#include <random>

int main(int argc, char** argv) {
    ros::init(argc, argv, "change_color");
    ros::NodeHandle nh;

    //----------------------------------------------------------------------------------
    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    // Define a distribution for integers between 0 and 255
    std::uniform_int_distribution<> dist(0, 255);
    //----------------------------------------------------------------------------------


    nh.setParam("/turtlesim/background_b",dist(gen));
    nh.setParam("/turtlesim/background_g",dist(gen));
    nh.setParam("/turtlesim/background_r",dist(gen));
    


    return 0;
}
