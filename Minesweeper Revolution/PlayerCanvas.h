#pragma once
#include "CanvasEntity.h"

class PlayerCanvas : public CanvasEntity {
private:
	sf::Font font;

public:
	PlayerCanvas(sf::RenderWindow& window, sf::View& view);
	~PlayerCanvas();
};