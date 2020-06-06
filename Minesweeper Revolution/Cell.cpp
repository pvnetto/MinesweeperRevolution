#include "Cell.h"
#include "CellIdleState.h"

Cell::Cell() { }

Cell::Cell(sf::Vector2f pos, sf::Vector2f size) {
	this->setPosition(pos);
	this->setSize(size);
	this->switchState(CellIdleState::getInstance());
}

Cell::~Cell() {
	printf("Destroying");
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

void Cell::switchState(CellState* newState) {
	if (this->currentState) {
		currentState->exit(*this);
	}
	this->currentState = newState;
	this->currentState->enter(*this);
}

void Cell::handleAction(Action action) {
	this->currentState->handleAction(*this, action);
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
