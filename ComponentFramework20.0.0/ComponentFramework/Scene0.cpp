#include <glew.h>
#include <iostream>
#include <SDL.h>
#include "Debug.h"
#include "Scene0.h"
#include "Camera.h"
#include "DemoObject.h"
#include "ObjLoader.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "MMath.h"
#include "Vector.h"
#include "Debug.h"
#include "Physics.h"

Scene0::Scene0(): camera(nullptr), demoObject(nullptr),meshPtr(nullptr),shaderPtr(nullptr),texturePtr(nullptr),Sphere1(nullptr), plane(nullptr), input(nullptr){
	Debug::Info("Created Scene0: ", __FILE__, __LINE__);
	
}

Scene0::~Scene0() {
	Input::Release();
	input = NULL;

}

void Scene0::Move(Vec3 vec)
{
	move += vec;
}

bool Scene0::OnCreate() {
	camera = new Camera();
	lightSource = Vec3(0.0, 0.0, 10.0);
	notCollided = true;
	input = Input::Instance();
	if (ObjLoader::loadOBJ("meshes/Sphere.obj") == false) {
		return false;
	}

	meshPtr = new Mesh(GL_TRIANGLES, ObjLoader::vertices, ObjLoader::normals, ObjLoader::uvCoords);
	shaderPtr = new Shader("phongVert.glsl", "phongFrag.glsl");
	texturePtr = new Texture();
	if (meshPtr == nullptr|| shaderPtr == nullptr || texturePtr == nullptr) {
		Debug::FatalError("Couldn't create game object assets", __FILE__, __LINE__);
		return false;
	}

	/*if (texturePtr->LoadImage("textures/mario_main.png") == false) {
		Debug::FatalError("Couldn't load texture", __FILE__, __LINE__);
		return false;
	}*/

	demoObject = new DemoObject(meshPtr, shaderPtr, nullptr);
	if (demoObject == nullptr) {
		Debug::FatalError("GameObject could not be created", __FILE__, __LINE__);
		return false;
	}



	meshPtr = new Mesh(GL_TRIANGLES, ObjLoader::vertices, ObjLoader::normals, ObjLoader::uvCoords);
	shaderPtr = new Shader("phongVert.glsl", "phongFrag.glsl");
	texturePtr = new Texture();
	Sphere1 = new DemoObject(meshPtr, shaderPtr, nullptr);

	if (Sphere1 == nullptr) {
		Debug::FatalError("GameObject could not be created", __FILE__, __LINE__);
		return false;
	}

	//plane = new Plane(Vec3(10.0f, 0.0f, -5.0f), Vec3(-10.0f, 0.0f, 10.0f), Vec3(3.0f, 0.0f, 8.0f));
	Vec3 normal;
	normal = Vec3(0.0f, 1.0f, 0.0);
	normal = VMath::normalize(normal);
	plane = new Plane(normal, 1.0f);
	
	demoObject->setPos(Vec3(-5.0, 5.0, 0.0));
	//demoObject->setVel(Vec3(0.0, 0.0, 0.0));
	//demoObject->setModelMatrix(MMath::translate(demoObject->getPos()));
	demoObject->setRadius(Sphere(1.0f));
	demoObject->setMass(10.0f);

	Sphere1->setPos(Vec3(5.0f,3.0f,0.0f));
	Sphere1->setVel(Vec3(-2.0f, -1.0f, 0.0f));
	//Sphere1->setModelMatrix(MMath::translate(Sphere1->getPos()));
	Sphere1->setRadius(Sphere(1.0f));
	Sphere1->setMass(5.0f);
	
	return true;
}

void Scene0::HandleEvents(const SDL_Event &sdlEvent) {
	//Input::HandleEvents(sdlEvent, move.x);
}

void Scene0::Update(const float deltaTime) {
	/***demoObject->Update(deltaTime); 
	static float rotation = 0.0f;
	rotation += 0.5f;
	demoObject->setModelMatrix(MMath::rotate(rotation, Vec3(0.0f, 1.0f, 0.0f)));
	***/
	//std::cout << VMath::di)->getRadius();
	//input->Update();


	/*if (input->keyDown(SDL_SCANCODE_W)) {
		Move(Vec3(0.0f, -1.0f, 0.0f));
	}*/

	//camera->Update(deltaTime);
	Physics::SimpleNewtonMotion(*demoObject, deltaTime);
	Physics::SimpleNewtonMotion(*Sphere1, deltaTime);



	if (Physics::SphereSphereCollision(*demoObject, *Sphere1)) {
		Physics::SphereSphereCollisionResponse(*demoObject, *Sphere1);
	}
	if (notCollided) {

	}
	if (Physics::PlaneSphereCollision(*Sphere1, *plane) && notCollided) {
		
		Physics::PlaneSphereCollisionResponse(*Sphere1, *plane);
		notCollided = false;
	}
	//Sphere1->setVel(Vec3(move));
	demoObject->setModelMatrix(MMath::translate(demoObject->getPos()));
	Sphere1->setModelMatrix(MMath::translate(Sphere1->getPos()));
}

void Scene0::Render() const {
	/// Clear the screen
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	/// Draw your scene here
	GLuint program = demoObject->getShader()->getProgram();
	GLuint program1 = Sphere1->getShader()->getProgram();
	glUseProgram(program);
	glUseProgram(program1);

	/// These pass the matricies and the light position to the GPU
	glUniformMatrix4fv(demoObject->getShader()->getUniformID("projectionMatrix"), 1, GL_FALSE, camera->getProjectionMatrix());
	glUniformMatrix4fv(demoObject->getShader()->getUniformID("viewMatrix"), 1, GL_FALSE, camera->getViewMatrix());
	glUniform3fv(demoObject->getShader()->getUniformID("lightPos"), 1, lightSource);

	glUniformMatrix4fv(Sphere1->getShader()->getUniformID("projectionMatrix"), 1, GL_FALSE, camera->getProjectionMatrix());
	glUniformMatrix4fv(Sphere1->getShader()->getUniformID("viewMatrix"), 1, GL_FALSE, camera->getViewMatrix());
	glUniform3fv(Sphere1->getShader()->getUniformID("lightPos"), 1, lightSource);

	demoObject->Render();
	Sphere1->Render();

	glUseProgram(0);
}


void Scene0::OnDestroy() {
	if (camera) delete camera, camera = nullptr;
	if (meshPtr) delete meshPtr, meshPtr = nullptr;
	if (texturePtr) delete texturePtr, texturePtr = nullptr;
	if (shaderPtr) delete shaderPtr, shaderPtr = nullptr;
	if (demoObject) delete demoObject, demoObject = nullptr;
	if (Sphere1) delete Sphere1, Sphere1 = nullptr;
	if (plane) delete plane, plane = nullptr;
}
