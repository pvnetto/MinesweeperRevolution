#pragma once
#include "CellState.h"

class CellFlaggedState : public CellState {
public:
	static CellFlaggedState* getInstance();

	virtual void handleMessage(Cell& owner, Message msg) override;
	virtual void enter(Cell& owner) override;
	virtual void exit(Cell& owner) override;
	virtual void handleAction(Cell& owner, Action action) override;

private:
	static CellFlaggedState* instance;
	static sf::Texture* flaggedTexture;

private:
	CellFlaggedState();
	~CellFlaggedState();
};