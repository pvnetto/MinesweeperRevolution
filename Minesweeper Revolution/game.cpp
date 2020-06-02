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

	// Circle
	float radius = 100.0;
	sf::CircleShape shape(radius);
	shape.setFillColor(sf::Color::Green);

	// Texture
	sf::Texture cellTex;
	cellTex.loadFromFile("Default.png");

	// Rectangle
	sf::Vector2f size(50.0, 50.0);
	sf::Vector2f pos(50.0, 50.0);
	sf::RectangleShape cell(size);
	cell.setPosition(pos);
	cell.setFillColor(sf::Color::Blue);
	cell.setOrigin(size.x / 2.0, size.y /2.0);
	cell.setTexture(&cellTex);



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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
			cell.setFillColor(sf::Color(std::rand() * 255.f, std::rand() * 255.f, std::rand() * 255.f));
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			// Gets mouse position relative to the window
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			sf::Vector2f mousePosF = sf::Vector2f(mousePos.x, mousePos.y);
			//cell.setPosition(mousePos.x, mousePos.y);
			if (cell.getGlobalBounds().contains(mousePosF)) {
				std::cout << "Clicked cell" << std::endl;
			}
		}

		// Clears screen buffer
		window.clear();

		// Draws all shapes
		window.draw(shape);
		window.draw(cell);

		// Displays everything that was rendered so far
		window.display();
	}

	return 0;
}