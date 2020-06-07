#include "ContextManager.h"
#include <iostream>

ContextManager::ContextManager(sf::RenderWindow & window) {
	this->window = &window;
}

void ContextManager::run() {
	sf::Clock clock;

	while (window->isOpen()) {
		if (currentContext) {
			float deltaTime = clock.restart().asSeconds();

			sf::Event evt;
			while (window->pollEvent(evt)) {
				if (evt.type == sf::Event::Closed) {
					window->close();
				}

				currentContext->handleEvents(*window, evt);
			}

			// Clears screen buffer
			window->clear(sf::Color(10, 10, 40));
			currentContext->draw(*window);
			window->display();
		}

		handleContextSwitch();
	}
}

void ContextManager::handleContextSwitch() {
	if (nextContext != currentContext) {
		if (this->currentContext) {
			delete currentContext;
			currentContext = nullptr;
		}

		this->currentContext = nextContext;
	}
}
