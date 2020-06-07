#pragma once
#include "SFML/Graphics.hpp"

class Entity {
private:
	bool active = true;
public:
	virtual void draw(sf::RenderWindow& window) = 0;

	inline bool isActive() { return active; }
	inline void setActive(bool val) { active = val; }
};