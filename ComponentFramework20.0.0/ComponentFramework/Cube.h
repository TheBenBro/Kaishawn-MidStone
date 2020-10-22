#ifndef CUBE_H
#define CUBE_H

#include "Plane.h"

namespace  MATH{
	struct Cube {
		float rx, ry, rz;
		Plane box[6];


		Cube(float width, float height, float depth);
		Cube();
	};
}
	

#endif 

