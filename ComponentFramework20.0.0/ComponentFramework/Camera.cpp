#include "Camera.h"
#include "MMath.h"
#include "Input.h"
#include <iostream>



bool Camera::OnCreate()
{
	
	input = new Input();
	return true;
}

void Camera::OnDestroy()
{
}

void Camera::Update(const float deltaTime)
{
	std::cout << move.x << std::endl;
}

void Camera::HandleEvents(const SDL_Event& event)
{
	if (input) {
		input->HandleEvents(event, move.x);
		
	}
}

Camera::Camera() {
	move = Vec3(0.0f, 0.0f, -10.0f);
	setProjectionMatrix(MMath::perspective(45.0f, (16.0f / 9.0f), 0.5f, 100.0f));
	//setViewMatrix(MMath::lookAt(Vec3(0.0, 0.0, 10.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 1.0f, 0.0f)));
	translate = MMath::translate(move);
	view = translate;


}

Camera::~Camera() {
	delete input;
}

void Camera::Render() const
{
}



