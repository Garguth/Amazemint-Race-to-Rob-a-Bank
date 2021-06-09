#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

class Point
{
public:
	double x;
	double y;
	Point(double xx, double yy) : x(xx), y(yy) {}
	~Point();
	inline friend ostream& operator<<(ostream& output, const Point& point)
	{
		output << "[" << point.x << ", " << point.y << "]";
		return output;
	}



	int get_quadrant(const Point& p);

	double get_clockwise_angle(const Point& p);

	bool compare_points(const Point& a, const Point& b);

	

};
