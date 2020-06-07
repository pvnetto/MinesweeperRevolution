#pragma once
#include "Entity.h"
#include "BaseContext.h"

/// <summary>
/// Entity that handles win/lose conditions and updates player canvas.
/// </summary>
class GameManager : public Entity {
private:
	int remainingCells;
	int mineCount;
	bool isGameOver = false;
	float currentGameTime = 0.0;

public:
	GameManager();
	~GameManager();

	virtual void draw(sf::RenderWindow& window) override { };

	void resetCellCount(int count);
	void decrementCellCount(BaseContext& ctx);

	void resetMineCount(BaseContext& ctx, int count);
	void changeMineCount(BaseContext& ctx, int diff);

	void gameOver(BaseContext& ctx, bool victory);
	void restart(BaseContext& ctx);
};