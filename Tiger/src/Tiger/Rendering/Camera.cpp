#include "Camera.h"

void Tiger::PerspectiveCamera::lookAt(glm::vec3 pos, glm::vec3 target, glm::vec3 up)
{
	this->position = pos;
	this->target = target;
	this->up = up;
	view = glm::lookAt(pos, target, up);
}

void Tiger::PerspectiveCamera::calcProj()
{
	proj = glm::perspective(fov, aspectRatio, nearClip, farClip);
}

Tiger::PerspectiveCamera::~PerspectiveCamera()
{
}

void Tiger::PerspectiveCamera::setPos(glm::vec3 pos)
{
	lookAt(pos, target, up);
}

void Tiger::PerspectiveCamera::setTarget(glm::vec3 target)
{
	lookAt(position, target, up);
}

void Tiger::PerspectiveCamera::setUp(glm::vec3 up)
{
	lookAt(position, target, up);
}

void Tiger::PerspectiveCamera::setFOV(float FOV)
{
	fov = FOV;
	calcProj();
}

void Tiger::PerspectiveCamera::setAspectRatio(float ar)
{
	aspectRatio = ar;
	calcProj();
}

void Tiger::PerspectiveCamera::setNear(float n)
{
	nearClip = n;
	calcProj();
}

void Tiger::PerspectiveCamera::setFar(float f)
{
	farClip = f;
	calcProj();
}

void Tiger::PerspectiveCamera::setClipSpace(float n, float f)
{
	nearClip = n;
	farClip = f;
	calcProj();
}

