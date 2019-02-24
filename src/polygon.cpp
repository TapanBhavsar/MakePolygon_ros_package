#include<cmath>
#include<ros/ros.h>
#include<geometry_msgs/Twist.h>

#include "polygon/polygon.h"

void Polygon::CalculationToFindAngleOfPolygon(double NumberOfSide)
{
	double DegreeAngleValue = kTotalOfAngles_/NumberOfSide;
	RadianAngleValue_ = 2 * M_PI - ((M_PI/180) * DegreeAngleValue);
}

void Polygon::PublishDataToCreatePolygon(bool toggle)
{
	if(toggle)
	{
		msg_.linear.x = kSideLength_;
		msg_.angular.z = 0;
	}
	else
	{
		msg_.linear.x = 0;
		msg_.angular.z = RadianAngleValue_;
	} 	
	pub_.publish(msg_);
}

void Polygon::StreamMessege()
{
	ROS_INFO_STREAM("Sending " << "Linear = " << msg_.linear.x << " Angular = " << msg_.angular.z);
}

void Polygon::DrawPolygon(double NumberOfSide, bool StreamMsg)
{
	pub_ = nh_.advertise<geometry_msgs::Twist>("turtle1/cmd_vel",kMaxQueueSize_);
	ros::Rate rate(kFrequency_);
	bool toggle = false;
	while(ros::ok())
	{
		toggle = !toggle;
		CalculationToFindAngleOfPolygon(NumberOfSide);
		PublishDataToCreatePolygon(toggle);
		if(StreamMsg) StreamMessege();
		rate.sleep();
	}
}
