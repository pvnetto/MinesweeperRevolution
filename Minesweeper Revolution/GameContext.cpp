#include "GameContext.h"
#include "GameManager.h"
#include "GameOverCanvas.h"
#include "ContextManager.h"

#include "MainMenuContext.h"

#define BOARD_HEIGHT 900.0

GameContext::GameContext(ContextManager& ctxManager, sf::RenderWindow & window) : BaseContext(ctxManager) {
	float windowWidth = float(window.getSize().x);
	float windowHeight = float(window.getSize().y);

	const float UI_HEIGHT = windowHeight - BOARD_HEIGHT;
	const float UI_HEIGHT_RATIO = UI_HEIGHT / windowHeight;
	const float BOARD_OFFSET_TOP = UI_HEIGHT_RATIO;
	const float BOARD_HEIGHT_RATIO = BOARD_HEIGHT / windowHeight;

	// Views
	sf::FloatRect boardRect(0, UI_HEIGHT, windowWidth, BOARD_HEIGHT);
	sf::View* boardView = new sf::View(boardRect);
	boardView->setViewport(sf::FloatRect(0, BOARD_OFFSET_TOP, 1, BOARD_HEIGHT_RATIO));

	sf::FloatRect uiRect(0, 0, windowWidth, UI_HEIGHT);
	sf::View uiView(uiRect);
	uiView.setViewport(sf::FloatRect(0, 0, 1, UI_HEIGHT_RATIO));

	board = new Board(window, *boardView);
	board->generateBoard(16, 30, 99);
	entities.push_back(board);
	entities.push_back(new GameManager());

	gameOverCanvas = new GameOverCanvas(window);
	gameOverCanvas->setActive(false);
	gameOverCanvas->toggleInput(false);
	entities.push_back(gameOverCanvas);

	Board* boardEntity = findEntity<Board>();
	if (boardEntity) {
		boardEntity->print();
	}
}

GameContext::~GameContext() {
	for (auto it = entities.begin(); it != entities.end(); it++) {
		delete *(it);
	}
}

void GameContext::handleEvents(const sf::RenderWindow & window, const sf::Event & evt) {
	if (board) {
		board->handleEvents(*this, window, evt);
	}
	if (gameOverCanvas) {
		gameOverCanvas->handleEvents(*this, window, evt);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
		getContextManager()->switchContext<MainMenuContext>();
	}
}
