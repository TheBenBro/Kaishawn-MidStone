#ifndef SCENE0_H
#define SCENE0_H
#include "Scene.h"
#include "Vector.h"
#include "Plane.h"
#include "Input.h"
using namespace MATH;

/// Forward declarations 
union SDL_Event;
class Camera;
class DemoObject;
class Mesh;
class Shader;
class Texture;
class Scene0 : public Scene {
private:
	SDL_Event event;
	Camera *camera;
	DemoObject *demoObject;
	Input* input;
	DemoObject* Sphere1;
	Plane* plane;
	Vec3 lightSource;
	Mesh *meshPtr;
	Shader *shaderPtr;
	Texture *texturePtr;
	Vec3 move = Vec3(0.0f, 0.0f, 0.0f);
	bool notCollided;
public:
	explicit Scene0();
	virtual ~Scene0();
	void Move(Vec3 vec);
	virtual bool OnCreate() override;
	virtual void OnDestroy() override;
	virtual void Update(const float deltaTime) override;
	virtual void Render() const override;
	virtual void HandleEvents(const SDL_Event &sdlEvent) override;
};


#endif // SCENE0_H