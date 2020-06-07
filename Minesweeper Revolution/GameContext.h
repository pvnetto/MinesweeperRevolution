#pragma once
#include "BaseContext.h"
#include "Board.h"
#include "GameOverCanvas.h"
#include "PlayerCanvas.h"

class GameContext : public BaseContext {
protected:
	Board* board = nullptr;
	GameOverCanvas* gameOverCanvas = nullptr;
	PlayerCanvas* playerCanvas = nullptr;

public:
	GameContext(ContextManager& ctxManager, sf::RenderWindow & window, int rows, int cols, int mines);
	virtual ~GameContext();

	virtual void handleEvents(const sf::RenderWindow& window, const sf::Event& evt) override;
};

class EasyGameContext : public GameContext {
public:
	EasyGameContext(ContextManager& ctxManager, sf::RenderWindow & window) : GameContext(ctxManager, window, 9, 9, 10) { }
};

class MediumGameContext : public GameContext {
public:
	MediumGameContext(ContextManager& ctxManager, sf::RenderWindow & window) : GameContext(ctxManager, window, 16, 16, 40) {}
};

class HardGameContext : public GameContext {
public:
	HardGameContext(ContextManager& ctxManager, sf::RenderWindow & window) : GameContext(ctxManager, window, 16, 30, 99) {}
};