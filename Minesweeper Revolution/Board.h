#pragma once
#include "Cell.h"
#include "Math.h"

class Board {
private:
	Cell** cells;

	// Board Dimensions
	int rows, cols, mineCount;
	int cellCount;

	// View Dimensions
	const float verticalOffset = 50.0f;		// TODO: Move this to view building, so the view considers the vertical offset
	float boardYStart, boardYEnd;
	float boardWidth;

public:
	Board(const sf::RenderWindow& window, const sf::View& view);
	~Board();

	void draw(sf::RenderWindow& window);

	void generateBoard(int rowCount, int colCount, int mineCount);
	//void clearBoard();
	//void resetBoard();

	int getCellCount();
private:

	//void handleEvents(sf::Event evt);
	//inline int findIndexByPos(sf::Vector2f pos);

	inline int get2DIndex(int row, int col) {
		return (row * cols) + col;
	}
};