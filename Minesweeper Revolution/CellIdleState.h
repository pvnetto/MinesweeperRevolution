#pragma once
#include "CellState.h"
#include "SFML/Graphics.hpp"

class CellIdleState : public CellState {
public:
	static CellIdleState* getInstance();

	virtual void handleMessage(Cell& owner, Message msg) override;
	virtual void enter(Cell& owner) override;
	virtual void exit(Cell& owner) override;
	virtual void handleClick() override;

private:
	static CellIdleState* instance;
	static sf::Texture* texture;

private:
	CellIdleState();
	~CellIdleState();

};