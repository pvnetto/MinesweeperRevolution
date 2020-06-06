#pragma once
#include "CellState.h"
#include "SFML/Graphics.hpp"

class CellIdleState : public CellState {
public:
	static CellIdleState* getInstance();

	virtual void handleMessage(Cell& owner, Message msg) override;
	virtual void enter(Cell& owner) override;
	virtual void exit(Cell& owner) override;
	virtual void handleAction(Cell& owner, Action action) override;

private:
	static CellIdleState* instance;
	static sf::Texture* idleTexture;

private:
	CellIdleState();
	~CellIdleState();

	void open(Cell& owner);
};