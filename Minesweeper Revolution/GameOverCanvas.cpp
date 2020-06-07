#include "GameOverCanvas.h"

GameOverCanvas::GameOverCanvas(sf::RenderWindow & window) {
	background.setSize(sf::Vector2f(window.getSize()));
	background.setPosition(0.0f, 0.0f);
	background.setFillColor(sf::Color(0, 0, 0, 120));

	sf::Vector2f screenCenter = sf::Vector2f(window.getSize()) / 2.0f;

	sf::Vector2f btnSize(300.0f, 80.0f);
	sf::Vector2f restartPos = screenCenter + sf::Vector2f(0, 50.0f);
	sf::Vector2f quitPos = screenCenter + sf::Vector2f(0, 150.0f);

	restartBtn = new Button("Restart", restartPos, btnSize, new Button::RestartAction());
	quitBtn = new Button("Quit", quitPos, btnSize, new Button::QuitAction(window));

	sf::Vector2f gameOverTextPos = screenCenter - sf::Vector2f(0, 200.0f);
	font.loadFromFile("OpenSans-Regular.ttf");
	gameOverText = sf::Text("Game Over", font, 64);
	gameOverText.setOrigin(
		gameOverText.getLocalBounds().left + gameOverText.getLocalBounds().width / 2.0f,
		gameOverText.getLocalBounds().top + gameOverText.getLocalBounds().height / 2.0f
	);
	gameOverText.setFillColor(sf::Color::White);
	gameOverText.setStyle(sf::Text::Bold);
	gameOverText.setPosition(gameOverTextPos);

	entities.push_back(restartBtn);
	entities.push_back(quitBtn);
}

GameOverCanvas::~GameOverCanvas() {
	for (auto it = entities.begin(); it != entities.end(); it++) {
		delete *it;
	}
}


void GameOverCanvas::handleEvents(BaseContext& ctx, const sf::RenderWindow& window, const sf::Event& evt) {
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

void GameOverCanvas::draw(sf::RenderWindow & window) {
	window.setView(window.getDefaultView());
	window.draw(background);
	window.draw(gameOverText);

	restartBtn->draw(window);
	quitBtn->draw(window);
}
