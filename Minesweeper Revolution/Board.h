#pragma once
#include "Cell.h"

class Board {
private:
	Cell* cells;
	int rows, cols, mineCount;

public:
	Board(const sf::View& view);
	void generateBoard(int rowCount, int colCount, int mineCount);
	void clearBoard();
	void resetBoard();

private:

	void handleEvents(sf::Event evt);
	inline int get2DIndex(int row, int col);
	inline int findIndexByPos(sf::Vector2f pos);


};