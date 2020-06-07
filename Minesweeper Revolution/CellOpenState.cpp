#include "CellOpenState.h"
#include "Cell.h"

CellOpenState* CellOpenState::instance = NULL;
sf::Texture* CellOpenState::numberTextures[9];

CellOpenState::CellOpenState() {
	for (int i = 0; i <= 8; i++) {
		numberTextures[i] = new sf::Texture();
		numberTextures[i]->loadFromFile("Assets/Cell_" + std::to_string(i) + ".png");
	}
}

CellOpenState::~CellOpenState() {
	delete this->instance;
	delete this->numberTextures;

	this->instance = nullptr;

	for (int i = 0; i <= 8; i++) {
		delete numberTextures[i];
	}
	delete[] numberTextures;
}

CellOpenState* CellOpenState::getInstance() {
	if (instance == NULL) {
		instance = new CellOpenState();
	}

	return instance;
}

void CellOpenState::enter(Cell & owner) {
	owner.setTexture(numberTextures[owner.getAdjacentMinesCount()]);
}

void CellOpenState::exit(Cell & owner) {}

void CellOpenState::handleAction(Cell & owner, Action action, BaseContext& ctx) {}
