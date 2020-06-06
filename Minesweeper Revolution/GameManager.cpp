#include "GameManager.h"
#include <iostream>

GameManager::GameManager() { }

GameManager::~GameManager() { }

void GameManager::startGame(int rowCount, int colCount, int numMines) {
}

void GameManager::endGame() {
	this->gameOver = true;
	std::cout << "Game Over" << std::endl;
}

bool GameManager::isGameOver() {
	return this->gameOver;
}
