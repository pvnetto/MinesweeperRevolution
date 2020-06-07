#pragma once
#include "CellState.h"

/// <summary>
/// State for open cells that are mines.
/// </summary>
class CellMineState : public CellState {
public:
	static CellMineState* getInstance();

	virtual void enter(Cell& owner) override;
	virtual void exit(Cell& owner) override;
	virtual void handleAction(Cell& owner, Action action, BaseContext& ctx) override;

private:
	static CellMineState* instance;
	static sf::Texture* mineTexture;

private:
	CellMineState();
	~CellMineState();
};