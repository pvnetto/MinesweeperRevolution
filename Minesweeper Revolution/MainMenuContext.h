#pragma once
#include "BaseContext.h"
#include "MainMenuCanvas.h"

/// <summary>
///	BaseContext subclass that handles initialization, drawing and events of all
/// entities in the game's main menu
/// </summary>
class MainMenuContext : public BaseContext {
private:
	MainMenuCanvas* mainMenuCanvas = nullptr;
public:
	MainMenuContext(ContextManager& ctxManager, sf::RenderWindow& window);
	virtual ~MainMenuContext();

	virtual void handleEvents(const sf::RenderWindow& window, const sf::Event& evt) override;
};