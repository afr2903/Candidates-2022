# Manipulation Challenge | RoBorregos Candidates 2022

## Development team

| Name                    | Email                                                               | Github                                                       | Role      |
| ----------------------- | ------------------------------------------------------------------- | ------------------------------------------------------------ | --------- |
| José Cisneros | [A01283070@itesm.mx](mailto:A01283070@itesm.mx) | [@Josecisneros001](https://github.com/Josecisneros001) | PM & Programmer |
| Kevin Vega | [vegakevinrdz@gmail.com](mailto:vegakevinrdz@gmai.com) | [@KevinVegaTec](https://github.com/KevinVegaTec)   | PM & Programmer  |


## Env setup
1. Install ROS Noetic : [Reference](http://wiki.ros.org/noetic/Installation/Ubuntu)

## Installation

1. **IMPORTANT: Fork the repository into your account**

2. Clone the project repository on your local machine.

HTTP:
``` bash
$ git clone https://github.com/your-username/Candidates-2022.git
```

SSH:
``` bash 
$ git clone git@github.com:your-username/Candidates-2022.git
```

**Be sure to be in the ManipulationChallenge Branch**


Tasks:
1. Read [xArm Developer](https://github.com/xArm-Developer/xarm_ros) documentation
2. Install any additional resource in order to use the [xArm Developer (3)](https://github.com/xArm-Developer/xarm_ros#3-preparations-before-using-this-package) package
3. Identify neccesary launchfiles to test [lite6](https://www.ufactory.cc/lite-6-collaborative-robot) robot ([Reference](https://github.com/xArm-Developer/xarm_ros#5-package-description--usage-guidance))
4. Run the [Color Cube Grasping Demo](https://github.com/xArm-Developer/xarm_ros#75-color-cube-grasping-demo)(It's not neccesary to use the lite6 robot)
5. Understand the [color_recognition.py](https://github.com/xArm-Developer/xarm_ros/blob/master/xarm_gazebo/scripts/color_recognition.py) script
6. Create a service which, depending the color you send, it returns a list with all the cubes positions. Then create an script able to perfom a pick and place task one cube over another in any order you want

## References
- [xArm developer ROS package](https://github.com/xArm-Developer/xarm_ros)
- [MoveIt](https://ros-planning.github.io/moveit_tutorials/)
