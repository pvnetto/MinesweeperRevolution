#include "ContextManager.h"
#include "MainMenuContext.h"
#include <SFML/Graphics.hpp>
#include <iostream>

#define WINDOW_WIDTH 1600.0
#define WINDOW_HEIGHT 960.0

int main() {
	auto windowStyles = sf::Style::Close | sf::Style::Titlebar;
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Minesweeper Revolution", windowStyles);

	ContextManager ctxManager(window);
	ctxManager.switchContext<MainMenuContext>();
	ctxManager.run();
	return 0;
}