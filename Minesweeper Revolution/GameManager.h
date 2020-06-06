#pragma once

class GameManager {
private:
	bool gameOver;
	float currentGameTime;

public:
	GameManager();
	~GameManager();

	void startGame(int rowCount, int colCount, int numMines);
	void endGame();

	bool isGameOver();
};