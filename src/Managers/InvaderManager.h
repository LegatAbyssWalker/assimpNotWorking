#pragma once

#include "GLWindow.h"
#include "glm/glm.hpp"

#include <iostream>
#include <vector>
#include <memory>
#include <array>

#include "Invader.h"
#include "Player.h"
#include "Entity.h"
#include "Random.h"


class InvaderManager {
	public:
		InvaderManager(GLWindow& window);

		void update();
		void render(const glm::mat4 viewMatrix, const glm::mat4& projection);

		bool collisions(std::unique_ptr<Entity>& entity);
		void handleCollisions();

		void removeEntities();

	private:
		GLWindow& window;
		Random<> random;

		std::vector<std::unique_ptr<Invader>> invaderVector;

		bool towardsPositiveX = false;
		bool towardsNegativeY = false;
		int downTick = 0;
		int downTickMax = 100;
};


