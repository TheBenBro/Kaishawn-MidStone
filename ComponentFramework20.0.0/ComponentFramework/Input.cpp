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
}

void Input::HandleEvents(const SDL_Event& sdlEvent, float x_)
{
	x_ = x;
	if (sdlEvent.type == SDLK_RIGHT) {
		x++;
	}
	else if (sdlEvent.type == SDLK_LEFT) {
		x--;
	}
}
