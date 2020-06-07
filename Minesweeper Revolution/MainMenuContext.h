#pragma once
#include "BaseContext.h"

class MainMenuContext : public BaseContext {
public:
	MainMenuContext(ContextManager& ctxManager, sf::RenderWindow& window);
	virtual ~MainMenuContext();

	virtual void handleEvents(const sf::RenderWindow& window, const sf::Event& evt) override;
};