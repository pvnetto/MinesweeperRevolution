#include "Cell.h";
#include <SFML/Graphics.hpp>
#include <iostream>

#define BOARD_HEIGHT 900.0
#define WINDOW_WIDTH 1600.0
#define WINDOW_HEIGHT 960.0

int getSingleIndex(int row, int col, int numberOfColumnsInArray) {
	return (row * numberOfColumnsInArray) + col;
}

float lerp(const float& a, const float& b, const float& t) {
	return (1 - t)*a + t * b;
}

//sf::Vector2f lerp(sf::Vector2f& res, const sf::Vector2f& a, const sf::Vector2f& b, float t) {
//	res.x = (1 - t)*a.x + t * b.x;
//	res.y = (1 - t)*a.y + t * b.y;
//}

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

	// Cells
	int boardHeight = 16, boardWidth = 30;
	int cellCount = boardHeight * boardWidth;
	Cell** cells { new Cell*[cellCount] };

	float verticalOffset = 50.0f;

	float boardYStart = UI_HEIGHT + verticalOffset;
	float boardYEnd = WINDOW_HEIGHT - verticalOffset;
	float cellSize = (boardYEnd - boardYStart) / boardHeight;

	float horizontalSpaceNeeded = cellSize * boardWidth;
	float horizontalOffset = (WINDOW_WIDTH - horizontalSpaceNeeded) / 2.0f;

	sf::Vector2f topLeftCorner(horizontalOffset, boardYStart);
	sf::Vector2f bottomRightCorner(WINDOW_WIDTH - horizontalOffset, boardYEnd);

	sf::Vector2f size(cellSize, cellSize);

	// Row -> Height -> Y
	// Col -> Width  -> X
	for (int j = 0; j < boardWidth; j++) {
		for (int i = 0; i < boardHeight; i++) {
			float widthRatio = float(j) / float(boardWidth);
			float heightRatio = float(i) / float(boardHeight);

			float xPos = lerp(topLeftCorner.x, bottomRightCorner.x, widthRatio);
			float yPos = lerp(topLeftCorner.y, bottomRightCorner.y, heightRatio);


			sf::Vector2f pos(xPos, yPos);
			pos += (size / 2.0f);
			int arrayIdx = getSingleIndex(i, j, boardWidth);
			cells[arrayIdx] = new Cell(pos, size);
		}
	}

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
		for (int i = 0; i < cellCount; i++) {
			window.draw(cells[i]->draw());
		}

		// Draw UI view
		window.setView(uiView);
		window.draw(minesweeperTitle);

		// Displays everything that was rendered so far
		window.display();
	}

	// TODO: This should be in pooling destructor, instead of board
	for (int i = 0; i < cellCount; i++) {
		delete cells[i];
	}

	delete[] cells;

	return 0;
}