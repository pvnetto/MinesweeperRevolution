#pragma once
#include "Entity.h"
#include "BaseContext.h"

/// <summary>
/// Entity reponsible for handling win and lose conditions.
/// </summary>
class GameManager : public Entity {
private:
	int remainingCells;
	bool isGameOver = false;
	float currentGameTime = 0.0;

public:
	GameManager();
	~GameManager();

	virtual void draw(sf::RenderWindow& window) override { };

	void resetCellCount(int count);
	void decrementCellCount(BaseContext& ctx);

	void gameOver(BaseContext& ctx, bool victory);
	void restart(BaseContext& ctx);
};