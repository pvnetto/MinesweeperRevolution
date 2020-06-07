#pragma once
#include "CanvasEntity.h"
#include "Cell.h"
#include "SFML/Graphics.hpp"
#include <iostream>

class BaseContext;

class Board : public CanvasEntity {
private:
	Cell** cells;

	// Board Dimensions
	int rows, cols, mineCount;
	int cellCount;

	// View Dimensions
	sf::View* view;
	const float verticalOffset = 50.0f;		// TODO: Move this to view building, so the view considers the vertical offset
	float boardYStart, boardYEnd;
	float boardMaxWidth;

	sf::Vector2f cellSize;
	sf::Vector2f topLeftCorner;
	sf::Vector2f bottomRightCorner;

public:
	Board(const sf::RenderWindow& window, sf::View& view);
	~Board();

	void draw(sf::RenderWindow& window);
	virtual void handleEvents(BaseContext& ctx, const sf::RenderWindow& window, const sf::Event& evt) override;

	void generateBoard(int rowCount, int colCount, int numMines);
	void revealAdjacent(int idx, BaseContext& ctx);
	void reset();

	int getCellCount();

	void print();
private:
	// Grid Methods
	void instantiateBoard(int rows, int cols);
	void updateBoardDimensions();
	void instantiateCell(const int& col, const int& row);

	std::vector<int> getAdjacentCells(int cellIdx);
	bool isGridPositionValid(const int &row, const int &col);

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

	// Board Methods
	void populateMines(int numMines);
	void placeMine(int mineIdx);
};