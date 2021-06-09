#pragma once
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <stddef.h>



//using namespace sf;
using namespace std;

class Rays
{
private:
	const float PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286;

public:



	const int NUMsegments = 60;

	struct ray  //The rays the calculate the view
	{
		float ax;
		float ay;
		float bx;
		float by;
	};

	struct segment //The shapes in the scene
	{
		float ax;
		float ay;
		float bx;      
		float by;
	};

	struct intersection
	{
		float x;
		float y;
	}intersectionFinalB[60], intersectionFinalT[60];

	ray rayMake; //Starting Ray used to calculate intersection

	ray rayFinal; //The Final Ray to be drawn

	struct segmentFinal //The shapes in the scene
	{
		float ax;
		float ay;
		float bx;
		float by;
	}Lines[60];


	intersection GetIntersection(ray rays, segmentFinal segments[], int x);


	void updateRays(ray ray, segmentFinal segments[], float BobX, float BobY);

	

	struct Point
	{
		float x, y;
		float angleP;
	}Points[60];




};