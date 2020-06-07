#pragma once
#include "CanvasEntity.h"
#include "Button.h"

class BaseContext;

class GameOverCanvas : public CanvasEntity {
private:
	sf::RectangleShape background;
	sf::Font font;
	sf::Text gameOverText;
	Button* restartBtn;
	Button* quitBtn;

	std::vector<InteractableEntity*> entities;
public:
	GameOverCanvas(sf::RenderWindow & window);
	~GameOverCanvas();

	virtual void handleEvents(BaseContext& ctx, const sf::RenderWindow& window, const sf::Event& evt) override;
	virtual void draw(sf::RenderWindow& window) override;

};