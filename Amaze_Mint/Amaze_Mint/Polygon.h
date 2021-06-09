#pragma once
#include "Engine.h"

class Polygon
{
public:
	
	Polygon()
	{
		ConvexShape  Blackness(3);
		Blackness.setPoint(0, Vector2f(0, 0));
	}

	
	//Here is my call to the sort:

	//positions.Sort(new Comparison<Position>(MapUtils.SortCornersClockwise));
	//And here is my SortCornersClockwise function:

public :
	int SortCornersClockwise(float Position_A, float Position_B);
	
	
};
