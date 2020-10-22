#include "Cube.h"

MATH::Cube::Cube(float width, float height, float depth)
{
	rx = width;
	ry = height;
	rz = depth;
	box[0] = Plane(1, 0, 0, 0);//x=0
	box[1] = Plane(0, 1, 0, 0);//y=0
	box[2] = Plane(0, 0, 1, 0);//z=o
	box[3] = Plane(1, 0, 0, -rx);
	box[4] = Plane(0, 1, 0, -ry);
	box[5] = Plane(0, 0, 1, -rz);
}

MATH::Cube::Cube()
{
	rx = 1.0f;
	ry = 1.0f;
	rz = 1.0f;
}
