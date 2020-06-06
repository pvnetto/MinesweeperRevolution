#pragma once
#include "Message.h"
#include "Action.h"

class Cell;

class CellState {

public:
	virtual void handleMessage(Cell& owner, Message msg);
	virtual void enter(Cell& owner) = 0;
	virtual void exit(Cell& owner) = 0;
	virtual void handleAction(Cell & owner, Action action) = 0;

};