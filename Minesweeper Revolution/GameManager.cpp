#include "GameManager.h"
#include "GameOverCanvas.h"

GameManager::GameManager() { }

GameManager::~GameManager() { }

void GameManager::startGame(int rowCount, int colCount, int numMines) {
	isGameOver = false;
}

void GameManager::endGame(BaseContext& ctx) {
	if (!isGameOver) {
		isGameOver = true;

		GameOverCanvas* gameOverCanvas = ctx.findEntity<GameOverCanvas>();
		if (gameOverCanvas) {
			gameOverCanvas->setActive(true);
		}
	}
}

bool GameManager::getGameOver() {
	return this->isGameOver;
}
