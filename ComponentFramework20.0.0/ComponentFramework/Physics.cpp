#include "Physics.h"
#include <iostream>



void Physics::SimpleNewtonMotion(PhysicsObject &object, const float deltaTime) {
	object.pos += object.vel * deltaTime + 0.5f * object.accel * deltaTime * deltaTime;
	object.vel += object.accel * deltaTime;
}

bool Physics::PlaneSphereCollision(const PhysicsObject &object, const Plane &p) {
	float dist = 0.0f;
	dist = PMath::distance(object.pos, p);
	if (dist <= object.boundingSphere.r) {
		return true;
	}
	else if(dist > object.boundingSphere.r) {
		return false;
	}
	
}

void Physics::PlaneSphereCollisionResponse(PhysicsObject &object, const Plane &p) {
	std::cout <<"bounced"<< std::endl;
	
	object.vel = PMath::reflect(object.vel, p);
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

