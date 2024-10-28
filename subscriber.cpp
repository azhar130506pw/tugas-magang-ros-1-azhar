#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>

void callback(const std_msgs::String::ConstPtr& msg) {
    ROS_INFO("Data diterima: %s", msg->data.c_str());
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "buku_subscriber");
    ros::NodeHandle nh;

    // Membuat subscriber untuk topik "buku_data"
    ros::Subscriber sub = nh.subscribe("buku_data", 1000, callback);

    ros::spin();  // Menunggu dan memproses callback
    return 0;
}

