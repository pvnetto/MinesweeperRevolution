#pragma once
#include "BaseContext.h"
#include "MainMenuCanvas.h"

class MainMenuContext : public BaseContext {
private:
	MainMenuCanvas* mainMenuCanvas = nullptr;
public:
	MainMenuContext(ContextManager& ctxManager, sf::RenderWindow& window);
	virtual ~MainMenuContext();

	virtual void handleEvents(const sf::RenderWindow& window, const sf::Event& evt) override;
};