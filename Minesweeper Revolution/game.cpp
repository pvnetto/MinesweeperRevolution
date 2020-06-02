#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
	// Config parameters
	const int WINDOW_WIDTH = 1280;
	const int WINDOW_HEIGHT = 960;
	
	// Close, minimize, maximize buttons are all configurable through SFML::Style 
	auto windowStyles = sf::Style::Close | sf::Style::Titlebar;

	// Game Parameters
	bool isGameOver = false;

	// VideoMode: Especifica as configurações de dimensão da tela
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!", windowStyles);
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);


	while (window.isOpen() && !isGameOver) {
		sf::Event evt;
		while (window.pollEvent(evt)) {
			if (evt.type == sf::Event::Closed) {
				window.close();
			}
			else if (evt.type == sf::Event::Resized) {
				std::cout << "Width: " << evt.size.width << std::endl;
				std::cout << "Height: " << evt.size.height << std::endl;
			}
			else if (evt.type == sf::Event::TextEntered) {
				std::cout << (char)evt.text.unicode << std::endl;
			}
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}