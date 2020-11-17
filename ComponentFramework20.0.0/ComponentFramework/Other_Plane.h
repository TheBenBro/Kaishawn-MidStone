#pragma once
#include <math.h>
#include"Vector.h"
#include "VMath.h"
using namespace MATH;
class Other_Plane
{
private:
	const Vec3 normal;
	const float distance;
public:
	Other_Plane(const Vec3& normal, float distance):
		normal(normal),
		distance(distance){}

	Other_Plane Normalized() const;
	inline const Vec3& GetNormal() const { return normal; }
	inline float GetDistance() const { return distance; }
};

