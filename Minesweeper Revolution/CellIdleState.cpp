#include "CellIdleState.h"
#include "Cell.h"
#include "CellFlaggedState.h"

CellIdleState* CellIdleState::instance = NULL;
sf::Texture* CellIdleState::idleTexture = NULL;

CellIdleState::CellIdleState() {
	if (idleTexture == NULL) {
		idleTexture = new sf::Texture();
		idleTexture->loadFromFile("Cell_Idle.png");
	}
}

CellIdleState::~CellIdleState() {
	delete this->instance;
	delete this->idleTexture;

	this->instance = nullptr;
	this->idleTexture = nullptr;
}

CellIdleState* CellIdleState::getInstance() {
	if (instance == NULL) {
		instance = new CellIdleState();
	}

	return instance;
}

void CellIdleState::handleMessage(Cell& owner, Message msg) {
	if (msg == Message::REVEAL) {
		owner.handleReveal();
	}
}

void CellIdleState::enter(Cell & owner) {
	owner.setTexture(idleTexture);
}

void CellIdleState::exit(Cell & owner) { }

void CellIdleState::handleAction(Cell & owner, Action action) {
	switch (action) {
		case Action::LEFT_CLICK:
			owner.open();
			break;
		case Action::ALT_CLICK:
			owner.switchState(CellFlaggedState::getInstance());
			break;
		case Action::MOUSE_ENTER:
			owner.setColor(sf::Color(220, 220, 220));
			break;
		case Action::MOUSE_LEAVE:
			owner.setColor(sf::Color::White);
			break;
	}
}
