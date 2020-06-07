#pragma once
#include "Action.h"
#include "SFML/Graphics.hpp"

class Cell;
class BaseContext;

/// <summary>
/// Base Class for cell state machine states. Each CellState child class is expected to implement the
/// singleton pattern and handle game rules for a cell
/// </summary>
class CellState {
public:
	enum class Message {
		REVEAL
	};

public:
	/// <summary>
	/// Handles messages received from other entities.
	/// </summary>
	virtual void handleMessage(Cell& owner, Message msg, BaseContext & ctx);

	/// <summary>
	/// Executes transition logic when state is entered.
	/// </summary>
	virtual void enter(Cell& owner) = 0;

	/// <summary>
	/// Executes transition logic when state is exited.
	/// </summary>
	virtual void exit(Cell& owner) = 0;

	/// <summary>
	/// Handles actions received from a CanvasEntity.
	/// </summary>
	virtual void handleAction(Cell & owner, Action action, BaseContext& ctx) = 0;

};