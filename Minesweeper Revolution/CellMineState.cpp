#include "CellMineState.h"
#include "Cell.h"

CellMineState* CellMineState::instance = NULL;
sf::Texture* CellMineState::mineTexture = NULL;

CellMineState::CellMineState() {
	if (mineTexture == NULL) {
		mineTexture = new sf::Texture();
		mineTexture->loadFromFile("Cell_Mine.png");
	}
}

CellMineState::~CellMineState() {
	delete this->instance;
	delete this->mineTexture;

	this->instance = nullptr;
	this->mineTexture = nullptr;
}

CellMineState* CellMineState::getInstance() {
	if (instance == NULL) {
		instance = new CellMineState();
	}

	return instance;
}

void CellMineState::enter(Cell & owner) {
	owner.setTexture(mineTexture);
}

void CellMineState::exit(Cell & owner) {}

void CellMineState::handleAction(Cell & owner, Action action, Board& board) { }
