#ifndef INPUT_H
#define INPUT_H
#include <SDL.h>
union SDL_Event;

class Input
{
private:
	static Input* sInstance;

	const Uint8* keyboardState;
	Input();
	~Input();
public:

	static Input* Instance();
	static void Release();

	bool keyDown(SDL_Scancode scanCode);
	void Update();


};
#endif

