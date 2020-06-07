#include "PlayerCanvas.h"
#include "Button.h"

PlayerCanvas::PlayerCanvas(sf::RenderWindow & window, sf::View & view) {
	this->view = &view;


	sf::Vector2f viewCenter = sf::Vector2f(view.getSize() / 2.0f);

	Button* resetBtn = new Button("", viewCenter, sf::Vector2f(50.0f, 50.0f), new Button::RestartAction());
	resetBtn->setFillColor(sf::Color::White);
	resetBtn->setTexture("Assets/Cell_Mine_Red.png");
	entities.push_back(resetBtn);
}

PlayerCanvas::~PlayerCanvas() {
	deleteCanvas();
}
