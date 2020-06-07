#include "ContextManager.h"
#include "GameContext.h"
#include <SFML/Graphics.hpp>
#include <iostream>

#define WINDOW_WIDTH 1600.0
#define WINDOW_HEIGHT 960.0

int main() {
	auto windowStyles = sf::Style::Close | sf::Style::Titlebar;
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Minesweeper Revolution", windowStyles);

	ContextManager ctxManager(window);
	GameContext* gameContext = new GameContext(window);
	ctxManager.switchContext(gameContext);
	ctxManager.run();


	// Views
	//sf::FloatRect boardRect(0, UI_HEIGHT, WINDOW_WIDTH, BOARD_HEIGHT);
	//sf::View boardView(boardRect);
	//boardView.setViewport(sf::FloatRect(0, BOARD_OFFSET_TOP, 1, BOARD_HEIGHT_RATIO));

	//sf::FloatRect uiRect(0, 0, WINDOW_WIDTH, UI_HEIGHT);
	//sf::View uiView(uiRect);
	//uiView.setViewport(sf::FloatRect(0, 0, 1, UI_HEIGHT_RATIO));


	// Text
	//sf::Font mainFont;
	//if (!mainFont.loadFromFile("OpenSans-Regular.ttf")) {
	//	std::cout << "Error while loading font!" << std::endl;
	//}
	//sf::Text minesweeperTitle;
	//minesweeperTitle.setFont(mainFont);
	//minesweeperTitle.setString("Minesweeper Revolution");
	//minesweeperTitle.setCharacterSize(32);
	//minesweeperTitle.setFillColor(sf::Color::Red);
	//minesweeperTitle.setStyle(sf::Text::Bold);
	//minesweeperTitle.setPosition(sf::Vector2f(0.0f, 0.0f));

	/*	Difficulties
		9 x 9		-	40
		16 x 16		-	10
		30 x 16		-	99
	*/

	return 0;
}