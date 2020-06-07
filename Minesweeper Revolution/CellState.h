#pragma once
#include "Message.h"
#include "Action.h"
#include "SFML/Graphics.hpp"

class Cell;
class BaseContext;

/// <summary>
/// 
/// </summary>
class CellState {

public:
	virtual void handleMessage(Cell& owner, Message msg, BaseContext & ctx);
	virtual void enter(Cell& owner) = 0;
	virtual void exit(Cell& owner) = 0;
	virtual void handleAction(Cell & owner, Action action, BaseContext& ctx) = 0;

};