#include "GameContext.h"

#define BOARD_HEIGHT 900.0

GameContext::GameContext(const sf::RenderWindow & window) {
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

	gameManager = new GameManager();
	entities.push_back(gameManager);

	Board* boardEntity = findEntity<Board*>();
	boardEntity->print();
}

GameContext::~GameContext() {
	for (auto it = entities.begin(); it != entities.end(); it++) {
		delete *(it);
	}
}

void GameContext::handleEvents(const sf::RenderWindow & window, const sf::Event & evt) {
	board->handleEvents(*this, window, evt);
}

void GameContext::draw(sf::RenderWindow & window) {
	for (auto it = entities.begin(); it != entities.end(); it++) {
		(*it)->draw(window);
	}
}
