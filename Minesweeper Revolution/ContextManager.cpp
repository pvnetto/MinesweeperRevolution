#include "ContextManager.h"
#include <iostream>

ContextManager::ContextManager(sf::RenderWindow & window) {
	this->window = &window;
}

void ContextManager::switchContext(BaseContext* newContext) {
	if (this->currentContext) {
		delete currentContext;
		currentContext = nullptr;
	}

	this->currentContext = newContext;
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
			else if (evt.type == sf::Event::TextEntered) {
				std::cout << (char)evt.text.unicode << std::endl;
			}

			currentContext->handleEvents(*window, evt);
		}

		// Clears screen buffer
		window->clear(sf::Color(10, 30, 90));
		currentContext->draw(*window);
		window->display();
	}
}
