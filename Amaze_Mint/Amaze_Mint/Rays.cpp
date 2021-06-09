#include "Rays.h"





Rays::intersection Rays::GetIntersection(ray rays, segmentFinal segments[], int x) //Math
{
	intersection intersections;

	float raypointx = rays.ax;
	float raypointy = rays.ay;
	float raydeltax = rays.bx - rays.ax;
	float raydeltay = rays.by - rays.ay;

	float segmentpointx = segments[x].ax; //All required to calculate the point that the ray intersects objects in the scene
	float segmentpointy = segments[x].ay;
	float segmentdeltax = segments[x].bx - segments[x].ax;
	float segmentdeltay = segments[x].by - segments[x].ay;

	float r_mag = sqrt(raydeltax * raydeltax + raydeltay * raydeltay);
	float s_mag = sqrt(segmentdeltax * segmentdeltax + segmentdeltay * segmentdeltay);

	if ((raydeltax / r_mag == segmentdeltax / s_mag) && (raydeltay / r_mag == segmentdeltay / s_mag))
	{
		return
		{
			{ intersections.x = NULL }, { intersections.y = NULL }
		};
	}

	float T2 = (raydeltax * (segmentpointy - raypointy) + raydeltay * (raypointx - segmentpointx)) / (segmentdeltax * raydeltay - segmentdeltay * raydeltax);
	float T1 = (segmentpointx + segmentdeltax * T2 - raypointx) / raydeltax;

	if ((T1 < 0))
	{
		return
		{
			{ intersections.x = NULL }, { intersections.y = NULL } //returns NULL on failure
		};
	}
	else if ((T2 < 0 || T2>1))
	{
		return
		{
			{ intersections.x = NULL }, { intersections.y = NULL }
		};
	}
	else return // return the point at which the ray intersects with an object
	{
		{ intersections.x = (raypointx + (raydeltax * T1)) },
		{ intersections.y = (raypointy + (raydeltay * T1)) }
	};



}



void Rays::updateRays(ray ray, segmentFinal segments[], float CharX, float CharY)
{


	intersection closestIntersection;//Object holding the closest intersection
	float distanceToIntersection = 9999999;
	closestIntersection.x = NULL;

	for (int x = 0; x < NUMsegments; x++)
	{
		intersection Intersection = GetIntersection(ray, segments, x);
		//Check to see which intersection is the closest
		if (distanceToIntersection > (sqrt((Intersection.x - ray.ax) * (Intersection.x - ray.ax)
			+ (Intersection.y - ray.ay) * (Intersection.y - ray.ay))) && Intersection.x != NULL)
		{
			distanceToIntersection = (sqrt((Intersection.x - ray.ax) * (Intersection.x - ray.ax)
				+ (Intersection.y - ray.ay) * (Intersection.y - ray.ay)));

			closestIntersection = Intersection;
			
		}

	}
	
	if (distanceToIntersection < (sqrt((ray.bx - CharX) * (ray.bx - CharX)
		+ (ray.by - CharY) * (ray.by - CharY))))//assign values to rayFinal
	{

		rayFinal = {

		{rayFinal.ax = CharX },
		{rayFinal.ay = CharY },
		{rayFinal.bx = closestIntersection.x },
		{rayFinal.by = closestIntersection.y }

		};
	}
	else
	{
		rayFinal = {

		{rayFinal.ax = CharX },
		{rayFinal.ay = CharY },
		{rayFinal.bx = ray.bx },
		{rayFinal.by = ray.by }

		};
	}
	
}





