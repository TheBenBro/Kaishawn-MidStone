#include "Physics.h"
#include <iostream>


void Physics::SimpleNewtonMotion(PhysicsObject &object, const float deltaTime) {
	object.pos += object.vel * deltaTime + 0.5f * object.accel * deltaTime * deltaTime;
	object.vel += object.accel * deltaTime;
}

bool Physics::PlaneSphereCollision(const PhysicsObject &object, const Plane &p) {
	Vec3 center = object.pos + object.boundingSphere;
	Vec3 sphere1 = object.pos;
	Plane plane = p;
	float dist = (VMath::distance(sphere1, plane));
	if (dist < object.boundingSphere.r) {
		return true;
	}

	return false;
}

void Physics::PlaneSphereCollisionResponse(PhysicsObject &object, const Plane &p) {
	Vec3 plane = Vec3(p.x, p.y, p.z);
	Vec3 normalPlane = VMath::normalize(plane);
	Vec3 projection = Vec3(0.0f, 0.0f, 0.0f);
	projection = (-1.0f * VMath::dot(object.vel, normalPlane) * normalPlane);

	object.vel = object.vel + 2.0f * projection;

}

bool Physics::SphereSphereCollision(const PhysicsObject &object1, const PhysicsObject &object2) {
	Vec3 Sphere1 = object1.pos;
	Vec3 Sphere2 = object2.pos;
	float dist = VMath::distance(Sphere1, Sphere2);
	if (dist < (object1.boundingSphere.r + object2.boundingSphere.r)) {
		return true;
	}
	return false;
}

void Physics::SphereSphereCollisionResponse(PhysicsObject &object1, PhysicsObject &object2) {
	float bounce = 1.0f;
	Vec3 lineOfAction = object1.pos - object2.pos;
	Vec3 normalizedLOA = VMath::normalize(lineOfAction);

	float v1p = VMath::dot(object1.vel, normalizedLOA);
	float v2p = VMath::dot(object2.vel, normalizedLOA);

	float vel1 = ((object1.mass - bounce * object2.mass) * v1p + (1.0f + bounce) * object2.mass * v2p) / (object1.mass + object2.mass);
	float vel2 = ((object2.mass - bounce * object1.mass) * v2p + (1.0f + bounce) * object1.mass * v1p) / (object1.mass + object2.mass);

	object1.vel += (vel1 - v1p) * normalizedLOA;
	object2.vel += (vel2 - v2p) * normalizedLOA;
}

