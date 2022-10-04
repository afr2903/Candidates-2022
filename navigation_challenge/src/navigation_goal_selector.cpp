#include <ros/ros.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <std_msgs/Float64.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Pose2D.h>
#include <tf/tf.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<geometry_msgs::Pose2D> points;
ofstream points_file;
bool finished = false;

void newPoseCallback(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg){
    //Conversion from the Quaternion orientation to RPY
    tf::Quaternion q(
        msg->pose.pose.orientation.x,
        msg->pose.pose.orientation.y,
        msg->pose.pose.orientation.z,
        msg->pose.pose.orientation.w);
    tf::Matrix3x3 m(q);
    double roll, pitch, yaw;
    m.getRPY(roll, pitch, yaw);
    
    //Current object for Pose2D
    geometry_msgs::Pose2D current_point;
    current_point.x = msg->pose.pose.position.x;
    current_point.y = msg->pose.pose.position.y;
    current_point.theta = yaw;

    ROS_INFO("New X:[%f], Y:[%f], Theta:[%f]", current_point.x, current_point.y, current_point.theta);
    
    //Key based interface
    char key;
    string path_name;
    cout << "Press an action key:\n-[N] Next point\n-[R] Repeat point\n-[D] Done\n-";
    cin >> key;

    switch (key){
        case 'N':
            points.push_back( current_point );
            ROS_INFO("point pushed");
        break;
        case 'D':
            //Save data in a txt file
            points.push_back( current_point );
            cout << "Type the name for this path:\n-";
            cin >> path_name;
            path_name = "/home/{user}/catkin_ws/src/navigation_challenge/paths/" + path_name + ".txt"; //Change username
            points_file.open( path_name ); 
            for(auto point:points){
                points_file << point.x << "\n";
                points_file << point.y << "\n";
                points_file << point.theta << "\n";
            }
            points_file.close();
            finished = true;
            ROS_INFO("end");
        break;
        default:
        break;
    }

}

int main(int argc, char **argv){
    //Node initialization
    ros::init(argc, argv, "goal_selector");
    ros::NodeHandle node;

    //Suscriber node to the initialpose topic that detects and shows only the changes in the pose
    ros::Subscriber sub = node.subscribe("initialpose", 100, newPoseCallback);

    while( ros::ok() ){
        //Flag activated when goal selector task finishes
        if( finished ){
            return 0;
        }
        ros::spinOnce();
    }

    return 0;
}