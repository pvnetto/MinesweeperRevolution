#include "Cell.h"
#include "CellIdleState.h"

Cell::Cell(sf::Vector2f pos, sf::Vector2f size) {
	this->setPosition(pos);
	this->setSize(size);
	this->switchState(CellIdleState::getInstance());
}

Cell::~Cell() {
	this->currentState = nullptr;
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

void Cell::switchState(CellState* newState) {
	if (this->currentState) {
		currentState->exit(*this);
	}
	this->currentState = newState;
	this->currentState->enter(*this);
}

void Cell::handleClick() {
	this->currentState->handleClick();
}

void Cell::setTexture(sf::Texture* newTexture) {
	shape.setTexture(newTexture);
}

const sf::Shape & Cell::draw() {
	return this->shape;
}

void Cell::open() {
	printf("Opening cell!\n");
}
