#include<ros/ros.h>
#include<geometry_msgs/Twist.h>

class Polygon
{
private:
	const double kFrequency_ = 1;
	const int kMaxQueueSize_ = 1000;
	const double kTotalOfAngles_ = 360;
	const double kSideLength_ = 1;
	ros::NodeHandle nh_;
	ros::Publisher pub_;
	geometry_msgs::Twist msg_;
	double RadianAngleValue_;
public:
	void CalculationToFindAngleOfPolygon(double NumberOfSide);
	void PublishDataToCreatePolygon(bool toggle);
	void StreamMessege();
	void DrawPolygon(double NumberOfSide, bool StreamMsg = true);
};