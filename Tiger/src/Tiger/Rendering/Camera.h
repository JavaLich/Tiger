#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Tiger {

	class PerspectiveCamera {
	public:
		PerspectiveCamera(float FOV = 45.0f, float ar = 1280.0f/720.0f, float n = 0.1f, float f = 100.0f) : fov(FOV), aspectRatio(ar), nearClip(n), farClip(f) {
			lookAt(position, target, up); 
			calcProj();
		}
		~PerspectiveCamera();

		void setPos(glm::vec3 pos);
		void setTarget(glm::vec3 target);
		void setUp(glm::vec3 up);

		void setFOV(float FOV);
		void setAspectRatio(float ar);
		void setNear(float n);
		void setFar(float f);
		void setClipSpace(float n, float f);

		inline glm::mat4 getViewProj() { return proj*view; }
		inline glm::mat4 getView() { return view; }
		inline glm::mat4 getProj() { return proj; }
	private:
		void calcProj();
		void lookAt(glm::vec3 pos, glm::vec3 target, glm::vec3 up = { 0.0f, 1.0f, 0.0f });

		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 proj = glm::mat4(1.0f);

		float fov;
		float aspectRatio;
		float nearClip;
		float farClip;

		glm::vec3 position = { 0.0f, 0.0f, -1.0f };
		glm::vec3 target = { 0.0f, 0.0f, 0.0f };
		glm::vec3 up = { 0.0f, 1.0f, 0.0f };
	};

}