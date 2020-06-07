#pragma once
#include "BaseContext.h"
#include "GameManager.h"
#include "Board.h"

class GameContext : public BaseContext {
public:
	GameManager* gameManager = nullptr;
	Board* board = nullptr;

public:
	GameContext(const sf::RenderWindow& window);
	virtual ~GameContext();

	virtual void handleEvents(const sf::RenderWindow& window, const sf::Event& evt) override;
	virtual void draw(sf::RenderWindow& window) override;
};