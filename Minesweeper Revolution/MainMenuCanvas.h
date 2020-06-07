#pragma once
#include "CanvasEntity.h"
#include "Button.h"

class BaseContext;

class MainMenuCanvas : public CanvasEntity {
private:
	sf::Font font;

public:
	MainMenuCanvas(sf::RenderWindow & window);
	~MainMenuCanvas();

};