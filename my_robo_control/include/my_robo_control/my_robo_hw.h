#include <ros/ros.h>
#include <hardware_interface/joint_command_interface.h>
#include <hardware_interface/joint_state_interface.h>
#include <hardware_interface/robot_hw.h>
#include <map>
#include <string>
#include <vector>

class MyRobo : public hardware_interface::RobotHW
{
public:
    MyRobo();
    ros::Time getTime() const { return ros::Time::now(); }
    ros::Duration getPeriod() const { return ros::Duration(0.01); }
    void read(ros::Time, ros::Duration);
    void write(ros::Time, ros::Duration);

protected:
    hardware_interface::JointStateInterface jnt_state_interface;
    hardware_interface::VelocityJointInterface velocity_joint_interface;
    double cmd_[2];
    double pos_[2];
    double vel_[2];
    double eff_[2];
};
