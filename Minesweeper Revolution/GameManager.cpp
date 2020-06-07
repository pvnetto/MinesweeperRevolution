#include "GameManager.h"
#include "GameOverCanvas.h"
#include "Board.h"

GameManager::GameManager() { }

GameManager::~GameManager() { }

void GameManager::start(int rowCount, int colCount, int numMines) {
}

void GameManager::gameOver(BaseContext& ctx) {
	if (!isGameOver) {
		isGameOver = true;

		GameOverCanvas* gameOverCanvas = ctx.findEntity<GameOverCanvas>();
		gameOverCanvas->setActive(true);
		gameOverCanvas->toggleInput(true);

		Board* board = ctx.findEntity<Board>();
		board->toggleInput(false);
	}
}

void GameManager::restart(BaseContext & ctx) {
	isGameOver = false;
	currentGameTime = 0.0;

	Board* board = ctx.findEntity<Board>();
	board->reset();

	GameOverCanvas* gameOverCanvas = ctx.findEntity<GameOverCanvas>();
	gameOverCanvas->setActive(false);
	gameOverCanvas->toggleInput(false);
}
