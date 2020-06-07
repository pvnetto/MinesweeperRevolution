#pragma once
#include "Entity.h"
#include "BaseContext.h"

class GameManager : public Entity {
private:
	bool isGameOver = false;
	float currentGameTime = 0.0;

public:
	GameManager();
	~GameManager();

	virtual void draw(sf::RenderWindow& window) override { };

	void start(int rowCount, int colCount, int numMines);
	void gameOver(BaseContext& ctx);
	void restart(BaseContext& ctx);

	bool getGameOver();
};