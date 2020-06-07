#pragma once
#include "Entity.h"
#include "BaseContext.h"

class GameManager : public Entity {
private:
	bool isGameOver = false;
	float currentGameTime;

public:
	GameManager();
	~GameManager();

	virtual void draw(sf::RenderWindow& window) override { };

	void startGame(int rowCount, int colCount, int numMines);
	void endGame(BaseContext& ctx);

	bool getGameOver();
};