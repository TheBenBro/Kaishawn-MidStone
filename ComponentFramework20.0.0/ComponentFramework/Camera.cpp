#include "Camera.h"
#include "MMath.h"

#include <iostream>



bool Camera::OnCreate()
{
	
	
	return true;
}

void Camera::OnDestroy()
{
}

void Camera::Update(const float deltaTime)
{
	
}

void Camera::HandleEvents(const SDL_Event& event)
{

}

Camera::Camera() {
	move = Vec3(0.0f, 0.0f, -10.0f);
	setProjectionMatrix(MMath::perspective(45.0f, (16.0f / 9.0f), 0.5f, 100.0f));
	//setViewMatrix(MMath::lookAt(Vec3(0.0, 0.0, 10.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 1.0f, 0.0f)));
	translate = MMath::translate(Vec3(0.0f, -5.0f, -20.0f));
	view = translate;


}

Camera::~Camera() {
	
}

void Camera::Render() const
{
}



