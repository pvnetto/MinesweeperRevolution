#pragma once
#include "CanvasEntity.h"
#include "Button.h"

class GameOverCanvas : public CanvasEntity {
private:
	sf::Text* gameOverText;
	sf::Font font;

public:
	GameOverCanvas(sf::RenderWindow & window);
	~GameOverCanvas();

	void switchTitle(bool victory);
};