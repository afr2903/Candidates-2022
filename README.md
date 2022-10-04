# navigation_challenge
## _Navigation Challenge for Candidates Rbrgs 22_


[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://travis-ci.org/joemccann/dillinger)

Navigation pathfollower application with a goal selector visual feature,
powered with ROS Noetic and the ROS Navigation Stack.

## Features

- PGM file generated through SLAM and optimized for different robot types
- Visual selector of the desired navigation goals thorugh the RViz interface
- Gazebo simulator application to follow the desired number of goals
- Navigation Stack features with  the Turtlebot3

## Tech used
- ROS Noetiic
- Ubuntu 20.04
- Gazebo
- RViz
- ROS Navigation Stack
- Turtlebot3
- GIMP
- Visual Studio Code
- Passion and dedication

## Installation

Package build in ROS Noetic for Ubuntu 20.04

Inside the local `catkin_ws` workspace clone this repository.

```
$ cd ~/catkin_ws/src
$ git clone https://github.com/afr2903/navigation_challenge.git
$ catkin_make
```
### _Turtlebot3 installation_ 
In case Turtlebot3 is not already installed:
```
$ sudo apt-get update
$ sudo apt-get upgrade
$ cd ~/catkin_ws/src/
$ git clone https://github.com/ROBOTIS-GIT/turtlebot3_msgs.git -b noetic-devel
$ git clone  https://github.com/ROBOTIS-GIT/turtlebot3.git -b noetic-devel
$ cd ~/catkin_ws && catkin_make
```
Then, install the simulation packages needes for the Turtlebot3, with the Gazeebo and RViz tools:
```
~/catkin_ws/src/
$ git clone https://github.com/ROBOTIS-GIT/turtlebot3_simulations.git
$ cd ~/catkin_ws && catkin_make
```
To avoid typing aliases and path lines in everey execution, modify the `./bashrc` file:
```
$ cd
$ gedit .bashrc
```
Inside the bashrc file, put the following aliases. 
```
alias burger='export TURTLEBOT3_MODEL=burger'
alias waffle='export TURTLEBOT3_MODEL=waffle'
alias tb3fake='roslaunch turtlebot3_fake turtlebot3_fake.launch'
alias tb3teleop='roslaunch turtlebot3_teleop turtlebot3_teleop_key.launch'
alias tb3='roslaunch turtlebot3_gazebo turtlebot3_empty_world.launch'
alias tb3maze='roslaunch turtlebot3_gazebo turtlebot3_world.launch'
alias tb3house='roslaunch turtlebot3_gazebo turtlebot3_house.launch'
```
Also, at the end of the file, write the following commands
```
source /opt/ros/noetic/setup.bash
source /home/{user}/catkin_ws/devel/setup.bash
export TURTLEBOT3_MODEL=burger
export SVGA_VGPU10=0
```
### _Move files location under "files" folder_
In order to use the custom launch files and maps, they need to be moved into different locations.
Go to the location of the package: `~/catkin_ws/src/navigation_challenge/files/`:

- Move `roborregos_navigation_challenge.world` to the:
`~/catkin_ws/src/turtlebot3_simulations/turtle3_gazebo/worlds/` folder.

- Move `turtlebot3_roborregos_nav.launch` to the:
`~/catkin_ws/src/turtlebot3_simulations/turtle3_gazebo/launch/` folder.

Now the package is ready to be executed.
## Execution

Run all the applications needed with the following commands.
```
$ roscore
$ roslaunch turtlebot3_gazebo turtlebot3_roborregos_nav.launch
$ roslaunch turtlebot3_navigation turtlebot3_navigation.launch map_file:=/home/{user}/catkin_ws/src/navigation_challenge/files/navigation_challenge_map.yaml
```
It will open the Gazebo simulator and the RViz Navigation Stack map.
In the RViz window, click on `2D Pose Estimate` and pose the robot in the same Pose as the Gazebo simulator
Open the script `navigation_goal_selector.cpp` and `navigation_pathfollower.cpp`, then change the field `{user}` for your device username, in lines 50 and 25, respectively. Save the changes.

Now build the changes, clear the costmaps and run the `navigation_goal_selector` script:
```
$ cd ~/catkin_ws && catkin_make
$ rosservice call /move_base/clear_costmaps
$ rosrun navigation_challenge goal_selector
```
In the RViz window, click on `2D Pose Estimate` and pose the robot to set a new `Goal`.
The terminal running the script will display a menu:
```
Press an action key:
-[N] Next point
-[R] Repeat point
-[D] Done
-
```
Type the key designated for the desired action then add another `Goal` and repeat.
Or keep adding `Goals` in RViz without typing in the terminal each time, until the end of path, the buffer size is big enough. Just remember the number of `Goals` added.
You can add as many `Goals` as you want.
After pressing the key `D` at the end of your path, you will be prompted with:
```
Type the name for this path:
-
```
After writing the name for your path and pressing `Enter` your path will have been saved in a _.txt_ file

For the `pathfollower` to perform correctly, reset the enviroment by posing the robot in the same Pose as the Gazebo simulator, and clearing the costmaps. Now you can run the `navigation_pathfollower` script.
```
$ rosservice call /move_base/clear_costmaps
$ rosrun navigation_challenge pathfollower
```
In the message display in the terminal, write the name of the desired path to run, exactly as how was saved in the `goal_selector`.
```
Type the name of the path you want to open:
-
```
Now you can enjoy watching the robot following your path ;)
Try adding obstacles during the runtime to witness the ROSNavigation Stack robustness and adaptability.

Any feedback is appreciated <3

[//]: # (These are reference links used in the body of this note and get stripped out when the markdown processor does its job. There is no need to format nicely because it shouldn't be seen. Thanks SO - http://stackoverflow.com/questions/4823468/store-comments-in-markdown-syntax)

   [dill]: <https://github.com/joemccann/dillinger>
   [git-repo-url]: <https://github.com/joemccann/dillinger.git>
   [john gruber]: <http://daringfireball.net>
   [df1]: <http://daringfireball.net/projects/markdown/>
   [markdown-it]: <https://github.com/markdown-it/markdown-it>
   [Ace Editor]: <http://ace.ajax.org>
   [node.js]: <http://nodejs.org>
   [Twitter Bootstrap]: <http://twitter.github.com/bootstrap/>
   [jQuery]: <http://jquery.com>
   [@tjholowaychuk]: <http://twitter.com/tjholowaychuk>
   [express]: <http://expressjs.com>
   [AngularJS]: <http://angularjs.org>
   [Gulp]: <http://gulpjs.com>

   [PlDb]: <https://github.com/joemccann/dillinger/tree/master/plugins/dropbox/README.md>
   [PlGh]: <https://github.com/joemccann/dillinger/tree/master/plugins/github/README.md>
   [PlGd]: <https://github.com/joemccann/dillinger/tree/master/plugins/googledrive/README.md>
   [PlOd]: <https://github.com/joemccann/dillinger/tree/master/plugins/onedrive/README.md>
   [PlMe]: <https://github.com/joemccann/dillinger/tree/master/plugins/medium/README.md>
   [PlGa]: <https://github.com/RahulHP/dillinger/blob/master/plugins/googleanalytics/README.md>
