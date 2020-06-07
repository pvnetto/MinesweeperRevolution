#include "Button.h"

Button::Button() { }

Button::Button(std::string text, sf::Vector2f pos, sf::Vector2f size, ButtonAction* clickAction) {
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


	font.loadFromFile("Assets/pixel.ttf");
	btnText = sf::Text(text, font, 24);
	btnText.setFillColor(sf::Color::White);
	btnText.setStyle(sf::Text::Bold);
	btnText.setPosition(pos);

	this->clickAction = clickAction;
}

Button::~Button() {
	if (btnTexture) {
		delete btnTexture;
	}
	delete clickAction;
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

sf::Shape* Button::getShape() {
	return &btnShape;
}

void Button::handleAction(Action action, BaseContext & ctx) {
	switch (action) {
		case Action::LEFT_CLICK:
			if (this->clickAction) {
				this->clickAction->action(ctx);
			}
			break;
		case Action::MOUSE_ENTER:
			break;
	}
}

void Button::setFillColor(sf::Color newColor) {
	btnShape.setFillColor(newColor);
}

void Button::setTexture(std::string texturePath) {
	btnTexture = new sf::Texture();

	if (btnTexture->loadFromFile(texturePath)) {
		btnShape.setTexture(btnTexture);
	}
}
