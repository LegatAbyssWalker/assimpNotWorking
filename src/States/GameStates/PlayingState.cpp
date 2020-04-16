#include "PlayingState.h"

PlayingState::PlayingState(StateMachine &machine, GLWindow &window, bool replace)
	: State(machine, window, replace), window(window) {

	// Player
	player = std::make_unique<Player>(window, glm::vec3(0), window.getPerspectiveMatrix());

	// InvaderManager
	invaderManager = std::make_unique<InvaderManager>(window);

	// Window
	this->window.setMouseVisible(false);
}

void PlayingState::keyboardInput(sf::Keyboard::Key &key, bool isPressed) {
	if (key == sf::Keyboard::Escape) { machine.quit(); }
}

void PlayingState::updateEvents() {
	while (window.getWindow().pollEvent(sfEvent)) {
		auto keyCode = sfEvent.key.code;
		switch (sfEvent.type) {
			case sf::Event::Resized:
				this->window.setViewPort(glm::vec2(0), glm::vec2(sfEvent.size.width, sfEvent.size.height));
				break;

			case sf::Event::Closed:
				machine.quit();
				break;

			case sf::Event::KeyPressed:
				keyboardInput(keyCode, true);
				break;

			case sf::Event::KeyReleased:
				keyboardInput(keyCode, false);
				break;
		}

		// Keyboard
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { player->keyboardUpdate(Movement::FORWARD,  deltaTime); }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { player->keyboardUpdate(Movement::LEFT,     deltaTime); }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { player->keyboardUpdate(Movement::BACKWARD, deltaTime); }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { player->keyboardUpdate(Movement::RIGHT,    deltaTime); }
	}

}

void PlayingState::update() {
	GLfloat now = clock.getElapsedTime().asSeconds();
	deltaTime = now - lastFrame;
	lastFrame = now;

	// Player
	player->update();

	// InvaderManager
	invaderManager->update();

}

void PlayingState::render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.5f, 1.f, 1.f, 1.f);


	invaderManager->render(player->getCamera().calculateViewMatrix(), window.getPerspectiveMatrix());


	window.swapBuffers();
}
