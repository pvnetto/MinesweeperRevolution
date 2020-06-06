#include "Cell.h"
#include "CellIdleState.h"
#include "CellMineState.h"
#include "CellOpenState.h"

#include "Board.h"

Cell::Cell() { }

Cell::Cell(sf::Vector2f pos, sf::Vector2f size) {
	this->setPosition(pos);
	this->setSize(size);
	this->switchState(CellIdleState::getInstance());
}

Cell::~Cell() {
	if (this->currentState) {
		this->currentState = nullptr;
	}
}

void Cell::setPosition(sf::Vector2f newPos) {
	this->shape.setPosition(newPos);
}

void Cell::setSize(sf::Vector2f newSize) {
	this->shape.setSize(newSize);
	this->shape.setOrigin(newSize / 2.0f);
}

void Cell::setColor(sf::Color color) {
	this->shape.setFillColor(color);
}

const sf::RectangleShape & Cell::getShape() {
	return this->shape;
}

void Cell::handleMessage(Message msg, Board & board) {
	currentState->handleMessage(*this, msg, board);
}

void Cell::switchState(CellState* newState) {
	if (this->currentState) {
		currentState->exit(*this);
	}
	this->currentState = newState;
	this->currentState->enter(*this);
}

void Cell::handleAction(Action action, Board& board) {
	this->currentState->handleAction(*this, action, board);
}

void Cell::setTexture(sf::Texture* newTexture) {
	shape.setTexture(newTexture);
}

const sf::Shape & Cell::draw() {
	return this->shape;
}

void Cell::setGridIndex(int idx) {
	this->gridIndex = idx;
}

void Cell::open(Board& board) {
	if (isMine) {
		switchState(CellMineState::getInstance());
	}
	else {
		switchState(CellOpenState::getInstance());
		if (adjacentMines == 0) {
			board.revealAdjacent(gridIndex);
		}
	}
}

void Cell::handleReveal(Board& board) {
	if (!isMine) {
		open(board);
	}
}

void Cell::setMine() {
	isMine = true;
}

void Cell::incrementMines() {
	this->adjacentMines++;
}

void Cell::reset() {
	this->isMine = false;
	this->adjacentMines = 0;
	this->gridIndex = -1;
	this->switchState(CellIdleState::getInstance());
}

int Cell::getAdjacentMinesCount() {
	return this->adjacentMines;
}
