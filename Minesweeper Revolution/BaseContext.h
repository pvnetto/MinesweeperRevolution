#pragma once
#include "Entity.h"

class BaseContext {
protected:
	std::vector<Entity*> entities;
	//virtual void handleEvents() = 0;

public:
	virtual void handleEvents(const sf::RenderWindow& window, const sf::Event& evt) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;

};