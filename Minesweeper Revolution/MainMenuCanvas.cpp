#include "MainMenuCanvas.h"
#include "GameContext.h"

MainMenuCanvas::MainMenuCanvas(sf::RenderWindow & window) {
	sf::RectangleShape* background = new sf::RectangleShape();
	background->setSize(sf::Vector2f(window.getSize()));
	background->setPosition(0.0f, 0.0f);
	background->setFillColor(sf::Color(0, 0, 0, 120));

	sf::Vector2f screenCenter = sf::Vector2f(window.getSize()) / 2.0f;

	sf::Vector2f btnSize(300.0f, 80.0f);
	sf::Vector2f easyBtnPos = screenCenter + sf::Vector2f(0, 50.0f);
	sf::Vector2f mediumBtnPos = screenCenter + sf::Vector2f(0, 150.0f);
	sf::Vector2f hardBtnPos = screenCenter + sf::Vector2f(0, 250.0f);
	sf::Vector2f quitBtnPos = screenCenter + sf::Vector2f(0, 350.0f);

	Button* easyBtn = new Button("Easy", easyBtnPos, btnSize, new Button::ContextAction<EasyGameContext>());
	Button* mediumBtn = new Button("Medium", mediumBtnPos, btnSize, new Button::ContextAction<MediumGameContext>());
	Button* hardBtn = new Button("Hard", hardBtnPos, btnSize, new Button::ContextAction<HardGameContext>());
	Button* quitBtn = new Button("Quit", quitBtnPos, btnSize, new Button::QuitAction(window));

	sf::Vector2f gameOverTextPos = screenCenter - sf::Vector2f(0, 200.0f);
	font.loadFromFile("Assets/pixel.ttf");
	sf::Text* gameTitleText = new sf::Text("Minesweeper Revolution", font, 64);
	gameTitleText->setOrigin(
		gameTitleText->getLocalBounds().left + gameTitleText->getLocalBounds().width / 2.0f,
		gameTitleText->getLocalBounds().top + gameTitleText->getLocalBounds().height / 2.0f
	);
	gameTitleText->setFillColor(sf::Color::White);
	gameTitleText->setStyle(sf::Text::Bold);
	gameTitleText->setPosition(gameOverTextPos);

	entities.push_back(easyBtn);
	entities.push_back(mediumBtn);
	entities.push_back(hardBtn);
	entities.push_back(quitBtn);

	drawables.push_back(background);
	drawables.push_back(gameTitleText);
}

MainMenuCanvas::~MainMenuCanvas() {  }
