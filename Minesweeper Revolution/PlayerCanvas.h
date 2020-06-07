#pragma once
#include "CanvasEntity.h"

/// <summary>
/// CanvasEntity that handles all in-game HUD.
/// </summary>
class PlayerCanvas : public CanvasEntity {
private:
	sf::Text* mineCountText = nullptr;
	sf::Font font;

public:
	PlayerCanvas(sf::RenderWindow& window, sf::View& view);
	virtual ~PlayerCanvas();

	void updateMineCountText(int count);
};