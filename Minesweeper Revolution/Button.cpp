#include "Button.h"

Button::Button() { }

Button::Button(std::string text, sf::Vector2f pos, sf::Vector2f size) {
	btnShape.setSize(size);
	btnShape.setPosition(pos);
	btnShape.setOrigin(size / 2.0f);
	btnShape.setFillColor(sf::Color(120, 120, 120));

	float borderWidth = 10.0f;
	sf::Vector2f borderSize = size + sf::Vector2f(borderWidth, borderWidth);
	btnBorder.setSize(borderSize);
	btnBorder.setPosition(pos);
	btnBorder.setOrigin(borderSize / 2.0f);
	btnBorder.setFillColor(sf::Color::Black);


	font.loadFromFile("OpenSans-Regular.ttf");
	btnText = sf::Text(text, font, 24);
	btnText.setFillColor(sf::Color::White);
	btnText.setStyle(sf::Text::Bold);
	btnText.setPosition(pos);
}

void Button::draw(sf::RenderWindow & window) {
	btnText.setFont(font);
	btnText.setOrigin(
		btnText.getLocalBounds().left + btnText.getLocalBounds().width / 2.0f,
		btnText.getLocalBounds().top + btnText.getLocalBounds().height / 2.0f
	);

	window.draw(btnBorder);
	window.draw(btnShape);
	window.draw(btnText);
}
