#pragma once
#include "Entity.h"
#include "Button.h"

class BaseContext;

class GameOverCanvas : public Entity {
private:
	sf::RectangleShape background;
	sf::Font font;
	sf::Text gameOverText;
	Button* restartBtn;
	Button* quitBtn;

	std::vector<InteractableEntity*> entities;
public:
	GameOverCanvas(const sf::RenderWindow & window);
	~GameOverCanvas();

	void handleEvents(BaseContext& ctx, const sf::RenderWindow& window, const sf::Event& evt);
	virtual void draw(sf::RenderWindow& window) override;

};