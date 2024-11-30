#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
//TODO: Include the ball_chaser "DriveToTarget" header file
#include "ball_chaser/DriveToTarget.h"


// ROS::Publisher motor commands;
ros::Publisher motor_command_publisher;

// TODO: Create a handle_drive_request callback function that executes whenever a drive_bot service is requested
// This function should publish the requested linear x and angular velocities to the robot wheel joints
// After publishing the requested velocities, a message feedback should be returned with the requested wheel velocities


 // This function checks and clamps the joint angles to a safe zone
std::vector<float> check_direction(float requested_v, float requested_om)
{
    // Define clamped joint angles and assign them to the requested ones
    float v = requested_v;
    float om = requested_om;
    
     if (v == 0.5 && om == 0.0) {
       v=0.5;
       om=0;
    } else if (v == 0.0 && om == 0.5) {
       v=0.0;
       om=0.5;
    } else if (v == 0.0 && om == -0.5) {
       v=0.0;
       om=-0.5;
    } else {
       
       v=0.0;
       om=0.0;
    }
    

   

    // Store clamped joint angles in a clamped_data vector
    std::vector<float> output_data = { v, om };

    return output_data;
}


bool handle_drive_request(ball_chaser::DriveToTarget::Request& req,
    ball_chaser::DriveToTarget::Response& res)
{

    ROS_INFO("DriveToTargetRequest received - linvel:%1.2f, angvel:%1.2f", (float)req.linear_x, (float)req.angular_z);
    
    geometry_msgs::Twist motor_command;
    std::vector<float> vels = check_direction(req.linear_x, req.angular_z);
       
    motor_command.linear.x = vels[0];
    motor_command.angular.z = vels[1];
        
    motor_command_publisher.publish(motor_command);

    // Return a response message
    res.msg_feedback = "Velocities - V: " + std::to_string( motor_command.linear.x) + " , Omega: " + std::to_string(motor_command.angular.z);
    ROS_INFO_STREAM(res.msg_feedback);

    return true;
    }



int main(int argc, char** argv)
{
    // Initialize a ROS node
    ros::init(argc, argv, "drive_bot");

    // Create a ROS NodeHandle object
    ros::NodeHandle n;

    // Inform ROS master that we will be publishing a message of type geometry_msgs::Twist on the robot actuation topic with a publishing queue size of 10
    motor_command_publisher = n.advertise<geometry_msgs::Twist>("/cmd_vel", 10);

    // Define a drive /ball_chaser/command_robot service with a handle_drive_request callback function
    ros::ServiceServer service = n.advertiseService("/ball_chaser/command_robot", handle_drive_request);
    ROS_INFO("Ready to send velocity commands");

    // Delete the loop, move the code to the inside of the callback function and make the necessary changes to publish the requested velocities instead of constant values
    
    

    // Handle ROS communication events
    ros::spin();

    return 0;
}
