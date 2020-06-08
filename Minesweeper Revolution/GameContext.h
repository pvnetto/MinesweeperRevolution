#pragma once
#include "BaseContext.h"
#include "Board.h"
#include "GameOverCanvas.h"
#include "PlayerCanvas.h"

/// <summary>
///	BaseContext subclass that handles initialization, drawing and events of all in-game entities
/// </summary>
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

/// <summary>
///	GameContext subclass for easy difficulty
/// </summary>
class EasyGameContext : public GameContext {
public:
	EasyGameContext(ContextManager& ctxManager, sf::RenderWindow & window) : GameContext(ctxManager, window, 9, 9, 10) { }
};

/// <summary>
///	GameContext subclass for medium difficulty
/// </summary>
class MediumGameContext : public GameContext {
public:
	MediumGameContext(ContextManager& ctxManager, sf::RenderWindow & window) : GameContext(ctxManager, window, 16, 16, 40) {}
};

/// <summary>
///	GameContext subclass for hard difficulty
/// </summary>
class HardGameContext : public GameContext {
public:
	HardGameContext(ContextManager& ctxManager, sf::RenderWindow & window) : GameContext(ctxManager, window, 16, 30, 99) {}
};