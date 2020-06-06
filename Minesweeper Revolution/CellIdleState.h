#pragma once
#include "CellState.h"

class CellIdleState : public CellState {
public:
	static CellIdleState* getInstance();

	virtual void handleMessage(Cell& owner, Message msg, Board& board) override;
	virtual void enter(Cell& owner) override;
	virtual void exit(Cell& owner) override;
	virtual void handleAction(Cell& owner, Action action, Board& board) override;

private:
	static CellIdleState* instance;
	static sf::Texture* idleTexture;

private:
	CellIdleState();
	~CellIdleState();
};