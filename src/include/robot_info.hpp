#include <iostream>
#include <vector>   // for vector
#include <string>
#include <array>

const std::vector<std::string> robot_list = {
    "Mini",
    "Miti",
    "Zero2",
    "Zero3",
    "Pro"
};

std::array<std::string, 7> additional_packages = {
    "Foxglove",
    "Slam Toolbox",
    "Nav2",
    "Slamtec Lidar Driver",
    "BMI088 IMU Driver",
    "BNO055 IMU Driver",
    "Intel Realsense Driver"
};

std::array<bool, 7> additional_packages_states = {
    true,
    false,
    false,
    false,
    false,
    false,
    false
};