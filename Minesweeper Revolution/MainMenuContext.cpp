#include "MainMenuContext.h"
#include "ContextManager.h"
#include "GameContext.h"

MainMenuContext::MainMenuContext(ContextManager& ctxManager, sf::RenderWindow & window) : BaseContext(ctxManager) {
	//gameOverCanvas = new GameOverCanvas(window);
	//gameOverCanvas->setActive(false);
	//gameOverCanvas->toggleInput(false);
	//entities.push_back(gameOverCanvas);

	//Board* boardEntity = findEntity<Board>();
	//if (boardEntity) {
	//	boardEntity->print();
	//}
}

MainMenuContext::~MainMenuContext() {

}

void MainMenuContext::handleEvents(const sf::RenderWindow& window, const sf::Event& evt){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		getContextManager()->switchContext<GameContext>();
	}
}
