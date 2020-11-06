#include "Other_Plane.h"

Other_Plane Other_Plane::Normalized() const
{
	float mag = VMath::mag(normal);
	return Other_Plane(normal/mag, distance/mag);
}
