#pragma once
#include "InteractableEntity.h"
#include "CellState.h"
#include "SFML/Graphics.hpp"
#include <iostream>

class BaseContext;

/// <summary>
/// InteractableEntity for a board Cell. Delegates events to CellState,
/// where all game rules related to the board and cells are handled.
/// </summary>
class Cell : public InteractableEntity {
public:
	bool isMine;
	int gridIndex;

private:
	int adjacentMines;

	sf::RectangleShape shape;

	CellState* currentState = nullptr;

public:
	Cell();
	Cell(sf::Vector2f pos, sf::Vector2f size);
	~Cell();

	void setPosition(sf::Vector2f newPos);
	void setSize(sf::Vector2f newSize);
	void setColor(sf::Color color);

	/* Inherited from InteractableEntity */
	sf::Shape* getShape();
	virtual void draw(sf::RenderWindow& window) override;

	/* Methods called by CellState when applicable. */
	/// <summary>
	/// Opens the cell, revealing its number/mine.
	/// <summary>
	void open(BaseContext& ctx);

	/// <summary>
	/// Delegates flagging/unflagging to GameManager
	/// </summary>
	void toggleFlagged(BaseContext& ctx, bool flagged);

	/// <summary>
	/// Determines if a cell should be opened when an adjacent 0 cell is opened.
	/// </summary>
	void handleRevealMessage(BaseContext & ctx);

	/* Methods used by the Board to handle its state. */
	/// <summary>
	/// Increments the number of adjacent mines by one.
	/// <summary>
	void incrementAdjacentMines();
	
	/// <summary>
	/// Resets cell state.
	/// </summary>
	void reset();


	/* Getters/Setters */
	void setMine();
	void setGridIndex(int idx);
	int getAdjacentMinesCount();

	/* Delegates for CellState methods */
	void handleMessage(Message msg, BaseContext & ctx);
	void switchState(CellState* newState);
	void handleAction(Action action, BaseContext & ctx);
	void setTexture(sf::Texture* newTexture);

	inline char toChar() {
		return isMine ? '*' : adjacentMines + '0';
	}

};