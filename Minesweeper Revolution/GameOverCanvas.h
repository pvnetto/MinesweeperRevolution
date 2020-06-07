#pragma once
#include "CanvasEntity.h"
#include "Button.h"

/// <summary>
/// CanvasEntity that handles all game over HUD initialization, drawing and events.
/// </summary>
class GameOverCanvas : public CanvasEntity {
private:
	sf::Text* gameOverText;
	sf::Font font;

public:
	GameOverCanvas(sf::RenderWindow & window);
	virtual ~GameOverCanvas();

	void switchTitle(bool victory);
};