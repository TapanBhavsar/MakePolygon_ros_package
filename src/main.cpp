#include<ros/ros.h>

#include "polygon/polygon.h"

int main(int argc, char **argv)
{
	ros::init(argc,argv,"draw_polygon");
	int NumberOfSide = 2;
	Polygon P;
	P.DrawPolygon(NumberOfSide);
	return 0;
}