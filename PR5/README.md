# Home Service Robot

## Project Overview
This capstone project is part of Udacity's Robotics Software Engineer Nanodegree. The goal is to develop a home service robot capable of navigating an indoor environment, driving to a pick up location, and delivering them to a specified location using **ROS (Robot Operating System)**.

## Project Overview
This project utilizes several ROS packages to enable Simultaneous Localization and Mapping (SLAM), autonomous navigation, and marker management for a TurtleBot robot. The system integrates various ROS functionalities to map an environment, localize the robot within it, and navigate efficiently based on user-defined goals.
- The robot autonomously moves to a pickup zone, simulates object pickup, and then navigates to the delivery zone.
The project consists of the following tasks:  

1. Design an indoor environment using the Building Editor in Gazebo.  
2. Generate a 2D occupancy grid map by teleoperating the robot and performing SLAM with the gmapping package, utilizing odometry and laser scan data.  
3. Implement Adaptive Monte Carlo Localization (AMCL) with the amcl package to localize the robot within the environment using odometry and laser scan data.  
4. Test the navigation stack by setting a goal for the robot via the 2D Nav Goal button in Rviz.  
5. Develop a `pick_objects` node to command the robot to navigate between designated pick-up and drop-off zones.  
6. Create an `add_markers` node that subscribes to the robot's odometry and publishes markers in Rviz to simulate object pick-up and drop-off.

## Packages Used
The project relies on the following ROS packages:

- **[slam_gmapping]**: Implements laser-based SLAM to create a 2D occupancy grid map using laser scan data and TurtleBot pose information as the robot moves through an environment.
- **[turtlebot] Package**: Provides essential functionalities for controlling the TurtleBot robot.
- **[AMCL](Adaptive Monte Carlo Localization)**: Utilizes a particle filter to localize the robot within a pre-generated map.
- **[navigation]Package**: Uses odometry data (from AMCL) and other sensor inputs to autonomously navigate the robot to a specified goal.
- **[my_robot]**: contains the custom world file.
- **[map]**: contains the map of the custom world, crucial for localisation.


## Custom Implementations
To streamline the management of markers in the environment, a custom **add_markers** node was developed. This node:

- Subscribes to requests to show or hide a marker at a given location using a custom ROS message.




## Project Structure
```
HomeServiceRobot/
│-- src/
│   ├── pick_objects/             # pick_objects node
│   ├── add_markers/              # add_marker node
│   ├── scripts/                  # shell scripts
│   ├── turtlebot/                # turtlebot_world.launch 
│   ├── turtlebot_interactions/   # view_navigation.launch 
│   ├── turtlebot_simulator/      # turtlebot_world.launch 
│   ├── SLAM_gmapping/            # gmapping_demo.launch
│   ├── map/                      # map yaml and png of custom world 
│   ├── my_robot/                 # world files and robot urdf
│   ├── capstone/                 # contains custom launch files for gazebo world and amcl_demo

│-- CMakeLists.txt

```

## Installation & Setup
1. Install **ROS1** (Kinetic/Melodic) and **Gazebo**.
2. Clone the repository into your **catkin_ws/src/** directory:
   ```sh
   cd ~/catkin_ws/src
   git clone <repository_link>
   ```
3. Build the workspace:
   ```sh
   cd ~/catkin_ws
   catkin_make
   source devel/setup.bash
   ```
4. Launch the Shell script home_service.sh:
   ```sh
   ./home_service.sh
   ```



## License
This project is licensed under the **MIT License**.



