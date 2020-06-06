#pragma once
#include "Cell.h"

class Board {
private:
	// Refactor to grid
	Cell** cells;

	// Board Dimensions
	int rows, cols, mineCount;
	int cellCount;

	// View Dimensions
	const float verticalOffset = 50.0f;		// TODO: Move this to view building, so the view considers the vertical offset
	float boardYStart, boardYEnd;
	float boardMaxWidth;

	sf::Vector2f cellSize;
	sf::Vector2f topLeftCorner;
	sf::Vector2f bottomRightCorner;

public:
	Board(const sf::RenderWindow& window, const sf::View& view);
	~Board();

	void draw(sf::RenderWindow& window);
	void handleEvents(const sf::RenderWindow& window, const sf::Event& evt);

	void generateBoard(int rowCount, int colCount, int numMines);
	//void clearBoard();
	//void resetBoard();

	int getCellCount();
private:
	void instantiateBoard(int rows, int cols);
	void updateBoardDimensions();

	void instantiateCell(const int& col, const int& row);
	void populateMines(int numMines);

	inline int getCellIndex(int row, int col) {
		return (row * cols) + col;
	}

	inline void getCellRowCol(int cellIdx, int& row, int& col) {
		row = std::floor(cellIdx / cols);
		col = cellIdx - (row * cols);
	}

	inline float getBoardHeight() {
		return (boardYEnd - boardYStart);
	}
};