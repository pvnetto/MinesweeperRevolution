#pragma once
#include "BaseContext.h"
#include "Board.h"

class GameContext : public BaseContext {
private:
	Board* board = nullptr;
public:
	GameContext(const sf::RenderWindow& window);
	virtual ~GameContext();

	virtual void handleEvents(const sf::RenderWindow& window, const sf::Event& evt) override;
};