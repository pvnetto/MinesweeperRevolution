#pragma once
#include "CanvasEntity.h"
#include "Button.h"

class GameOverCanvas : public CanvasEntity {
private:
	sf::Font font;

public:
	GameOverCanvas(sf::RenderWindow & window);
	~GameOverCanvas();

};