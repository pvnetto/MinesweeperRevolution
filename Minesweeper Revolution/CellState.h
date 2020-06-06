#pragma once

class Cell;

enum Message { OPEN };

class CellState {

public:
	virtual void handleMessage(Cell& owner, Message msg);
	virtual void enter(Cell& owner) = 0;
	virtual void exit(Cell& owner) = 0;
	virtual void handleClick() = 0;

};