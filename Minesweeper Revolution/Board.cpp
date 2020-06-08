#include "Board.h"
#include "Math.h"
#include "GameManager.h"
#include <iostream>

Board::Board(const sf::RenderWindow& window, sf::View& view) {
	float windowHeight = window.getSize().y;
	float offsetTop = view.getViewport().top * windowHeight;

	this->view = &view;
	this->boardYStart = offsetTop + verticalOffset;
	this->boardYEnd = windowHeight - verticalOffset;
	this->boardMaxWidth = view.getSize().x;
}

Board::~Board() {
	delete[] cells;
}

void Board::generateGrid(int rows, int cols, int numMines) {
	this->mineCount = numMines;
	instantiateBoard(rows, cols);

	// Row -> Height -> Y
	// Col -> Width  -> X
	for (int col = 0; col < cols; col++) {
		for (int row = 0; row < rows; row++) {
			instantiateCell(col, row);
		}
	}
}

void Board::revealAdjacent(BaseContext& ctx, int cellIdx) {
	std::vector<int> adjacentCells = getAdjacentCells(cellIdx);

	for (std::vector<int>::iterator it = adjacentCells.begin(); it != adjacentCells.end(); ++it) {
		cells[*it]->handleMessage(CellState::Message::REVEAL, ctx);
	}
}

void Board::startGame(BaseContext & ctx, int cellIdx) {
	if (!gameStarted) {
		gameStarted = true;
		populateMines(cellIdx);

		GameManager* gm = ctx.findEntity<GameManager>();
		gm->resetCellCount(cellCount - mineCount);
		gm->resetMineCount(ctx, mineCount);
	}
}

void Board::resetGrid() {
	inputEnabled = true;
	gameStarted = false;
	for (int i = 0; i < cellCount; i++) {
		cells[i]->reset();
	}
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
	cells[cellIdx]->setGridIndex(cellIdx);
	entities.push_back(cells[cellIdx]);
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

void Board::populateMines(int cellIdx) {
	std::vector<int> mineIndices = msrevo::Math::sampleFromRange(this->cellCount, this->mineCount, cellIdx);
	for (std::vector<int>::iterator it = mineIndices.begin(); it != mineIndices.end(); ++it) {
		placeMine(*it);
	}
}

void Board::placeMine(int mineIdx) {
	cells[mineIdx]->setMine();

	std::vector<int> adjacentCells = getAdjacentCells(mineIdx);
	for (std::vector<int>::iterator it = adjacentCells.begin(); it != adjacentCells.end(); ++it) {
		cells[*it]->incrementAdjacentMines();
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
