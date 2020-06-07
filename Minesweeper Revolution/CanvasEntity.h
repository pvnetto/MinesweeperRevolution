#pragma once
#include "BaseContext.h"

class CanvasEntity : public Entity {
protected:
	bool inputEnabled = true;

public:
	virtual void handleEvents(BaseContext& ctx, const sf::RenderWindow& window, const sf::Event& evt) = 0;
	void toggleInput(bool val);
};