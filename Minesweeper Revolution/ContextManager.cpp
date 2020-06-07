#include "ContextManager.h"
#include <iostream>

ContextManager::ContextManager(sf::RenderWindow & window) {
	this->window = &window;
}

void ContextManager::run() {
	sf::Clock clock;

	while (window->isOpen()) {
		float deltaTime = clock.restart().asSeconds();
	
		sf::Event evt;
		while (window->pollEvent(evt)) {
			if (evt.type == sf::Event::Closed) {
				window->close();
			}

			currentContext->handleEvents(*window, evt);
		}

		// Clears screen buffer
		window->clear(sf::Color(10, 30, 90));
		currentContext->draw(*window);
		window->display();
	}
}
