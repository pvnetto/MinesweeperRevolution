#pragma once
#include "BaseContext.h"
#include "Board.h"
#include "GameOverCanvas.h"

class GameContext : public BaseContext {
private:
	Board* board = nullptr;
	GameOverCanvas* gameOverCanvas = nullptr;

public:
	GameContext(const sf::RenderWindow& window);
	virtual ~GameContext();

	virtual void handleEvents(const sf::RenderWindow& window, const sf::Event& evt) override;
};