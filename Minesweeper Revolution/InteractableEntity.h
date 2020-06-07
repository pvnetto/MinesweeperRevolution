#pragma once
#include "Entity.h"
#include "Action.h"

class BaseContext;

class InteractableEntity : public Entity {
public:
	virtual sf::Shape* getShape() = 0;
	virtual void handleAction(Action action, BaseContext & ctx) = 0;
};