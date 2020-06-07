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

	/* Inherited from Entity. */
	virtual void draw(sf::RenderWindow& window) override { };

	/// <summary>
	/// Toggles game over screen and player board when the game is finished.
	/// </summary>
	void gameOver(BaseContext& ctx, bool victory);
	/// <summary>
	/// Restarts the game.
	/// </summary>
	void restart(BaseContext& ctx);

	void resetCellCount(int count);
	void decrementCellCount(BaseContext& ctx);

	void resetMineCount(BaseContext& ctx, int count);
	void changeMineCount(BaseContext& ctx, int diff);
};