# MakePolygon_ros_package

This repository has been made for making convex polygon on turtlesim. User needs to put just number of sides of polygon in main function.

## Instructions
- install [ros](http://wiki.ros.org/kinetic/Installation/Ubuntu) on linux system. I prefer ubuntu 16.04 LTS.
- Run following command in terminal to run ros master:
```
roscore
```
- check for turtlesim (ros simulator), run following command in new terminal:
```
rosrun turtlesim turtlesim_node
```
- if above command runs sucessfully then run below commands in new terminal:
```
catkin_make
source devel/setup.bash
rosrun polygon Pmain
```
