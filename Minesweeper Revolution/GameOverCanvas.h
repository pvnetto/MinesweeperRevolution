#pragma once
#include "Entity.h"
#include "Button.h"

class GameOverCanvas : public Entity {
private:
	sf::Font font;

	sf::RectangleShape background;
	sf::Text gameOverText;
	Button restartBtn;
	Button quitBtn;
public:
	GameOverCanvas(const sf::RenderWindow & window);

	virtual void draw(sf::RenderWindow& window) override;

};