# Home Service Robot

## Project Overview
This capstone project is part of Udacity's Robotics Software Engineer Nanodegree. The goal is to develop a home service robot capable of navigating an indoor environment, driving to a pick up location, and delivering them to a specified location using **ROS (Robot Operating System)**.

## Localization, Navigation, and Mapping
- **Localization**: The robot determines its position in the environment using **Adaptive Monte Carlo Localization (AMCL)**. This approach helps the robot estimate its position by comparing sensor data with a pre-built map.
- **Mapping**: The **Simultaneous Localization and Mapping (SLAM)** algorithm is used to create a map of the environment. The robot builds the map dynamically while exploring an unknown space.
- **Navigation**: The **move_base** package is used to plan and execute paths to a target location while avoiding obstacles. It utilizes **global and local costmaps** to ensure safe movement.

## Project Structure
```
HomeServiceRobot/
│-- src/
│   ├── pick_objects/
│   ├── add_markers/
│   ├── scripts/
│   ├── turtlebot/
│   ├── turtlebot_interactions/
│   ├── turtlebot_simulator/
│   ├── SLAM_gmapping/
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

   

## Usage
- The robot autonomously moves to a pickup zone, simulates object pickup, and then navigates to the delivery zone.
- The environment includes obstacles to test path planning and obstacle avoidance.



## License
This project is licensed under the **MIT License**.



