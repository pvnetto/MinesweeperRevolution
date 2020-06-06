#pragma once

#include "BaseContext.h"

class ContextManager {
private:
	BaseContext* currentContext = nullptr;
	sf::RenderWindow* window;

public:
	ContextManager(sf::RenderWindow& window);

	void switchContext(BaseContext* newContext);
	void run();
};