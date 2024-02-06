// Include necessary headers
#include "ros/ros.h"
#include <actionlib/client/simple_action_client.h>
#include "ros1_cpp_concepts/Demo_actionAction.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "demo_action_client");
  actionlib::SimpleActionClient<ros1_cpp_concepts::Demo_actionAction> ac("demo_action", true);

  // Wait for the action server to start
  ac.waitForServer();

  // Create a goal and send it to the action server
  ros1_cpp_concepts::Demo_actionGoal goal;
  goal.count = 10;
  ac.sendGoal(goal);

  // Optionally, wait for the action to finish and check the result/feedback
  ac.waitForResult();
  return 0;
}
