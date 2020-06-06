#pragma once
#include "CellState.h"
#include "SFML/Graphics.hpp"

class Cell {
public:
	bool isMine;

private:
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

	void open();

	void switchState(CellState* newState);
	void handleAction(Action action);
	void setTexture(sf::Texture* newTexture);

};