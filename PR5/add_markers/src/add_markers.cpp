#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "add_markers");
    ros::NodeHandle n;
    ros::Rate r(1);
    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

  // Set our initial shape type to be a cube
    uint32_t shape = visualization_msgs::Marker::CUBE;

 
    visualization_msgs::Marker marker;
    // Set the frame ID and timestamp. See the TF tutorials for information on these.
    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker. This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "add_markers";
    marker.id = 0;

    // Set the marker type. Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker.type = shape;

    // Set the marker action. Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker.action = visualization_msgs::Marker::ADD;

    // Set the pose of the marker. This is a full 6DOF pose relative to the frame/time specified in the header
    marker.pose.position.x = 3;
    marker.pose.position.y = 2;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 0.25;
    marker.scale.y = 0.25;
    marker.scale.z = 1.0;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.0f;
    marker.color.g = 1.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0;

    marker.lifetime = ros::Duration();

    // Publish the marker
    while (marker_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        return 0;
      }
      ROS_WARN_ONCE("Please create a subscriber to the marker1");
      sleep(1);
    }
    marker_pub.publish(marker);
    
   // Wait for 5 seconds
    ros::Duration(5.0).sleep();

  // After 5 seconds, set the action to DELETE the marker
    marker.action = visualization_msgs::Marker::DELETE;

  // Publish the delete command
    marker_pub.publish(marker);

 // Wait for 5 seconds
    ros::Duration(5.0).sleep();



////////////////////////////////////////////////////////////////7
    visualization_msgs::Marker marker2;
// Set the frame ID and timestamp. See the TF tutorials for information on these.
    marker2.header.frame_id = "map";
    marker2.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker. This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker2.ns = "add_markers";
    marker2.id = 1;


 // Set the marker type. Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker2.type = shape;

    // Set the marker action. Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker2.action = visualization_msgs::Marker::ADD;

    // Set the pose of the marker. This is a full 6DOF pose relative to the frame/time specified in the header
    marker2.pose.position.x = 4;
    marker2.pose.position.y = 2;
    marker2.pose.position.z = 0;
    marker2.pose.orientation.x = 0.0;
    marker2.pose.orientation.y = 0.0;
    marker2.pose.orientation.z = 0.0;
    marker2.pose.orientation.w = 1.0;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker2.scale.x = 0.25;
    marker2.scale.y = 0.25;
    marker2.scale.z = 1.0;

    // Set the color -- be sure to set alpha to something non-zero!
    marker2.color.r = 0.0f;
    marker2.color.g = 1.0f;
    marker2.color.b = 0.0f;
    marker2.color.a = 1.0;

    marker2.lifetime = ros::Duration();

    // Publish the marker
    while (marker_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        return 0;
      }
      ROS_WARN_ONCE("Please create a subscriber to the marker2");
      sleep(1);
    }
    marker_pub.publish(marker2);
    ROS_INFO("Publishing marker");
    
    ros::Duration().sleep();
    ros::spin();
    return 0;
}

