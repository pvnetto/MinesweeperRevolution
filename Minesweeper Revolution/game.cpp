#include "Animation.h"
#include "Cell.h";
#include <SFML/Graphics.hpp>
#include <iostream>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 960

int snippet();

/* A memory leak occurs when a pointer goes out of scope without being deleted, making it impossible
to deallocate the memory, so it's only deallocated when the program is ended. */
void memoryLeak() {
	// Will leak memory if variable isn't deleted until end of scope
	int* ptr { new int {} };

	// Also a memory leak, because memory isn't deallocated before the pointer is reassigned
	int myVar = 5;
	int* otherPtr{ new int {} };
	otherPtr = &myVar;
}

int main() {
	// Close, minimize, maximize buttons are all configurable through SFML::Style 
	auto windowStyles = sf::Style::Close | sf::Style::Titlebar;

	// Views
	sf::FloatRect viewRect(100.0f, 100.0f, 512.0f, 512.0f);
	sf::View view(viewRect);
	view.setViewport(sf::FloatRect(0.0f, 0.0f, 512.0f / WINDOW_WIDTH, 512.0f / WINDOW_HEIGHT));

	// Game Parameters
	bool isGameOver = false;

	// VideoMode: Especifica as configurações de dimensão da tela
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Minesweeper Revolution", windowStyles);

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
	Cell cell(pos, size);

	// Animation

	// Spritesheet
	const int SPRITESHEET_COLS = 3;
	const int SPRITESHEET_ROWS = 3;
	sf::Texture spritesheet;
	spritesheet.loadFromFile("");

	// sprite_size = (spritesheet_width / rows, spritesheet_height / cols)
	sf::Vector2u textureSize = spritesheet.getSize();
	textureSize.x /= SPRITESHEET_COLS;
	textureSize.y /= SPRITESHEET_ROWS;

	Animation animation(&spritesheet, sf::Vector2u(3, 9), 2.0);

	// Text
	sf::Font mainFont;
	if (!mainFont.loadFromFile("OpenSans-Regular.ttf")) {
		std::cout << "Error while loading font!" << std::endl;
	}
	sf::Text minesweeperTitle;
	minesweeperTitle.setFont(mainFont);
	minesweeperTitle.setString("Minesweeper Revolution");
	minesweeperTitle.setCharacterSize(64);
	minesweeperTitle.setFillColor(sf::Color::Cyan);
	minesweeperTitle.setStyle(sf::Text::Bold);
	minesweeperTitle.setPosition(sf::Vector2f(200.0f, 200.0f));


	// Adds clocking functionality
	float deltaTime = 0.0f;
	sf::Clock clock;

	snippet();

	while (window.isOpen() && !isGameOver) {
		deltaTime = clock.restart().asSeconds();

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
			cell.setColor(sf::Color(std::rand() * 255.f, std::rand() * 255.f, std::rand() * 255.f));
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			//// Gets mouse position relative to the window
			//sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			//sf::Vector2f mousePosF = sf::Vector2f(mousePos.x, mousePos.y);

			//sf::Vector2f mousePosWorld = window.mapPixelToCoords(mousePos);
			////cell.setPosition(mousePos.x, mousePos.y);
			//if (cell.getGlobalBounds().contains(mousePosWorld)) {
			//	std::cout << "Clicked cell" << std::endl;
			//}
		}

		animation.Update(0, deltaTime);
		//cell.setTextureRect(animation.uvRect);

		// Clears screen buffer
		window.clear(sf::Color(120, 23, 40));
		//window.setView(view);

		// Draws all shapes
		window.draw(shape);
		window.draw(cell.draw());
		window.draw(minesweeperTitle);

		// Displays everything that was rendered so far
		window.display();
	}

	return 0;
}