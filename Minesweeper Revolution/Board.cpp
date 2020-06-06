#include "Board.h"
#include "Math.h"
#include <iostream>


Board::Board(const sf::RenderWindow& window, const sf::View& view) {
	float windowHeight = window.getSize().y;
	float offsetTop = view.getViewport().top * windowHeight;

	this->boardYStart = offsetTop + verticalOffset;
	this->boardYEnd = windowHeight - verticalOffset;
	this->boardMaxWidth = view.getSize().x;
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

void Board::handleEvents(const sf::RenderWindow& window, const sf::Event& evt) {
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::Vector2f mousePosF = sf::Vector2f(mousePos.x, mousePos.y);
	sf::Vector2f mousePosWorld = window.mapPixelToCoords(mousePos);

	for (int i = 0; i < cellCount; i++) {
		if (cells[i]->getShape().getGlobalBounds().contains(mousePosWorld)) {
			if (evt.mouseButton.button == sf::Mouse::Left && evt.type == sf::Event::MouseButtonReleased) {
				cells[i]->handleAction(Action::LEFT_CLICK);
			}
			else {
				cells[i]->handleAction(Action::MOUSE_ENTER);
			}
		}
		else {
			cells[i]->handleAction(Action::MOUSE_LEAVE);
		}
	}
}

void Board::generateBoard(int rows, int cols, int numMines) {
	instantiateBoard(rows, cols);

	// Row -> Height -> Y
	// Col -> Width  -> X
	for (int col = 0; col < cols; col++) {
		for (int row = 0; row < rows; row++) {
			instantiateCell(col, row);
		}
	}

	populateMines(numMines);
}

void Board::instantiateBoard(int rows, int cols) {
	this->rows = rows;
	this->cols = cols;
	this->cellCount = rows * cols;

	this->cells = { new Cell*[cellCount] };

	updateBoardDimensions();
}

void Board::updateBoardDimensions() {
	// Cells should always fill board height
	float cellHeight = getBoardHeight() / rows;
	this->cellSize = sf::Vector2f(cellHeight, cellHeight);

	float boardWidth = cellHeight * cols;
	float horizontalOffset = (boardMaxWidth - boardWidth) / 2.0f;

	this->topLeftCorner = sf::Vector2f(horizontalOffset, boardYStart);
	this->bottomRightCorner = sf::Vector2f(boardMaxWidth - horizontalOffset, boardYEnd);
}

void Board::instantiateCell(const int & col, const int & row) {
	float widthRatio = float(col) / float(cols);
	float heightRatio = float(row) / float(rows);

	float xPos = msrevo::Math::lerp(topLeftCorner.x, bottomRightCorner.x, widthRatio);
	float yPos = msrevo::Math::lerp(topLeftCorner.y, bottomRightCorner.y, heightRatio);

	sf::Vector2f pos(xPos, yPos);
	pos += (cellSize / 2.0f);

	int cellIdx = getCellIndex(row, col);
	cells[cellIdx] = new Cell(pos, cellSize);
}

bool Board::isGridPositionValid(const int &row, const int &col) {
	return row >= 0 && row < rows && col >= 0 && col < cols;
}

std::vector<int> Board::getAdjacentCells(int cellIdx) {
	int row, col;
	getCellRowCol(cellIdx, row, col);

	std::vector<int> adjacentCells;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {

			if (i != 0 || j != 0) {
				if (isGridPositionValid(row + i, col + j)) {
					adjacentCells.push_back(getCellIndex(row + i, col + j));
				}
			}

		}
	}

	return adjacentCells;
}

int Board::getCellCount() {
	return cellCount;
}

void Board::populateMines(int numMines) {
	std::vector<int> mineIndices = msrevo::Math::sampleFromRange(this->cellCount, numMines);
	std::cout << mineIndices.size() << std::endl;
	for (std::vector<int>::iterator it = mineIndices.begin(); it != mineIndices.end(); ++it) {
		placeMine(*it);
	}
}

void Board::placeMine(int mineIdx) {
	cells[mineIdx]->setMine();

	std::vector<int> adjacentCells = getAdjacentCells(mineIdx);
	for (std::vector<int>::iterator it = adjacentCells.begin(); it != adjacentCells.end(); ++it) {
		cells[*it]->incrementMines();
	}
}

void Board::print() {

	for (int i = 0; i < rows; i++) {
		std::string row = "";
		for (int j = 0; j < cols; j++) {
			Cell* currentCell = cells[getCellIndex(i, j)];
			row += currentCell->toChar();
		}
		std::cout << row << std::endl;
	}

}
