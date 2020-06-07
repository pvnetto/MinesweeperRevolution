#pragma once
#include "BaseContext.h"
#include "InteractableEntity.h"

class CanvasEntity : public Entity {
protected:
	bool inputEnabled = true;
	sf::View* view = nullptr;
	std::vector<InteractableEntity*> entities;
	std::vector<sf::Drawable*> drawables;

public:
	virtual void draw(sf::RenderWindow& window) override;
	virtual void handleEvents(BaseContext& ctx, const sf::RenderWindow& window, const sf::Event& evt);
	void toggleInput(bool val);
};