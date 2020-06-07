#pragma once
#include "CanvasEntity.h"
#include "Button.h"

class BaseContext;

class MainMenuCanvas : public CanvasEntity {
private:
	sf::RectangleShape background;
	sf::Font font;
	sf::Text gameTitleText;
	Button* easyBtn;
	Button* mediumBtn;
	Button* hardBtn;

	std::vector<InteractableEntity*> entities;
public:
	MainMenuCanvas(sf::RenderWindow & window);
	~MainMenuCanvas();

	virtual void handleEvents(BaseContext& ctx, const sf::RenderWindow& window, const sf::Event& evt) override;
	virtual void draw(sf::RenderWindow& window) override;

};