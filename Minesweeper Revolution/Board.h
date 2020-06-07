#pragma once
#include "CanvasEntity.h"
#include "Cell.h"
#include "SFML/Graphics.hpp"
#include <iostream>

class BaseContext;

/// <summary>
/// CanvasEntity that handles a grid of Cells (InteractableEntity) and game logic
/// that involve communication between different cells, since they have no direct access
/// to each other.
/// </summary>
class Board : public CanvasEntity {
private:
	// Board State
	Cell** cells;
	bool gameStarted = false;

	// Board Dimensions
	int rows, cols, mineCount;
	int cellCount;

	// View Dimensions
	const float verticalOffset = 50.0f;
	float boardYStart, boardYEnd;
	float boardMaxWidth;

	sf::Vector2f cellSize;
	sf::Vector2f topLeftCorner;
	sf::Vector2f bottomRightCorner;

public:
	Board(const sf::RenderWindow& window, sf::View& view);
	~Board();

	/// <summary>
	/// Generates a grid of cells with the specified dimensions.
	/// </summary>
	void generateGrid(int rowCount, int colCount, int numMines);

	/// <summary>
	/// Sends Reveal message to all cells adjacent to specified Cell.
	/// </summary>
	void revealAdjacent(BaseContext& ctx, int idx);

	/// <summary>
	/// Populates cells with mines and delegates game start event
	/// </summary>
	void startGame(BaseContext& ctx, int cellIdx);

	/// <summary>
	/// Resets the state of all grid cells.
	/// </summary>
	void resetGrid();

	/* Getters/Setters */
	inline bool hasStarted() { return gameStarted; }
	int getCellCount();

	/// <summary>
	/// Utility function to print the grid.
	/// </summary>
	void print();
private:
	/* Grid Management */
	/// <summary>
	/// Allocates memory for grid on a flattened 2D array
	/// </summary>
	void instantiateBoard(int rows, int cols);

	/// <summary>
	/// Updates grid dimensions depending on view size and number of cells
	/// </summary>
	void updateBoardDimensions();

	/// <summary>
	/// Handles all Cell instantiation logic
	/// </summary>
	void instantiateCell(const int& col, const int& row);

	/// <summary>
	/// Returns indices for all cells adjacent to specified cell in the grid,
	/// </summary>
	std::vector<int> getAdjacentCells(int cellIdx);

	/// <summary>
	/// Checks if row and col are within bounds of cell grid.
	/// </summary>
	bool isGridPositionValid(const int &row, const int &col);

	/// <summary>
	/// Helper function to convert 2D cell coordinates to a flattened index.
	/// </summary>
	inline int getCellIndex(int row, int col) {
		return (row * cols) + col;
	}

	/// <summary>
	/// Helper function to convert a flattened index back to a 2D coordinate
	/// </summary>
	inline void getCellRowCol(int cellIdx, int& row, int& col) {
		row = std::floor(cellIdx / cols);
		col = cellIdx - (row * cols);
	}

	/// <summary>
	/// Returns board height depending on calculated dimensions of the view.
	/// </summary>
	inline float getBoardHeight() {
		return (boardYEnd - boardYStart);
	}

	/* Game Logic */
	/// <summary>
	/// Populates cells with mines and their adjacent mine count.
	/// </summary>
	void populateMines(int cellIdx);
	void placeMine(int mineIdx);
};