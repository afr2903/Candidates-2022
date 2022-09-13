#  Navigation Challenge - RoBorregos Candidates 2022 

## Development team

| Name                    | Email                                                               | Github                                                       | Role      |
| ----------------------- | ------------------------------------------------------------------- | ------------------------------------------------------------ | --------- |
| José Cisneros | [A01283070@itesm.mx](mailto:A01283070@itesm.mx) | [@Josecisneros001](https://github.com/Josecisneros001) | PM & Programmer |
| Kevin Vega | [vegakevinrdz@gmail.com](mailto:vegakevinrdz@gmai.com) | [@KevinVegaTec](https://github.com/KevinVegaTec)   | PM & Programmer  |


## Env setup
1. Install ROS Melodic with tiago : [Reference](http://wiki.ros.org/Robots/TIAGo/Tutorials/Installation/InstallUbuntuAndROS)
2. Or Install Tiago with Docker: [Reference](http://wiki.ros.org/Robots/TIAGo/Tutorials/Installation/Installing_Tiago_tutorial_docker)

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
**Be sure to be in the NavigationChallenge Branch**

Tasks:
1. Follow [TIAGo Tutorials](http://wiki.ros.org/noetic/Installation/Ubuntu) in order to understand how the navigation system works
2. Create a map (using [@Home map](https://github.com/RoBorregos/robocup-home/blob/develop/catkin_home/src/simulation/worlds/manipulation.world) ) 
3. Design a system using the navigation stack and save at least 4 different goals
4. Plan a route avoiding an area (n point)
5. With the goals saved, make an script to load and send to the navigation node.

## References
- [TIAGo Tutorials](http://wiki.ros.org/Robots/TIAGo/Tutorials)
- [ROS Navigation](http://wiki.ros.org/navigation)
