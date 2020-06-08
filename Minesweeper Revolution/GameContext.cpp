#include "GameContext.h"
#include "GameManager.h"
#include "GameOverCanvas.h"

#define BOARD_HEIGHT 860.0

GameContext::GameContext(ContextManager& ctxManager, sf::RenderWindow & window, int rows, int cols, int mines)
	: BaseContext(ctxManager) {
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

	board = new Board(window, *boardView);
	board->generateGrid(rows, cols, mines);
	entities.push_back(board);

	sf::FloatRect uiRect(0, 0, windowWidth, UI_HEIGHT);
	sf::View* uiView = new sf::View(uiRect);
	uiView->setViewport(sf::FloatRect(0, 0, 1, UI_HEIGHT_RATIO));
	playerCanvas = new PlayerCanvas(window, *uiView);
	entities.push_back(playerCanvas);

	gameOverCanvas = new GameOverCanvas(window);
	gameOverCanvas->setActive(false);
	gameOverCanvas->toggleInput(false);
	entities.push_back(gameOverCanvas);

	entities.push_back(new GameManager());
}

GameContext::~GameContext() {
	for (auto it = entities.begin(); it != entities.end(); it++) {
		delete *(it);
	}

	board = nullptr;
	gameOverCanvas = nullptr;
	playerCanvas = nullptr;
}

void GameContext::handleEvents(const sf::RenderWindow & window, const sf::Event & evt) {	
	if (board) {
		board->handleEvents(*this, window, evt);
	}
	if (gameOverCanvas) {
		gameOverCanvas->handleEvents(*this, window, evt);
	}
	if (playerCanvas) {
		playerCanvas->handleEvents(*this, window, evt);
	}
}
