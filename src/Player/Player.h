#pragma once

#include "State.h"
#include "Camera.h"
#include "GLWindow.h"
#include "Variables.h"
#include "Program.h"
#include "Mesh.h"
#include "FileLocations.h"
#include "Object.h"
#include "Entity.h"

#include <iostream>
#include <memory>

class Player {
	public:
		Player(GLWindow& window, glm::vec3 cameraPosition, glm::mat4 projection);

		void keyboardUpdate(Movement movement, GLfloat deltaTime);

		void update();
		void render(const glm::mat4 viewMatrix, const glm::mat4& projection);

		Camera& getCamera() { return camera; }


	private:
		Movement movement;
		GLWindow& window;

		Camera camera;
		GLfloat lastX = window.getWindow().getSize().x / 2.f;
		GLfloat lastY = window.getWindow().getSize().y / 2.f;
		bool firstMouse = true;
};