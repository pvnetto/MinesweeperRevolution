#pragma once
#include "InteractableEntity.h"
#include "CellState.h"
#include "SFML/Graphics.hpp"
#include <iostream>

class BaseContext;

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
	sf::Shape* getShape();
	virtual void draw(sf::RenderWindow& window) override;

	void setGridIndex(int idx);

	void open(BaseContext & ctx);
	void handleReveal(BaseContext & ctx);
	void setMine();
	void incrementMines();
	void reset();

	int getAdjacentMinesCount();

	void handleMessage(Message msg, BaseContext & ctx);
	void switchState(CellState* newState);
	void handleAction(Action action, BaseContext & ctx);
	void setTexture(sf::Texture* newTexture);

	inline char toChar() {
		return isMine ? '*' : adjacentMines + '0';
	}

};