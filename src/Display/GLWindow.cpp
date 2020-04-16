#include "GLWindow.h"


GLWindow::~GLWindow() {
	window.close();
}

void GLWindow::initWindow() {
	std::string title;
	sf::VideoMode windowBounds;
	sf::ContextSettings contextSettings;
	unsigned int framerateLimit = 120;

	std::string pathToFile = std::experimental::filesystem::current_path().parent_path().string();
	std::cout << pathToFile << '\n';
	pathToFile += WINDOW_INI_CONFIG;
	std::cout << pathToFile << '\n';

	std::ifstream inFile(pathToFile);
	if (inFile.is_open()) {
		std::getline(inFile, title);
		inFile >> windowBounds.width;
		inFile >> windowBounds.height;
		inFile >> framerateLimit;
		inFile >> contextSettings.majorVersion >> contextSettings.minorVersion;
		inFile >> contextSettings.depthBits;
	}
	inFile.close();

	// SFML
	window.create(windowBounds, title, sf::Style::Default, contextSettings);
std::cout << "TEST\n";

	window.setPosition({window.getPosition().x, window.getPosition().y - 50});
	window.setFramerateLimit(framerateLimit);
	window.setActive();

	if (!gladLoadGL()) { throw std::runtime_error("Glad not loaded!\n");  }

	glEnable(GL_DEPTH_TEST);
	
	// Viewport
	setViewPort(glm::vec2(0), glm::vec2(getWindow().getSize().x, getWindow().getSize().y));
}

void GLWindow::swapBuffers() {
	window.display();
}

void GLWindow::setMouseVisible(bool visible) {
	window.setMouseCursorVisible(visible);
	mouseVisible = visible;
}

void GLWindow::setViewPort(glm::vec2 origin, glm::vec2 newWidthNewHeight) {
	glViewport(origin.x, origin.y, newWidthNewHeight.x, newWidthNewHeight.y); // Lower left corner should be (0, 0);
}
