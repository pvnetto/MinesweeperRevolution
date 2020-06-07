#include "GameOverCanvas.h"

GameOverCanvas::GameOverCanvas(const sf::RenderWindow & window) {
	background.setSize(sf::Vector2f(window.getSize()));
	background.setPosition(0.0f, 0.0f);
	background.setFillColor(sf::Color(0, 0, 0, 120));

	sf::Vector2f screenCenter = sf::Vector2f(window.getSize()) / 2.0f;

	sf::Vector2f btnSize(300.0f, 80.0f);
	sf::Vector2f restartPos = screenCenter + sf::Vector2f(0, 50.0f);
	sf::Vector2f quitPos = screenCenter + sf::Vector2f(0, 150.0f);
	restartBtn = Button("Restart", restartPos, btnSize);
	quitBtn = Button("Quit", quitPos, btnSize);

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
}

void GameOverCanvas::draw(sf::RenderWindow & window) {
	window.setView(window.getDefaultView());
	window.draw(background);
	window.draw(gameOverText);

	restartBtn.draw(window);
	quitBtn.draw(window);
}
