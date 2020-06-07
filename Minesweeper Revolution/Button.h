#pragma once
#include "Entity.h"

class Button : public Entity {
public:
	sf::Font font;
	sf::RectangleShape btnShape;
	sf::RectangleShape btnBorder;
	sf::Text btnText;

public:
	Button();
	Button(std::string text, sf::Vector2f pos, sf::Vector2f size);

	virtual void draw(sf::RenderWindow & window) override;
};