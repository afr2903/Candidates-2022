#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <geometry_msgs/Pose2D.h>
#include <tf/tf.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

vector<geometry_msgs::Pose2D> points;

int main(int argc, char **argv){
    ros::init(argc, argv, "pathfollower");

    string line;
    int line_idx = 0;
    geometry_msgs::Pose2D current_point;
    
    string path_name;
    cout << "Type the name of the path you want to open:\n-";
    cin >> path_name;
    path_name = "/home/{user}/catkin_ws/src/navigation_challenge/paths/" + path_name + ".txt"; //Change username
    ifstream myfile ( path_name );
    if (myfile.is_open()){
        while ( getline (myfile,line) ){
            //Append the pose info in a local vector
            switch (line_idx%3){
                case 0:
                    current_point.x = stof(line);
                break;
                case 1:
                    current_point.y = stof(line);
                break;
                case 2:
                    current_point.theta = stof(line);
                    points.push_back(current_point);
                break;
                default:
                break;
            }
            line_idx++;
            cout<<points.size();
        }
        myfile.close();
    }

    for(auto point:points){
        ROS_INFO("point [%f],[%f],[%f]", point.x, point.y, point.theta);
    }

    //Tell the action client that we want to spin a thread by default
    MoveBaseClient ac("move_base", true);

    //Wait for the action server to come up
    while(!ac.waitForServer(ros::Duration(5.0))){
        ROS_INFO("Waiting for the move_base action server to come up");
    }

    move_base_msgs::MoveBaseGoal goal;

    for(auto point:points){
        goal.target_pose.header.frame_id = "odom";
        goal.target_pose.header.stamp = ros::Time::now();

        goal.target_pose.pose.position.x = point.x;
        goal.target_pose.pose.position.y = point.y;

        //Reverse the conversion to get a Quaternion
        tf::Quaternion current_quaternion;
        current_quaternion.setRPY(0, 0, point.theta);
        current_quaternion = current_quaternion.normalize();

        goal.target_pose.pose.orientation.x = current_quaternion.x();
        goal.target_pose.pose.orientation.y = current_quaternion.y();
        goal.target_pose.pose.orientation.z = current_quaternion.z();
        goal.target_pose.pose.orientation.w = current_quaternion.w();

        ROS_INFO("Sending goal");
        ac.sendGoal(goal);

        ac.waitForResult();

        if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
            ROS_INFO("Goal reached :)");
        else
            ROS_INFO("Goal failed :(");
    }
    ROS_INFO("Task finished ;)");

    return 0;
}