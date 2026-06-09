#pragma once

#ifdef ROS
#include <can_msgs/Frame.h>
#else
//! Fake ros messages to allow for testing without needing to include ROS
namespace can_msgs
{
    class Frame
    {
        public:
        int id;
        int dlc;
        uint8_t data[8];
    };
}
#endif //ROS
