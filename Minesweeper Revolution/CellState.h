#pragma once
#include "Message.h"
#include "Action.h"
#include "SFML/Graphics.hpp"

class Board;
class Cell;

class CellState {

public:
	virtual void handleMessage(Cell& owner, Message msg, Board& board);
	virtual void enter(Cell& owner) = 0;
	virtual void exit(Cell& owner) = 0;
	virtual void handleAction(Cell & owner, Action action, Board& board) = 0;

};