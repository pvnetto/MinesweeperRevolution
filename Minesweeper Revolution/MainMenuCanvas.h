#pragma once
#include "CanvasEntity.h"
#include "Button.h"

class BaseContext;

/// <summary>
/// CanvasEntity that handles all main menu HUD initialization, drawing and events.
/// </summary>
class MainMenuCanvas : public CanvasEntity {
private:
	sf::Font font;

public:
	MainMenuCanvas(sf::RenderWindow & window);
	virtual ~MainMenuCanvas();

};