#include "Board.h"
#include <iostream>

Board::Board(const sf::RenderWindow& window, const sf::View& view) {
	float windowHeight = window.getSize().y;
	float offsetTop = view.getViewport().top * windowHeight;

	this->boardYStart = offsetTop + verticalOffset;
	this->boardYEnd = windowHeight - verticalOffset;
	this->boardWidth = view.getSize().x;
}

Board::~Board() {
	// TODO: This should be in pooling destructor, instead of board
	for (int i = 0; i < cellCount; i++) {
		delete cells[i];
	}

	delete[] cells;
}

void Board::draw(sf::RenderWindow& window) {
	for (int i = 0; i < cellCount; i++) {
		window.draw(cells[i]->draw());
	}
}

void Board::generateBoard(int rows, int cols, int mines) {
	this->rows = rows;
	this->cols = cols;
	this->cellCount = rows * cols;

	this->cells = { new Cell*[cellCount] };

	float newCellSize = (boardYEnd - boardYStart) / rows;
	float horizontalSpaceNeeded = newCellSize * cols;
	float horizontalOffset = (boardWidth - horizontalSpaceNeeded) / 2.0f;

	sf::Vector2f topLeftCorner(horizontalOffset, boardYStart);
	sf::Vector2f bottomRightCorner(boardWidth - horizontalOffset, boardYEnd);

	sf::Vector2f size(newCellSize, newCellSize);

	// Row -> Height -> Y
	// Col -> Width  -> X
	for (int j = 0; j < cols; j++) {
		for (int i = 0; i < rows; i++) {
			float widthRatio = float(j) / float(cols);
			float heightRatio = float(i) / float(rows);

			float xPos = msrevo::Math::lerp(topLeftCorner.x, bottomRightCorner.x, widthRatio);
			float yPos = msrevo::Math::lerp(topLeftCorner.y, bottomRightCorner.y, heightRatio);

			sf::Vector2f pos(xPos, yPos);
			pos += (size / 2.0f);
			int arrayIdx = get2DIndex(i, j);
			cells[arrayIdx] = new Cell(pos, size);
		}
	}
}

int Board::getCellCount() {
	return cellCount;
}
