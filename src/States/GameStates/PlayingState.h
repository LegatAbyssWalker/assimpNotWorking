#pragma once

#include "State.h"
#include "StateMachine.h"
class StateMachine;

#include <iostream>
#include <array>
#include <memory>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

#include "FileLocations.h"
#include "Variables.h"
#include "GLWindow.h"
#include "Random.h"

#include "Player.h"
#include "InvaderManager.h"

class PlayingState : public State {
	public:
		PlayingState(StateMachine& machine, GLWindow& window, bool replace = true);

		void keyboardInput(sf::Keyboard::Key& key, bool isPressed);

		void updateEvents();
		void update();
		void render();

	private:
		GLWindow& window;
		sf::Event sfEvent;
		sf::Clock clock;
		GLfloat deltaTime = 0, lastFrame = 0;


		std::unique_ptr<Player> player = nullptr;
		std::unique_ptr<InvaderManager> invaderManager = nullptr;
};

