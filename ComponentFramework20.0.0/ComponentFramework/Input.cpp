#include "Input.h"
#include <SDL.h>

Input::Input()
{
	keyDown = false;
	x = 0.0f;
}

Input::~Input()
{
}

void Input::moveRight(float x)
{
	x += 1;
}

void Input::HandleEvents(const SDL_Event& sdlEvent, float x_)
{
	if (sdlEvent.type == SDLK_RIGHT) {
		moveRight(x_);
	}
}
