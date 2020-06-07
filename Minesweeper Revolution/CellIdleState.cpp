#include "CellIdleState.h"
#include "Cell.h"
#include "CellFlaggedState.h"

CellIdleState* CellIdleState::instance = NULL;
sf::Texture* CellIdleState::idleTexture = NULL;

CellIdleState::CellIdleState() {
	if (idleTexture == NULL) {
		idleTexture = new sf::Texture();
		idleTexture->loadFromFile("Assets/Cell_Idle.png");
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

void CellIdleState::handleMessage(Cell& owner, Message msg, BaseContext & ctx) {
	if (msg == Message::REVEAL) {
		owner.handleRevealMessage(ctx);
	}
}

void CellIdleState::enter(Cell & owner) {
	owner.setTexture(idleTexture);
}

void CellIdleState::exit(Cell & owner) {
	owner.setColor(sf::Color::White);
}

void CellIdleState::handleAction(Cell & owner, Action action, BaseContext& ctx) {
	switch (action) {
		case Action::LEFT_CLICK:
			owner.open(ctx);
			break;
		case Action::ALT_CLICK:
			owner.toggleFlagged(ctx, true);
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
