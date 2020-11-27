#ifndef INPUT_H
#define INPUT_H
union SDL_Event;

class Input
{
private:
	bool keyDown;
	float x;

public:
	Input();
	~Input();
	static void moveRight(float x);
	static void HandleEvents(const SDL_Event& sdlEvent, float x_);
};
#endif

