#pragma once
#include "CellState.h"
#include "SFML/Graphics.hpp"
#include <iostream>

class Cell {
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
	const sf::RectangleShape& getShape();
	const sf::Shape& draw();

	void setGridIndex(int idx);

	void open(Board& board);
	void handleReveal(Board& board);
	void setMine();
	void incrementMines();
	void reset();

	int getAdjacentMinesCount();

	void handleMessage(Message msg, Board& board);
	void switchState(CellState* newState);
	void handleAction(Action action, Board& board);
	void setTexture(sf::Texture* newTexture);

	inline char toChar() {
		return isMine ? '*' : adjacentMines + '0';
	}

};