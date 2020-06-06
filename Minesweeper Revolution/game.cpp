#include "Board.h";
#include <SFML/Graphics.hpp>
#include <iostream>

#define BOARD_HEIGHT 900.0
#define WINDOW_WIDTH 1600.0
#define WINDOW_HEIGHT 960.0

void draw(sf::RenderWindow& window, const sf::Drawable& drawable) {
	window.draw(drawable);
}

int main() {
	const float UI_HEIGHT = WINDOW_HEIGHT - BOARD_HEIGHT;
	const float UI_HEIGHT_RATIO = UI_HEIGHT / WINDOW_HEIGHT;
	const float BOARD_OFFSET_TOP = UI_HEIGHT_RATIO;
	const float BOARD_HEIGHT_RATIO = BOARD_HEIGHT / WINDOW_HEIGHT;

	// Close, minimize, maximize buttons are all configurable through SFML::Style 
	auto windowStyles = sf::Style::Close | sf::Style::Titlebar;

	// Views
	sf::FloatRect boardRect(0, UI_HEIGHT, WINDOW_WIDTH, BOARD_HEIGHT);
	sf::View boardView(boardRect);
	boardView.setViewport(sf::FloatRect(0, BOARD_OFFSET_TOP, 1, BOARD_HEIGHT_RATIO));

	sf::FloatRect uiRect(0, 0, WINDOW_WIDTH, UI_HEIGHT);
	sf::View uiView(uiRect);
	uiView.setViewport(sf::FloatRect(0, 0, 1, UI_HEIGHT_RATIO));

	// VideoMode: Especifica as configurações de dimensão da tela
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Minesweeper Revolution", windowStyles);

	// Text
	sf::Font mainFont;
	if (!mainFont.loadFromFile("OpenSans-Regular.ttf")) {
		std::cout << "Error while loading font!" << std::endl;
	}
	sf::Text minesweeperTitle;
	minesweeperTitle.setFont(mainFont);
	minesweeperTitle.setString("Minesweeper Revolution");
	minesweeperTitle.setCharacterSize(32);
	minesweeperTitle.setFillColor(sf::Color::Cyan);
	minesweeperTitle.setStyle(sf::Text::Bold);
	minesweeperTitle.setPosition(sf::Vector2f(0.0f, 0.0f));


	// Adds clocking functionality
	float deltaTime = 0.0f;
	sf::Clock clock;

	// Board
	Board board(window, boardView);
	board.generateBoard(16, 30, 99);
	

	while (window.isOpen()) {
		deltaTime = clock.restart().asSeconds();

		sf::Event evt;
		while (window.pollEvent(evt)) {
			if (evt.type == sf::Event::Closed) {
				window.close();
			}
			else if (evt.type == sf::Event::TextEntered) {
				std::cout << (char)evt.text.unicode << std::endl;
			}
		
			//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
			//	cell.setColor(sf::Color(std::rand() * 255.f, std::rand() * 255.f, std::rand() * 255.f));
			//}

			// Gets mouse position relative to the window
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			sf::Vector2f mousePosF = sf::Vector2f(mousePos.x, mousePos.y);
			sf::Vector2f mousePosWorld = window.mapPixelToCoords(mousePos);

			//cell.setPosition(mousePos.x, mousePos.y);
			//if (cell.getShape().getGlobalBounds().contains(mousePosWorld)) {
			//	if (evt.mouseButton.button == sf::Mouse::Left && evt.type == sf::Event::MouseButtonReleased) {
			//		cell.handleAction(Action::LEFT_CLICK);
			//	}
			//	else {
			//		cell.handleAction(Action::MOUSE_ENTER);
			//	}
			//}
			//else {
			//	cell.handleAction(Action::MOUSE_LEAVE);
			//}
		}

		// Clears screen buffer
		window.clear(sf::Color(120, 120, 120));

		// Draw board view
		window.setView(boardView);
		board.draw(window);

		// Draw UI view
		window.setView(uiView);
		draw(window, minesweeperTitle);

		// Displays everything that was rendered so far
		window.display();
	}

	return 0;
}