#pragma once
#include "SFML/Graphics.hpp"

class Entity {
public:
	virtual void handleEvents(const sf::RenderWindow& window, const sf::Event& evt) = 0;
};