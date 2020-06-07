#include "Cell.h"
#include "CellIdleState.h"
#include "CellMineState.h"
#include "CellOpenState.h"

#include "GameManager.h"
#include "Board.h"
#include "BaseContext.h"

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

sf::Shape* Cell::getShape() {
	return &shape;
}

void Cell::handleMessage(Message msg, BaseContext & ctx) {
	currentState->handleMessage(*this, msg, ctx);
}

void Cell::switchState(CellState* newState) {
	if (this->currentState) {
		currentState->exit(*this);
	}
	this->currentState = newState;
	this->currentState->enter(*this);
}

void Cell::handleAction(Action action, BaseContext & ctx) {
	this->currentState->handleAction(*this, action, ctx);
}

void Cell::setTexture(sf::Texture* newTexture) {
	shape.setTexture(newTexture);
}

void Cell::draw(sf::RenderWindow& window) {
	window.draw(shape);
}

void Cell::setGridIndex(int idx) {
	this->gridIndex = idx;
}

void Cell::open(BaseContext & ctx) {
	Board* board = ctx.findEntity<Board>();
	if (!board->hasStarted()) {
		board->start(gridIndex);
	}
	if (isMine) {
		switchState(CellMineState::getInstance());

		GameManager* gm = ctx.findEntity<GameManager>();
		gm->gameOver(ctx);
	}
	else {
		switchState(CellOpenState::getInstance());
		if (adjacentMines == 0) {
			board->revealAdjacent(gridIndex, ctx);
		}
	}
}

void Cell::handleReveal(BaseContext & ctx) {
	if (!isMine) {
		open(ctx);
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
	this->switchState(CellIdleState::getInstance());
}

int Cell::getAdjacentMinesCount() {
	return this->adjacentMines;
}
