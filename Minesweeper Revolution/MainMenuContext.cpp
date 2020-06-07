#include "MainMenuContext.h"

MainMenuContext::MainMenuContext(ContextManager& ctxManager, sf::RenderWindow & window) : BaseContext(ctxManager) {
	mainMenuCanvas = new MainMenuCanvas(window);
	entities.push_back(mainMenuCanvas);
}

MainMenuContext::~MainMenuContext() {
	for (auto it = entities.begin(); it != entities.end(); it++) {
		delete *(it);
	}

	mainMenuCanvas = nullptr;
}

void MainMenuContext::handleEvents(const sf::RenderWindow& window, const sf::Event& evt){
	mainMenuCanvas->handleEvents(*this, window, evt);
}
