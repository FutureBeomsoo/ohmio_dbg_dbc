#pragma once

#include <cstdint>

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
