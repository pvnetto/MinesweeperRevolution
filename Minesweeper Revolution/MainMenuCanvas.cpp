#include "MainMenuCanvas.h"
#include "GameContext.h"

MainMenuCanvas::MainMenuCanvas(sf::RenderWindow & window) {
	background.setSize(sf::Vector2f(window.getSize()));
	background.setPosition(0.0f, 0.0f);
	background.setFillColor(sf::Color(0, 0, 0, 120));

	sf::Vector2f screenCenter = sf::Vector2f(window.getSize()) / 2.0f;

	sf::Vector2f btnSize(300.0f, 80.0f);
	sf::Vector2f easyBtnPos = screenCenter + sf::Vector2f(0, 50.0f);
	sf::Vector2f mediumBtnPos = screenCenter + sf::Vector2f(0, 150.0f);
	sf::Vector2f hardBtnPos = screenCenter + sf::Vector2f(0, 250.0f);
	sf::Vector2f quitBtnPos = screenCenter + sf::Vector2f(0, 350.0f);

	easyBtn = new Button("Easy", easyBtnPos, btnSize, new Button::PlayAction<EasyGameContext>());
	mediumBtn = new Button("Medium", mediumBtnPos, btnSize, new Button::PlayAction<MediumGameContext>());
	hardBtn = new Button("Hard", hardBtnPos, btnSize, new Button::PlayAction<HardGameContext>());
	quitBtn = new Button("Quit", quitBtnPos, btnSize, new Button::QuitAction(window));

	sf::Vector2f gameOverTextPos = screenCenter - sf::Vector2f(0, 200.0f);
	font.loadFromFile("OpenSans-Regular.ttf");
	gameTitleText = sf::Text("Minesweeper Revolution", font, 64);
	gameTitleText.setOrigin(
		gameTitleText.getLocalBounds().left + gameTitleText.getLocalBounds().width / 2.0f,
		gameTitleText.getLocalBounds().top + gameTitleText.getLocalBounds().height / 2.0f
	);
	gameTitleText.setFillColor(sf::Color::White);
	gameTitleText.setStyle(sf::Text::Bold);
	gameTitleText.setPosition(gameOverTextPos);

	entities.push_back(easyBtn);
	entities.push_back(mediumBtn);
	entities.push_back(hardBtn);
	entities.push_back(quitBtn);
}

MainMenuCanvas::~MainMenuCanvas() {
	for (auto it = entities.begin(); it != entities.end(); it++) {
		delete *it;
	}
}


void MainMenuCanvas::handleEvents(BaseContext& ctx, const sf::RenderWindow& window, const sf::Event& evt) {
	if (active && inputEnabled) {
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		sf::Vector2f mousePosF = sf::Vector2f(mousePos.x, mousePos.y);
		sf::Vector2f mousePosWorld = window.mapPixelToCoords(mousePos);

		for (auto it = entities.begin(); it != entities.end(); it++) {
			auto entity = *it;
			if (entity->getShape()->getGlobalBounds().contains(mousePosWorld)) {
				if (evt.type == sf::Event::MouseButtonReleased) {
					if (evt.mouseButton.button == sf::Mouse::Left) {
						entity->handleAction(Action::LEFT_CLICK, ctx);
					}
					else if (evt.mouseButton.button == sf::Mouse::Right) {
						entity->handleAction(Action::ALT_CLICK, ctx);
					}
				}
				else {
					entity->handleAction(Action::MOUSE_ENTER, ctx);
				}
			}
			else {
				entity->handleAction(Action::MOUSE_LEAVE, ctx);
			}
		}
	}
}

void MainMenuCanvas::draw(sf::RenderWindow & window) {
	window.setView(window.getDefaultView());
	window.draw(background);
	window.draw(gameTitleText);

	easyBtn->draw(window);
	mediumBtn->draw(window);
	hardBtn->draw(window);
	quitBtn->draw(window);
}
