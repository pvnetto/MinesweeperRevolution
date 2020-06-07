#include "CellFlaggedState.h"
#include "CellIdleState.h"
#include "Cell.h"

CellFlaggedState* CellFlaggedState::instance = NULL;
sf::Texture* CellFlaggedState::flaggedTexture = NULL;

CellFlaggedState::CellFlaggedState() {
	if (flaggedTexture == NULL) {
		flaggedTexture = new sf::Texture();
		flaggedTexture->loadFromFile("Assets/Cell_Flagged.png");
	}
}

CellFlaggedState::~CellFlaggedState() {
	delete this->instance;
	delete this->flaggedTexture;

	this->instance = nullptr;
	this->flaggedTexture = nullptr;
}

CellFlaggedState* CellFlaggedState::getInstance() {
	if (instance == NULL) {
		instance = new CellFlaggedState();
	}

	return instance;
}

void CellFlaggedState::handleMessage(Cell& owner, Message msg, BaseContext & ctx) {
	if (msg == Message::REVEAL) {
		owner.handleRevealMessage(ctx);
	}
}

void CellFlaggedState::enter(Cell& owner) {
	owner.setTexture(flaggedTexture);
}

void CellFlaggedState::exit(Cell& owner) {
	owner.setColor(sf::Color::White);
}

void CellFlaggedState::handleAction(Cell& owner, Action action, BaseContext& ctx) {
	switch (action) {
		case Action::LEFT_CLICK:
			owner.open(ctx);
			break;
		case Action::ALT_CLICK:
			owner.toggleFlagged(ctx, false);
			owner.switchState(CellIdleState::getInstance());
			break;
		case Action::MOUSE_ENTER:
			owner.setColor(sf::Color(220, 220, 220));
			break;
		case Action::MOUSE_LEAVE:
			owner.setColor(sf::Color::White);
			break;
	}
}
