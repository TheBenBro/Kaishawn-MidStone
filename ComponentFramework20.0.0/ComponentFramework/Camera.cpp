#include "Camera.h"
#include "MMath.h"

Camera::Camera() {
	setProjectionMatrix(MMath::perspective(45.0f, (16.0f / 9.0f), 0.5f, 100.0f));
	setViewMatrix(MMath::lookAt(Vec3(0.0, 0.0, 10.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 1.0f, 0.0f)));
}

Camera::~Camera() {}

