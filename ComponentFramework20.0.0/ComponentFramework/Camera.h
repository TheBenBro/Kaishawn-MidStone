#ifndef CAMERA_H
#define CAMERA_H
#include "Vector.h"
#include "Matrix.h"
#include "GameObject.h"


using namespace MATH;
class Camera : public GameObject{
	class Input* input;
private:

	Matrix4 projection;
	Matrix4 view;
	Matrix4 rotate;
	Matrix4 translate;
	Vec3 move;
public:

	bool OnCreate() override;
	void OnDestroy() override;
	void Update(const float deltaTime) override;
	void HandleEvents(const SDL_Event& event)override;
	inline Matrix4 getProjectionMatrix() const { return projection; }
	inline Matrix4 getViewMatrix() const { return view; }
	inline void setProjectionMatrix(Matrix4 projection_){ projection = projection_; }
	inline void setViewMatrix(Matrix4 view_) { view = view_;  }
	
	Camera();
	~Camera();	
	void Render() const override;
};

#endif



