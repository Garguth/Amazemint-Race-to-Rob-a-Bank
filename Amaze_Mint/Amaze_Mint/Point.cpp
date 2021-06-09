#include "Point.h"

Point::~Point() { ; }


/* get quadrant from 12 o'clock*/
int Point::get_quadrant(const Point& p)
{
	int result = 4; //origin

	if (p.x > 0 && p.y > 0)
		return 1;
	else if (p.x < 0 && p.y > 0)
		return 2;
	else if (p.x < 0 && p.y < 0)
		return 3;
	//else 4th quadrant
	return result;
}

double Point::get_clockwise_angle(const Point& p)
{
	double angle = 0.0;
	int quadrant = get_quadrant(p);

	/*making sure the quadrants are correct*/
	cout << "Point: " << p << " is on the " << quadrant << " quadrant" << endl;

	/*calculate angle and return it*/
	angle = -atan2(p.x, -p.y);
	return angle * 180/3.141592;
}

bool Point::compare_points(const Point& a, const Point& b)
{
	return (get_clockwise_angle(a) < get_clockwise_angle(b));
}