#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    ros::init(argc, argv, "buku_publisher");
    ros::NodeHandle nh;

    // Membuat publisher dengan topik "buku_data"
    ros::Publisher pub = nh.advertise<std_msgs::String>("buku_data", 1000);

    ros::Rate loop_rate(1);  // Frekuensi pengiriman 1 Hz

    while (ros::ok()) {
        string judul, penulis;
        int id, tahun;

        // Meminta input dari pengguna
        cout << "Masukkan ID Buku: ";
        cin >> id;
        cin.ignore();  // Membersihkan buffer
        cout << "Masukkan Judul Buku: ";
        getline(cin, judul);
        cout << "Masukkan Penulis Buku: ";
        getline(cin, penulis);
        cout << "Masukkan Tahun Terbit: ";
        cin >> tahun;

        // Membuat pesan
        std_msgs::String msg;
        stringstream ss;
        ss << "ID: " << id << ", Judul: " << judul
           << ", Penulis: " << penulis << ", Tahun: " << tahun;
        msg.data = ss.str();

        // Publish pesan
        ROS_INFO("Mempublikasikan: %s", msg.data.c_str());
        pub.publish(msg);

        ros::spinOnce();  // Memastikan ROS berjalan
        loop_rate.sleep();  // Tunggu sebelum iterasi berikutnya
    }

    return 0;
}

// ROS error, hanya kode yang bisa saya kerjakan