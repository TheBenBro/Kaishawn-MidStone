#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H
#include "Vector.h"
#include "Sphere.h"
#include "Cube.h"

using namespace MATH;

class PhysicsObject {
	friend class Physics;
public:
	PhysicsObject();
	virtual ~PhysicsObject();
	

public:
	/// Untility functions so small they cane be inlined
	inline void setPos(const Vec3 &pos_) { pos = pos_; }
	inline Vec3 getPos() { return pos; }

	inline void setVel(const Vec3 &vel_) { vel = vel_; }
	inline Vec3 getVel() { return vel; }

	inline void setAccel(const Vec3 &accel_) { accel = accel_; }
	inline Vec3 getAccel() { return accel; }
	inline void applyForce(const Vec3 force) { accel = force / mass;  }

	inline void setRadius(const Sphere boundingSphere_) { boundingSphere = boundingSphere_; }
	inline Sphere getRadius() { return boundingSphere; }

	inline void setDistance(const Plane distance_) { distance = distance_;}

	inline void setMass(const float mass_) { mass = mass_; }

	inline void setCube(const Cube width_, const Cube height_, const Cube depth_) { width = width_; height = height_; depth = depth_; }

protected:
	Vec3 pos, vel, accel;
	float mass;
	Sphere boundingSphere;
	Cube width, height, depth;
	Plane distance;
};
#endif

