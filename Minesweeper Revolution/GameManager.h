#pragma once
#include "Entity.h"

class GameManager : public Entity {
private:
	bool gameOver;
	float currentGameTime;

public:
	GameManager();
	~GameManager();

	virtual void draw(sf::RenderWindow& window) override {};

	void startGame(int rowCount, int colCount, int numMines);
	void endGame();

	bool isGameOver();
};