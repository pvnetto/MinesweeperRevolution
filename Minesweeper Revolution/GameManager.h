#pragma once
#include "Board.h"

class GameManager {
private:
	Board board;

	bool isGameOver;
	float currentGameTime;

public:
	void startGame(int rowCount, int colCount);
	void gameOver();

	bool isGameOver() {
		return isGameOver;
	}
};