#include "Input.h"
#include <SDL.h>
Input* Input::sInstance = NULL;
Input::Input()
{
	keyboardState = NULL;
}

Input::~Input()
{
}

Input* Input::Instance()
{
	if (sInstance == NULL)
		sInstance = new Input();

	return sInstance;
}

void Input::Release()
{
	delete sInstance;
	sInstance = NULL;
}

/*bool Input::keyDown(SDL_Scancode scanCode)
{
	return keyboardState[scanCode];
}*/

void Input::Update()
{
	keyboardState = SDL_GetKeyboardState(NULL);
}


