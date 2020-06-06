#pragma once
#include "CellState.h"

class CellMineState : public CellState {
public:
	static CellMineState* getInstance();

	virtual void handleMessage(Cell& owner, Message msg) override;
	virtual void enter(Cell& owner) override;
	virtual void exit(Cell& owner) override;
	virtual void handleAction(Cell& owner, Action action) override;

private:
	static CellMineState* instance;
	static sf::Texture* idleTexture;

private:
	CellMineState();
	~CellMineState();

	void open(Cell& owner);
};