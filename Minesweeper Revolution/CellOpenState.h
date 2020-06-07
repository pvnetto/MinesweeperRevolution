#pragma once
#include "CellState.h"

class CellOpenState : public CellState {
public:
	static CellOpenState* getInstance();

	virtual void enter(Cell& owner) override;
	virtual void exit(Cell& owner) override;
	virtual void handleAction(Cell& owner, Action action, BaseContext& ctx) override;

private:
	static CellOpenState* instance;
	static sf::Texture* numberTextures[9];

private:
	CellOpenState();
	~CellOpenState();
};