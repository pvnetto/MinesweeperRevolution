#include "CellIdleState.h"
#include "Cell.h"

CellIdleState* CellIdleState::instance = NULL;
sf::Texture* CellIdleState::texture = NULL;

CellIdleState::CellIdleState() {
	if (texture == NULL) {
		texture = new sf::Texture();
		texture->loadFromFile("Default.png");
	}
}

CellIdleState::~CellIdleState() {
	delete this->instance;
	delete this->texture;

	this->instance = nullptr;
	this->texture = nullptr;
}

CellIdleState* CellIdleState::getInstance() {
	if (instance == NULL) {
		instance = new CellIdleState();
	}

	return instance;
}

void CellIdleState::handleMessage(Cell& owner, Message msg) {
	if (msg == Message::OPEN) {
		owner.open();
	}
}

void CellIdleState::enter(Cell & owner) {
	owner.setTexture(texture);
}

void CellIdleState::exit(Cell & owner) {
}

void CellIdleState::handleClick() {
	
}
