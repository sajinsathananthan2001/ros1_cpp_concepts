// Include necessary headers
#include "ros/ros.h"
#include <actionlib/server/simple_action_server.h>
#include "ros1_cpp_concepts/Demo_actionAction.h"

class DemoActionServer {
public:
  DemoActionServer(std::string name) :
    as_(nh_, name, boost::bind(&DemoActionServer::executeCB, this, _1), false),
    action_name_(name)
  {
    as_.start();
  }

  // Callback function for executing the action
  void executeCB(const ros1_cpp_concepts::Demo_actionGoalConstPtr &goal)
  {
    // Your action logic goes here
    // Use goal->count to determine the target count
    // Publish feedback using as_.publishFeedback(feedback);
    // Set result when the action is completed
    // as_.setSucceeded(result);
  }

private:
  ros::NodeHandle nh_;
  actionlib::SimpleActionServer<ros1_cpp_concepts::Demo_actionAction> as_;
  std::string action_name_;
};

int main(int argc, char** argv)
{
  ros::init(argc, argv, "simple_action_server");
  DemoActionServer demo_action_server("demo_action");
  ros::spin();
  return 0;
}
