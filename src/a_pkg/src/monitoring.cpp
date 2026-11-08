#include <cstdio>
#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "a_pkg/modern_time.hpp"

using namespace std::chrono_literals;
using namespace std;


/*
  Before you start reading this:
  1. DONT CHANGE ANYTHING
  2. DONT CHANGE ANYTHING

  and lastly and not least DONT CHANGE ANYTHING

  thank you ^^

  and before you push to github, just check if you DID CHANGE SOMETHING and YES, i can see the git history ^^
*/


struct hola {
  string TopicName;
  double lastTime;
  string TopicType;
  std::shared_ptr<rclcpp::GenericSubscription> SubObject = nullptr;
};

class MonitoringNode : public rclcpp::Node
{
  public:
  MonitoringNode() : Node("MonitoringNode")
  {
    for (size_t i=0;i < (List.size());i++)
    {
      List[i].SubObject = this->create_generic_subscription(List[i].TopicName,List[i].TopicType, rclcpp::QoS(10), 
      [this, i](std::shared_ptr<rclcpp::SerializedMessage> msg){
        this->List[i].lastTime = ModernTime::NowInMs();
      });
    }
  }
  private:
  double t = ModernTime::NowInMs();
  vector<hola> List = { 
    {"topic",t, "std_msgs/msg/String"}
  };
};

int main(int argc, char ** argv)
{
  (void) argc;
  (void) argv;

  printf("Starting MonitoringNode\n");

  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MonitoringNode>());
  rclcpp::shutdown();
  return 0;
}
