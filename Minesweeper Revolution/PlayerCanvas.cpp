#include "PlayerCanvas.h"
#include "Button.h"

PlayerCanvas::PlayerCanvas(sf::RenderWindow & window, sf::View & view) {
	this->view = &view;


	sf::Vector2f viewCenter = sf::Vector2f(view.getSize() / 2.0f);
	sf::Vector2f btnSize = sf::Vector2f(50.0f, 50.0f);

	// Initializes reset button
	Button* resetBtn = new Button("", viewCenter, btnSize, new Button::RestartAction());
	resetBtn->setFillColor(sf::Color::White);
	resetBtn->setTexture("Assets/Cell_Mine_Red.png");
	entities.push_back(resetBtn);

	// Initializes remaining mine text
	sf::Vector2f minesTextPos = viewCenter - sf::Vector2f(200.0f, 0);
	font.loadFromFile("Assets/pixel.ttf");
	minesText = new sf::Text("-", font, 32);
	minesText->setOrigin(
		minesText->getLocalBounds().left + minesText->getLocalBounds().width / 2.0f,
		minesText->getLocalBounds().top + minesText->getLocalBounds().height / 2.0f
	);
	minesText->setFillColor(sf::Color::White);
	minesText->setStyle(sf::Text::Bold);
	minesText->setPosition(minesTextPos);
	drawables.push_back(minesText);

	// Initializes remaining mine icon
	sf::Vector2f iconPos = minesTextPos - sf::Vector2f(60.0f, 0.0f);
	sf::Texture* iconTexture = new sf::Texture();
	iconTexture->loadFromFile("Assets/Cell_Mine_X.png");

	sf::RectangleShape* minesIcon = new sf::RectangleShape(btnSize);
	minesIcon->setOrigin(btnSize / 2.0f);
	minesIcon->setTexture(iconTexture);
	minesIcon->setPosition(iconPos);
	drawables.push_back(minesIcon);
}

PlayerCanvas::~PlayerCanvas() {
	deleteCanvas();
	minesText = nullptr;
}

void PlayerCanvas::updateMineCountText(int count) {
	if (minesText) {
		minesText->setString(std::to_string(count));
	}
}
